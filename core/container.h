#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <algorithm>
#include <memory>
#include "components/component.h"

class Container {
public:
    ~Container() {

    }

    template <typename T>
    std::shared_ptr<T> getComponent(Component::ComponentType type) {
        for (auto component : _components) {
            if (component->getComponentType() == type) {
                return std::dynamic_pointer_cast<T>(component);
            }
        }
        return nullptr;
    }

    template <typename T>
    std::shared_ptr<const T> getComponent(Component::ComponentType type) const {
        for (auto component : _components) {
            if (component->getComponentType() == type) {
                return std::dynamic_pointer_cast<const T>(component);
            }
        }
        return nullptr;
    }

    void addComponent(std::shared_ptr<Component>&& component) {
        _components.push_back(std::move(component));
    }
private:
    std::vector<std::shared_ptr<Component>> _components;
};

#endif
