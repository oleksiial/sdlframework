#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>

class Container;

class Scene {
public:
    Scene();

    void registerEntity(std::shared_ptr<Container> container);

    Scene* run();
private:
    std::vector<std::shared_ptr<Container>> _objects;

    Scene *_nextScreen;
    bool _exit;
};

#endif // SCENE_H
