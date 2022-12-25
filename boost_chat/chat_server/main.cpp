#include "chat_server.h"

int main(int argc, char* argv[])
{
    try
    {
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
            std::cerr << "argc = " << argc << "\n";
            std::cerr << "argv[1] = " << argv[1] << "\n";
            std::cerr << "argv[2] = " << argv[2] << "\n";
            std::cerr << "io_context.run\n";
            tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
            servers.emplace_back(io_context, endpoint);
        }

        std::cerr << "io_context.run\n";
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
