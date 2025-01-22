/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** MovableSystem
*/

#ifndef MOVABLESYSTEM_HPP_
#define MOVABLESYSTEM_HPP_

#include "../ASystem.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include "../../../OstreamHelper.hpp"

#include "../../Components/Position/PositionComponent.hpp"
#include "../../Components/Velocity/Velocity.hpp"
#include "../../Components/Renderable/Renderable.hpp"

class MovableSystem : public ASystem {
    public:
        MovableSystem();
        ~MovableSystem();

        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;        
        void addEntity(std::shared_ptr<Entity> &entity) final;
        void update() final;
    protected:
    private:
};

#endif /* !MOVABLESYSTEM_HPP_ */
