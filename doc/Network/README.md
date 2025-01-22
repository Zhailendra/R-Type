# Network

## Description
This is the network part of the project. It's composed of 2 parts:
> - The server
> - The client

The server is the one that will handle all the connections and the game logic. The client is the one that will handle the user inputs and the rendering.
All the communications between the server and the client are done with the UDP protocol.

## Design Class
That's a representation of the network part of the project:
[![](https://mermaid.ink/img/pako:eNrNVktv2zAM_iuCD0EyuMXO7gPIsh1yaFEs3WUIYCgSkwi1JUOiMwRd_dtH-ZHIadIuwLDNB8vi4yMpfpL1HAkjIUoikXHnPiu-sjyfa0ZPLWHTe8Afxj6x50bqn9IpvWJrrmUG1qXIbphDmSTLUgtURlcbo-Sw86weLy8vKzaIWStIkgcungC9yOvYqNpjb5TFkmfMQ1AgGDa2j9sCGNIrDuO2nyNK4ONriIUxGbOlHp7Q1yEcaDkURjtkbpkk02IspQUqfKCKmJXaqZUGMlsbi6ygV8wa609bBDZY0PsteIIqyLwrgw2KejwPZGENl4I7bBPtsN4PLkBtYLIG8TT01XWObtlP47zKvfXMeH8akWNJLq4eg2ReQhJNMgUaZ2hLgSGR-nFVEVDsdfjAzZNNrK3RJklQ5ZAWRmmsenK3dQh5KjLKtGKUBn5tluNIfuPfI7nnn-Y5sD61k2RvFXTiLAIvlebZ3jmg7oHmz5H2GPAZdD3mfoqoDcqpkH-dpGYD1ioJV3Pd5-I3WTQ-LHX1eHVAupwX1b6fYSsrlnaTPmYDOIMMBBpLrWs-DoA3tbAKNwohinrqjjB2BpaKCPn6rxaz7WlYD0clmnwys-p46qt0aP2mGuQUlK9gdNrpgDnvop9OcO_6RaPC7R3XFNqyFMLpyUPrv1ziOhHhM5gYraH-6Q7fjzfwAUchUH3OpMq1MGR5w5Y8cxAQv6nvvswXftWKcEan_eEOcWtuQaYF2iok9qGu6UVVVW0fFLgjW213YWjMpzJmD8YpX-7E5HRSkS8h-MO9k_caeX091Qh2yQXc3u5O7U43XhAfuUBSjXuq3Z3n4uLnXscSpvQarEKuRfsXGe8tP_T_cgn1lTIMkxr3YNsd_DYo2bU0PLCL4igHm3Ml6e5WU3Qe4RpymEcJfUpOtURz_UJ2vEQz22oRJXVn46gsJEdo73o7KUhFjbprb4N-iKOC6-_GdDYvvwBnVmjL?type=jpg)](https://mermaid.ink/img/pako:eNrNVktv2zAM_iuCD0EyuMXO7gPIsh1yaFEs3WUIYCgSkwi1JUOiMwRd_dtH-ZHIadIuwLDNB8vi4yMpfpL1HAkjIUoikXHnPiu-sjyfa0ZPLWHTe8Afxj6x50bqn9IpvWJrrmUG1qXIbphDmSTLUgtURlcbo-Sw86weLy8vKzaIWStIkgcungC9yOvYqNpjb5TFkmfMQ1AgGDa2j9sCGNIrDuO2nyNK4ONriIUxGbOlHp7Q1yEcaDkURjtkbpkk02IspQUqfKCKmJXaqZUGMlsbi6ygV8wa609bBDZY0PsteIIqyLwrgw2KejwPZGENl4I7bBPtsN4PLkBtYLIG8TT01XWObtlP47zKvfXMeH8akWNJLq4eg2ReQhJNMgUaZ2hLgSGR-nFVEVDsdfjAzZNNrK3RJklQ5ZAWRmmsenK3dQh5KjLKtGKUBn5tluNIfuPfI7nnn-Y5sD61k2RvFXTiLAIvlebZ3jmg7oHmz5H2GPAZdD3mfoqoDcqpkH-dpGYD1ioJV3Pd5-I3WTQ-LHX1eHVAupwX1b6fYSsrlnaTPmYDOIMMBBpLrWs-DoA3tbAKNwohinrqjjB2BpaKCPn6rxaz7WlYD0clmnwys-p46qt0aP2mGuQUlK9gdNrpgDnvop9OcO_6RaPC7R3XFNqyFMLpyUPrv1ziOhHhM5gYraH-6Q7fjzfwAUchUH3OpMq1MGR5w5Y8cxAQv6nvvswXftWKcEan_eEOcWtuQaYF2iok9qGu6UVVVW0fFLgjW213YWjMpzJmD8YpX-7E5HRSkS8h-MO9k_caeX091Qh2yQXc3u5O7U43XhAfuUBSjXuq3Z3n4uLnXscSpvQarEKuRfsXGe8tP_T_cgn1lTIMkxr3YNsd_DYo2bU0PLCL4igHm3Ml6e5WU3Qe4RpymEcJfUpOtURz_UJ2vEQz22oRJXVn46gsJEdo73o7KUhFjbprb4N-iKOC6-_GdDYvvwBnVmjL?type=jpg)
So we can see that the server and the client are both linked to the ANetwork. The ANetwork is the one that will handle all the communications and call handlers in function of type of packet. The server and the client both inherit from the ANetwork because they both works the same way. The only difference is that the server will handle the game logic and the client will handle the user inputs and the rendering.

## How Works packet exchange between server and client
- [RFC](../../doc/Network/RFC.md)
- [Exchange](../../doc/Network/Exchange.md)

## How to use client or server

### Add a new handler

To add a new handler, you need to create a new class that inherit from the `AHandler` class. This class is an abstract class that contains the `getType` method. This method will return the type of the handler.

You can do it like that:
```cpp
server.use(Network::Pong, [](Network::INetwork<TemplateRefServer> &server, Network::Packet &packet){
    std::cout << "Pong" << std::endl;
});
```

if you want to add data to the handler, you need to add a new template parameter to the `AHandler` class. This template parameter will be the type of the data you want to add to the handler.

> ### Ressources
> - [ANetwork](../../src/common/Network/ANetwork.hpp)
> - [Server](../../src/common/Network/Server.hpp)
> - [Client](../../src/common/Network/Client.hpp)