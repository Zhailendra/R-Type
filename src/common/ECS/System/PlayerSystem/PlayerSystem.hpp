/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../ASystem.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include "../../../OstreamHelper.hpp"

#include "../../Components/Position/PositionComponent.hpp"
#include "../../Components/Renderable/Renderable.hpp"
#include "../../Components/Velocity/Velocity.hpp"
#include "../../Components/Controllable/ControllableComponent.hpp"
#include "../../Components/Rectable/Rectable.hpp"

#include "Utils/SoundLoader.hpp"
class PlayerSystem : public ASystem {
    public:
        PlayerSystem();
        ~PlayerSystem();

        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;        
        void addEntity(std::shared_ptr<Entity> &entity) final;

        void KeyReleased(std::shared_ptr<Entity> &entity, auto &controllable, auto &velo, auto &rect, auto &ev);
        void keyPressed(std::shared_ptr<Entity> &entity, auto &controllable, auto &velo, auto &rect, auto &ev);

        void update() final;
    private:
};

#endif /* !PLAYER_HPP_ */
