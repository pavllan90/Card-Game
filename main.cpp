#include <QtGui/QApplication>
#include "mainwindow.h"
#include <cassert>

int main(int argc, char *argv[])
{

    Stack stack;
    assert(stack.size()==0&& stack.isEmpty()==true);
    stack.push(card());
    stack.push(card(Nominal(10), Suit(2)));
    assert(stack.size()==2&&stack.isEmpty()==false);
    assert(stack.getFirst()->cardToString()=="jack of spades");
    assert(stack.pop().cardToString()=="jack of spades"&&stack.getFirst()->cardToString()=="ace of spades");
    stack.show();
    Stack copy_check (stack);
    assert(stack.size()==copy_check.size());
    for(Node* b1 = stack.front(), *b2 = copy_check.front();b1&&b2; b1 = b1->next, b2 = b2->next )
        assert(b1->data.cardToString()==b2->data.cardToString());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
