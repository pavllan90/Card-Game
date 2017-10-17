#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i<52; i++)
        coloda.push(card(Nominal(i%13), Suit(i%4))),
    srand(time(NULL));
    card temp;
    int curr;
    for(int i = 0; i<52; i++)
    {
        Node* a, *b;
        a = b = coloda.front();
        curr=rand()%51;
        for(int j = 0; j<i; j++) a = a->next;
        for(int k = 0; k<curr; k++) b = b->next;
        temp=b->data;
        b->data=a->data;
        a->data = temp;
    }
    qDebug("Size is %d", coloda.size());
    coloda.show();
    miss_counter=0;
    gameOver = false;
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(giveCards()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(nextStep()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(fastGame()));
}

void MainWindow::fastGame()
{
    while(!gameOver)
    {
        nextStep();
    }
}

void MainWindow::giveCards()
{
    bool f;
    col_p = ui->lineEdit->text().toInt(&f);
    if(f&&col_p<=8)
    {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        col_c=int(52/col_p);
        for(int i = 0; i<col_p; i++)
        {
            for(; players[i].size()<col_c; ) players[i].push(coloda.pop());
            std::cout<<"Player "<<i+1<<std::endl;
            players[i].show();
        }
//        qDebug("Col c %d", col_c);
//        int c = 0;
//        for(int i = 0; i<col_p; i++)
//            for(int j = 0; j<col_c; j++)
//                array[i][j]= card (*coloda[c]), c+=1;
//        for(int i = 0; i<col_p; i++)
//        {
//            qDebug("\nPlayer # %d\n:  ", i);
//            for(int j = 0; j<col_c; j++)
//                qDebug(" %s \n", array[i][j].cardToString().toLatin1().data());
//        }
//        for(int i = 0; i<col_p; i++) col[i]=col_c-1;
//        top_counter=0;
          curr_player = 0;
          top_card.push(players[0].pop());
          curr_player = 1;
//        col[curr_player]-=1;
//        curr_player+=1;
    }
    else
    {
        ui->textEdit->append("Put number between 1 and 8");
        ui->pushButton_2->setDisabled(true);
    }
}

void MainWindow::nextStep()
{
    if(top_card.isEmpty())
    {
        top_card.push(players[curr_player].pop());
    }
    ui->textEdit->append("-----------\nTop card is: "+top_card.getFirst()->cardToString()+"\n");
    if(players[curr_player].getFirst()->getSuit()==top_card.getFirst()->getSuit()||players[curr_player].getFirst()->getNominal()==top_card.getFirst()->getNominal())
    {
      ui->textEdit->append("Player #: "+QString::number(curr_player)+" -> "+players[curr_player].getFirst()->cardToString());
      top_card.push(players[curr_player].pop());
      miss_counter = 0;
    }
    else
    {
      miss_counter+=1;
      ui->textEdit->append("Player #: "+ QString::number(curr_player)+" misses the step\n");
    }
    if(miss_counter==col_p)
    {
      top_card.pop();
      miss_counter = 0;
    }
    if(players[curr_player].isEmpty())
      ui->textEdit->append("Player #"+QString::number(curr_player)+" is a WINNER!"), ui->pushButton_2->setDisabled(true), gameOver = true;
    if(curr_player<col_p-1)curr_player+=1;
    else curr_player = 0;

//    if(array[curr_player][col[curr_player]].getSuit()==top_card[top_counter]->getSuit()|| array[curr_player][col[curr_player]].getNominal()==top_card[top_counter]->getNominal()){
//        ui->textEdit->append("Player #: "+QString::number(curr_player)+" -> "+array[curr_player][col[curr_player]].cardToString());
//        top_counter+=1;
//        top_card[top_counter] = new card;
//        *top_card[top_counter]=array[curr_player][col[curr_player]];
//        col[curr_player]-=1;
//        miss_counter=0;
//    }
//    else
//    {
//        ui->textEdit->append("Player #: "+ QString::number(curr_player)+" misses the step\n");
//        miss_counter+=1;
//    }
//    if(miss_counter==col_p)
//    {
//        delete top_card[top_counter];
//        top_card[top_counter] = NULL;
//        top_counter-=1;
//        if(top_counter<0)
//        {
//            top_counter+=1;
//            top_card[top_counter] = new card;
//            *top_card[top_counter]=array[curr_player][col[curr_player]];
//            col[curr_player]-=1;
//        }
//        ui->textEdit->append("Top card removed\nNew top card is: "+top_card[top_counter]->cardToString());
//        miss_counter=0;
//    }
//    if(col[curr_player]<0) ui->textEdit->append("Player #"+QString::number(curr_player)+" is a WINNER!"), ui->pushButton_2->setDisabled(true);
//    curr_player+=1;
//    if(curr_player>=col_p) curr_player=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
