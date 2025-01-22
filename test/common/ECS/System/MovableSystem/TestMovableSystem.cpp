// #include <criterion/criterion.h>
// #include "../../../src/common/ECS/System/MovableSystem/MovableSystem.hpp"
// #include "../../../src/common/ECS/System/ASystem.hpp"

// // Test du déplacement d'une entity
// Test(MovableSystem, UpdateTest)
// {
//     auto entity = std::make_shared<Entity>();

//     PositionComponent position(10, 20, 0);
//     Velocity velocity(5, -2, 0);

//     entity->addComponent<PositionComponent>(position);
//     entity->addComponent<Velocity>(velocity);
//     entity->addComponent<Renderable>(Renderable(ENEMY_0_SPRITE));

//     MovableSystem movableSystem;
//     movableSystem.addEntity(entity);
//     // movableSystem.update();

//     // PositionComponent &pos = entity->getComponent<PositionComponent>();
//     // cr_assert_eq(pos.x, 15, "Mise à jour de la position en x incorrecte.");
//     // cr_assert_eq(pos.y, 18, "Mise à jour de la position en y incorrecte.");

//     // Renderable &render = entity->getComponent<Renderable>();
//     // cr_assert_eq(render._sprite.getPosition().x, 15, "Mise à jour de la position du Renderable en x incorrecte.");
//     // cr_assert_eq(render._sprite.getPosition().y, 18, "Mise à jour de la position du Renderable en y incorrecte.");
// }
