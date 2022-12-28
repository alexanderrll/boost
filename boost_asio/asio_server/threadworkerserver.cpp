#include "threadworkerserver.h"

ThreadWorkerServer::ThreadWorkerServer(QString IP, QString PORT) : IP_(IP), PORT_(PORT)
{

}

void ThreadWorkerServer::SendMessage(const char *line)
{
    chat_message msg;
    msg.body_length(std::strlen(line));
    std::memcpy(msg.body(), line, msg.body_length());
    msg.encode_header();
    clnt->write(msg);
}

void ThreadWorkerServer::run()
{
    try
    {
        //input\output OS
        boost::asio::io_context io_context;

        std::list<chat_server> servers;

        tcp::endpoint endpoint1(tcp::v4(), std::atoi(IP_.toStdString().c_str()));
        servers.emplace_back(io_context, endpoint1);

        tcp::endpoint endpoint2(tcp::v4(), std::atoi(PORT_.toStdString().c_str()));
        servers.emplace_back(io_context, endpoint2);

        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

ThreadWorkerServer::~ThreadWorkerServer()
{

}
