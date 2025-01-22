# How to create you own system

## Description
This is a tutorial on how to create your own system.

## Design Class
The design class of the all ECS can be found [here](../../doc/ECS/README.md).

## How to create a system

To create a system, you need to create a class that inherit from the `ASystem` class. This class is an abstract class that contains the `update` method. This method will be called every frame.

You can do it like that:
```cpp
#include <ECS/System/ASystem.hpp>

class MySystem : public ASystem {
    public:
        MySystem() = default;
        ~MySystem() = default;

        void update() override {
            // Do something
        }
        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final std::shared_ptr<std::vector<std::shared_ptr<Entity>>> ScaleSystem::getEntites()
        {
            return _entities;
        }
        void addEntity(std::shared_ptr<Entity> &entity) final {
            _entities->push_back(entity);
        }
};
```

