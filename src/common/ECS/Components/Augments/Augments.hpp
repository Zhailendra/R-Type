/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Augments
*/

#ifndef AUGMENTS_HPP_
#define AUGMENTS_HPP_

#include <ECS/Components/AComponent.hpp>
#include <ECS/Types.hpp>

class Augments : public AComponent {
    public:
        Augments();
        Augments(std::vector<bool> augments) { _type = Components::AUGMENTS; _augments = augments;};
        ~Augments();

        std::vector<bool> _augments;
    protected:
    private:
};

#endif /* !AUGMENTS_HPP_ */
