/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Byte.cpp
*/

#include "Byte.hpp"

Network::Byte::Byte()
{
}

Network::Byte::Byte(sf::Packet &packet)
{
    packet.getDataSize();
    void *data = const_cast<void *>(packet.getData());
    auto *ptr = static_cast<uint8_t *>(data);
    size_t size = packet.getDataSize();
    _bytes.resize(size);
    memcpy(&_bytes[0], ptr, size);
    _size = size;
}

Network::Byte::Byte(const size_t size)
{
    reserve(size);
}

Network::Byte::Byte(const std::vector<uint8_t> &bytes)
    :
    _bytes(bytes),
    _size(bytes.size())
{
}

Network::Byte::Byte(const std::vector<uint8_t> &bytes, size_t size)
    :
    _bytes(bytes),
    _size(size)
{
}

Network::Byte::Byte(const uint8_t *byte, size_t size)
    :
    _size(size)
{
    resize(size);
    memcpy(&_bytes[0], byte, size);
}

Network::Byte::Byte(const Network::Byte &other)
{
    _bytes = std::vector<uint8_t>(other._bytes);
    _size = other._size;
    _cursor = other._cursor;
}

Network::Byte &Network::Byte::operator=(const Network::Byte &other)
{
    _bytes = std::vector<uint8_t>(other._bytes);
    _size = other._size;
    _cursor = other._cursor;
    return *this;
}

void Network::Byte::reserve(const size_t &size)
{
    _bytes.reserve(size);
}

void Network::Byte::resize(const size_t &size)
{
    _bytes.resize(size);
}

void Network::Byte::setCursor(const size_t &cursor)
{
    _cursor = cursor;
}

const size_t &Network::Byte::getCursor() const
{
    return _cursor;
}

void Network::Byte::setSize(const size_t &size)
{
    _size = size;
}

const size_t &Network::Byte::getSize() const
{
    return _size;
}

const std::vector<uint8_t> &Network::Byte::getBytes() const
{
    return _bytes;
}

void Network::Byte::clear()
{
    _bytes.clear();
    _size = 0;
    _cursor = 0;
}

bool Network::Byte::operator==(const Network::Byte &other) const
{
    return _bytes == other._bytes;
}

bool Network::Byte::operator!=(const Network::Byte &other) const
{
    return _bytes != other._bytes;
}

void Network::Byte::writeToByte(const void *thing, const size_t &size)
{
    resize(_size + size);
    uint8_t *ptr = &_bytes[_size];
    memcpy(ptr, thing, size);
    _size += size;
}

template<typename T>
void Network::Byte::writeToByteT(const T &thing, const size_t &size)
{
    memcpy((T *) thing, thing,
        0); //DO NOT REMOVE: You forgot to overload "operator<<()" on the class specified bellow
    writeToByte(thing, size);
}

void Network::Byte::readFromByte(void *thing, const size_t &size)
{
    uint8_t *ptr = &_bytes[_cursor];
    memcpy(thing, ptr, size);
    _cursor += size;
}

template<typename T>
void Network::Byte::readFromByteT(const T &thing, const size_t &size)
{
    memcpy(thing, thing,
        0); //DO NOT REMOVE: You forgot to overload "operator>>()" on the class specified bellow
    readFromByte(thing, size);
}

Network::Byte &Network::Byte::operator+(const Network::Byte &other) const
{
    size_t new_size = this->_size + other.getSize();
    std::vector<uint8_t> new_bytes(new_size);
    new_bytes.insert(new_bytes.end(), this->_bytes.begin(), this->_bytes.end());
    new_bytes.insert(new_bytes.end(), other.getBytes().begin(),
        other.getBytes().end());
    auto *new_byte_object = new Byte(new_bytes, new_size);
    return *new_byte_object;
}

Network::Byte &Network::Byte::operator<<(const Network::Byte &other)
{
    size_t size = other.getSize();
    *this << size;
    writeToByte(other.getBytes().data(), other.getBytes().size());
    return *this;
}

Network::Byte &Network::Byte::operator<<(const std::string &str)
{
    size_t size = str.size();
    *this << size;
    writeToByte(&str[0], str.size());
    return *this;
}

Network::Byte &Network::Byte::operator<<(const Network::PacketType &packetType)
{
    writeToByte(&packetType, sizeof(packetType));
    return *this;
}

Network::Byte &Network::Byte::operator<<(const std::uint32_t &packetNumber)
{
    writeToByte(&packetNumber, sizeof(packetNumber));
    return *this;
}

Network::Byte &Network::Byte::operator<<(const std::uint16_t &EntityType)
{
    writeToByte(&EntityType, sizeof(EntityType));
    return *this;
}

Network::Byte &Network::Byte::operator<<(
    const PositionComponent &positionComponent
)
{
    *this << positionComponent.x << positionComponent.y << positionComponent.z;
    return *this;
}

Network::Byte &Network::Byte::operator<<(const Velocity &velocity)
{
    *this << velocity.x << velocity.y << velocity.z;
    return *this;
}

