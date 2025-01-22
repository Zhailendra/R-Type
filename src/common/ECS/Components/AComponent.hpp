/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"


class AComponent : public IComponent {
    public:
        AComponent();
        virtual ~AComponent() override = default;

        virtual Components getType() const final;
        virtual void setType(Components type) final;

    protected:
        Components _type;
};

#endif /* !ACOMPONENT_HPP_ */
