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
    connect(ui->pb_ConnectToServer, SIGNAL(clicked(bool)), this, SLOT(slt_initBoostClient()));

    qt_thr = new ThreadWorker();

    ui->le_IP->setText(QString("127.0.0.1"));
    ui->le_PORT->setText(QString("12000"));

    ui->te_Log->setText(QString("Client Start"));
}

void MainWindowClient::slt_initBoostClient()
{
    qt_thr->start();
}

void MainWindowClient::slt_pbSend()
{
    qt_thr->SendMessage(ui->le_Send->text().toStdString().c_str());
    ui->te_Log->append(QString("Send!"));
}

MainWindowClient::~MainWindowClient()
{
    std::cout << "start ~MainWindowClient()" << std::endl;
    delete qt_thr;
    delete ui;
    std::cout << "end ~MainWindowClient()" << std::endl;
}

