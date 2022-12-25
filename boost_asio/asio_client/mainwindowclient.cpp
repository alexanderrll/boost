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

    ui->te_Log->setText(QString("Client Start"));
}

void MainWindowClient::slt_initBoostClient()
{
    try
    {
        boost::asio::io_context io_context;

        ip::tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(ui->le_IP->text().toStdString(), ui->le_PORT->text().toStdString());
        chat_client c(io_context, endpoints);

        std::thread t([&io_context](){ io_context.run(); });

        char line[chat_message::max_body_length + 1];
        while (std::cin.getline(line, chat_message::max_body_length + 1))
        {
            chat_message msg;
            msg.body_length(std::strlen(line));
            std::memcpy(msg.body(), line, msg.body_length());
            msg.encode_header();
            c.write(msg);
        }

        ui->te_Log->append(QString("Connected"));

        c.close();
        t.join();
    }
    catch (std::exception& e)
    {
        ui->te_Log->append(QString(e.what()));
    }
}

void MainWindowClient::slt_pbSend()
{
    ui->te_Log->append(QString("Send!"));
}

MainWindowClient::~MainWindowClient()
{
    delete ui;
}

