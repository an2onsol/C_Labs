#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this); //создание сокета
    socket->connectToHost("127.0.0.1", 8888); //подключение к серверу
    connect(socket, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(ui->IBox, SIGNAL(returnPressed()), SLOT(enterPressed()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_connectButton_clicked(){
    ui->OBox->clear();
    socket->connectToHost("127.0.0.1", 8888);
    socket->write(nick.toUtf8());
}

void MainWindow::on_updateButton_clicked(){
    ui->roomView->clear();
    QString command = "r";
    socket->write(command.toUtf8());
}

void MainWindow::on_setNickButton_clicked(){
    if (ui->nick->text().isEmpty()){
        QMessageBox::information(this, "Error", "This name is invalid.");
    }
    else{
        QString name = "n " + ui->nick->text();
        socket->write(name.toUtf8());
        nick = name;
    }
}

void MainWindow::on_sendButton_clicked(){
    if(!(nick.isEmpty()) && roomS == 1){
        if (!(ui->IBox->text().isEmpty())){
            QString message = "m " + ui->IBox->text();
            socket->write(message.toUtf8());
            ui->OBox->append("You: " + ui->IBox->text());
            ui->IBox->clear();
        }
    }
    else{
        QMessageBox::information(this, "Error", "Please, enter your name or join a room.");
    }
}

void MainWindow::on_findRoomButton_clicked(){
    if(!(nick.isEmpty())){
        if (ui->roomName->text().isEmpty()){
            QMessageBox::information(this, "Error", "This room name is invalid.");
        }
        else{
            QString name = "j " + ui->roomName->text();
            socket->write(name.toUtf8());
            roomS = 1;
            ui->OBox->clear();
        }
    }
    else{
        QMessageBox::information(this, "Error", "Please, enter your name.");
    }
}

void MainWindow::on_exitButton_clicked(){
    QString command = "q";
    socket->write(command.toUtf8());
    roomS = 0;
    ui->OBox->clear();
}

void MainWindow::enterPressed(){
    if(!(nick.isEmpty()) && roomS == 1){
        QString message = "m " + ui->IBox->text();
        socket->write(message.toUtf8());
        ui->OBox->append("You: " + ui->IBox->text());
        ui->IBox->clear();
    }
    else{
        QMessageBox::information(this, "Error", "Please, enter your name or join a room.");
    }
}

void MainWindow::onSokReadyRead(){
    QByteArray Data = socket->readAll();
    QDataStream dstream (Data);
    QString str;
    char command;
    dstream >> command;
    str = QString::fromUtf8(Data);
    if(command == 'r'){
        QStringList list = str.split(' ');
        for(int i = 1; i < list.length(); i++){
            ui->roomView->addItem(list[i]);
        }
    }
    else{
        ui->OBox->append(str);
    }
}
