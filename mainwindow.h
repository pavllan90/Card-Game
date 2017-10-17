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
    int col_p, col_c, curr_player;
    Stack players[10];
    Stack top_card;
    int miss_counter;
    bool gameOver;
private slots:
    void giveCards();
    void nextStep();
    void fastGame();
};

#endif // MAINWINDOW_H
