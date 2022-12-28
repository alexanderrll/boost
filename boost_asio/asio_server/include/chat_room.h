#ifndef CHAT_ROOM_H
#define CHAT_ROOM_H

#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <boost/asio.hpp>
#include "chat_message.h"
#include "chat_participant.h"

using boost::asio::ip::tcp;
typedef std::shared_ptr<chat_participant> chat_participant_ptr;
typedef std::deque<chat_message> chat_message_queue;

class chat_room
{
public:

    chat_room();

    void join(chat_participant_ptr participant);

    void leave(chat_participant_ptr participant);

    void deliver(const chat_message& msg);

private:
    std::set<chat_participant_ptr> participants_;
    enum { max_recent_msgs = 100 };
    chat_message_queue recent_msgs_;
};

#endif // CHAT_ROOM_H
