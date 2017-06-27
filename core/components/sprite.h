#ifndef SPRITE_H
#define SPRITE_H

#include "component.h"
#include <string>

struct SDL_Texture;

class Sprite : public Component {
public:
    Sprite(Container& container, const std::string& textureId);
    void update() override;
    SDL_Texture* getTexture() const;
private:
    std::string _textureId;
};

#endif
