#include <criterion/criterion.h>
#include "TestEntityManager.hpp"

// Test la création d'une entity
Test(EntityManager, createEntity) {
    EntityManager manager;
    auto entity = manager.createEntity();
    entity->setId(0);
    cr_assert_not_null(entity.get(), "createEntity devrait retourner une entité non nulle.");
    cr_assert_eq(entity.get()->getId(), 0, "L'ID de la première entité créée devrait être 0.");
}


// Test la recuperation d'entity
Test(EntityManager, getEntityById) {
    EntityManager manager;
    auto entity = manager.createEntity();
    std::uint32_t entityId = entity.get()->getId();

    auto retrievedEntity = manager.getEntity(entityId);
    cr_assert_eq(retrievedEntity.get()->getId(), entityId, "getEntity devrait retourner l'entité avec l'ID correspondant.");
}

// Test la recuperation d'entity
Test(EntityManager, getAllEntities) {
    EntityManager manager;
    manager.createEntity();
    manager.createEntity();

    auto entities = manager.getEntity();
    cr_assert_eq(entities.get()->size(), 2, "getEntity devrait retourner toutes les entités.");
}


// Test la liste available entities
// Test(EntityManager, DestroyEntityTest) {
//     EntityManager entityManager;

//     std::shared_ptr<Entity> entity1 = entityManager.createEntity();
//     std::shared_ptr<Entity> entity2 = entityManager.createEntity();

//     entityManager.destroyEntity(entity1->getId());

//     std::queue<std::uint32_t> availableEntities = entityManager.getAvailableEntities();

//     cr_assert_eq(availableEntities.size(), 1, "La file d'entités disponibles ne contient pas l'ID de l'entité détruite.");

//     entityManager.destroyEntity(entity2->getId());

//     availableEntities = entityManager.getAvailableEntities();

//     cr_assert_eq(availableEntities.size(), 2, "La file d'entités disponibles ne contient pas les IDs des entités détruites.");
// }
