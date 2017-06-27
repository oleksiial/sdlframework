#include "resourceloader.h"
#include "resourcecontainer.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

ResourceLoader::ResourceLoader(SDL_Renderer *renderer)
    : _renderer(renderer) {

}

void ResourceLoader::loadImage(const std::string& path, const std::string& id) const {
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        std::cout << "Cannot find the image: " << path.c_str() << std::endl;
        return;
    }

    SDL_Texture *_texture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);

    SDL_FreeSurface(loadedSurface);
    if (_texture == nullptr) {
        std::cout << "Cannot create texture";
        return;
    }

    ResourceContainer::imageContainer[id] = _texture;
}
