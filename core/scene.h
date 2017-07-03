#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>

class Entity;

class Scene {
public:
    Scene();

    void registerEntity(std::shared_ptr<Entity> entity);

    Scene* run();
private:
    std::vector<std::shared_ptr<Entity>> _objects;

    Scene *_nextScreen;
    bool _exit;
};

#endif // SCENE_H
