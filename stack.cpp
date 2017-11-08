#include "stack.h"
#include <QFile>
#include <QDataStream>
#include <time.h>
#include <stdlib.h>

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
    while(el>0)
    {
        for(int i = 0; i < el-1; i++) temp = temp->next;
        push(temp->data);
        temp = copy.first;
        el-=1;
    }
}

void Stack::mix()
{
    SimpleCard *temp;
    for(int i = 0; i<stack_size; i++)
    {
        Stack::Node* a, *b;
        a = b = first;
        int curr = rand()%(stack_size-1);
        for(int j = 0; j<i; j++) a = a->next;
        for(int k = 0; k<curr; k++) b = b->next;
        temp=(b->data);
        (b->data)=(a->data);
        (a->data) = temp;
    }
}

void Stack::show()
{
    Node *temp = first;
    while(temp)
    {
        temp->data->show();
        temp = temp->next;
    }
}

void Stack::saveToFile(QString name)
{
    QFile file;
    file.setFileName(name);
    file.open(QIODevice::WriteOnly);
    QDataStream stream(&file);
    for(Node* temp = first; temp; temp=temp->next)
    {
        stream<<QString::number(temp->data->getType());
        if(temp->data->getType()==0)
            stream<<QString::number(int(dynamic_cast<Card*>(temp->data)->getSuit()))<<QString::number(int(dynamic_cast<Card*>(temp->data)->getNominal()));
        else
            stream<<QString::number(int(dynamic_cast<UnoCard*>(temp->data)->getColor()))<<QString::number(int(dynamic_cast<UnoCard*>(temp->data)->getNominal()));

    }
    file.close();
}

void Stack::loadFromFile(QString name)
{
    QFile file;
    file.setFileName(name);
    file.open(QIODevice::ReadOnly);
    QDataStream stream(&file);
    while(!file.atEnd())
    {
        QString _suit ;//= file.readLine();
        QString _nominal ;//= file.readLine(); //= file.readLine();
        QString _type;
        stream<<_type;
        stream>>_suit>>_nominal;
        if(_type.toInt()==0)
        {
            Card* a =  new Card(Nominal(_nominal.toInt()),Suit(_suit.toInt()));
            push(a);
        }
        else
        {
            UnoCard* a = new UnoCard(Nominal(_nominal.toInt()),Colors(_suit.toInt()));
            push (a);
        }
    }
    file.close();
}

SimpleCard *Stack::get_First()
{
    return (first->data);
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

void Stack::push(SimpleCard *a)
{
    Node *temp = new Node;
    temp->data = a;
    stack_size+=1;
    if(!first) first = temp;
    else temp->next = first, first = temp;
}

SimpleCard *Stack::pop()
{
    if(first)
    {
        Node *temp = first;
        SimpleCard* ret = first->data;
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