Network::Byte &Network::Byte::operator<<(const Renderable &renderable)
{
    *this << renderable._sprite_type;
    return *this;
}

Network::Byte &Network::Byte::operator<<(const float &other)
{
    writeToByte(&other, sizeof(other));
    return *this;
}

Network::Byte &Network::Byte::operator<<(const Rectable &rectable)
{
    *this << rectable._upKeyPressed;
    *this << rectable._downKeyPressed;
    *this << rectable._newFrame;
    *this << rectable._currentPlayerFrame;
    *this << rectable._nbFrames;
    *this << rectable._switchTop;
    *this << rectable._frameNumber;
    *this << rectable._nbFramesHeight;
    *this << rectable._frameHeightMultiplier;
    *this << rectable._frameSizeWidth;
    *this << rectable._frameSizeHeight;
    return *this;
}

Network::Byte &Network::Byte::operator<<(const ScaleComponent &scaleComponent)
{
    *this << scaleComponent._x << scaleComponent._y;
    return *this;
}

Network::Byte &Network::Byte::operator<<(const EnemyComponent &enemyComponent)
{
    *this << enemyComponent._enemyType;
    return *this;
}

Network::Byte &Network::Byte::operator<<(const BulletComponent &bulletComponent)
{
    *this << bulletComponent._typeBullet;
    return *this;
}

Network::Byte &Network::Byte::operator>>(Network::Byte &other)
{
    other.clear();
    size_t size;
    *this >> size;
    setSize(size);
    other.resize(other._size);
    readFromByteT(other._bytes.data(), other._size);
    return other;
}

Network::Byte &Network::Byte::operator>>(std::string &str)
{
    size_t size;
    *this >> size;
    str.resize(size);
    readFromByteT(&str[0], size);
    return *this;
}

Network::Byte &Network::Byte::operator>>(Network::PacketType &packetType)
{
    readFromByte(&packetType, sizeof(packetType));
    return *this;
}

Network::Byte &Network::Byte::operator>>(std::uint32_t &packetNumber)
{
    readFromByte(&packetNumber, sizeof(packetNumber));
    return *this;
}

Network::Byte &Network::Byte::operator>>(std::uint16_t &EntityType)
{
    readFromByte(&EntityType, sizeof(EntityType));
    return *this;
}

Network::Byte &Network::Byte::operator>>(PositionComponent &positionComponent)
{
    *this >> positionComponent.x >> positionComponent.y >> positionComponent.z;
    return *this;
}

Network::Byte &Network::Byte::operator>>(Velocity &velocity)
{
    *this >> velocity.x >> velocity.y >> velocity.z;
    return *this;
}

Network::Byte &Network::Byte::operator>>(Renderable &renderable)
{
    SpriteType spriteType;
    *this >> spriteType;
    renderable = Renderable(spriteType);
    return *this;
}

Network::Byte &Network::Byte::operator>>(float &other)
{
    readFromByte(&other, sizeof(other));
    return *this;
}

Network::Byte &Network::Byte::operator>>(Rectable &rectable)
{
    *this >> rectable._upKeyPressed;
    *this >> rectable._downKeyPressed;
    *this >> rectable._newFrame;
    *this >> rectable._currentPlayerFrame;
    *this >> rectable._nbFrames;
    *this >> rectable._switchTop;
    *this >> rectable._frameNumber;
    *this >> rectable._nbFramesHeight;
    *this >> rectable._frameHeightMultiplier;
    *this >> rectable._frameSizeWidth;
    *this >> rectable._frameSizeHeight;
    return *this;
}

Network::Byte &Network::Byte::operator>>(ScaleComponent &scaleComponent)
{
    *this >> scaleComponent._x >> scaleComponent._y;
    return *this;
}

Network::Byte &Network::Byte::operator>>(EnemyComponent &enemyComponent)
{
    *this >> enemyComponent._enemyType;
    return *this;
}

Network::Byte &Network::Byte::operator>>(BulletComponent &bulletComponent)
{
    *this >> bulletComponent._typeBullet;
    return *this;
}

template<typename T>
Network::Byte &sequence_container_write(Network::Byte &byte, const T &other)
{
    size_t size = other.size();
    byte << size;
    for (auto &it: other) {
        byte << it;
    }
    return byte;
}

template<typename T>
Network::Byte &associative_container_write(Network::Byte &byte, const T &other)
{
    size_t size = other.size();
    byte << size;
    for (auto &it: other) {
        byte << it.first << it.second;
    }
    return byte;
}

template<typename... Ts>
Network::Byte &Network::Byte::operator<<(std::tuple<Ts...> const &other)
{
    std::apply([&](auto &&... args) {(((*this) << args), ...);}, other);
    return *this;
}

template<typename T>
Network::Byte &Network::Byte::operator<<(std::vector<T> const &other)
{
    return sequence_container_write(*this, other);
}

template<typename T>
Network::Byte &Network::Byte::operator<<(std::list<T> const &other)
{
    return sequence_container_write(*this, other);
}

