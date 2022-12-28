#ifndef THREADWORKERSERVER_H
#define THREADWORKERSERVER_H

#include <QThread>
#include <iostream>
#include <boost/asio.hpp>
#include "chat_server.h"

class ThreadWorkerServer : public QThread
{
    Q_OBJECT

public:
    ThreadWorkerServer(QString IP, QString PORT);
    ~ThreadWorkerServer();

private:
    QString IP_;
    QString PORT_;
    boost::asio::io_context io_context;
    tcp::endpoint endpoints;
    std::list<chat_server> servers;
    chat_server *serv;

protected:
    void run();
};

#endif // THREADWORKERSERVER_H
