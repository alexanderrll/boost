#include "threadworker.h"

ThreadWorker::ThreadWorker()
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
        auto endpoints = resolver.resolve(std::string("127.0.0.1"), std::string("12000"));
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
