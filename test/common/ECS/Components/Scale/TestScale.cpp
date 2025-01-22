#include <criterion/criterion.h>
#include "../../../../../src/common/ECS/Components/Scale/ScaleComponent.hpp"

Test(ScaleComponent, DefaultConstructor)
{
    ScaleComponent scaleComponent;

    cr_assert_eq(scaleComponent._x, 1.0f, "La valeur par défaut de x n'est pas égale à 1.0f.");
    cr_assert_eq(scaleComponent._y, 1.0f, "La valeur par défaut de y n'est pas égale à 1.0f.");
}

Test(ScaleComponent, CustomConstructor)
{
    float x = 2.5f;
    float y = 3.0f;

    ScaleComponent scaleComponent(x, y);

    cr_assert_eq(scaleComponent._x, x, "La valeur de x n'a pas été initialisée correctement.");
    cr_assert_eq(scaleComponent._y, y, "La valeur de y n'a pas été initialisée correctement.");
}

Test(ScaleComponent, OutputOperator)
{
    ScaleComponent scaleComponent(2.0f, 3.5f);
    std::ostringstream oss;
    oss << scaleComponent;

    cr_assert_eq(oss.str(), "ScaleComponent: {x: 2, y: 3.5}", "L'opérateur de sortie ne fonctionne pas correctement.");
}
