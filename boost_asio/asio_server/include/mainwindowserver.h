#ifndef MAINWINDOWSERVER_H
#define MAINWINDOWSERVER_H

#include <QMainWindow>
#include <boost/asio.hpp>
#include "chat_server.h"
#include "threadworkerserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowServer; }
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
    Ui::MainWindowServer *ui;
};
#endif // MAINWINDOWSERVER_H
