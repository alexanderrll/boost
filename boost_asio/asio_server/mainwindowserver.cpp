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

    ui->te_Log->setText(QString("Server Start"));
}

void MainWindowServer::slt_pbSend()
{
    ui->te_Log->append(QString("Send!"));
}

MainWindowServer::~MainWindowServer()
{
    delete ui;
}

