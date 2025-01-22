#ifndef RTYPE_SERVER_HPP
#define RTYPE_SERVER_HPP

#include "ANetwork.hpp"
#include <ECS/EntityManager.hpp>

namespace Network {
    template <typename... T>
    class Server : public ANetwork<T...> {
    public:
        explicit Server(const unsigned short &port, EntityManager &entityManager) : ANetwork<T...>(port) {
            _entityManager = entityManager;
            std::cout << "Server started on port " << port << std::endl;
        }

        static void log(const sf::Socket::Status &status) {
            switch (status) {
                case sf::Socket::Partial:
                    log("Partial packet received");
                    break;
                case sf::Socket::Error:
                    log("Error receiving packet");
                    break;
                case sf::Socket::Disconnected:
                    log("Disconnected");
                    break;
                default:
                    break;
            }
        }


        static void log(Packet &packet) {
            log("Ip: " + packet.ip.toString() + ":" + std::to_string(packet.port) + ", PacketType: " +
                Network::packetTypeToString[packet.packetType] + ", PackerNumber: " + std::to_string(packet.packetNumber));
        }
        static void log(const std::string &message) {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            std::string hour = std::to_string(ltm->tm_hour);
            std::string min = std::to_string(ltm->tm_min);
            std::string sec = std::to_string(ltm->tm_sec);
            if (hour.size() == 1) hour = "0" + hour;
            if (min.size() == 1) min = "0" + min;
            if (sec.size() == 1) sec = "0" + sec;

            std::cout << "[" << hour << ":" << min << ":" << sec << "] " << message << std::endl;
        }


        void receiveCheck(sf::Packet &sfpacket, const sf::IpAddress &ip, unsigned short port,
                                        const sf::Socket::Status &status) final {
            if (status != sf::Socket::Done) {
                log(status);
                return;
            }
            if (sfpacket.getDataSize() * 8 < MINIMUM_PACKET_SIZE) {
                log("Packet too small");
                return;
            }
            Packet packet(sfpacket, ip, port);
            if (packet.ip == sf::IpAddress::getLocalAddress() && packet.port == this->_socket.getLocalPort()) {
                log("Packet from local address");
                return;
            }
            if (this->_handlers.find(packet.packetType) == this->_handlers.end()) {
                if (packetTypeToString.find(packet.packetType) != packetTypeToString.end())
                    log("No handler for PacketType : " + packetTypeToString[packet.packetType]);
                else
                    log("No handler for PacketType : " + std::to_string(packet.packetType));
                return;
            }
            log(packet);
            this->_handlers[packet.packetType](*this, packet, _entityManager);
        }

    private:
        EntityManager _entityManager;
    };

    template class Server<EntityManager &>;
}


#endif //RTYPE_SERVER_HPP
