#include <criterion/criterion.h>
#include "./TestVelocity.hpp"

// Test de création d'une instance Velocity avec des valeurs x, y, z
Test(Velocity, CreateWithXYZValues) {
    float x = 1.5f;
    float y = -2.0f;
    float z = 0.0f;

    Velocity velocity(x, y, z);

    cr_assert_float_eq(velocity.x, x, 0.001f);
    cr_assert_float_eq(velocity.y, y, 0.001f);
    cr_assert_float_eq(velocity.z, z, 0.001f);
}

// Test de création d'une instance Velocity par défaut (valeurs par défaut x=0, y=0, z=0)
Test(Velocity, CreateWithDefaultValues) {
    Velocity velocity;

    cr_assert_float_eq(velocity.x, 0.0f, 0.001f);
    cr_assert_float_eq(velocity.y, 0.0f, 0.001f);
    cr_assert_float_eq(velocity.z, 0.0f, 0.001f);
}
