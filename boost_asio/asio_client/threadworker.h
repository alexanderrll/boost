#ifndef THREADWORKER_H
#define THREADWORKER_H
#include <QThread>
#include <iostream>
#include <boost/asio.hpp>
#include "chat_client.h"
//#include "chat_message.h"

using namespace boost::asio;

class ThreadWorker : public QThread
{
    Q_OBJECT

public:
    ThreadWorker();
    ~ThreadWorker();
    void SendMessage(const char *q_msg);
private:
    io_context io_context_;
    tcp::endpoint  endpoints_;
    chat_client *clnt;
protected:
    void run();
};

#endif // THREADWORKER_H
