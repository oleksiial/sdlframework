#include "sprite.h"

#include "../../gfxengine/resourcecontainer.h"

Sprite::Sprite(Container &container, const std::string &textureId)
    : Component(container)
    , _textureId(textureId){
    _componentType = ComponentType::sprite;
}

void Sprite::update() {

}

SDL_Texture *Sprite::getTexture() const {
    return ResourceContainer::imageContainer[_textureId];
}
