#ifndef MAINWINDOWCLIENT_H
#define MAINWINDOWCLIENT_H

#include <QMainWindow>
#include <boost/asio.hpp>
#include "chat_client.h"
#include "threadworkerclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindowClient : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowClient(QWidget *parent = nullptr);
    ~MainWindowClient();

private slots:
    void slt_pbSend();
    void slt_initBoostClient();

private:
    QString IP;
    QString PORT;
    ThreadWorkerClient *qt_thr;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOWCLIENT_H
