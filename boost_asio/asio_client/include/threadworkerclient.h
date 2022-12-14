#ifndef THREADWORKERCLIENT_H
#define THREADWORKERCLIENT_H
#include <QThread>
#include <iostream>
#include <boost/asio.hpp>
#include "chat_client.h"

//using namespace boost::asio;

class ThreadWorkerClient : public QThread
{
    Q_OBJECT

public:
    ThreadWorkerClient(QString IP, QString PORT);
    ~ThreadWorkerClient();
    void SendMessage(const char *q_msg);
private:
    QString IP_;
    QString PORT_;
    boost::asio::io_context io_context;
    //io_context io_context;
    chat_client *clnt;
    //io_context io_context;

protected:
    void run();
};

#endif // THREADWORKERCLIENT_H
