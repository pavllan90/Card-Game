#ifndef NODE_H
#define NODE_H
#include "card.h"

class Node
{
public:
    Node();
    Node *next;
    card data;
};

#endif // NODE_H
