#ifndef CARD_H
#define CARD_H
#include <QString>
#include <iostream>
#include "simplecard.h"

class card : public SimpleCard
{
public:
    card();
    card(Nominal _nominal, Suit _suit);
    card(const card &a);
    ~card();
    virtual void set_Nominal(Nominal _nominal);
    virtual void set_Suit(Suit _suit);
    virtual int getType();
private:
    Suit suit;
};

#endif // CARD_H
