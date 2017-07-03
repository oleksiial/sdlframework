#ifndef PICTURE_H
#define PICTURE_H

#include "../core/entity.h"

class Picture : public Entity {
public:
    Picture(const std::string &image, Scene& scene, const Entity *parent = nullptr);

    void update() override;

    void setTransform(float x, float y, float w, float h);
};
#endif // PICTURE_H
