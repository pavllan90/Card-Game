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
        coloda[i].nominal=i%13+1, coloda[i].mast=i%4+1,
                printf("%d %d \n", coloda[i].mast, coloda[i].nominal);
    srand(time(NULL));
    card temp;
    int curr;
    for(int i = 0; i<52; i++)
    {
        curr=rand()%51;
        temp=coloda[i];
        coloda[i]=coloda[curr];
        coloda[curr] = temp;
    }
    miss_counter=0;
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(giveCards()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(nextStep()));
}

void MainWindow::giveCards()
{
    col_p = ui->lineEdit->text().toInt();
    col_c=int(52/col_p);
    int c = 0;
    for(int i = 0; i<col_p; i++)
        for(int j = 0; j<col_c; j++)
            array[i][j]=coloda[c], c+=1;
    for(int i = 0; i<col_p; i++)
    {
        printf("\nPlayer # %d:  ", i+1);
        for(int j = 0; j<col_c; j++)
            printf(" %d %d ", array[i][j].mast, array[i][j].nominal);
    }
    for(int i = 0; i<col_p; i++) col[i]=col_c;
    top_counter=0;
    top_card[top_counter] = array[0][0];
    col[0]-=1;
    curr_player=1;
}

void MainWindow::nextStep()
{
    ui->textEdit->append("-----------\nTop card is: "+QString::number(top_card[top_counter].mast)+" "+QString::number(top_card[top_counter].nominal)+"\n");
    if(array[curr_player][col[curr_player]].mast==top_card[top_counter].mast || array[curr_player][col[curr_player]].nominal==top_card[top_counter].nominal){
        ui->textEdit->append("Player #: "+QString::number(curr_player)+" -> "+QString::number(array[curr_player][col[curr_player]].mast)+" "+QString::number(array[curr_player][col[curr_player]].nominal));
        top_counter+=1;
        top_card[top_counter]=array[curr_player][col[curr_player]];

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
        top_counter-=1;
        if(top_counter<0)
        {
            top_counter+=1;
            top_card[top_counter]=array[curr_player][col[curr_player]];
            col[curr_player]-=1;
        }
        ui->textEdit->append("Top card removed\nNew top card is: "+QString::number(top_card[top_counter].mast)+" "+QString::number(top_card[top_counter].nominal)+"\n");
        miss_counter=0;
    }
    if(col[curr_player]<0) ui->textEdit->append("Player #"+QString::number(curr_player)+" is a WINNER!"), ui->pushButton_2->setDisabled(true);
    curr_player+=1;
    if(curr_player==col_p) curr_player=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}
