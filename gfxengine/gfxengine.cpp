#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "../utilities/log.h"

#include "gfxengine.h"

#include "resourceloader.h"
#include "resourcepreloadholder.h"
#include "resourcecontainer.h"

#include "../core/components/sprite.h"
#include "../core/components/transform.h"

GfxEngine::GfxEngine()
    : _window(nullptr)
    , _renderer(nullptr) {

}

GfxEngine & GfxEngine::getInstance() {
    static GfxEngine instance;
    return instance;
}

bool GfxEngine::init() {
    Log::print(Log::INFO, "start initialization\n");
    if(SDL_Init(SDL_INIT_VIDEO) == 0) {
        _window = SDL_CreateWindow("My window", 300, 50, 720, 480, SDL_WINDOW_SHOWN);
        if (_window != nullptr) {
            _renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (_renderer == nullptr) {
                Log::print(Log::ERROR, "Cannot create renderer:\n", SDL_GetError());
                return false;
            }
            if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
                Log::print(Log::ERROR, "Cannot init img:", SDL_GetError());
                return false;
            }
            if (TTF_Init() < 0) {
                Log::print(Log::ERROR, "Cannot init fonts:", SDL_GetError());
                return false;
            }
        } else {
            Log::print(Log::ERROR, "Cannot create window:", SDL_GetError());
            return false;
        }
    } else {
        Log::print(Log::ERROR, "Cannot init sdl:", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(_renderer, 200, 200, 0, 255);
    Log::print(Log::INFO, "initialization complete");
    return true;
}

void GfxEngine::loadResources(const ResourcePreloadHolder& resourcePreloadHolder) {
    Log::print(Log::INFO, "load resources");
    ResourceLoader resourceLoader(_renderer);

    const auto& images = resourcePreloadHolder.getImages();

    for (const std::pair<std::string, std::string>& image : images) {
        resourceLoader.loadImage(image.first, image.second);
    }
    Log::print(Log::INFO, "load resources completed");
}

void GfxEngine::free() {
    Log::print(Log::INFO, "free resources");
    for (auto& image: ResourceContainer::imageContainer) {
        SDL_DestroyTexture(image.second);
    }

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    Log::print(Log::INFO, "free resources completed, bye");
}

void GfxEngine::startFrame() {
    SDL_RenderClear(_renderer);
}

void GfxEngine::drawSprite(const Sprite *sprite, const Transform *transform) {
    SDL_Texture *texture = sprite->getTexture();
    if (texture != nullptr) {
        SDL_Rect r = transform->getScreenRect();
        SDL_RenderCopy(_renderer, texture , nullptr, &r);
    }
}

void GfxEngine::endFrame() {
    SDL_RenderPresent(_renderer);
}
