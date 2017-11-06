#ifndef UNOCARD_H
#define UNOCARD_H
#include "simplecard.h"

class UnoCard : public SimpleCard
{
public:
    UnoCard();
    UnoCard(Nominal _nom, Suit _suit);
    UnoCard(const UnoCard &a);
    ~UnoCard();
    virtual void set_Suit(Suit _suit);
    virtual void setNominal(Nominal _nom);
    virtual int getType();
};

#endif // UNOCARD_H
