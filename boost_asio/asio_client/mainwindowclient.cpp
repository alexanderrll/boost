#include "mainwindowclient.h"
#include "ui_mainwindowclient.h"

using namespace boost::asio;

MainWindowClient::MainWindowClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowClient)
{
    ui->setupUi(this);
    ui->te_Log->setDisabled(true);
    QWidget::setWindowTitle(QString("Client"));
    connect(ui->pb_send, SIGNAL(clicked(bool)), this, SLOT(slt_pbSend()));

    ui->te_Log->setText(QString("Client Start"));
}

void MainWindowClient::slt_pbSend()
{
    ui->te_Log->append(QString("Send!"));
}

MainWindowClient::~MainWindowClient()
{
    delete ui;
}

