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
    try
    {
        //input\output OS
        boost::asio::io_context io_context;

        std::list<chat_server> servers;

        tcp::endpoint endpoint1(tcp::v4(), std::atoi(ui->le_IP->text().toStdString().c_str()));
        servers.emplace_back(io_context, endpoint1);

        tcp::endpoint endpoint2(tcp::v4(), std::atoi(ui->le_PORT->text().toStdString().c_str()));
        servers.emplace_back(io_context, endpoint2);

        io_context.run();
        ui->te_Log->append(QString("Server is starting!"));
    }
    catch (std::exception& e)
    {
        ui->te_Log->append(QString(e.what()));
    }

}

void MainWindowServer::slt_pbSend()
{
    ui->te_Log->append(QString("Send!"));
}

MainWindowServer::~MainWindowServer()
{
    delete ui;
}

