#ifndef RTYPE_ANETWORK_HPP
#define RTYPE_ANETWORK_HPP

#include "INetwork.hpp"
#include <ECS/EntityManager.hpp>

#include <chrono>

struct Client {
    sf::IpAddress ip;
    unsigned short port;
    std::chrono::time_point<std::chrono::system_clock> lastReceive;
};

namespace Network {
    template<typename... T>
    class ANetwork : public INetwork<T...> {
    public:
        using handlers_t = typename INetwork<T...>::handlers_t;

        explicit ANetwork(unsigned short port) : _socket() {
            if (_socket.bind(port) != sf::Socket::Done)
                throw Error("Cannot bind socket");
            selector.add(_socket);
            _clients = std::vector<Client>();
        }
        ~ANetwork() {
            _socket.unbind();
        }

        void use(PacketType type, handlers_t handler) final {
            _handlers[type] = std::move(handler);
        }

        void send(const sf::IpAddress &ip, unsigned short port, const Byte &byte) final {
            sf::Packet sfpacket;
            sfpacket.append(byte.getBytes().data(), byte.getBytes().size());
            _socket.send(sfpacket, ip, port);
        }

        void response(Packet &packet, const Byte &byte) final {
            this->send(packet.ip, packet.port, byte);
        }

        void broadcast(const Packet &packet) final {
            for (auto &client: this->_clients) {
                if (client.ip == packet.ip && client.port == packet.port)
                    continue;
                this->send(client.ip, client.port, packet.byte);
            }
        }

        bool run() final {
            bool received = false;
            if (selector.wait(sf::milliseconds(1))) {
                if (selector.isReady(_socket)) {
                    sf::Packet sfpacket;
                    sf::IpAddress ip;
                    unsigned short port;
                    sf::Socket::Status status = _socket.receive(sfpacket, ip, port);
                    for (auto &client: this->_clients) {
                        if (client.ip == ip && client.port == port) {
                            client.lastReceive = std::chrono::system_clock::now();
                            break;
                        }
                    }
                    this->_clients.emplace_back(Client{ip, port, std::chrono::system_clock::now()});
                    this->receiveCheck(sfpacket, ip, port, status);
                    received= true;
                }
            }
            return received;
        }

        std::vector<Client> _clients;
    protected:
        sf::UdpSocket _socket;
        std::map<PacketType, handlers_t> _handlers;

        sf::SocketSelector selector;

    };

    template class ANetwork<EntityManager>;
    template class ANetwork<EntityManager &>;
    template class ANetwork<std::shared_ptr<std::vector<std::shared_ptr<Entity>>> &>;
}

#endif //RTYPE_ANETWORK_HPP
