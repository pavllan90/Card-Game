#ifndef UNOCARD_H
#define UNOCARD_H
#include "simplecard.h"

enum Colors
{
    red, green, blue, yellow, no_color
};

enum UnoNominal
{
    u_zero, u_one, u_two, u_three, u_four, u_five, u_six, u_seven, u_eight, u_nine,
     u_stop, u_arrows, u_two_cards, u_four_colors, u_four_cards
};

class UnoCard : public SimpleCard
{
public:
    UnoCard();
    UnoCard(UnoNominal _nom, Colors _color);
    UnoCard(const UnoCard &a);
    ~UnoCard();
    void setColor(Colors color);
    Colors getColor();
    UnoNominal getNominal();
    void setNominal(UnoNominal _nom);
    void show();
    QString cardToString();
    virtual int getType();
private:
    QString colorToString();
    QString nominalToString();
    Colors color;
    UnoNominal nominal;
};

#endif // UNOCARD_H
