#include "chat_room.h"

chat_room::chat_room()
{

}

void chat_room::join(chat_participant_ptr participant)
{
    std::cout << "server -> chat_room::client connect\n";
    participants_.insert(participant);
    for (auto msg: recent_msgs_)
        participant->deliver(msg);
}

void chat_room::leave(chat_participant_ptr participant)
{
    std::cout << "server -> chat_room::client disconnect\n";
    participants_.erase(participant);
}

void chat_room::deliver(const chat_message& msg)
{
    std::cout << "server -> chat_room::deliver\n";
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs)
        recent_msgs_.pop_front();

    for (auto participant: participants_)
        participant->deliver(msg);
}
