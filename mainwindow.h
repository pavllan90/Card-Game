#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "card.h"

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
    card coloda [52];
    int col_p, col_c, curr_player;
    card array[52][8], top_card[52];
    int col[8],top_counter, miss_counter;
private slots:
    void giveCards();
    void nextStep();
};

#endif // MAINWINDOW_H
