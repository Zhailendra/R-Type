// #include <criterion/criterion.h>
// #include "../../../src/common/ECS/System/ScaleSystem/ScaleSystem.hpp"
// #include "../../../src/common/ECS/System/ASystem.hpp"



// // Test case for adding entities to ScaleSystem
// Test(ScaleSystem, AddEntity) {
//     ScaleSystem scaleSystem;
//     EntityManager manager;
//     std::shared_ptr<Entity> entity = manager.createEntity(/* Initialisez votre entité ici */);
//     scaleSystem.addEntity(entity);

//     std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities = scaleSystem.getEntites();

//     cr_assert_not_null(entities, "Le vecteur d'entités ne doit pas être nul");
//     cr_assert_eq(entities->size(), static_cast<size_t>(1), "Le nombre d'entités doit être égal à 1");
// }

// // Test case for getting entities from ScaleSystem
// Test(ScaleSystem, GetEntities) {
//     ScaleSystem scaleSystem;
//     EntityManager manager;
//     std::shared_ptr<Entity> entity1 = manager.createEntity(/* Initialisez votre première entité ici */);
//     std::shared_ptr<Entity> entity2 = manager.createEntity(/* Initialisez votre deuxième entité ici */);
//     scaleSystem.addEntity(entity1);
//     scaleSystem.addEntity(entity2);

//     std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities = scaleSystem.getEntites();

//     cr_assert_not_null(entities, "Le vecteur d'entités ne doit pas être nul");
//     cr_assert_eq(entities->size(), static_cast<size_t>(2), "Le nombre d'entités doit être égal à 2");
// }
