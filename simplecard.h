#ifndef SIMPLECARD_H
#define SIMPLECARD_H

#include <QString>
#include<iostream>
using namespace std;

enum Nominal
{
   jack, queen, king, ace, two, three, four, five, six, seven, eight, nine, ten,  zero, one
};

class SimpleCard
{
public:
    SimpleCard();
    SimpleCard(Nominal _nom);
    SimpleCard(const SimpleCard& a);
    ~SimpleCard();
    virtual int getType();
    virtual void show();
    QString nominalToString();
    Nominal getNominal();
    virtual QString cardToString();
protected:
    Nominal nominal;

};

#endif // SIMPLECARD_H
