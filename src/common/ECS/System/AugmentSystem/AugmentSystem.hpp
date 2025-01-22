/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** AugmentSystem
*/

#ifndef AUGMENTSYSTEM_HPP_
#define AUGMENTSYSTEM_HPP_

#ifdef __APPLE__
    #include <MacTypes.h>
#endif
#include <ECS/System/ASystem.hpp>
#include <ECS/Components/Augments/Augments.hpp>
#include <ECS/EntityManager.hpp>

class AugmentSystem : public ASystem {
    public:
        AugmentSystem();
        ~AugmentSystem();

        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;
        void addEntity(std::shared_ptr<Entity> &entity) final;
        void update() final;

        void updateAugments(PositionComponent posComp);
        void setAugments(Augments &augmentComp, PositionComponent posComp, std::vector<bool> augments);
    protected:
    private:
        std::vector<bool> _setAugments = {false, false};
};

#endif /* !AUGMENTSYSTEM_HPP_ */
