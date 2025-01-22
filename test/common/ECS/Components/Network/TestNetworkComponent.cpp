// #include <criterion/criterion.h>
// #include "../../../../../src/common/ECS/Components/Network/NetworkComponent.hpp"

// // Test initialisation
// Test(NetworkComponent, Creation)
// {
//     sf::IpAddress ip = sf::IpAddress::getLocalAddress();
//     unsigned short port = 5000;

//     NetworkComponent networkComponent(ip, port);

//     cr_assert_eq(networkComponent._ip, ip, "L'adresse IP n'a pas été initialisée correctement.");
//     cr_assert_eq(networkComponent._port, port, "Le port n'a pas été initialisé correctement.");
//     cr_assert_eq(networkComponent._client, nullptr, "Le client n'a pas été initialisé à nullptr par défaut.");
//     cr_assert_eq(networkComponent._isInit, false, "La valeur 'isInit' n'a pas été initialisée à false par défaut.");
//     cr_assert_eq(networkComponent._checksums.size(), 0, "Le nombre de checksums n'est pas initialisé à zéro par défaut.");
// }

// // Test des operateurs
// Test(NetworkComponent, OutputOperator)
// {
//     sf::IpAddress ip = sf::IpAddress::getLocalAddress();
//     unsigned short port = 5000;

//     NetworkComponent networkComponent(ip, port);
//     std::ostringstream oss;
//     oss << networkComponent;

//     std::string expectedOutput = "NetworkComponent{ip: " + ip.toString() + ", port: " + std::to_string(port) + ", isInit: " + std::to_string(false) + "}";
//     cr_assert_eq(oss.str(), expectedOutput, "La sortie de l'opérateur de flux est incorrecte.");
// }
