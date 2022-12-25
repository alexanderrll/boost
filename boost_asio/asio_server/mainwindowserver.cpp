#include "mainwindowserver.h"
#include "ui_mainwindowserver.h"

MainWindowServer::MainWindowServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowServer)
{
    ui->setupUi(this);
    ui->te_Log->setDisabled(true);
    QWidget::setWindowTitle(QString("Server"));
    connect(ui->pb_Send, SIGNAL(clicked(bool)), this, SLOT(slt_pbSend()));
    connect(ui->pb_InitServer, SIGNAL(clicked()), this, SLOT(slt_InitServer()));

    ui->le_IP->setText(QString("127.0.0.1"));
    ui->le_PORT->setText(QString("12000"));

    ui->te_Log->setText(QString("Server Start"));
}

void MainWindowServer::slt_InitServer()
{
    IP = ui->le_IP->text();
    PORT = ui->le_PORT->text();
    qt_thr = new ThreadWorkerServer(IP, PORT);
    qt_thr->start();
}

void MainWindowServer::slt_pbSend()
{
    ui->te_Log->append(QString("Send!"));
}

MainWindowServer::~MainWindowServer()
{
    delete qt_thr;
    delete ui;
}

