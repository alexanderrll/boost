#ifndef MAINWINDOWSERVER_H
#define MAINWINDOWSERVER_H

#include <QMainWindow>
#include <boost/asio.hpp>
#include "chat_server.h"
#include "threadworkerserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindowServer : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowServer(QWidget *parent = nullptr);
    ~MainWindowServer();

private slots:
    void slt_pbSend();
    void slt_InitServer();

private:
    QString IP;
    QString PORT;
    ThreadWorkerServer *qt_thr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOWSERVER_H
