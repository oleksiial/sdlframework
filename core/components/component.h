#ifndef COMPONENT_H
#define COMPONENT_H

class Container;

class Component {
public:
    Component(Container& container)
        : _container(container) {}


    virtual ~Component() {}
    virtual void update() = 0;

    enum class ComponentType { transform, sprite, total };

    Container& getContainer() { return _container; }
    ComponentType getComponentType() const { return _componentType; }
protected:
    Container& _container;
    ComponentType _componentType;
};

#endif
