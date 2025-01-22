//
// Created by Simon BANDIERA on 09/01/2024.
//

#ifndef TEXTSYSTEM_HPP
#define TEXTSYSTEM_HPP

#include <ECS/Components/Text/TextComponent.hpp>
#include <ECS/Components/Button/ButtonComponent.hpp>
#include <ECS/System/ASystem.hpp>
#include <ECS/Components/Input/InputComponent.hpp>

class TextSystem : public ASystem {
    public:
        TextSystem();
        ~TextSystem() override = default;

        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;
        void addEntity(std::shared_ptr<Entity> &entity) final;
        void update() final;

        sf::Font _font;
        bool init = false;
    protected:
    private:
};



#endif //TEXTSYSTEM_HPP
