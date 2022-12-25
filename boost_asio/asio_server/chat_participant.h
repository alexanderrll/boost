#ifndef CHAT_PARTICIPANT_H
#define CHAT_PARTICIPANT_H

class chat_participant
{
public:
    virtual ~chat_participant() {}
    virtual void deliver(const chat_message& msg) = 0;
};

typedef std::shared_ptr<chat_participant> chat_participant_ptr;

#endif // CHAT_PARTICIPANT_H
