#ifndef RTYPE_CLIENT_HPP
#define RTYPE_CLIENT_HPP

#include "ANetwork.hpp"

namespace Network {
    template <typename... T>
    class Client : public ANetwork<T...> {
    public:
        explicit Client(const unsigned short &port, std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities) :
            ANetwork<T...>(port),
            _entities(std::move(entities))
        {
            this->_socket.setBlocking(false);
        }
        ~Client() override = default;

        void receiveCheck(sf::Packet &sfpacket, const sf::IpAddress &ip, unsigned short port, const sf::Socket::Status &status) final 
        {
            if (status != sf::Socket::Done) return;
            if (sfpacket.getDataSize() * 8 < MINIMUM_PACKET_SIZE) return;
            Packet packet(sfpacket, ip, port);
            if (this->_handlers.find(packet.packetType) == this->_handlers.end()) return;
            this->_handlers[packet.packetType](*this, packet, _entities);
        }


        void checkConnection(sf::IpAddress &ip, unsigned short &port)
        {
            Network::Byte byte;
            this->_packetNumber++;
            byte << PacketType::Ping;
            byte << this->_packetNumber;
            time_t start = time(nullptr);
            this->send(ip, port, byte);
            while (!this->_isConnected && time(nullptr) - start < 1) {
                if (this->selector.wait(sf::milliseconds(1))) {
                    if (this->selector.isReady(this->_socket)) {
                        sf::Packet sfpacket;
                        sf::IpAddress ip;
                        unsigned short port;
                        sf::Socket::Status status = this->_socket.receive(sfpacket, ip, port);
                        if (status != sf::Socket::Done) return;
                        if (sfpacket.getDataSize() * 8 < MINIMUM_PACKET_SIZE) return;
                        Packet packet(sfpacket, ip, port);
                        if (packet.packetType == PacketType::Pong) {
                            std::cout << "Connected to server" << std::endl;
                            this->_isConnected = true;
                            return;
                        }
                    }
                }
            }
            throw Network::Error("Server not found");
        }

        bool _isConnected = false;
        PacketNumber _packetNumber = 0;
        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> _entities;

        std::map<Network::EntityId, PositionComponent> _lastPosition;
    };

    template class Client<std::shared_ptr<std::vector<std::shared_ptr<Entity>>> &>;
}


#endif //RTYPE_CLIENT_HPP
