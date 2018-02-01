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
      name = std::to_string(num) + "_" + suit;
      faceValue = std::to_string(num);
    }
  }

  Card(std::string name) : name(name)
  {
    if(name.substr(0,1) == "10")
    {
      num = 10;
      faceValue = "10";
      suit = name.substr(3);
    }
    else if(name.substr(0) == "J")
    {
      num = 11;
      faceValue = "J";
      suit = name.substr(2);
    }
    else if(name.substr(0) == "Q")
    {
      num = 12;
      faceValue = "Q";
      suit = name.substr(2);
    }
    else if(name.substr(0) == "K")
    {
      num = 13;
      faceValue = "K";
      suit = name.substr(2);
    }
    else if(name.substr(0) == "A")
    {
      num = 1;
      faceValue = "A";
      suit = name.substr(2);
    }
    else
    {
      num = (int) (name.at(0) - '0');
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
  std::string getFaceValue();
  int getNum();
  bool operator==(const Card &c);
  bool operator<(const Card &c);
  bool operator>(const Card &c);
};

std::string Card::getSuit()
{
  return suit;
}

std::string Card::getName()
{
  return name;
}

//DOESNT WORK, RETURNS NAME
// std::string Card::getFaceValue()
// {
//   return faceValue;
// }

//ALSO DOESN'T WORK FOR SOME REASON (see main for print statements)
int Card::getNum()
{
  return num;
}

bool Card::operator==(const Card &c)
{
  if ((this->suit == c.suit) && (this->num == c.num)) {return true;}
  else return false;
}

bool Card::operator<(const Card &c)
{
  if (this->num > c.num) {return false;}
  else if (this->num < c.num) {return true;}
  else if (this->suit == "C") {return true;}
  else if ((this->suit == "D") && (c.suit != "C")) {return true;}
  else if ((this->suit == "H") && (c.suit == "S")) {return true;}
  else {return false;}
}

bool Card::operator>(const Card &c)
{
  if (this->num < c.num) {return false;}
  else if (this->num > c.num) {return true;}
  else if (this->suit == "S") {return true;}
  else if ((this->suit == "H") && (c.suit != "S")) {return true;}
  else if ((this->suit == "D") && (c.suit == "C")) {return true;}
  else {return false;}
}

class Deck
{
  std::vector<Card> allCards;
  std::vector<Card> fiveCards;

public:
  Deck(): allCards(allCards){};

  void initialDeck();
  int size();
  // Deck removeCard(Card c);
  friend std::ostream &operator<<(std::ostream &os, const Deck &d);
};

void Deck::initialDeck()
{
  std::vector<std::string> suits;
  suits.push_back("C");
  suits.push_back("D");
  suits.push_back("H");
  suits.push_back("S");

  for(int num = 1; num <=13; num++)
  {
    for(auto suit : suits)
    {
      allCards.push_back(Card(suit,num));
    }
  }
}

int Deck::size()
{
  return allCards.size();
}

std::ostream &operator<<(std::ostream &os, const Deck &d)
{
  for (int i=0; i<d.allCards.size(); i++)
  {
    os << d.allCards.at(i) << ", ";
  }
  return os;
}

std::vector<Card> determineCards(std::vector<Card> fiveCards)
{
  std::vector<Card> sameSuitCards;
  for (int i=0; i<5; i++) {
    for (int j=i+1; j<5; j++) {
      if ((i != j) && (fiveCards.at(i).getSuit() == fiveCards.at(j).getSuit()) && (sameSuitCards.size()<=2)) {
        sameSuitCards.push_back(fiveCards[i]);
        sameSuitCards.push_back(fiveCards[j]);
      }
    }
  }

  int diff;
  if (sameSuitCards[0].getNum() > sameSuitCards[1].getNum())
    diff = sameSuitCards[0].getNum() - sameSuitCards[1].getNum();
  else
    diff = sameSuitCards[1].getNum() - sameSuitCards[0].getNum();

  Card visibleCard;
  Card hiddenCard;

  int diff_encode;
  if (diff>6) {
    visibleCard = sameSuitCards[0];
    hiddenCard = sameSuitCards[1];
    diff_encode = 13-diff;
  }
  else {
    visibleCard = sameSuitCards[1];
    hiddenCard = sameSuitCards[0];
    diff_encode = diff;
  }

  std::vector<Card> threeCards;
  for (int k=0; k<5; k++) {
    if ((fiveCards[k] == visibleCard) || (fiveCards[k] == hiddenCard)) {}
    else
      threeCards.push_back(fiveCards[k]);
  }

  // for (int a=0; a<threeCards.size(); a++) {
  //   std::cout << "threeCards[a]: " << threeCards[a] << std::endl;
  // }

  int min = 0;
  int max = 0;
  int mid = 0;

//something wrong w/ this part: putting in 5_C, 3_D, A_H, 3_H, 5_H does not give right ordered triple

  for (int m = 0; m < 3; m++)
  {
    if (threeCards.at(m) > threeCards.at(max)) {
      max = m;
    }
  }

  for (int n = 0; n < 3; n++)
  {
    std::cout << "at n: " << threeCards.at(n) << std::endl;
    std::cout << "at min: " << threeCards.at(min) << std::endl;
    if (threeCards.at(n) > threeCards.at(min)) {}
    else if (threeCards.at(n) == threeCards.at(min)) {}
    else {
      min = n;
      std::cout << "n: " << n << std::endl;
      std::cout << "min: " << min << std::endl;
      std::cout << threeCards.at(min) << std::endl;
    }
    std::cout << "bool: " << (threeCards.at(n) > threeCards.at(min)) << std::endl;
  }

  for (int p = 0; p < 3; p++)
  {
    if ((max != p) && (min != p))
      mid = p;
  }

  std::cout << "max: " << max << std::endl;
  std::cout << "max card: " << threeCards.at(max) << std::endl;
  std::cout << "min: " << min << std::endl;
  std::cout << "min card: " << threeCards.at(min) << std::endl;
  std::cout << "mid: " << mid << std::endl;
  std::cout << "mid card: " << threeCards.at(mid) << std::endl;

  std::vector<Card> ordered;
  ordered.push_back(visibleCard);
  if (diff_encode == 1){
    ordered.push_back(threeCards.at(min));
    ordered.push_back(threeCards.at(mid));
    ordered.push_back(threeCards.at(max));
  }
  else if (diff_encode == 2){
    ordered.push_back(threeCards.at(min));
    ordered.push_back(threeCards.at(max));
    ordered.push_back(threeCards.at(mid));
  }
  else if (diff_encode == 3){
    ordered.push_back(threeCards.at(mid));
    ordered.push_back(threeCards.at(min));
    ordered.push_back(threeCards.at(max));
  }
  else if (diff_encode == 4){
    ordered.push_back(threeCards.at(mid));
    ordered.push_back(threeCards.at(max));
    ordered.push_back(threeCards.at(min));
  }
  else if (diff_encode == 5){
    ordered.push_back(threeCards.at(max));
    ordered.push_back(threeCards.at(min));
    ordered.push_back(threeCards.at(mid));
  }
  else{
    ordered.push_back(threeCards.at(max));
    ordered.push_back(threeCards.at(mid));
    ordered.push_back(threeCards.at(min));
  }
  ordered.push_back(hiddenCard);
  return ordered;
}

bool guessIsRight(Card guess, Card hiddenCard)
{
  if(guess.getName() == hiddenCard.getName())
    return true;
  else
    return false;
}

int main()
{
  Deck d;
  Card c1;
  std::vector<Card> fiveCards; //the five cards to be ordered
  std::vector<Card> orderedCards; //visible card, three cards encoding difference, and hidden card

  // COMMENT BACK IN FOR SUBMISSION
  // for(int i = 0; i < 5; i++)
  // {
  //   std::cout << "Enter your card: ";
  //   std::string input1;
  //   std::cin >> input1;
  //
  //   c1 = Card(input1);
  //   fiveCards.push_back(c1);
  // //  d.removeCard(c1);
  // }

  fiveCards.push_back(Card("5_S"));
  fiveCards.push_back(Card("K_D"));
  fiveCards.push_back(Card("10_H"));
  fiveCards.push_back(Card("3_H"));
  fiveCards.push_back(Card("A_H"));

  for (int i=0; i<5; i++) {
    std::cout << "five Cards [i]: " << fiveCards[i].getNum() << std::endl;
  }

  orderedCards = determineCards(fiveCards);

  std::cout << "I will display four of the five cards chosen. Then, guess the fifth hidden card." << std::endl;

  for(int j=0; j<4; j++)
  {
    std::cout << orderedCards.at(j) << ", ";
  }

  std::string guess;
  std::cin >> guess;

  Card cGuess = Card(guess);
  if(guessIsRight(cGuess,orderedCards.at(4)))
    std::cout << "YAY YOU GUESSED IT RIGHT" << std::endl;
  else
    std::cout << "WRONG. STEW-PID!! CORRECT CARD: " << orderedCards.at(4) << std::endl;

  return 0;
}
