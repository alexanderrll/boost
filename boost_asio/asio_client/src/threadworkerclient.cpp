#include "threadworkerclient.h"

using namespace boost::asio;

ThreadWorkerClient::ThreadWorkerClient(QString IP, QString PORT) : IP_(IP), PORT_(PORT)
{
    ip::tcp::resolver resolver(io_context);
    auto  endpoints = resolver.resolve(IP_.toStdString(), PORT_.toStdString());
    clnt = new chat_client(io_context, endpoints);
}

void ThreadWorkerClient::SendMessage(const char *line)
{
    chat_message msg;
    msg.body_length(std::strlen(line));
    std::memcpy(msg.body(), line, msg.body_length());
    msg.encode_header();
    clnt->write(msg);
}

void ThreadWorkerClient::run()
{
    try
    {
        std::cout << "ThreadWorkerClient::start run -> io_context.run()" << std::endl;
        io_context.run();
        std::cout << "ThreadWorkerClient::end run -> io_context.run()" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


ThreadWorkerClient::~ThreadWorkerClient()
{
    clnt->close();
    delete clnt;
}
