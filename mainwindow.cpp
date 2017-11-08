#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(giveCards()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(nextStep()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(fastGame()));
    QObject::connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(restart()));
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(showStack()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(size()));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(isEmpty()));
    QObject::connect(ui->pushButton_7, SIGNAL(clicked()), this,SLOT(save()));
    QObject::connect(ui->pushButton_8, SIGNAL(clicked()), this,SLOT(load()));
    restart();
}

void MainWindow::restart()
{
    ui->label_2->setVisible(false);
    while(!coloda.isEmpty()) coloda.pop();
    for(int i = 0; i<playersCount; i++)
        while(!players[i].isEmpty()) players[i].pop();
    while(!topCard.isEmpty()) topCard.pop();
    gameOver = false;
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem ("Player"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem ("Action"));
    ui->tableWidget->setColumnWidth(1,250);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width()-250-ui->tableWidget->verticalHeader()->width());
    ui->tableWidget->setVisible(false);
    ui->radioButton->setChecked(true);
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    stepCounter = 0;
    ui->label->setVisible(true);
    ui->pushButton->setVisible(true);
    ui->lineEdit->setVisible(true);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_2->setVisible(false);

}

void MainWindow::fastGame()
{
    while(!gameOver)
    {
        nextStep();
    }
}

void MainWindow::save()
{
    players[ui->spinBox->value()].saveToFile(ui->lineEdit_3->text());
}

void MainWindow::load()
{
    players[ui->spinBox->value()].loadFromFile(ui->lineEdit_3->text());
}

void MainWindow::giveCards()
{
    bool f;
    playersCount = ui->lineEdit->text().toInt(&f);
    if(ui->radioButton->isChecked())
    {
        cardsCount=int(52/playersCount);
        for(int i = 0; i<52; i++)
            coloda.push(new Card(Nominal(i%13), Suit(i%4)));
    }
    else if(ui->radioButton_2->isChecked())
    {
        cardsCount=int(76/playersCount);
        for(int i = 0; i<4; i++) coloda.push(new UnoCard(Nominal(13), Colors(i%4)));
        for(int i = 0; i<76; i++)
        {
            if(Nominal(int(4+i%10))==zero) i++;
            coloda.push(new UnoCard(Nominal(4+i%10), Colors(i%4)));
        }
    }
    srand(time(NULL));
    coloda.show();
    coloda.mix();
    missCounter=0;
    if(f&&playersCount<=9&&playersCount>0)
    {
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        for(int i = 0; i<playersCount; i++)
        {
            for(; players[i].size()<cardsCount; ) players[i].push(coloda.pop());
            std::cout<<"Player "<<i+1<<"  "<<players[i].size()<<std::endl;
            players[i].show();
        }
          currPlayer = 0;
          topCard.push(players[0].pop());
          currPlayer = 1;
          ui->tableWidget->setVisible(true);
          ui->label->setVisible(false);
          ui->pushButton->setVisible(false);
          ui->lineEdit->setVisible(false);
          ui->pushButton_3->setVisible(true);
          ui->pushButton_2->setVisible(true);
          ui->label_2->setVisible(true);
          ui->radioButton->setEnabled(false);
          ui->radioButton_2->setEnabled(false);
          ui->label_2->setText("Top card: "+topCard.get_First()->cardToString()+"\n");
          ui->tableWidget->setColumnWidth(0, ui->tableWidget->width()-250-ui->tableWidget->verticalHeader()->width());
    }
    else
    {
        ui->pushButton_2->setDisabled(true);
    }
}

void MainWindow::size()
{
    ui->lineEdit_2->setText("Size is "+ QString::number(players[ui->spinBox->value()].size()));
}

void MainWindow::isEmpty()
{
    if(players[ui->spinBox->value()].isEmpty()) ui->lineEdit_2->setText("Empty");
    else ui->lineEdit_2->setText("Not empty");
}

void MainWindow::showStack()
{
    Stack::Node *temp = players[ui->spinBox->value()].first;
    ui->tableWidget_2->setRowCount( players[ui->spinBox->value()].size());

    ui->tableWidget_2->setColumnCount(1);
    ui->tableWidget_2->setColumnWidth(0, ui->tableWidget_2->width());
    ui->tableWidget_2->setHorizontalHeaderItem(0, new QTableWidgetItem ("Player "+QString::number(ui->spinBox->value())));
    int i = 0;
    while(temp)
    {
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(temp->data->cardToString()));
        temp = temp->next;
        i+=1;
    }

}

void MainWindow::nextStep()
{
    stepCounter+=1;
    ui->tableWidget->setRowCount(stepCounter);
    if(players[currPlayer].isEmpty())
        ui->label_2->setText("Player #"+QString::number(currPlayer)+" is a WINNER!"), ui->pushButton_2->setDisabled(true), gameOver = true;
    else
    {
        if(topCard.isEmpty())
        {
            topCard.push(players[currPlayer].pop());
        }

        ui->tableWidget->setItem(stepCounter-1, 0, new QTableWidgetItem("Player #: "+QString::number(currPlayer)));
        if(topCard.get_First()->getType()==1)
        {
            Card* a = dynamic_cast<Card*>(players[currPlayer].get_First());
            Card *b = dynamic_cast<Card*>(topCard.get_First());
                if(a->getSuit()==b->getSuit()||a->getNominal()==b->getNominal())
                {
                    ui->tableWidget->setItem(stepCounter-1, 1, new QTableWidgetItem(a->cardToString()));
                    topCard.push(players[currPlayer].pop());
                    missCounter = 0;
                }
                else
                {
                    missCounter+=1;
                    ui->tableWidget->setItem(stepCounter-1, 1, new QTableWidgetItem("Miss step"));
                }
        }
        else
        {
            UnoCard* a = dynamic_cast<UnoCard*>(players[currPlayer].get_First());
            UnoCard *b = dynamic_cast<UnoCard*>(topCard.get_First());
                if(a->getColor()==b->getColor()||a->getNominal()==b->getNominal())
                {
                    ui->tableWidget->setItem(stepCounter-1, 1, new QTableWidgetItem(a->cardToString()));
                    topCard.push(players[currPlayer].pop());
                    missCounter = 0;
                }
                else
                {
                    missCounter+=1;
                    ui->tableWidget->setItem(stepCounter-1, 1, new QTableWidgetItem("Miss step"));
                }
        }
        if(missCounter==playersCount)
        {
            ui->tableWidget->setItem(stepCounter-1, 1, new QTableWidgetItem("Removes top card"));
            topCard.pop();
            if(topCard.isEmpty()) topCard.push(players[currPlayer].pop());
            missCounter = 0;
        }
    }
    if(players[currPlayer].isEmpty())
        ui->label_2->setText("Player #"+QString::number(currPlayer)+" is a WINNER!"), ui->pushButton_2->setVisible(false), ui->pushButton_3->setVisible(false), /*ui->label_2->setVisible(false),*/ gameOver = true,     ui->pushButton_9->setVisible(true);
    else ui->label_2->setText("Top card: "+topCard.get_First()->cardToString()+"\n");
    if(currPlayer<playersCount-1)currPlayer+=1;
    else currPlayer = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}


