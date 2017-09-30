#include "card.h"

card::card()
{
    nominal = 0;
    mast = 1;
}

card::card(int nom, int mas)
{
    if(nom>=0&&nom<=14&&mast>=0&&mast<=4)
    {
        nominal = nom;
        mast = mas;
    }
    else
    {
        nominal = card().nominal;
        mast = card().mast;
    }
}

card::card(const card &a)
{
    mast = a.mast;
    nominal = a.nominal;
}

card::~card()
{

}
