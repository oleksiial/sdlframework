#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

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
    if(SDL_Init(SDL_INIT_VIDEO) == 0) {
        _window = SDL_CreateWindow("My window", 300, 50, 720, 480, SDL_WINDOW_SHOWN);
        if (_window != nullptr) {
            _renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (_renderer == nullptr) {
                std::cout << "Cannot create renderer\n";
                return false;
            }
            if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
                std::cout<<"Cannot init img\n";
                return false;
            }
            if (TTF_Init() < 0) {
                std::cout << "Cannot init font\n";
                return false;
            }
        } else {
            std::cout << "Cannot create window\n";
            return false;
        }
    } else {
        std::cout << "Cannot init sdl\n";
        return false;
    }

    SDL_SetRenderDrawColor(_renderer, 200, 200, 0, 255);

    return true;
}

void GfxEngine::loadResources(const ResourcePreloadHolder& resourcePreloadHolder) {
    ResourceLoader resourceLoader(_renderer);

    const auto& images = resourcePreloadHolder.getImages();

    for (const std::pair<std::string, std::string>& image : images) {
        resourceLoader.loadImage(image.first, image.second);
    }
}

void GfxEngine::free() {
    for (auto& image: ResourceContainer::imageContainer) {
        SDL_DestroyTexture(image.second);
    }

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
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
