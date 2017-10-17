#include "card.h"

card::card()
{
    nominal = ace;
    suit = spades;
}

card::card(Nominal _nominal, Suit _suit)
{
    if(_nominal>=ace&&_nominal<=king)
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

card::card(const card &a)
{
    suit = a.suit;
    nominal = a.nominal;
}

card::~card()
{

}

void card::show()
{
    std::cout<<cardToString().toLatin1().data()<<std::endl;
}

QString card::suitToString()
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

QString card::nominalToString()
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

QString card::cardToString()
{
    return nominalToString()+" of "+suitToString();
}

Nominal card::getNominal()
{
    return nominal;
}

Suit card::getSuit()
{
    return suit;
}

void card::setNominal(Nominal _nominal)
{
    nominal = (_nominal>=ace&&_nominal<=king) ? _nominal : nominal;
}

void card::setSuit(Suit _suit)
{
    suit = (_suit>=diamonds && _suit<=clubs) ? _suit : suit;
}
