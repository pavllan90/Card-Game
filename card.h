#ifndef CARD_H
#define CARD_H
#include <QString>
#include <iostream>
#include "simplecard.h"

enum Suit
{
    diamonds, hearts, spades, clubs
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
    QString suitToString();
    QString cardToString();
    void show();
    virtual int getType();
private:
    Suit suit;
};

#endif // CARD_H
