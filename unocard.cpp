#include "unocard.h"
#include <iostream>

UnoCard::UnoCard() : SimpleCard()
{
    color = blue;
    nominal = u_two;
}

UnoCard::UnoCard(UnoNominal _nom, Colors _color)
{
    nominal = (_nom>=u_zero && _nom<=u_four_colors) ? _nom : UnoCard().nominal;
    color = (_color>=red && _color<=no_color) ? _color : UnoCard().color;
}

UnoCard::UnoCard(const UnoCard &a)
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


UnoNominal UnoCard::getNominal()
{
    return nominal;
}

void UnoCard::setColor(Colors _color)
{
    color = (_color>=red&&_color<=yellow) ? _color : color;
}

QString UnoCard::nominalToString()
{
    switch (nominal)
    {
    case u_zero:
        return "zero";
        break;
    case u_one:
        return "one";
        break;
    case u_two:
        return "two";
        break;
    case u_three:
        return "three";
        break;
    case u_four:
        return "four";
        break;
    case u_five:
        return "five";
        break;
    case u_six:
        return "six";
        break;
    case u_seven:
        return "seven";
        break;
    case u_eight:
        return "eight";
        break;
    case u_nine:
        return "nine";
        break;
    case u_four_colors:
        return "four colors";
        break;
    case u_stop:
        return "stop";
        break;
    case u_arrows:
        return "arrows";
        break;
    case u_two_cards:
        return "two cards";
        break;
    case u_four_cards:
        return "four cards";
        break;
    }
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
    case no_color:
        return "No color";
        break;
    }
}

void UnoCard::setNominal(UnoNominal _nom)
{
    nominal = (_nom>=u_zero && _nom<=u_four_colors) ? _nom : nominal;
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
