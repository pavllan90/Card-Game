#ifndef UNOCARD_H
#define UNOCARD_H
#include "simplecard.h"

enum Colors
{
    red, green, blue, yellow
};

class UnoCard : public SimpleCard
{
public:
    UnoCard();
    UnoCard(Nominal _nom, Colors _color);
    UnoCard(const UnoCard &a);
    ~UnoCard();
    void set_Color(Colors color);
    Colors getColor();
    void setNominal(Nominal _nom);
    void show();
    Nominal getNominal();
    QString colorToString();
    QString cardToString();
    virtual int getType();
Colors color;
};

#endif // UNOCARD_H
