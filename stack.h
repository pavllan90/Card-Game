#ifndef STACK_H
#define STACK_H
#include "node.h"
#include <iostream>
#include <unocard.h>
class Stack
{
public:
    struct Node
    {
        Node(){next=NULL;}
        Node *next;
        SimpleCard *data;
    };
    Stack();
    Stack(const Stack &copy);
    SimpleCard* get_First();
    void push(SimpleCard* a);
    SimpleCard* pop();
    int size();
    bool isEmpty();
    void show();
    void saveToFile(QString name);
    void loadFromFile(QString name);
    void mix();
    Node *first;
private:
    int stack_size;

};

#endif // STACK_H
