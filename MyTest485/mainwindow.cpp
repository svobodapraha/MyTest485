#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RS485Bus = new QSerialPort(this);
    RS485Bus->setPortName("/dev/ttyS0");
    RS485Bus->setBaudRate(QSerialPort::Baud115200);
    RS485Bus->setDataBits(QSerialPort::Data8);
    RS485Bus->setParity(QSerialPort::NoParity);
    RS485Bus->setStopBits(QSerialPort::OneStop);
    RS485Bus->setFlowControl(QSerialPort::NoFlowControl);
    RS485Bus->open(QIODevice::ReadWrite);
    qDebug()<<RS485Bus->errorString();

}

MainWindow::~MainWindow()
{
    delete ui;
    RS485Bus->close();
}

void MainWindow::on_Btn_TestWrite_clicked()
{
    #define BUFF_SIZE 100
    char buff[BUFF_SIZE];
    snprintf (buff, sizeof(buff), "Btn pressed" );
    RS485Bus->write(buff, strlen(buff));
}
