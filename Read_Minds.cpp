#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>


class Card;
class Deck;


class Card
{
  std::string name;
  std::string suit;
  int num;

public:
  Card(std::string suit, int num) :suit(suit), num(num)
  {
      if(num == 11)
        name = "J_" + suit;

      else if(num == 12)
        name = "Q_" + suit;

      else if(num == 13)
        name = "K_" + suit;

      else if(num == 1)
        name = "A_" + suit;

      else
        name = num + "_" + suit;

  }


  friend std::istream &operator>>(std::istream &is, Card &c)
  {
      is >> c.name;
        return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const Card &c)
  {
      os << c.name;
      return os;
  }


};

class Deck
{
  std::vector<Card> allCards;
  int numCards;
  std::vector<Card> fiveCards;


public:
  Deck(): numCards(52), allCards(allCards){};

  Card cPickCard(Deck d1);
  //Card pPickCard(Deck d1);
  Deck removeCard(Deck d1, Card c1);
  void initialDeck();
};

void Deck::initialDeck()
{
  std::vector<std::string> suits = {"C","D","H","S"};
  for(int num = 1; num <=13; num++)
  {
    for(auto suit : suits)
    {
      allCards.push_back(Card(suit,num));
    }
  }
}

Card Deck::cPickCard(Deck d1)
{
  int index = rand() % d1.numCards;
  return allCards.at(index);
}

//Card Deck::pPickCard(Deck d1)
//{


//}

Deck Deck::removeCard(Deck d1, Card c1)
{
  //std::vector<int>::iterator newVec;
  //d1.allCards.
  //newVec = std::remove(d1.allCards.begin(),d1.allCards.end(),c1);
  //int pos = find(d1.allCards.begin(),d1.allCards.end(),c1)-d1.allCards.begin();
  //d1.allCards.erase(d1.allCards.begin()+pos);

  //std::vector<int>::iterator position = std::find(d1.allCards.begin(), d1.allCards.end(), c1);
  //  if (position != d1.allCards.end()) // == myVector.end() means the element was not found
  //      d1.allCards.erase(position);


  for(auto card1 : d1.allCards)
  {
    if(card1.name == c1.name)

  }

  return d1;


  //auto it = std::find(d1.allCards.begin(), d1.allCards.end(), c1)
  //if(it != d1.allCards.end())
  //  d1.allCards.erase(it);

  //return d1;
}

Card Deck::hiddenCard (){
  // cards are c1,c2,c3,c4,c5 should be in a vector deck d1

}

Card Deck::firstCard(){
  //finds the first card
}

Card Deck::nextThreeCards(){
  //orders the remaning three cards
  //suit order from greatest to least in value is spades, hearts, clubs, diamonds

}


int main()
{
  Deck d;
  
  std::vector<Card> fiveCards(5);
  for(int i = 0; i < 5; i++)
  {
    std::cout << "Enter your card";
    Card c1;
    std::cin >> c1;
    fiveCards.push_back(c1);
    d.removeCard(c1);
  }

  return 0;
}
