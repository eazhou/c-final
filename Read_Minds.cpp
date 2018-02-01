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
  faceValue = name.substr(0);
  suit = name.substr(2);
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

std::string Card::getSuit()
{
  return suit;
}

std::string Card::getName()
{
  return name;
}

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
  Deck removeCard(Card c1);
  void initialDeck();
  int size();
};

void Deck::initialDeck()
{
  std::vector<std::string> suits(4);
  suits.push_back("C");
  suits.push_back("D");
  suits.push_back("H");
  suits.push_back("S");

  for(int num = 1; num <=13; num++)
  {
    std::string faceValue;
    faceValue = numToValue(num);
    //faceValue = "A";
    for(auto suit : suits)
    {
      allCards.push_back(Card(suit,faceValue));
    }
  }
}

int Deck::size()
{
  return allCards.size();
}

// Card Deck::cPickCard(Deck d1)
// {
//   int index = rand() % d1.allCards.size();
//   return allCards.at(index);
// }

// Deck Deck::removeCard(Deck d1, Card c1)
// {
//   for (int i = 0; i < d1.allCards.size(); i++) {
//     if (d1.allCards.at(i) == c1) {
//       d1.allCards.erase(i);
//     }
//   }
//
//   return d1;
//   //std::vector<int>::iterator newVec;
//   //d1.allCards.
//   //newVec = std::remove(d1.allCards.begin(),d1.allCards.end(),c1);
//   //int pos = find(d1.allCards.begin(),d1.allCards.end(),c1)-d1.allCards.begin();
//   //d1.allCards.erase(d1.allCards.begin()+pos);
//
//   //std::vector<int>::iterator position = std::find(d1.allCards.begin(), d1.allCards.end(), c1);
//   //  if (position != d1.allCards.end()) // == myVector.end() means the element was not found
//   //      d1.allCards.erase(position);
//
//
//   // for(auto card1 : d1.allCards)
//   // {
//   //   if(card1.name == c1.name)
//   //
//   // }
//   //
//   // return d1;
//
//
//   //auto it = std::find(d1.allCards.begin(), d1.allCards.end(), c1)
//   //if(it != d1.allCards.end())
//   //  d1.allCards.erase(it);
//
//   //return d1;
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
  Card c2;

  std::cout << "size of deck: " << d.size() << std::endl;

  // c1 = d.cPickCard(d);
  // c2 = d.cPickCard(d);

  // std::cout << c1 << std::endl;
  // std::cout << c2 << std::endl;
  //
  // if (c1 == c2) {
  //   std::cout << "the cards are the same!" << std::endl;
  // }
  // else
  //   std::cout << "the cards are not the same!" << std::endl;
  //
  // std::cout << "program finished" << std::endl;
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
