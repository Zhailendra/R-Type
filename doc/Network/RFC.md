# RFC

## Description
This is the RFC of the project. It's a document that will explain how the communication between the server and the client works.

## Table of Contents
- [RFC](#rfc)
  - [Description](#description)
  - [Table of Contents](#table-of-contents)
  - [Binary Protocol](#binary-protocol)
    - [How to add new convert methods](#how-to-add-new-convert-methods)
  - [Byte Encapsulation](#byte-encapsulation)
  - [Types](#types)
  - [Packet](#packet)
    - [Description of the packets](#description-of-the-packets)
      - [Network::Ping](#networkping)
      - [Network::Pong](#networkpong)
      - [Network::NewEntity](#networknewentity)
      - [Network::UpdateEntity](#networkupdateentity)
      - [Network::DeleteEntity](#networkdeleteentity)
      - [Network::GatherAllEntities](#networkgatherallentities)
  - [More Details](#more-details)
## Binary Protocol
So the protocol is binary. using the [Byte](../../src/common/Network/Byte.hpp) class.
This class is a class that use a `std::vector<uint8_t>` to store the data. It's a class that will help us to manipulate the data.
So in Byte class we have 2 methods to convert data to binary and binary to data.

### How to add new convert methods
To add new convert methods, you need to add a new method in the Byte class. This method will take a parameter and will return a reference to the Byte class.
You can do it like that:
```cpp
Byte &operator<<(const std::string &data) {
    size_t size = str.size();
    *this << size;
    writeToByte(&str[0], str.size());
}
```
```cpp
Byte &operator>>(std::string &data) {
    size_t size;
    *this >> size;
    data.resize(size);
    readFromByte(&data[0], size);
}
```

## Byte Encapsulation
So Byte is Encapsulated in Packet. Packet is a class that will encapsulate the Byte class. It's a class that will help us to manipulate the data.
Packet is a class that add `sf::IpAddress` and `unsigned short` for port to the Byte class.
Packet also add a `PacketType` to the Byte class and a `PacketNumber` to the Byte class.

## Types
So all the types are in the [RFC.hpp](../../src/common/Network/RFC.hpp) file.
So we have 4 types:
- PacketType is an enum that contains all the types of packet
- PacketNumber is `std::uint32_t` and is the number of the packet
- EntityId is `std::uint32_t` and is the id of the entity
- ComponentsType is `uint16_t` and is the type of the component (it's converter for ComponentType to uint16_t)
- MINIMUM_PACKET_SIZE is `size_t` and is the minimum size of a packet every packet below this size will be ignored
## Packet
So the packet is composed of 3 parts:
- The router (`PacketType`)
- The header (`PacketNumber`)
- The body (`Byte`)

So we will enumerate every packet type and explain what they do.

## Description of the packets

- `[Data]` is a variable that can be anything
- `[?Data]` is a variable that can be anything but is optional
- `[!Data]` is a variable that can be anything but is required
- `[Data1|Data2]` is a variable that can be Data1 or Data2
- `([Data])` is a list of Data

### Network::Ping
This packet is used to ping the server. The server will respond with a `Network::Pong` packet.
The Packet is composed of:

`[PacketType::Ping][PacketNumber]`

Response to the client:

`[PacketType::Pong][PacketNumber]`

### Network::Pong
This packet is used to pong the client. The client will send a `Network::Ping` packet and the server will respond with a `Network::Pong` packet.
The Packet is composed of:

`[PacketType::Pong][PacketNumber]`

This packet is only a response to the `Network::Ping` packet.

### Network::NewEntity
This packet is used to create a new entity. The server will send this packet to the client when a new entity is created.

The Packet is composed of:

`[PacketType::NewEntity][PacketNumber][EntityId]([ComponentsType][DataOfComponent])`

The response broadcasted to all clients:

`[PacketType::NewEntity][PacketNumber][EntityId]([ComponentsType][DataOfComponent])`

### Network::UpdateEntity
This packet is used to update an entity. The server will send this packet to the client when an entity is updated.

The Packet is composed of:

`[PacketType::UpdateEntity][PacketNumber][EntityId]([ComponentsType][DataOfComponent])`

Response broadcasted to all clients:

`[PacketType::DeleteEntity][PacketNumber][EntityId]([ComponentsType][DataOfComponent])`

### Network::DeleteEntity
This packet is used to delete an entity. The server will send this packet to the client when an entity is deleted.

The Packet is composed of:

`[PacketType::DeleteEntity][PacketNumber][EntityId]`

Response broadcasted to all clients:

`[PacketType::DeleteEntity][PacketNumber][EntityId]`

### Network::GatherAllEntities
This packet is used to gather all the entities. The server will send this packet to the client when the client is connected to the server.

The Packet is composed of:

`[PacketType::GatherAllEntities][PacketNumber]`

The response send to the client:

`[PacketType::NewEntity][PacketNumber][EntityId]([ComponentsType][DataOfComponent])`

## More Details
- [Network](../../src/common/Network)

### How a entity is serialized.
- [EntitySerializer.cpp](../../src/common/Network/EntitySerializer.cpp).
### How a component is serialized 
- [Byte.cpp](../../src/common/Network/Byte.cpp).
