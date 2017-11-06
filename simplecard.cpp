#include "simplecard.h"

SimpleCard::SimpleCard()
{
    nominal = two;
}

SimpleCard::SimpleCard(Nominal _nom, Suit _suit)
{
    nominal = (_nom>=ace&&_nom<=king) ? _nom : SimpleCard().nominal;
    suit = (_suit>=diamonds && _suit<=yellow) ? _suit : SimpleCard().suit;
}

SimpleCard::SimpleCard(const SimpleCard &a)
{
    nominal = a.nominal;
    suit = a.suit;
}

SimpleCard::~SimpleCard()
{

}

int SimpleCard::getType()
{
    return 0;
}

QString SimpleCard::suit_To_String()
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
    case red:
        return "red";
        break;
    case green:
        return "green";
        break;
    case blue:
        return "blue";
        break;
    case yellow:
        return "yellow";
        break;
    }
}

QString SimpleCard::nominal_To_String()
{
    switch (nominal)
    {
    case ace:
        return "ace";
        break;
    case zero:
        return "zero";
        break;
    case one:
        return "one";
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

Nominal SimpleCard::get_Nominal()
{
    return nominal;
}

Suit SimpleCard::get_Suit()
{
    return suit;
}

QString SimpleCard::card_To_String()
{
    return nominal_To_String()+" of "+suit_To_String();
}

void SimpleCard::show()
{
   cout<<card_To_String().toLatin1().data()<<endl;
}

void SimpleCard::set_Nominal()
{

}

void SimpleCard::set_Suit()
{

}
