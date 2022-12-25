#include "threadworker.h"

ThreadWorker::ThreadWorker(QString IP, QString PORT) : IP_(IP), PORT_(PORT)
{

}

void ThreadWorker::SendMessage(const char *line)
{
    chat_message msg;
    msg.body_length(std::strlen(line));
    std::memcpy(msg.body(), line, msg.body_length());
    msg.encode_header();
    clnt->write(msg);
}

void ThreadWorker::run()
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
        std::cout << e.what() << std::endl;
    }
}


ThreadWorker::~ThreadWorker()
{
    clnt->close();
    delete clnt;
}
