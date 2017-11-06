#ifndef SIMPLECARD_H
#define SIMPLECARD_H

#include <QString>
#include<iostream>
using namespace std;

enum Nominal
{
   jack, queen, king, ace, two, three, four, five, six, seven, eight, nine, ten,  zero, one
};

enum Suit
{
    diamonds, hearts, spades, clubs, red, green, blue, yellow
};

class SimpleCard
{
public:
    SimpleCard();
    SimpleCard(Nominal _nom, Suit _suit);
    SimpleCard(const SimpleCard& a);
    ~SimpleCard();
    virtual void set_Suit();
    virtual void set_Nominal();
    virtual int getType();
    void show();
    QString nominal_To_String();
    Nominal get_Nominal();
    QString suit_To_String();
    QString card_To_String();
    Suit get_Suit();
protected:
    Nominal nominal;
    Suit suit;
};

#endif // SIMPLECARD_H