template<typename T, typename U>
Network::Byte &Network::Byte::operator<<(std::map<T, U> const &other)
{
    return associative_container_write(*this, other);
}

template<typename T, typename U>
Network::Byte &Network::Byte::operator<<(std::multimap<T, U> const &other)
{
    return associative_container_write(*this, other);
}

template<typename T, typename U>
Network::Byte &Network::Byte::operator<<(std::unordered_map<T, U> const &other)
{
    return associative_container_write(*this, other);
}

template<typename T>
Network::Byte &Network::Byte::operator<<(std::set<T> const &other)
{
    return sequence_container_write(*this, other);
}

template<typename T, typename U>
Network::Byte &Network::Byte::operator<<(std::set<T, U> const &other)
{
    return sequence_container_write(*this, other);
}

template<typename T>
Network::Byte &Network::Byte::operator<<(std::unordered_set<T> const &other)
{
    return sequence_container_write(*this, other);
}

template<typename T>
Network::Byte &Network::Byte::operator<<(std::shared_ptr<T> const &other)
{
    *this << other.get();
    if (_ptrKeeper.find(static_cast<void *>(other.get())) == _ptrKeeper.end()) {
        *this << *other;
        _ptrKeeper.emplace(static_cast<void *>(other.get()), _ptrKeeper.size());
    }
    return *this;
}

template<typename T>
Network::Byte &Network::Byte::operator<<(std::unique_ptr<T> const &other)
{
    *this << *other;
    return *this;
}

template<typename T>
Network::Byte &Network::Byte::operator<<(const T &other)
{
    writeToByteT(&other, sizeof(other));
    return *this;
}

template<typename T>
Network::Byte &sequence_container_read(Network::Byte &byte, T &other)
{
    size_t size;
    byte >> size;
    other.resize(size);
    for (auto &it: other) {
        byte >> it;
    }
    return byte;
}

template<typename T>
Network::Byte &associative_container_read(Network::Byte &byte, T &other)
{
    size_t size;
    byte >> size;
    for (size_t i = 0; i < size; i++) {
        typename T::key_type key;
        typename T::mapped_type value;
        byte >> key >> value;
        other.emplace(key, value);
    }
    return byte;
}

template<typename... Ts>
Network::Byte &Network::Byte::operator>>(std::tuple<Ts...> &other)
{
    std::apply([&](auto &&... args) {(((*this) >> args), ...);}, other);
    return *this;
}

template<typename T>
Network::Byte &Network::Byte::operator>>(std::vector<T> &other)
{
    return sequence_container_read(*this, other);
}

template<typename T>
Network::Byte &Network::Byte::operator>>(std::list<T> &other)
{
    return sequence_container_read(*this, other);
}

template<typename T, typename U>
Network::Byte &Network::Byte::operator>>(std::map<T, U> &other)
{
    return associative_container_read(*this, other);
}

template<typename T, typename U>
Network::Byte &Network::Byte::operator>>(std::multimap<T, U> &other)
{
    return associative_container_read(*this, other);
}

template<typename T, typename U>
Network::Byte &Network::Byte::operator>>(std::unordered_map<T, U> &other)
{
    return associative_container_read(*this, other);
}

template<typename T>
Network::Byte &Network::Byte::operator>>(std::set<T> &other)
{
    return sequence_container_read(*this, other);
}

template<typename T, typename U>
Network::Byte &Network::Byte::operator>>(std::set<T, U> &other)
{
    return sequence_container_read(*this, other);
}

template<typename T>
Network::Byte &Network::Byte::operator>>(std::unordered_set<T> &other)
{
    return sequence_container_read(*this, other);
}

template<typename T>
Network::Byte &Network::Byte::operator>>(std::shared_ptr<T> &other)
{
    T *ptr;
    *this >> ptr;
    if (_ptrKeeperRead.find(static_cast<void *>(ptr)) == _ptrKeeperRead.end()) {
        std::shared_ptr<T> shared = std::make_shared<T>();
        *this >> *shared;
        _ptrKeeperRead.emplace(static_cast<void *>(ptr), shared);
    }
    other =
        std::static_pointer_cast<T>(_ptrKeeperRead[static_cast<void *>(ptr)]);
    return *this;
}

template<typename T>
Network::Byte &Network::Byte::operator>>(std::unique_ptr<T> &other)
{
    other = std::make_unique<T>();
    *this >> *other;
    return *this;
}

template<typename T>
Network::Byte &Network::Byte::operator>>(T &other)
{
    readFromByteT(&other, sizeof(other));
    return *this;
}

namespace Network {
    std::ostream &operator<<(std::ostream &os, const Network::Byte &byte)
    {
        os << "Byte(";
        for (size_t i = 0; i < byte.getSize(); i++) {
            if (i == byte.getSize() - 1) {
                os << std::bitset<8>(byte.getBytes()[i]);
            } else {
                os << std::bitset<8>(byte.getBytes()[i]) << ", ";
            }
        }
        os << ")";
        return os;
    }
}