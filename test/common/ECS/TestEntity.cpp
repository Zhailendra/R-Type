#include "./TestEntity.hpp"
#include <criterion/criterion.h>

Test(entity_class, create_entity_with_specified_id)
{
    std::uint32_t id = 5;
    Entity entity = Entity(id);

    cr_assert_eq(entity.getId(), 5, "L'id de l'entity devrait être 5");
}

Test(entity_class, test_operator_left)
{
    std::uint32_t id = 5;
    Entity entity = Entity(id);
    std::stringstream os;
    os << entity;

    cr_assert_eq(os.str(), "Entity{id: 5}", "L'id de l'entity devrait être 5");
}
