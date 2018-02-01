#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>


class Card;
class Deck;

class Card
{
  std::string name;
  std::string suit;
  std::string faceValue;

public:
  Card(std::string suit, std::string faceValue) :suit(suit), faceValue(faceValue)
  {
      name = faceValue + "_" + suit;
  }

  Card(std::string name) : name(name)
  {
    if(name.substr(0,1) == "10")
    {
      faceValue = "10";
      suit = name.substr(3);
    }
    else
    {
      faceValue = name.substr(0);
      suit = name.substr(2);
    }
  }

  Card(){};

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

  std::string getSuit();
  std::string getName();
  bool operator==(const Card &c);
};

//WORKS
std::string Card::getSuit()
{
  return suit;
}

//WORKS
std::string Card::getName()
{
  return name;
}

//WORKS
bool Card::operator==(const Card &c)
{
  if ((this->suit == c.suit) && (this->faceValue == c.faceValue)) {
    return true;
  }
  else
    return false;
}

std::string numToValue(int num)
{
  std::string faceValue;

  if(num == 11)
    faceValue = "J";

  else if(num == 12)
    faceValue = "Q";

  else if(num == 13)
    faceValue = "K";

  else if(num == 1)
    faceValue = "A";

  else
    faceValue = std::to_string(num);

  return faceValue;
}

class Deck
{
  std::vector<Card> allCards;
  std::vector<Card> fiveCards;

public:
  Deck(): allCards(allCards){};

  Card cPickCard();
  void initialDeck();
  int size();
  void removeCard(Card c1);
  friend std::ostream &operator<<(std::ostream &os, const Deck &d);
};

//WORKS
void Deck::initialDeck()
{
  std::vector<std::string> suits;
  suits.push_back("C");
  suits.push_back("D");
  suits.push_back("H");
  suits.push_back("S");

  for(int num = 1; num <=13; num++)
  {
    std::string faceValue;
    faceValue = numToValue(num);
    for(auto suit : suits)
    {
      allCards.push_back(Card(suit,faceValue));
    }
  }
}

//WORKS
int Deck::size()
{
  return allCards.size();
}

//WE HAVE A DECK OMG
std::ostream &operator<<(std::ostream &os, const Deck &d)
{
  for (int i=0; i<d.allCards.size(); i++)
  {
    os << d.allCards.at(i) << ", ";
  }
  return os;
}

//WORKS
// Card Deck::cPickCard()
// {
//   int index = rand() % allCards.size();
//   return allCards.at(index);
// }

//DOESNT WORK I GIVE UP
// void Deck::removeCard(Card c1)
// {
//   for (int i = 0; i < allCards.size(); i++)
//   {
//     std::cout << allCards[i] << std::endl;
//     if (c1 == allCards[i])
//     {
//       std::cout << "YES IT WORKS" << std::endl;
//       allCards.erase(allCards.begin()+i);
//     }
//   }
// }

// Card Deck::hiddenCard (){
//   // cards are c1,c2,c3,c4,c5 should be in a vector deck d1
//
// }
//
// Card Deck::firstCard(){
//   //finds the first card
// }
//
// Card Deck::nextThreeCards(){
//   //orders the remaning three cards
//   //suit order from greatest to least in value is spades, hearts, clubs, diamonds
//
// }
//
// std::vector<int> sameIndexCards(std::vector<Card> fiveCards)
// {
//   int index1;
//   int index2;
//   std::vector<int> indexes(2);
//
//   for (int i = 0; i < 5; i++)
//   {
//     for (int j = i+1; j < 5; i++)
//     {
//       if (fiveCards.at(i).getSuit == fiveCards.at(j).getSuit)
//       {
//         index1 = i;
//         index2 = j;
//         indexes.push_back(i);
//         indexes.push_back(j);
//         return indexes;
//       }
//     }
//   }
//
// }


int main()
{
  Deck d;
  Card c1;
  c1 = Card("4_S");

  std::cout << c1 << std::endl;

  d.initialDeck();
  std::cout << "initial deck: " << d << std::endl;

  d.removeCard(c1);
  std::cout << "after remove: " << d << std::endl;
  //
  // std::cout << "size of deck: " << d.size() << std::endl;

  // std::cout << c1 << std::endl;
  // std::cout << c2 << std::endl;
  //
  // if (c1 == c2) {
  //   std::cout << "the cards are the same!" << std::endl;
  // }
  // else
  //   std::cout << "the cards are not the same!" << std::endl;

  std::cout << "program finished" << std::endl;
  // std::vector<Card> fiveCards(5);
  // for(int i = 0; i < 5; i++)
  // {
  //   std::cout << "Enter your card";
  //   string c1;
  //   std::cin >> c1;
  //   c1.substr(0)
  //   fiveCards.push_back(c1);
  //   d.removeCard(c1);
  // }

  return 0;
}
