// #include <criterion/criterion.h>
// #include "../../../src/common/ECS/System/PlayerSystem/PlayerSystem.hpp"
// #include "../../../src/common/ECS/System/ASystem.hpp"
// #include "../../../../../src/common/ECS/Components/Position/PositionComponent.hpp"

// // Test case for checking if PlayerSystem's getEntities returns a valid pointer
// Test(PlayerSystem, GetEntitiesNotNull) {
//     PlayerSystem playerSystem;

//     cr_assert_null(playerSystem.getEntites(), "Returned entities pointer should be null");
// }

// // Test case for adding an entity to PlayerSystem
// Test(PlayerSystem, AddEntity) {
//     PlayerSystem playerSystem;

//     std::shared_ptr<Entity> entity = std::make_shared<Entity>();
//     PositionComponent positionComponent;
//     entity->addComponent<PositionComponent>(positionComponent);
//     playerSystem.addEntity(entity);
    

//     std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities = playerSystem.getEntites();
//     cr_assert_eq(entities.get()->size(), 1, "One entity should be added");
//     cr_assert_eq(entities.get()->at(0), entity, "The added entity should be in the entities vector");
// }
