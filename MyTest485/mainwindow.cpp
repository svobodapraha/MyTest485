#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RS485Bus = new QSerialPort(this);
    RS485Bus->setPortName("/dev/ttyS0");
    RS485Bus->open(QIODevice::ReadWrite);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_TestWrite_clicked()
{
    #define BUFF_SIZE 100
    char buff[BUFF_SIZE];
    snprintf (buff, sizeof(buff), "Btn pressed" );
    RS485Bus->write(buff, strlen(buff));
}
