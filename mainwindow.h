#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "card.h"
#include "stack.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Stack coloda;
    int playersCount, cardsCount, currPlayer;
    Stack players[10];
    Stack topCard;
    int missCounter, stepCounter;
    bool gameOver;
private slots:
    void giveCards();
    void nextStep();
    void fastGame();
    void save();
    void load();
    void restart();
    void showStack();
    void size();
    void isEmpty();

};

#endif // MAINWINDOW_H
