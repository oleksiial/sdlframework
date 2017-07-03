#include "sprite.h"

#include "../../gfxengine/resourcecontainer.h"

Sprite::Sprite(Entity &entity, const std::string &textureId)
    : Component(entity)
    , _textureId(textureId){
    _componentType = ComponentType::sprite;
}

void Sprite::update() {

}

SDL_Texture *Sprite::getTexture() const {
    return ResourceContainer::imageContainer[_textureId];
}
