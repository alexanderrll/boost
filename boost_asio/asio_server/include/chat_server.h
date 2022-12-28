#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H

#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <boost/asio.hpp>
#include "chat_session.h"

using boost::asio::ip::tcp;

class chat_server
{
public:
    chat_server(boost::asio::io_context& io_context, const tcp::endpoint& endpoint);

private:
    void do_accept();

    tcp::acceptor acceptor_;
    chat_room room_;
};
#endif // CHAT_SERVER_H
