#include "Packet.hpp"

Network::Packet::Packet() :
    packetType(PacketType::UNDEFINED), packetNumber(0), byte(Byte()), ip(sf::IpAddress::None), port(0)
{
}

Network::Packet::Packet(sf::Packet &packet, const sf::IpAddress &ip, const unsigned short &port)
    : packetType(PacketType::UNDEFINED), packetNumber(0), byte(Byte()), ip(ip), port(port)
{
    byte = Byte(packet);
    byte >> packetType;
    byte >> packetNumber;
}
