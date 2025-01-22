/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include "../Types.hpp"
#include <iostream>
#include <vector>
#include <cstdint>

class IComponent {
    public:
        IComponent();
        virtual ~IComponent() = 0; 

        virtual Components getType() const = 0;
        virtual void setType(Components type) = 0;
    protected:
        Components _type;
};

#endif /* !ICOMPONENT_HPP_ */
