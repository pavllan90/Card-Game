#include "card.h"

card::card() : SimpleCard()
{
    nominal = ace;
    suit = spades;
}

card::card(Nominal _nominal, Suit _suit) : SimpleCard(_nominal, _suit)
{
    if(_nominal>=jack&&_nominal<=ten)
    {
        nominal = _nominal;
    }
    else
    {
        nominal = card().nominal;
    }
    if(_suit>=diamonds&&_suit<=clubs)
    {
        suit = _suit;
    }
    else
    {
        suit = card().suit;
    }
}

card::card(const card &a) : SimpleCard(a)
{
    suit = a.suit;
    nominal = a.nominal;
}

card::~card()
{

}

void card::set_Nominal(Nominal _nominal)
{
    nominal = (_nominal>=jack&&_nominal<=ten) ? _nominal : nominal;
}

void card::set_Suit(Suit _suit)
{
    suit = (_suit>=diamonds && _suit<=clubs) ? _suit : suit;
}

int card::getType()
{
    return 1;
}
