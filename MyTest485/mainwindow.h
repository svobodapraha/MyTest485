#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <stdio.h>
#include "osprotocol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Btn_TestWrite_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *RS485Bus;
    void RS485DataReceived();
};

#endif // MAINWINDOW_H
