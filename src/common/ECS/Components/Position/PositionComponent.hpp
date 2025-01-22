/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** PositionComponent
*/

#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_

#include "../AComponent.hpp"
#include <functional>

class PositionComponent : public AComponent {
    public:
        PositionComponent(float x = 0, float y = 0, float z = 0);
        ~PositionComponent() = default;

        // Register a callback for position change
        void registerPositionChangeCallback(std::function<void(float, float)> callback) {
            positionChangeCallback = std::move(callback);
        }

        bool operator==(const PositionComponent &rhs) const {
            return x == rhs.x &&
                   y == rhs.y &&
                   z == rhs.z;
        }
        
        void setPos(float x, float y, float z);
        void setPos(float x, float y);

        friend std::ostream &operator<<(std::ostream &os, const PositionComponent &positionComponent);
        
        float x;
        float y;
        float z;

    private:
        std::function<void(float, float)> positionChangeCallback;
};

#endif /* !POSITIONCOMPONENT_HPP_ */
