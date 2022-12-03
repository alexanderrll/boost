#ifndef MAINWINDOWCLIENT_H
#define MAINWINDOWCLIENT_H

#include <QMainWindow>
#include <boost/asio.hpp>

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

private:
    Ui::MainWindowClient *ui;

};
#endif // MAINWINDOWCLIENT_H
