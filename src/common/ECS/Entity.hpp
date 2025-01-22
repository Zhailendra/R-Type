/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Entity
*/


#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>
#include <type_traits>
#include <algorithm>
#include <memory>
#include <list>
#include "./Components/AComponent.hpp"
#include <cstdint>


class Entity {
    public:
        Entity(std::uint32_t id = 0);
        ~Entity();
        std::uint32_t getId() const;
        void setId(std::uint32_t id);
        
        template <class T> bool hasComponent()
        {
            static_assert(std::is_base_of<AComponent, T>::value, "Doesnt inherit from AComponent");
            T comp;
			for (auto &y : _components) {
				if (y.get()->getType() == comp.getType())
					return true;
			}
            // std::cout << "Entity " << _id << " does not have component " << comp.getType() << std::endl;
            return false;
        }

        bool hasType(Components type)
        {
            for (auto &y : _components) {
                if (y.get()->getType() == type)
                    return true;
            }
            return false;
        }

        template <class T> void addComponent(T component) 
        {
            static_assert(std::is_base_of<AComponent, T>::value, "Doesnt inherit from AComponent");
            if (hasComponent<T>())
                return;
            _components.push_back(std::make_shared<T>(component));
        }

        template <class T> void removeComponent()
        {
            static_assert(std::is_base_of<AComponent, T>::value, "Doesnt inherit from AComponent");
            T component;
            if (!hasComponent<T>())
                return;
            _components.remove_if([&](std::shared_ptr<AComponent> &x) {
                return x->getType() == component.getType();
            });
        }
        
        template <class T> T& getComponent()
        {
            static_assert(std::is_base_of<AComponent, T>::value, "Doesnt inherit from AComponent");
            T comp;
            for (auto &y : _components) {
                if (y.get()->getType() == comp.getType())
                    return *std::dynamic_pointer_cast<T>(y);
            }
            //throw std::runtime_error("Entity " + std::to_string(_id) + " does not have component " + std::to_string(comp.getType()));
        }

        template <class TA, class TB, class... Other> 
        bool hasComponents();

        friend std::ostream &operator<<(std::ostream &os, const Entity &Entity);
    private:
        std::uint32_t _id;
        std::list<std::shared_ptr<AComponent>> _components;
};

#endif /* !ENTITY_HPP_ */
