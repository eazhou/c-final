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
  int num;


public:
  // Card(std::string suit, std::string faceValue) :suit(suit), faceValue(faceValue)
  // {
  //     name = faceValue + "_" + suit;
  // }

  Card(std::string suit, int num) :suit(suit), num(num)
  {
    if(num == 11)
    {
      name = "J_" + suit;
      faceValue = "J";
    }
    else if(num == 12)
    {
      name = "Q_" + suit;
      faceValue = "Q";
    }
    else if(num == 13)
    {
      name = "K_" + suit;
      faceValue = "K";
    }
    else if(num == 1)
    {
      name = "A_" + suit;
      faceValue = "A";
    }
    else
    {
      name = num + "_" + suit;
      faceValue = num + "";
    }
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
  std::string getFaceValue();
  int getNum();
};

class Deck
{
  std::vector<Card> allCards;
  int numCards;
  std::vector<Card> fiveCards;


public:
  Deck(): allCards(allCards){};


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

std::string Card::getSuit()
{
  return suit;
}

std::string Card::getName()
{
  return name;
}

std::string Card::getFaceValue()
{
  return faceValue;
}

int Card::getNum()
{
  return num;
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

std::vector<Card> sameSuitCards(int index1, int index2, std::vector<Card> fiveCards)
{
  //returns the smallest difference between the two numbers needed in threeCards function
  std::vector<Card> sameSuitCards;
  int diff;
  int num1;
  int num2;
  Card hiddenCard;
  Card visibleCard;
  num1 = fiveCards.at(index1).getNum();
  num2 = fiveCards.at(index2).getNum();

  if(num1 > num2)
    diff = num1-num2;
  else
    diff = num2-num1;

  if(diff>6)
  {
    visibleCard = fiveCards.at(index1);
    hiddenCard = fiveCards.at(index2);

  }
  else
  {
    visibleCard = fiveCards.at(index2);
    hiddenCard = fiveCards.at(index1);
  }

  sameSuitCards.push_back(hiddenCard);
  sameSuitCards.push_back(visibleCard);

  return sameSuitCards;
}

int diff(std::vector<Card> sameSuitCards)
{
  int diff;
  int num1;
  int num2;

  num1 = sameSuitCards.at(0).getNum();
  num2 = sameSuitCards.at(1).getNum();

  if(num1>num2)
    diff = num1-num2;
  else
    diff = num2-num1;

  if(diff<=6)
    return diff;
  else
    return 13-diff;

  return diff;
}


std::vector<Card> nextThreeCards(int index1, int index2, std::vector<Card> fiveCards, int diff )
{
  //returns a vector of the three cards in order
  std::vector<Card> threeCards;
  for (int i = 0; i < 5; i++)
  {
    if (i == index1 or i == index2){}
    else
      threeCards.push_back(fiveCards.at(i));
  }
  int min = 0;
  int max = 0;
  int mid = 0;
  for (int i = 1; i < 3; i++)
  {
    if (threeCards.at(i).getNum() > threeCards.at(max).getNum())
      max = i;
    if (threeCards.at(i).getNum() < threeCards.at(min).getNum())
      min = i;
  }
  for (int i = 0; i < 3; i++)
  {
    if (max != i && min != i)
      mid = i;
  }

  std::vector<Card> ordered;
  if (diff == 1){
    ordered.push_back(threeCards.at(min));
    ordered.push_back(threeCards.at(mid));
    ordered.push_back(threeCards.at(max));
  }
  else if (diff == 2){
    ordered.push_back(threeCards.at(min));
    ordered.push_back(threeCards.at(max));
    ordered.push_back(threeCards.at(mid));
  }
  else if (diff == 3){
    ordered.push_back(threeCards.at(mid));
    ordered.push_back(threeCards.at(min));
    ordered.push_back(threeCards.at(max));
  }
  else if (diff == 4){
    ordered.push_back(threeCards.at(mid));
    ordered.push_back(threeCards.at(max));
    ordered.push_back(threeCards.at(min));
  }
  else if (diff == 5){
    ordered.push_back(threeCards.at(max));
    ordered.push_back(threeCards.at(min));
    ordered.push_back(threeCards.at(mid));
  }
  else{
    ordered.push_back(threeCards.at(max));
    ordered.push_back(threeCards.at(mid));
    ordered.push_back(threeCards.at(min));
  }
  return ordered;
}

bool guessIsRight(Card guess, Card hiddenCard)
{
  if(guess.getName() == hiddenCard.getName())
    return true;

  return false;
}

int main()
{
  Deck d;
  Card c1;
  std::vector<Card> fiveCards; //the five cards to be ordered.
  std::vector<int> indexes; //the indexes of the two cards of the same suit.
  std::vector<Card> sameSuitCards1; //the two cards of the same suit in the five cards to be ordered.
  int diff1; //difference between two cards of same suit (<=6)
  std::vector<Card> nextThreeCards1; //other three cards, ordered correctly.

  for(int i = 0; i < 5; i++) //these are the five cards to be ordered.
  {
    std::cout << "Enter your card";
    std::string input1;
    std::cin >> input1;

    c1 = Card(input1);
    fiveCards.push_back(c1);
  //  d.removeCard(c1);
  }

  indexes = sameIndexCards(fiveCards);
  int index1 = indexes.at(0);
  int index2 = indexes.at(1);

  sameSuitCards1 = sameSuitCards(index1, index2, fiveCards);
  diff1 = diff(sameSuitCards1);
  nextThreeCards1 = nextThreeCards(index1, index2,fiveCards,diff1);

  std::cout << "I will display four of the five cards chosen. Then, guess the fifth hidden card."
            << sameSuitCards1.at(1) << nextThreeCards1.at(0) << nextThreeCards1.at(1) << nextThreeCards1.at(2);

  std::string guess;
  std::cin >> guess;

  Card cGuess = Card(guess);
  if(guessIsRight(cGuess,sameSuitCards1.at(0)) == true)
    std::cout << "YAY YOU GUESSED IT RIGHT";
  else
    std::cout << "WRONG. STEW-PID";

  return 0;
}
