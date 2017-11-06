#include "unocard.h"
#include <iostream>

UnoCard::UnoCard() : SimpleCard()
{
    suit = blue;
    nominal = two;
}

UnoCard::UnoCard(Nominal _nom, Suit _suit) : SimpleCard(_nom, _suit)
{
    nominal = (_nom>=two && _nom<=one) ? _nom : UnoCard().nominal;
    suit = (_suit>=red && _suit<=yellow) ? _suit : UnoCard().suit;
}

UnoCard::UnoCard(const UnoCard &a) : SimpleCard(a)
{
    nominal = a.nominal;
    suit = a.suit;
}

UnoCard::~UnoCard()
{

}

void UnoCard::set_Suit(Suit _suit)
{
    suit = (_suit>=red&&_suit<=yellow) ? _suit : suit;
}

void UnoCard::setNominal(Nominal _nom)
{
    nominal = (_nom>=two&&_nom<=one) ? _nom : nominal;
}

int UnoCard::getType()
{
    return 2;
}

