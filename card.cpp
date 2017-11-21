#include "card.h"

Card::Card() : SimpleCard()
{
    nominal = ace;
    suit = spades;
}

Card::Card(Nominal _nominal, Suit _suit)
{
    if(_nominal>=jack&&_nominal<=ten)
    {
        nominal = _nominal;
    }
    else
    {
        nominal = Card().nominal;
    }
    if(_suit>=diamonds&&_suit<=clubs)
    {
        suit = _suit;
    }
    else
    {
        suit = Card().suit;
    }
}

QString Card::nominalToString()
{
    switch (nominal)
    {
    case ace:
        return "ace";
        break;
    case two:
        return "two";
        break;
    case three:
        return "three";
        break;
    case four:
        return "four";
        break;
    case five:
        return "five";
        break;
    case six:
        return "six";
        break;
    case seven:
        return "seven";
        break;
    case eight:
        return "eight";
        break;
    case nine:
        return "nine";
        break;
    case ten:
        return "ten";
        break;
    case jack:
        return "jack";
        break;
    case queen:
        return "queen";
        break;
    case king:
        return "king";
        break;
    }
}


Nominal Card::getNominal()
{
    return nominal;
}

Card::Card(const Card &a) : SimpleCard(a)
{
    suit = a.suit;
    nominal = a.nominal;
}

Card::~Card()
{

}

void Card::setNominal(Nominal _nominal)
{
    nominal = (_nominal>=jack&&_nominal<=ten) ? _nominal : nominal;
}

void Card::setSuit(Suit _suit)
{
    suit = (_suit>=diamonds && _suit<=clubs) ? _suit : suit;
}

QString Card::suitToString()
{
    switch (suit)
    {
    case spades:
        return "spades";
        break;
    case clubs:
        return "clubs";
        break;
    case diamonds:
        return "diamonds";
        break;
    case hearts:
        return "hearts";
        break;
    }
}

Suit Card::getSuit()
{
    return suit;
}

QString Card::cardToString()
{
    return nominalToString() + " of " + suitToString();
}

int Card::getType()
{
    return 1;
}

void Card::show()
{
    std::cout<<cardToString().toLatin1().data()<<std::endl;
}


