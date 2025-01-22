//
// Created by Simon BANDIERA on 14/01/2024.
//

#ifndef ITEM_HPP
#define ITEM_HPP

#include "ECS/Components/AComponent.hpp"

class ItemComponent : public AComponent {
    public:
        ItemComponent() { _type = Components::ITEMCOMP; };
        ItemComponent(int type) { _type = Components::ITEMCOMP; _indexType = type; };
        ~ItemComponent() = default;

        int _indexType;
    protected:
    private:
};



#endif //ITEM_HPP
