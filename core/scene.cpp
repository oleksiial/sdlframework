#include <SDL2/SDL.h>
#include "scene.h"

#include "../core/container.h"

#include "../utilities/log.h"
#include "../gfxengine/gfxengine.h"

#include "../core/components/sprite.h"
#include "../core/components/transform.h"

Scene::Scene()
    : _nextScreen(nullptr)
    , _exit(false) {

}


void Scene::registerEntity(std::shared_ptr<Container> container) {
    _objects.push_back(std::move(container));
}

Scene *Scene::run() {
    SDL_Event event;

    GfxEngine& gfxengine = GfxEngine::getInstance();

    Log::print(Log::INFO, "run scene");

    while (_exit == false) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return _nextScreen;
            }
        }

        gfxengine.startFrame();

        for(auto& obj : _objects) {
            gfxengine.drawSprite(obj->getComponent<Sprite>(Component::ComponentType::sprite).get(),
                                 obj->getComponent<Transform>(Component::ComponentType::transform).get());
        }


        gfxengine.endFrame();
    }

    return _nextScreen;
}
