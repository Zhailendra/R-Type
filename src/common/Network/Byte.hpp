/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Byte.hpp
*/

#ifndef Byte_HPP
#define Byte_HPP

#include <vector>
#include <ostream>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <bitset>

#include <cstdint>
#include <string>
#include <cstring>
#include <memory>

#include <SFML/Network.hpp>
#include "RFC.hpp"
#include "ECS/Components/Scale/ScaleComponent.hpp"

        #include "ECS/Components/Enemy/EnemyComponent.hpp"
#include "ECS/Components/Bullet/BulletComponent.hpp"

#include <ECS/Components/Position/PositionComponent.hpp>
#include <ECS/Components/Velocity/Velocity.hpp>
#include <ECS/Components/Renderable/Renderable.hpp>
#include <ECS/Components/Rectable/Rectable.hpp>
#include <ECS/Components/Bullet/BulletComponent.hpp>

namespace Network {
    class Byte {
    public:
        Byte();
        Byte(size_t size);
        Byte(sf::Packet &packet);
        Byte(const std::vector<uint8_t> &bytes);
        Byte(const std::vector<uint8_t> &bytes, size_t size);
        Byte(const uint8_t *byte, size_t size);
        ~Byte() = default;

        Byte(const Byte &other);
        Byte &operator=(const Byte &other);

        void reserve(const size_t &size);
        void resize(const size_t &size);
        void setCursor(const size_t &cursor);
        const size_t &getCursor() const;
        void setSize(const size_t &size);
        void clear();

        const size_t &getSize() const;
        const std::vector<uint8_t> &getBytes() const;

        virtual void writeToByte(const void *thing, const size_t &size);

        template<typename T>
        void writeToByteT(const T &thing, const size_t &size);

        Byte &operator+(const Byte &other) const;
        bool operator==(const Byte &other) const;
        bool operator!=(const Byte &other) const;
        Byte &operator<<(const Byte &other);
        Byte &operator<<(const std::string &str);
        Byte &operator<<(const Network::PacketType &packetType);
        Byte &operator<<(const std::uint32_t &packetNumber);
        Byte &operator<<(const std::uint16_t &EntityType);
        Byte &operator<<(const PositionComponent &positionComponent);
        Byte &operator<<(const Velocity &velocity);
        Byte &operator<<(const Renderable &renderable);
        Byte &operator<<(const float &other);
        Byte &operator<<(const Rectable &rectable);
        Byte &operator<<(const ScaleComponent &scaleComponent);
        Byte &operator<<(const EnemyComponent &enemyComponent);
        Byte &operator<<(const BulletComponent &bulletComponent);

        template<typename T>
        Byte &operator<<(const std::vector<T> &other);
        template<typename... Ts>
        Byte &operator<<(const std::tuple<Ts...> &other);
        template<typename T>
        Byte &operator<<(const std::list<T> &other);
        template<typename T, typename U>
        Byte &operator<<(const std::map<T, U> &other);
        template<typename T, typename U>
        Byte &operator<<(const std::multimap<T, U> &other);
        template<typename T, typename U>
        Byte &operator<<(const std::unordered_map<T, U> &other);
        template<typename T>
        Byte &operator<<(const std::set<T> &other);
        template<typename T, typename U>
        Byte &operator<<(const std::set<T, U> &other);
        template<typename T>
        Byte &operator<<(const std::unordered_set<T> &other);
        template<typename T>
        Byte &operator<<(const std::shared_ptr<T> &other);
        template<typename T>
        Byte &operator<<(const std::unique_ptr<T> &other);
        template<typename T>
        Byte &operator<<(const T &other);

        virtual void readFromByte(void *thing, const size_t &size);

        template<typename T>
        void readFromByteT(const T &thing, const size_t &size);
        Byte &operator>>(Byte &other);
        Byte &operator>>(std::string &str);
        Byte &operator>>(Network::PacketType &packetType);
        Byte &operator>>(std::uint32_t &packetNumber);
        Byte &operator>>(std::uint16_t &EntityType);
        Byte &operator>>(PositionComponent &positionComponent);
        Byte &operator>>(Velocity &velocity);
        Byte &operator>>(Renderable &renderable);
        Byte &operator>>(float &other);
        Byte &operator>>(Rectable &rectable);
        Byte &operator>>(ScaleComponent &scaleComponent);
        Byte &operator>>(EnemyComponent &enemyComponent);
        Byte &operator>>(BulletComponent &bulletComponent);

        template<typename T>
        Byte &operator>>(std::vector<T> &other);
        template<typename... Ts>
        Byte &operator>>(std::tuple<Ts...> &other);
        template<typename T>
        Byte &operator>>(std::list<T> &other);
        template<typename T, typename U>
        Byte &operator>>(std::map<T, U> &other);
        template<typename T, typename U>
        Byte &operator>>(std::multimap<T, U> &other);
        template<typename T, typename U>
        Byte &operator>>(std::unordered_map<T, U> &other);
        template<typename T>
        Byte &operator>>(std::set<T> &other);
        template<typename T, typename U>
        Byte &operator>>(std::set<T, U> &other);
        template<typename T>
        Byte &operator>>(std::unordered_set<T> &other);
        template<typename T>
        Byte &operator>>(std::shared_ptr<T> &other);
        template<typename T>
        Byte &operator>>(std::unique_ptr<T> &other);
        template<typename T>
        Byte &operator>>(T &other);

        friend std::ostream &operator<<(std::ostream &os, const Byte &byte);
    protected:
    private:
        std::vector<uint8_t> _bytes;
        std::unordered_map<void *, size_t> _ptrKeeper;
        std::unordered_map<void *, std::shared_ptr<void>> _ptrKeeperRead;
        size_t _size = 0;
        size_t _cursor = 0;
    };
}

#endif //Byte_HPP
