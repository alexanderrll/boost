#include "chat_message.h"
#include <iostream>

chat_message::chat_message()
    : body_length_(0)
{
}

const char* chat_message::data() const
{
    //std::cout << "Uchat_message::data()\n";
    return data_;
}

char* chat_message::data()
{
    //std::cout << "chat_message::data()\n";
    return data_;
}

std::size_t chat_message::length() const
{
    //std::cout << "chat_message::length()\n";
    return header_length + body_length_;
}

const char* chat_message::body() const
{
    //std::cout << "chat_message::body()\n";
    return data_ + header_length;
}

char* chat_message::body()
{
    //std::cout << "chat_message::body()\n";
    return data_ + header_length;
}

//get message size
std::size_t chat_message::body_length() const
{
    //std::cout << "chat_message::get message size\n";
    return body_length_;
}

void chat_message::body_length(std::size_t new_length)
{
    std::cout << "chat_message::body_length\n";
    body_length_ = new_length;
    if (body_length_ > max_body_length)
        body_length_ = max_body_length;
}

//get message size and decode
bool chat_message::decode_header()
{
    //std::cout << "chat_message::decode_header(set message size and decode)\n";
    char header[header_length + 1] = "";
    std::strncat(header, data_, header_length);
    body_length_ = std::atoi(header);
    if (body_length_ > max_body_length)
    {
        body_length_ = 0;
        return false;
    }
    return true;
}

void chat_message::encode_header()
{
    std::cout << "chat_message::encode_header()\n";
    char header[header_length + 1] = "";
    std::sprintf(header, "%4d", static_cast<int>(body_length_));
    std::memcpy(data_, header, header_length);
}
