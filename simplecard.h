#ifndef SIMPLECARD_H
#define SIMPLECARD_H

#include <QString>
#include<iostream>
using namespace std;

class SimpleCard
{
public:
    SimpleCard();
    ~SimpleCard();
    virtual int getType() = 0;
    virtual void show() = 0;
    virtual QString cardToString() = 0;
};

#endif // SIMPLECARD_H
