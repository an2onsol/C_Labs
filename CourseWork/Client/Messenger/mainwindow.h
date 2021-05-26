#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QMainWindow>
#include <QTcpSocket>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_setNickButton_clicked();
    void on_findRoomButton_clicked();
    void on_connectButton_clicked();
    void on_updateButton_clicked();
    void on_exitButton_clicked();
    void on_sendButton_clicked();
    void enterPressed();
    void onSokReadyRead();
private:
    void Connection();
    Ui::MainWindow *ui;
    quint16 _blockSize;
    QTcpSocket *socket;
    QString nick;
    int roomS;
};
#endif // MAINWINDOW_H
