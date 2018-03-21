#include "picture.h"

#include "../core/components/sprite.h"
#include "../core/components/transform.h"

Picture::Picture(const std::string& image, Scene& scene, std::shared_ptr<const Entity> parent)
    : Entity(scene, parent) {
    addComponent(std::make_shared<Sprite>(*this, image));
    addComponent(std::make_shared<Transform>(*this, 0, 0, 100, 100));
}

void Picture::update() {

}

void Picture::setTransform(float x, float y, float w, float h) {
    auto transform = getComponent<Transform>(Component::ComponentType::transform);
    transform->setX(x);
    transform->setY(y);
    transform->setW(w);
    transform->setH(h);
}
