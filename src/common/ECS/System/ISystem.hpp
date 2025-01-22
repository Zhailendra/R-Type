/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

#include <iostream>
#include <vector>
#include <memory>

class ISystem {
    public:
        ISystem();
        virtual ~ISystem() = 0;
        virtual void update() = 0;
    protected:
    private:
};

#endif /* !ISYSTEM_HPP_ */
