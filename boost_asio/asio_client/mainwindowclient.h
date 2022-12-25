#ifndef MAINWINDOWCLIENT_H
#define MAINWINDOWCLIENT_H

#include <QMainWindow>
#include <boost/asio.hpp>
#include "chat_client.h"
#include "threadworker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClient; }
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
    ThreadWorker *qt_thr;
    Ui::MainWindowClient *ui;

};
#endif // MAINWINDOWCLIENT_H
