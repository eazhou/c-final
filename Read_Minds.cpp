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
  std::string getSuit();
  std::string getName();
  int getNum();
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
    if(card1.getName() == c1.getName()){

    }

  }

  return d1;


  //auto it = std::find(d1.allCards.begin(), d1.allCards.end(), c1)
  //if(it != d1.allCards.end())
  //  d1.allCards.erase(it);

  //return d1;
}


std::string Card::getSuit(){
  return suit;
}
std::string Card::getName(){
  return name;
}
int Card::getNum(){
  return num;
}

std::vector<int> sameIndexCards(std::vector<Card> fiveCards)
{
  int index1;
  int index2;
  std::vector<int> indexes(2);

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
int difference(int index1, int index2, std::vector<Card> fiveCards){
  //returns the difference between the two numbers needed in threeCards function
  int diff;
  bool firstGreater = true;
  if (fiveCards.at(index1).getNum()>fiveCards.at(index2).getNum()){
    diff = fiveCards.at(index1).getNum()-fiveCards.at(index2).getNum();
  }
  else{
    diff = fiveCards.at(index2).getNum()-fiveCards.at(index1).getNum();
    firstGreater = false;
  }


  if (diff>7){
    if (firstGreater){
      return 13+fiveCards.at(index2).getNum()-fiveCards.at(index1).getNum();
    }
    else{
      return 13+fiveCards.at(index1).getNum()-fiveCards.at(index2).getNum();
    }
  }
  else{
    return diff;
  }
}

int hiddenCard(int index1, int index2, std::vector<Card> fiveCards){
  //returns the index of the hidden Card
  int diff;
  bool firstGreater = true;
  if (fiveCards.at(index1).getNum()>fiveCards.at(index2).getNum()){
    diff = fiveCards.at(index1).getNum()-fiveCards.at(index2).getNum();
  }
  else{
    diff = fiveCards.at(index2).getNum()-fiveCards.at(index1).getNum();
    firstGreater = false;
  }

  if (diff>7){
    if (firstGreater){
      return index1;
    }
    else{
      return index2;
    }
  }
  else{
    if (firstGreater){
      return index2;
    }
    else{
      return index1;
    }
  }
}

int firstCard(int index1, int index2, int indexHidden){
  //returns the index of the first card
  if (indexHidden == index1){
    return index2;
  }
  else{
    return index1;
  }
}

std::vector<Card> nextThreeCards(int index1, int index2, std::vector<Card> fiveCards, int diff ){
  //returns a vector of the three cards in order
  std::vector<Card> threeCards;
  for (int i = 0; i < 5; i++){
    if (i == index1 or i == index2){}
    else{
      threeCards.push_back(fiveCards.at(i));
    }
  }
  int min = 0;
  int max = 0;
  int mid = 0;
  for (int i = 1; i < 3; i++){
    if (threeCards.at(i).getNum() > threeCards.at(max).getNum()){
      max = i;
    }
    if (threeCards.at(i).getNum() < threeCards.at(min).getNum()){
      min = i;
    }
  }
  for (int i = 0; i < 3; i++){
    if (max == i or min == i){

    }
    else{
      mid = i;
    }
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


int main()
{
  Deck d;

  std::vector<Card> fiveCards(5);
  for(int i = 0; i < 5; i++)
  {
    std::cout << "Enter your card";
    std::string c1;
    std::cin >> c1;
    c1.substr(0);
    fiveCards.push_back(c1);
    d.removeCard(c1);
  }






  return 0;
}
