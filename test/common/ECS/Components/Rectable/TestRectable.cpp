// #include <criterion/criterion.h>
// #include "../../../../../src/common/ECS/Components/Rectable/Rectable.hpp"

// // Test initialisation
// Test(Rectable, Creation)
// {
//     int frameNumber = 5;
//     int nbFrames = 10;
//     Rectable rectable(frameNumber, nbFrames);

//     cr_assert_eq(rectable._currentPlayerFrame, frameNumber, "La frame du joueur n'a pas été initialisée correctement.");
//     cr_assert_eq(rectable._nbFrames, nbFrames, "La nbFrames du joueur n'a pas été initialisée correctement.");
//     // cr_assert_eq(rectable._upKeyPressed, false, "La touche 'up' n'a pas été initialisée à false par défaut.");
//     // cr_assert_eq(rectable._downKeyPressed, false, "La touche 'down' n'a pas été initialisée à false par défaut.");
// }

// // Test constructor par defaut
// Test(Rectable, DefaultConstructor)
// {
//     Rectable rectable;

//     cr_assert_eq(rectable._currentPlayerFrame, 0, "La frame du joueur n'a pas été initialisée à zéro par défaut.");
//     // cr_assert_eq(rectable._upKeyPressed, false, "La touche 'up' n'a pas été initialisée à false par défaut.");
//     // cr_assert_eq(rectable._downKeyPressed, false, "La touche 'down' n'a pas été initialisée à false par défaut.");
// }
