#include "threadworkerserver.h"

using namespace boost::asio;

ThreadWorkerServer::ThreadWorkerServer(QString IP, QString PORT) : IP_(IP), PORT_(PORT)
{

    tcp::endpoint endpoint1(tcp::v4(), std::atoi(IP_.toStdString().c_str()));
    servers.emplace_back(io_context, endpoint1);

    tcp::endpoint endpoint2(tcp::v4(), std::atoi(PORT_.toStdString().c_str()));
    servers.emplace_back(io_context, endpoint2);
}

void ThreadWorkerServer::run()
{
    try
    {
        //input\output OS
        std::cout << "ThreadWorkerServer::start run -> io_context.run()" << std::endl;
        io_context.run();
        std::cout << "ThreadWorkerServer::start run -> io_context.run()" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

ThreadWorkerServer::~ThreadWorkerServer()
{

}
