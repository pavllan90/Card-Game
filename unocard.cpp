#include "unocard.h"
#include <iostream>

UnoCard::UnoCard() : SimpleCard()
{
    color = blue;
    nominal = two;
}

UnoCard::UnoCard(Nominal _nom, Colors _color) : SimpleCard(_nom)
{
    nominal = (_nom>=two && _nom<=one) ? _nom : UnoCard().nominal;
    color = (_color>=red && _color<=yellow) ? _color : UnoCard().color;
}

UnoCard::UnoCard(const UnoCard &a) : SimpleCard(a)
{
    nominal = a.nominal;
    color = a.color;
}

UnoCard::~UnoCard()
{

}

Colors UnoCard::getColor()
{
    return color;
}

void UnoCard::set_Color(Colors _color)
{
    color = (_color>=red&&_color<=yellow) ? _color : color;
}

QString UnoCard::colorToString()
{
    switch (color)
    {
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

void UnoCard::setNominal(Nominal _nom)
{
    nominal = (_nom>=two&&_nom<=one) ? _nom : nominal;
}

int UnoCard::getType()
{
    return 2;
}

QString UnoCard::cardToString()
{
    return nominalToString()+" of "+colorToString();
}

void UnoCard::show()
{
    cout<<cardToString().toLatin1().data()<<endl;
}
