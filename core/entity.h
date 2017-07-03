#ifndef ENTITY_H
#define ENTITY_H

#include "container.h"

class Scene;

class Entity : public Container {
public:
    Entity(Scene& scene, const Entity *parent = nullptr)
        : _scene(scene)
        , _parent(parent)
        , _isVisible(true)
        , _isActive(true) {

    }

    virtual ~Entity() {}
    virtual void update() = 0;

    bool isVisible() const {
        if (_isVisible == true && _parent != nullptr) {
            return _parent->isVisible();
        }
        return _isVisible;
    }
    bool isActive() const { return _isActive; }

    void setVisible(bool value) { _isVisible = value; }
    void setActive(bool value) { _isActive = value; }
    const Entity* getParent() const { return _parent; }

private:
    Scene& _scene;
    const Entity *_parent;

    bool _isVisible;
    bool _isActive;
};

#endif // ENTITY_H
