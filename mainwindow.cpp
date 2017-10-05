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
        coloda[i]=new card(Nominal(i%13), Suit(i%4)),
                printf("%s \n", coloda[i]->cardToString().toLatin1().data());
    srand(time(NULL));
    card temp;
    int curr;
    for(int i = 0; i<52; i++)
    {
        curr=rand()%51;
        temp=*coloda[i];
        *coloda[i]=*coloda[curr];
        *coloda[curr] = temp;
    }
    miss_counter=0;
    ui->pushButton_2->setDisabled(true);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(giveCards()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(nextStep()));
}

void MainWindow::giveCards()
{
    col_p = ui->lineEdit->text().toInt();
    if(col_p<=8)
    {
        ui->pushButton_2->setEnabled(true);
        col_c=int(52/col_p);
        qDebug("Col c %d", col_c);
        int c = 0;
        for(int i = 0; i<col_p; i++)
            for(int j = 0; j<col_c; j++)
                array[i][j]= card (*coloda[c]), c+=1;
        for(int i = 0; i<col_p; i++)
        {
            qDebug("\nPlayer # %d\n:  ", i);
            for(int j = 0; j<col_c; j++)
                qDebug(" %s \n", array[i][j].cardToString().toLatin1().data());
        }
        for(int i = 0; i<col_p; i++) col[i]=col_c-1;
        top_counter=0;
        curr_player = 0;
        top_card[top_counter] = new card(array[curr_player][col[curr_player]]);
        col[curr_player]-=1;
        curr_player+=1;
    }
    else
    {
        ui->textEdit->append("Put number between 1 and 8");
        ui->pushButton_2->setDisabled(true);
    }
}

void MainWindow::nextStep()
{
    ui->textEdit->append("-----------\nTop card is: "+top_card[top_counter]->cardToString()+"\n");
    if(array[curr_player][col[curr_player]].getSuit()==top_card[top_counter]->getSuit()|| array[curr_player][col[curr_player]].getNominal()==top_card[top_counter]->getNominal()){
        ui->textEdit->append("Player #: "+QString::number(curr_player)+" -> "+array[curr_player][col[curr_player]].cardToString());
        top_counter+=1;
        top_card[top_counter] = new card;
        *top_card[top_counter]=array[curr_player][col[curr_player]];
        col[curr_player]-=1;
        miss_counter=0;
    }
    else
    {
        ui->textEdit->append("Player #: "+ QString::number(curr_player)+" misses the step\n");
        miss_counter+=1;
    }
    if(miss_counter==col_p)
    {
        delete top_card[top_counter];
        top_card[top_counter] = NULL;
        top_counter-=1;
        if(top_counter<0)
        {
            top_counter+=1;
            top_card[top_counter] = new card;
            *top_card[top_counter]=array[curr_player][col[curr_player]];
            col[curr_player]-=1;
        }
        ui->textEdit->append("Top card removed\nNew top card is: "+top_card[top_counter]->cardToString());
        miss_counter=0;
    }
    if(col[curr_player]<0) ui->textEdit->append("Player #"+QString::number(curr_player)+" is a WINNER!"), ui->pushButton_2->setDisabled(true);
    curr_player+=1;
    if(curr_player>=col_p) curr_player=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
