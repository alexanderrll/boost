#include "chat_client.h"

#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include "../common/chat_message.h"

using boost::asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;

chat_client::chat_client(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoints) : io_context_(io_context), socket_(io_context)
{
    std::cout << "client -> chat_client::chat_client\n";
    do_connect(endpoints);
}

void chat_client::write(const chat_message& msg)
{
    std::cout << "chat_client::write\n";
    boost::asio::post(io_context_,
                      [this, msg]()
    {
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress)
        {
            do_write();
        }
    });
}

void chat_client::close()
{
    std::cout << "client -> chat_client::close\n";
    boost::asio::post(io_context_, [this]() { socket_.close(); });
}


void chat_client::do_connect(const tcp::resolver::results_type& endpoints)
{
    boost::asio::async_connect(socket_, endpoints,
                               [this](boost::system::error_code ec, tcp::endpoint)
    {
        if (!ec)
        {
            do_read_header();
        }
    });
}

void chat_client::do_read_header()
{
    std::cout << "client -> chat_client::do_read_header\n";
    boost::asio::async_read(socket_,
                            boost::asio::buffer(read_msg_.data(), chat_message::header_length),
                            [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (!ec && read_msg_.decode_header())
        {
            do_read_body();
        }
        else
        {
            socket_.close();
        }
    });
}

void chat_client::do_read_body()
{
    std::cout << "client -> chat_client::do_read_body\n";
    boost::asio::async_read(socket_,
                            boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
                            [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (!ec)
        {
            std::cout.write(read_msg_.body(), read_msg_.body_length()) << std::endl;
            std::cout << "\n";
            do_read_header();
        }
        else
        {
            socket_.close();
        }
    });
}

void chat_client::do_write()
{
    std::cout << "client -> chat_client::do_write\n";
    boost::asio::async_write(socket_,
                             boost::asio::buffer(write_msgs_.front().data(),
                                                 write_msgs_.front().length()),
                             [this](boost::system::error_code ec, std::size_t /*length*/)
    {
        if (!ec)
        {
            write_msgs_.pop_front();
            if (!write_msgs_.empty())
            {
                do_write();
            }
        }
        else
        {
            socket_.close();
        }
    });
}


