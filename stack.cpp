#include "stack.h"

Stack::Stack()
{
    stack_size = 0;
    first = NULL;
}

Stack::Stack(const Stack &copy)
{
    stack_size = 0;
    first = NULL;
    Node* temp = copy.first;
    int el = copy.stack_size;
    while(el>=0)
    {
        for(int i = 0; i<el; i++) temp = temp->next;
        push(temp->data);
        temp = copy.first;
        el-=1;
    }
}

Node* Stack::front()
{
    return first;
}

void Stack::show()
{
    Node *temp = first;
    while(temp)
    {
        temp->data.show();
        temp = temp->next;
    }
}

card* Stack::getFirst()
{
    return &(first->data);
}

int Stack::size()
{
    return stack_size;
}

bool Stack::isEmpty()
{
    if(first) return false;
    else return true;
}

void Stack::push(card a)
{
    Node *temp = new Node;
    temp->data = a;
    stack_size+=1;
    if(!first) first = temp;
    else temp->next = first, first = temp;
}

card Stack::pop()
{
    if(first)
    {
        Node *temp = first;
        card ret = first->data;
        if(first->next)
        {
            first = first->next;
            delete temp;
        }
        else
        {
            delete first;
            first = NULL;
        }
        stack_size-=1;
        return ret;
    }
}
