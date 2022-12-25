#include "chat_server.h"

int main(int argc, char* argv[])
{
    try
    {
        std::cout << "host name = " << boost::asio::ip::host_name() << std::endl;

        if (argc < 2)
        {
            std::cerr << "Usage: chat_server <port> [<port> ...]\n";
            return 1;
        }

        //input\output OS
        boost::asio::io_context io_context;
        std::list<chat_server> servers;
        for (int i = 1; i < argc; ++i)
        {
            tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
            servers.emplace_back(io_context, endpoint);
        }

        std::cout << "io_context.run\n";
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
