#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bool boResult = false;
    int  iResult  = -1;
    RS485Bus = new QSerialPort(this);
    RS485Bus->setPortName("/dev/ttyS0");
    RS485Bus->setBaudRate(QSerialPort::Baud115200);
    RS485Bus->setDataBits(QSerialPort::Data8);
    RS485Bus->setParity(QSerialPort::NoParity);
    RS485Bus->setStopBits(QSerialPort::OneStop);
    RS485Bus->setFlowControl(QSerialPort::NoFlowControl);
    boResult = RS485Bus->open(QIODevice::ReadWrite);
    if (!boResult)
    {
      ui->plainTextEdit_DataReceive->clear();
      ui->plainTextEdit_DataReceive->appendPlainText(RS485Bus->errorString());
    }
    qDebug()<<RS485Bus->errorString();

    connect(RS485Bus, &QSerialPort::readyRead, this, &MainWindow::RS485DataReceived);

    //init protocol
    iResult = fnInit();

}

MainWindow::~MainWindow()
{
    int  iResult  = -1;
    RS485Bus->close();
    iResult = fnDeInt();
    delete ui;
}

void MainWindow::on_Btn_TestWrite_clicked()
{
    #define BUFF_SIZE 100
    char buff[BUFF_SIZE];
    snprintf (buff, sizeof(buff), "Btn pressed" );
    RS485Bus->write(buff, strlen(buff));
}

void MainWindow::RS485DataReceived()
{
   QByteArray data = RS485Bus->readAll();
   ui->plainTextEdit_DataReceive->appendPlainText(data);
}
