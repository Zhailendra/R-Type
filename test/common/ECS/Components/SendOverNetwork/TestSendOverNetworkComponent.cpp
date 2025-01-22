#include <criterion/criterion.h>
#include "../../../../../src/common/ECS/Components/SendOverNetwork/SendOverNetworkComponent.hpp"

Test(SendOverNetworkComponent, OutputOperator)
{
    SendOverNetworkComponent sendOverNetworkComponent;
    std::ostringstream oss;
    oss << sendOverNetworkComponent;

    cr_assert_eq(oss.str(), "SendOverNetworkComponent{}", "L'opérateur de sortie ne fonctionne pas correctement.");
}
