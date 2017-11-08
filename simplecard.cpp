#include "simplecard.h"

SimpleCard::SimpleCard()
{
    nominal = two;
}

SimpleCard::SimpleCard(Nominal _nom)
{
    nominal = (_nom>=ace&&_nom<=king) ? _nom : SimpleCard().nominal;
}

SimpleCard::SimpleCard(const SimpleCard &a)
{
    nominal = a.nominal;
}

SimpleCard::~SimpleCard()
{

}

int SimpleCard::getType()
{
    return 0;
}

QString SimpleCard::nominalToString()
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

Nominal SimpleCard::getNominal()
{
    return nominal;
}

QString SimpleCard::cardToString()
{

}

void SimpleCard::show()
{

}
