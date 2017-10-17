#ifndef STACK_H
#define STACK_H
#include "node.h"

class Stack
{
public:
    Stack();
    Stack(const Stack &copy);
    card* getFirst();
    Node* front();
    void push(card a);
    card pop();
    int size();
    bool isEmpty();
    void show();
private:
    Node *first;
    int stack_size;

};

#endif // STACK_H
