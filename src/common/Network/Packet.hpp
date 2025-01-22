#ifndef RTYPE_PACKET_HPP
#define RTYPE_PACKET_HPP

#include "Byte.hpp"
#include "RFC.hpp"

namespace Network {
    class Packet {
    public:
        Packet();
        Packet(sf::Packet &packet, const sf::IpAddress &ip, const unsigned short &port);
        ~Packet() = default;

        PacketType packetType;
        PacketNumber packetNumber;
        Byte byte;
        sf::IpAddress ip;
        unsigned short port{};
    };
}


#endif //RTYPE_PACKET_HPP
