#include "resourceloader.h"
#include "resourcecontainer.h"
#include "../utilities/log.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

ResourceLoader::ResourceLoader(SDL_Renderer *renderer)
    : _renderer(renderer) {

}

void ResourceLoader::loadImage(const std::string& path, const std::string& id) const {
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        Log::print(Log::INFO, "Cannot find the image: ", path.c_str());
        return;
    }

    SDL_Texture *_texture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);

    SDL_FreeSurface(loadedSurface);
    if (_texture == nullptr) {
        Log::print(Log::INFO, "Cannot create texture: ", SDL_GetError());
        return;
    }

    ResourceContainer::imageContainer[id] = _texture;
}
