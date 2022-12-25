#include "threadworkerclient.h"

ThreadWorkerClient::ThreadWorkerClient(QString IP, QString PORT) : IP_(IP), PORT_(PORT)
{

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
        boost::asio::io_context io_context;

        ip::tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(IP_.toStdString(), PORT_.toStdString());
        clnt = new chat_client(io_context, endpoints);

        std::thread t([&io_context](){ io_context.run(); });

        std::cout << "ThreadWorker::run -> io_context.run()" << std::endl;

        t.join();
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
