#include <criterion/criterion.h>
#include "../../../src/common/ECS/System/EnemySystem/EnemySystem.hpp"
#include "../../../src/common/ECS/System/ASystem.hpp"
#include "../../../src/common/ECS/EntityManager.hpp"

// Test case for adding entities to the EnemySystem
// Test(EnemySystem, AddEntity) {
//     EnemySystem enemySystem;
//     EntityManager entityManager;
    
//     // Create an entity and add it to the EnemySystem
//     std::shared_ptr<Entity> entity = entityManager.createEntity();
//     enemySystem.addEntity(entity);

//     // Retrieve entities from the EnemySystem
//     std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities = enemySystem.getEntites();

//     cr_assert_eq(entities->size(), static_cast<size_t>(1), "Number of entities should be 1");
//     // Additional assertions to check the state of the added entity if needed
// }

// Test case for getting entities from the EnemySystem
// Test(EnemySystem, GetEntities) {
//     EnemySystem enemySystem;
//     EntityManager entityManager;
//     // Add entities to the EnemySystem
//     std::shared_ptr<Entity> entity1 = entityManager.createEntity(/* Initialize your first entity here */);
//     std::shared_ptr<Entity> entity2 = entityManager.createEntity(/* Initialize your second entity here */);
//     enemySystem.addEntity(entity1);
//     enemySystem.addEntity(entity2);

//     // Retrieve entities from the EnemySystem
//     std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities = enemySystem.getEntites();

//     cr_assert_eq(entities->size(), static_cast<size_t>(2), "Number of entities should be 2");
//     // Additional assertions to check the state of the retrieved entities if needed
// }
