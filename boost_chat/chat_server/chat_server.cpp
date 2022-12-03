#include "chat_server.h"

chat_server::chat_server(boost::asio::io_context& io_context,
                         const tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint)
{
    std::cerr << "chat_session::chat_server construct\n";
    do_accept();
}


void chat_server::do_accept()
{
    std::cerr << "chat_session::do_accept\n";
    acceptor_.async_accept(
                [this](boost::system::error_code ec, tcp::socket socket)
    {
        if (!ec)
        {
            std::make_shared<chat_session>(std::move(socket), room_)->start();
        }

        do_accept();
    });
}
