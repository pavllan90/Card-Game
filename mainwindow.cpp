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
    QObject::connect(ui->pushButton_7, SIGNAL(clicked()), this,SLOT(save_c()));
    QObject::connect(ui->pushButton_8, SIGNAL(clicked()), this,SLOT(load_c()));
    restart();
}

void MainWindow::restart()
{
    ui->label_2->setVisible(false);
    while(!coloda.is_Empty()) coloda.pop();
    for(int i = 0; i<col_p; i++)
        while(!players[i].is_Empty()) players[i].pop();
    while(!top_card.is_Empty()) top_card.pop();
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
    ui->radioButton_3->setEnabled(true);
    step_counter = 0;
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

void MainWindow::save_c()
{
    players[ui->spinBox->value()].save_to_file(ui->lineEdit_3->text());
}

void MainWindow::load_c()
{
    players[ui->spinBox->value()].load_from_file(ui->lineEdit_3->text());
}

void MainWindow::giveCards()
{
    bool f;
    col_p = ui->lineEdit->text().toInt(&f);
    if(ui->radioButton->isChecked())
    {
        col_c=int(52/col_p);
        for(int i = 0; i<52; i++)
            coloda.push(new card(Nominal(i%13), Suit(i%4)));
    }
    else if(ui->radioButton_2->isChecked())
    {
        col_c=int(76/col_p);
        for(int i = 0; i<76; i++)
            coloda.push(new UnoCard(Nominal(4+i%10), Suit(4+i%4)));//, coloda.get_First()->show();
    }
    else
    {
        col_c=int(128/col_p);
        for(int i = 0; i<52;i++)
            coloda.push(new card(Nominal(i%13), Suit(i%4)));
        for(int i = 0; i<76; i++)
            coloda.push(new UnoCard(Nominal(4+i%10), Suit(4+i%4)));//, coloda.get_First()->show();
    }
    srand(time(NULL));
    coloda.show();
    coloda.mix();
    miss_counter=0;
    if(f&&col_p<=9&&col_p>0)
    {
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        for(int i = 0; i<col_p; i++)
        {
            for(; players[i].size()<col_c; ) players[i].push(coloda.pop());
            std::cout<<"Player "<<i+1<<"  "<<players[i].size()<<std::endl;
            players[i].show();
        }
          curr_player = 0;
          top_card.push(players[0].pop());
          curr_player = 1;
          ui->tableWidget->setVisible(true);
          ui->label->setVisible(false);
          ui->pushButton->setVisible(false);
          ui->lineEdit->setVisible(false);
          ui->pushButton_3->setVisible(true);
          ui->pushButton_2->setVisible(true);
          ui->label_2->setVisible(true);
          ui->radioButton->setEnabled(false);
          ui->radioButton_2->setEnabled(false);
          ui->radioButton_3->setEnabled(false);
          ui->label_2->setText("Top card: "+top_card.get_First()->card_To_String()+"\n");
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
    if(players[ui->spinBox->value()].is_Empty()) ui->lineEdit_2->setText("Empty");
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
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(temp->data->card_To_String()));
        temp = temp->next;
        i+=1;
    }

}

void MainWindow::nextStep()
{
    step_counter+=1;
    ui->tableWidget->setRowCount(step_counter);
    if(players[curr_player].is_Empty())
        ui->label_2->setText("Player #"+QString::number(curr_player)+" is a WINNER!"), ui->pushButton_2->setDisabled(true), gameOver = true;
    else
    {
        if(top_card.is_Empty())
        {
            top_card.push(players[curr_player].pop());
        }

        ui->tableWidget->setItem(step_counter-1, 0, new QTableWidgetItem("Player #: "+QString::number(curr_player)));
        if(players[curr_player].get_First()->get_Suit()==top_card.get_First()->get_Suit()||players[curr_player].get_First()->get_Nominal()==top_card.get_First()->get_Nominal())
        {   
            ui->tableWidget->setItem(step_counter-1, 1, new QTableWidgetItem(players[curr_player].get_First()->card_To_String()));
            top_card.push(players[curr_player].pop());
            miss_counter = 0;
        }
        else
        {
            miss_counter+=1;
            ui->tableWidget->setItem(step_counter-1, 1, new QTableWidgetItem("Miss step"));
        }
        if(miss_counter==col_p)
        {
            ui->tableWidget->setItem(step_counter-1, 1, new QTableWidgetItem("Removes top card"));
            top_card.pop();
            if(top_card.is_Empty()) top_card.push(players[curr_player].pop());
            miss_counter = 0;
        }
    }
    if(players[curr_player].is_Empty())
        ui->label_2->setText("Player #"+QString::number(curr_player)+" is a WINNER!"), ui->pushButton_2->setVisible(false), ui->pushButton_3->setVisible(false), /*ui->label_2->setVisible(false),*/ gameOver = true,     ui->pushButton_9->setVisible(true);
    else ui->label_2->setText("Top card: "+top_card.get_First()->card_To_String()+"\n");
    if(curr_player<col_p-1)curr_player+=1;
    else curr_player = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}
