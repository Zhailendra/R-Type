#ifndef RTYPE_RFC_HPP
#define RTYPE_RFC_HPP

#include <cstdint>
#include <map>
#include <string>

namespace Network {

    // START OF PACKET
    typedef enum : uint16_t {
        UNDEFINED = 0,
        Ping = 1,
        Pong,
        NewEntity,
        DestroyEntity,
        UpdateEntity,
        GatherAllEntities,
        OK,
    } PacketType;

    static std::map<PacketType, std::string> packetTypeToString = {
            {PacketType::UNDEFINED, "UNDEFINED"},
            {PacketType::Ping, "Ping"},
            {PacketType::Pong, "Pong"},
            {PacketType::NewEntity, "NewEntity"},
            {PacketType::DestroyEntity, "DestroyEntity"},
            {PacketType::UpdateEntity, "UpdateEntity"},
            {PacketType::GatherAllEntities, "GatherAllEntities"},
            {PacketType::OK, "OK"},
    };

    // PACKET NUMBER
    typedef uint32_t PacketNumber;

    // ENTITY ID
    typedef uint32_t EntityId;

    // ENTITY COMPONENTS TYPE
    typedef uint16_t ComponentsType;
};


#define MINIMUM_PACKET_SIZE (sizeof(PacketType) + sizeof(PacketNumber))

#endif //RTYPE_RFC_HPP
