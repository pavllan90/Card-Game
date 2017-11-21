#ifndef CARD_H
#define CARD_H
#include <QString>
#include <iostream>
#include "simplecard.h"

enum Suit
{
    diamonds, hearts, spades, clubs
};

enum Nominal
{
    jack, queen, king, ace, two, three,
    four, five, six, seven, eight, nine, ten
};

class Card : public SimpleCard
{
public:
    Card();
    Card(Nominal _nominal, Suit _suit);
    Card(const Card &a);
    ~Card();
    void setNominal(Nominal _nominal);
    void setSuit(Suit _suit);
    Suit getSuit();
    Nominal getNominal();
    QString cardToString();
    void show();
    virtual int getType();
private:
    QString suitToString();
    QString nominalToString();
    Suit suit;
    Nominal nominal;
};

#endif // CARD_H
