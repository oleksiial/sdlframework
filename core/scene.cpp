#include <SDL2/SDL.h>
#include "scene.h"

#include "entity.h"
#include "input.h"

#include "../utilities/log.h"
#include "../gfxengine/gfxengine.h"

#include "../core/components/sprite.h"
#include "../core/components/transform.h"

Scene::Scene()
    : _nextScreen(nullptr)
    , _exit(false) {

}


void Scene::registerEntity(std::shared_ptr<Entity> entity) {
    _objects.push_back(std::move(entity));
}

Scene *Scene::run() {
    SDL_Event event;

    GfxEngine& gfxengine = GfxEngine::getInstance();
    Input& input = Input::getInstance();

    Log::print(Log::INFO, "run scene");

    while (_exit == false) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return _nextScreen;
            } else {
                input.processEvent(event);
            }
        }

        if (input.getEnter(SDLK_ESCAPE)) {
            return _nextScreen;
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
