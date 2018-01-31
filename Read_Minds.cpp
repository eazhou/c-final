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
  std::string faceValue;

public:
  Card(std::string suit, std::string faceValue) :suit(suit), faceValue(faceValue)
  {
    //  if(num == 11)
      //  name = "J_" + suit;

      //else if(num == 12)
        //name = "Q_" + suit;

      //else if(num == 13)
      //  name = "K_" + suit;

      //else if(num == 1)
        //name = "A_" + suit;

      //else
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
};

class Deck
{
  std::vector<Card> allCards;
  int numCards;
  std::vector<Card> fiveCards;


public:
  Deck(): numCards(52), allCards(allCards){};

  //Card cPickCard(Deck d1);
  //Card pPickCard(Deck d1);
  Deck removeCard(Deck d1, Card c1);
  void initialDeck();
};

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
    faceValue = num + "";

  return faceValue;
}

void Deck::initialDeck()
{
  std::vector<std::string> suits = {"C","D","H","S"};
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

std::string Card::getSuit()
{
  return suit;
}

std::string Card::getName()
{
  return name;
}

std::vector<int> sameIndexCards(std::vector<Card> fiveCards)
{
  int index1;
  int index2;
  std::vector<int> indexes;

  for (int i = 0; i < 5; i++)
  {
    for (int j = i+1; j < 5; i++)
    {
      if (fiveCards.at(i).getSuit() == fiveCards.at(j).getSuit())
      {
        index1 = i;
        index2 = j;
        indexes.push_back(i);
        indexes.push_back(j);
        return indexes;
      }
    }
  }

}

int main()
{

  Deck d;
  Card c1;
  std::vector<Card> fiveCards;
  for(int i = 0; i < 5; i++)
  {
    std::cout << "Enter your card";
    std::string input1;
    std::cin >> input1;

    c1 = Card(input1);
    fiveCards.push_back(c1);
  //  d.removeCard(c1);
  }





  return 0;
}
