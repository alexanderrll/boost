#ifndef THREADWORKERSERVER_H
#define THREADWORKERSERVER_H

#include <QThread>
#include <iostream>
#include <boost/asio.hpp>
#include "chat_server.h"

using namespace boost::asio;

class ThreadWorkerServer : public QThread
{
    Q_OBJECT

public:
    ThreadWorkerServer(QString IP, QString PORT);
    ~ThreadWorkerServer();

private:
    QString IP_;
    QString PORT_;
    io_context io_context_;
    tcp::endpoint endpoints_;
    chat_server *serv;

protected:
    void run();
};

#endif // THREADWORKERSERVER_H
