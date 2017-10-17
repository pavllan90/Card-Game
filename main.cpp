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
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
