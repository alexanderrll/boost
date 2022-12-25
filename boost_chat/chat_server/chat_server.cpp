#include "chat_server.h"

chat_server::chat_server(boost::asio::io_context& io_context,
                         const tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint)
{
    std::cerr << "server -> chat_server::chat_server construct\n";
    do_accept();
}


void chat_server::do_accept()
{
    std::cerr << "client -> chat_server::do_accept\n";
    acceptor_.async_accept(
                [this](boost::system::error_code ec, tcp::socket socket)
    {
        std::cerr << "server -> chat_server::async_accept lambda work\n";
        if (!ec)
        {
            std::make_shared<chat_session>(std::move(socket), room_)->start();
        }

        do_accept();
    });
}
