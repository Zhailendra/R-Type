#ifndef RTYPE_INETWORK_HPP
#define RTYPE_INETWORK_HPP

#include "RFC.hpp"
#include "Packet.hpp"
#include <functional>
#include <ECS/Entity.hpp>

namespace Network {
    template<typename... T>
    class INetwork;
}

namespace Network {
    class Error : public std::exception {
    public:
        explicit Error(const std::string &message) : _message(message) {};
        ~Error() override = default;

        const char *what() const noexcept override {
            return _message.c_str();
        }
    private:
        std::string _message;
    };

    template<typename... T>
    class INetwork {
    public:
        using handlers_t = std::function<void(INetwork<T...> &, Network::Packet &, T... )>;

        virtual ~INetwork() = default;
        virtual void use(PacketType type, handlers_t handler) = 0;

        virtual bool run() = 0;

        virtual void send(const sf::IpAddress &ip, unsigned short port, const Byte &byte) = 0;

        virtual void response(Packet &packet, const Byte &byte) = 0;
        virtual void broadcast(const Packet &byte) = 0;

        virtual void receiveCheck(sf::Packet &sfpacket, const sf::IpAddress &ip, unsigned short port, const sf::Socket::Status &status) = 0;

    };
}

#endif //RTYPE_INETWORK_HPP
