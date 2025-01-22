# ECS

## Description
What is an ECS ? It's an architectural pattern used in game development. It's a way to decouple data from logic. It's composed of 3 main parts:
> - Entities
> - Components
> - Systems

All of these parts are stored in a manager. that can create, delete, and update Entities.
Entities are just a container for components. Components are just data. Systems are the logic of the game. They are the ones that will update the components.

## Design Class

This is a representation of the basics of our ECS:
[![](https://mermaid.ink/img/pako:eNrdV1tv2jAU_itWHlCYKOLa0vQisa0PPFSrVp4mJOTGplgLdmY7qGnX_PY5sQMOMZepexpVwfa5fef4XJI3L2QIe4EXRlCIrwQ-c7iaUaA-xQmYfGGrmFFMJXjT5_lnTbhMYAQ2RAGesZymMfabIGRUSHADOnX-NSMICMNpCUu1b25F3m0EYyeCA5YXhMLIsn3QpmF2Kp7nLA5ED0wQSRh1AqsR_UXEoAQvuXstoDepvXnNN00bwxNjEWAx5lAyfnPja7_qZht8KYzXW-HtyhjePUh3D14dPn7HFCn7TxF2eukg-83DZCFREAjJCX0GEr_IhOMjEtptF5IGk0vMD4srpjKCp2ja6hKLIJhqgCoF9KJKfYw5kYooil-LZrlYSj5AuazE16qos7Pft3Z-B2BCFRoiIQ2N2vEOdz0JThByOe4QMxX_mAqJV65yzwzNL2r1ak99JzGCEu_l0UFaQo7RPJY8K_ZrHKqLynZpd1QSmWZZlhd5scHCbx7oLRAhLePvUQUauFjs7TYO700DmdA4kcI_iF8lx91aWVCIG6Tgb9YVFVAIPqJqbyiwEa8m7Ymo5hrViYJ7McxLEI4Q3rN1nmr1QP6Dmy_adaXJ_e21u6bDJmMtYrXjRzDF_P_wqKxv3XzMxtVEbL7qnR7jroRrb6PRjtTCmRAq-725zMM0QX5tvm3KEflVfoKarimoMMSRCgbItNlppufrEgrn7CqJzueFg2rLi9uqnSrwZt0Ex2U5XrG1PVFP8mbayEPl9KXGPW6Z4E8_m1W73Qbf8hnoCIvw6z1mE-45QVc7tIgIWcv77TDK-8YmHtvOUc-Je0jhM-Z2aiQiH6r38MVUjmrfFTgF5_7CLIsm5FiFw1TWbmtGWM1ultp1t_G2rLbjJsrq3tWgFUxQLaE_1kRS363wV4ITnFUgFELjNSRRXsubKVSXJ69Y19-jWm3pH4VcnRmHkcJdmJUeZlrH2dkn-3Eq0A_v-gHJZizzKec3oifwlp2ydPz6ekIl5gsY4ttby66TWopq0vhJZRYM5a39uOci2mLlt_7L117LW2G-ggSpN7aiOGaeKt0VnnmBWiLIf868GX1XfDCR7DGloRcsYCRwy9MTwbzhbU5jSL3gzXvxgm6v074YdEaD7qDf73aHw1HLS9Vx_7w9uOidj0bdYe-i0x-8t7xXxpQGxX7Zv-yp_1FneDkaDFseRkRlwL15o8x_Cgs_Cn7JE_z-B8K4zzw?type=jpg)](https://mermaid.ink/img/pako:eNrdV1tv2jAU_itWHlCYKOLa0vQisa0PPFSrVp4mJOTGplgLdmY7qGnX_PY5sQMOMZepexpVwfa5fef4XJI3L2QIe4EXRlCIrwQ-c7iaUaA-xQmYfGGrmFFMJXjT5_lnTbhMYAQ2RAGesZymMfabIGRUSHADOnX-NSMICMNpCUu1b25F3m0EYyeCA5YXhMLIsn3QpmF2Kp7nLA5ED0wQSRh1AqsR_UXEoAQvuXstoDepvXnNN00bwxNjEWAx5lAyfnPja7_qZht8KYzXW-HtyhjePUh3D14dPn7HFCn7TxF2eukg-83DZCFREAjJCX0GEr_IhOMjEtptF5IGk0vMD4srpjKCp2ja6hKLIJhqgCoF9KJKfYw5kYooil-LZrlYSj5AuazE16qos7Pft3Z-B2BCFRoiIQ2N2vEOdz0JThByOe4QMxX_mAqJV65yzwzNL2r1ak99JzGCEu_l0UFaQo7RPJY8K_ZrHKqLynZpd1QSmWZZlhd5scHCbx7oLRAhLePvUQUauFjs7TYO700DmdA4kcI_iF8lx91aWVCIG6Tgb9YVFVAIPqJqbyiwEa8m7Ymo5hrViYJ7McxLEI4Q3rN1nmr1QP6Dmy_adaXJ_e21u6bDJmMtYrXjRzDF_P_wqKxv3XzMxtVEbL7qnR7jroRrb6PRjtTCmRAq-725zMM0QX5tvm3KEflVfoKarimoMMSRCgbItNlppufrEgrn7CqJzueFg2rLi9uqnSrwZt0Ex2U5XrG1PVFP8mbayEPl9KXGPW6Z4E8_m1W73Qbf8hnoCIvw6z1mE-45QVc7tIgIWcv77TDK-8YmHtvOUc-Je0jhM-Z2aiQiH6r38MVUjmrfFTgF5_7CLIsm5FiFw1TWbmtGWM1ultp1t_G2rLbjJsrq3tWgFUxQLaE_1kRS363wV4ITnFUgFELjNSRRXsubKVSXJ69Y19-jWm3pH4VcnRmHkcJdmJUeZlrH2dkn-3Eq0A_v-gHJZizzKec3oifwlp2ydPz6ekIl5gsY4ttby66TWopq0vhJZRYM5a39uOci2mLlt_7L117LW2G-ggSpN7aiOGaeKt0VnnmBWiLIf868GX1XfDCR7DGloRcsYCRwy9MTwbzhbU5jSL3gzXvxgm6v074YdEaD7qDf73aHw1HLS9Vx_7w9uOidj0bdYe-i0x-8t7xXxpQGxX7Zv-yp_1FneDkaDFseRkRlwL15o8x_Cgs_Cn7JE_z-B8K4zzw?type=jpg)

In this image, we can see that the manager is the one that will create, delete and update the entities.
The systems are the ones that will update the components. 
The components are just data. 
The entities are just a container for components.
The Systems are hard linked to the Entity Manager, but the components are not. They are just data, so they can be used by any system.

## How to use

### Create a new Entity

To create a new entity, you need to call the `createEntity` method of the manager. This method will return an Entity object. This object is just a container for components. You can add components to this entity with the `addComponent` method of the manager. This method will return a pointer to the component you just added. You can use this pointer to update the component.

You can do it like that:
```cpp
EntityManager manager;
auto entity = manager.createEntity();
auto position = entity.addComponent<PositionComponent>(PositionComponent(0, 0));
```

### How to check if an entity has a component

To check if an entity has a component, you need to call the `hasComponent` method of the manager. This method will return a boolean. If the entity has the component, it will return true, else it will return false.

You can do it like that:
```cpp
EntityManager manager;
auto entity = manager.createEntity();
auto position = entity.addComponent<PositionComponent>(PositionComponent(0, 0));
if (entity.hasComponent<PositionComponent>())
    std::cout << "The entity has a position component" << std::endl;
```

### How to get a component

To get a component, you need to call the `getComponent` method of the manager. This method will return a pointer to the component. If the entity doesn't have the component, it will return a nullptr.

You can do it like that:
```cpp
EntityManager manager;
auto entity = manager.createEntity();
auto position = entity.addComponent<PositionComponent>(PositionComponent(0, 0));
auto position = entity.getComponent<PositionComponent>();
```

### How to remove a component

To remove a component, you need to call the `removeComponent` method of the manager. This method will remove the component from the entity.

You can do it like that:
```cpp
EntityManager manager;
auto entity = manager.createEntity();
auto position = entity.addComponent<PositionComponent>(PositionComponent(0, 0));
entity.removeComponent<PositionComponent>();
```

### How to delete an entity

To delete an entity, you need to call the `destroyEntity` method of the manager. This method will delete the entity and all of its components.

You can do it like that:
```cpp
EntityManager manager;
auto entity = manager.createEntity();
auto position = entity.addComponent<PositionComponent>(PositionComponent(0, 0));
manager.destroyEntity(entity->getId());
```

### How to create you own component and system
- [How to create a component](../../doc/ECS/HowToCreateAComponent.md)
- [How to create a system](../../doc/ECS/HowToCreateASystem.md)


> ### Ressources
> - [EntityManager](../../src/common/ECS/EntityManager.hpp)
> - [Entity](../../src/common/ECS/Entity.hpp)
> - [AComponent](../../src/common/ECS/Components/Position/AComponent.hpp)
> - [ASystem](../../src/common/ECS/System/ASystem.hpp)




