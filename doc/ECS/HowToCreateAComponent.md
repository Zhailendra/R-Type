# How to create you own Component

## Description
This is a tutorial on how to create your own component.

## Design Class
The design class of the all ECS can be found [here](../../doc/ECS/README.md).

## How to create a component

To create a component, you need to create a class that inherit from the `AComponent` class. This class is an abstract class that contains the `getType` method. This method will return the type of the component.

You can do it like that:
```cpp
#include <ECS/Component/AComponent.hpp>

class MyComponent : public AComponent {
    public:
        MyComponent() { _type = ComponentType::MY_COMPONENT; };
        ~MyComponent() = default;
};
```

To add ComponentType, you need to add it in the `ComponentType` in the [Types.hpp](../../src/common/ECS/Types.hpp) file and add 1 to the COMPONENTS_SIZE.

So in your class MyComponent, you can add every attributes you want in public is easier.