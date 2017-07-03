#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component {
public:
    Component(Entity& entity)
        : _entity(entity) {}


    virtual ~Component() {}
    virtual void update() = 0;

    enum class ComponentType { transform, sprite, total };

    Entity& getEntity() { return _entity; }
    ComponentType getComponentType() const { return _componentType; }
protected:
    Entity& _entity;
    ComponentType _componentType;
};

#endif
