#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

//Programming for the Puzzled -- Srini Devadas
//You Can Read Minds (With a Little Calibration)
//Five random cards are chosen and one of them is hidden.
//Given four cards in a particular order, you can figure out what the fifth card is!

//Deck is are a list of strings, each string is a card
//The order of cards in the list matters.
//std::vector<char> deck = {"A_C", "A_D", "A_H", "A_S", "2_C", "2_D", "2_H", "2_S", "3_C", "3_D", "3_H", "3_S",
//      "4_C", "4_D", "4_H", "4_S", "5_C", "5_D", "5_H", "5_S", "6_C", "6_D", "6_H", "6_S",
  //      "7_C", "7_D", "7_H", "7_S", "8_C", "8_D", "8_H", "8_S", "9_C", "9_D", "9_H", "9_S",
    //    "10_C", "10_D", "10_H", "10_S", "J_C", "J_D", "J_H", "J_S",
      //  "Q_C", "Q_D", "Q_H", "Q_S", "K_C", "K_D", "K_H", "K_S"};
//Given 5 cards, Assistant hides an appropriate card
//He/she reads out the remaining four cards after choosing their order carefully!

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
  //std::vector<std::string> vCards = {"A_C", "A_D", "A_H", "A_S", "2_C", "2_D", "2_H", "2_S", "3_C", "3_D", "3_H", "3_S",
    //    "4_C", "4_D", "4_H", "4_S", "5_C", "5_D", "5_H", "5_S", "6_C", "6_D", "6_H", "6_S",
      //    "7_C", "7_D", "7_H", "7_S", "8_C", "8_D", "8_H", "8_S", "9_C", "9_D", "9_H", "9_S",
        //  "10_C", "10_D", "10_H", "10_S", "J_C", "J_D", "J_H", "J_S",
        //  "Q_C", "Q_D", "Q_H", "Q_S", "K_C", "K_D", "K_H", "K_S"};

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
  std::vector<Card> vCards;
  int numCards;

public:
  Deck(): numCards(52), vCards(vCards){};

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
      vCards.push_back(Card(suit,num));
    }
  }
}

Card Deck::cPickCard(Deck d1)
{
  int index = rand() % d1.numCards;
  return vCards.at(index);
}

//Card Deck::pPickCard(Deck d1)
//{


//}

Deck Deck::removeCard(Deck d1, Card c1)
{
  //std::vector<int>::iterator newVec;
  //d1.vCards.
  //newVec = std::remove(d1.vCards.begin(),d1.vCards.end(),c1);
  //int pos = find(d1.vCards.begin(),d1.vCards.end(),c1)-d1.vCards.begin();
  //d1.vCards.erase(d1.vCards.begin()+pos);

  //std::vector<int>::iterator position = std::find(d1.vCards.begin(), d1.vCards.end(), c1);
  //  if (position != d1.vCards.end()) // == myVector.end() means the element was not found
  //      d1.vCards.erase(position);

  
  for(auto card1 : d1.vCards)
  {
    if(card1.name == c1.name)

  }

  return d1;


  //auto it = std::find(d1.vCards.begin(), d1.vCards.end(), c1)
  //if(it != d1.vCards.end())
  //  d1.vCards.erase(it);

  //return d1;
}




int main()
{

  return 0;
}
