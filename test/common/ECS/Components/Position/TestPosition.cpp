
#include "TestPosition.hpp"
#include <criterion/criterion.h>

// Set des positons x, y, z
Test(PositionComponent, set_position_xyz) {
    PositionComponent position;
    position.setPos(1.0f, 2.0f, 3.0f);

    cr_assert_float_eq(position.x, 1.0f, EPSILON);
    cr_assert_float_eq(position.y, 2.0f, EPSILON);
    cr_assert_float_eq(position.z, 3.0f, EPSILON);
}

// Set des position x et y seulement 
Test(PositionComponent, SetPositionXY) {
    PositionComponent position;
    position.setPos(4.0f, 5.0f);

    cr_assert_float_eq(position.x, 4.0f, EPSILON);
    cr_assert_float_eq(position.y, 5.0f, EPSILON);
    cr_assert_float_eq(position.z, 0.0f, EPSILON);
}

// Verifier le callback lors du changement de positons
Test(PositionComponent, PositionChangeCallback) {
    PositionComponent position;

    bool callbackCalled = false;
    position.registerPositionChangeCallback([&](float x, float y) {
        callbackCalled = true;
    });

    position.setPos(1.0f, 1.0f);

    cr_assert(callbackCalled);
}
