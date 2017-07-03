#include "transform.h"
#include "../entity.h"
#include <cmath>

Transform::Transform(Entity &entity, float x, float y, float w, float h)
    : Component(entity)
    , _center(CenterPoint::center)
    , _rotationAngle(0)
    , _x(x)
    , _y(y)
    , _w(w)
    , _h(h) {
    _componentType = ComponentType::transform;

//    const auto parent = entity.getParent();

//    if (parent != nullptr) {
//        parent->addChild(shared_from_this());
//    }
}

void Transform::update() {

}

Transform::Coord Transform::getScreenCoord(Coord coord) const {
//    if (_parent.lock() != nullptr) {
//        return _parent.lock()->getScreenCoord(coord + Coord(_x, _y));
//    } else {
//        return coord + Coord(_x, _y);
//    }
    return coord + Coord(_x, _y);
}

SDL_Rect Transform::getScreenRect() const {
    SDL_Rect r;
    Coord c = getScreenCoord(Coord(0, 0));
    r.x = c._x;
    r.y = c._y;
    r.w = _w;
    r.h = _h;
    return r;
}

int Transform::getAngle() const {
//    if (_parent.lock() != nullptr) {
//        return _parent.lock()->getAngle() + _rotationAngle;
//    } else {
//        return _rotationAngle;
//    }
    return _rotationAngle;
}

bool Transform::isMouseOver(int x, int y) const {
    const SDL_Rect& rect = getScreenRect();
    return x >= rect.x &&
        x <= rect.x + rect.w &&
        y >= rect.y &&
        y <= rect.y + rect.h;
}

SDL_Point Transform::getCenter() const {
    SDL_Point center;
    center.x = _w / 2;
    center.y = _h / 2;
    return center;
}

void Transform::rotate(int angle) {
//    _rotationAngle += angle;
//    _rotationAngle %= 360;
//    auto radian = angleToRadian(angle);

//    for (auto child : _childs) {
//        auto childTransform = child.lock();
//        double centerX = _w / 2 - childTransform->getCenter().x;
//        double centerY = _h / 2 - childTransform->getCenter().y;
//        double x = childTransform->getX();
//        double y = childTransform->getY();
//        double newX = centerX +
//            (x - centerX) * std::cos(radian) -
//            (y - centerY) * std::sin(radian);
//        double newY = centerY +
//            (x - centerX) * std::sin(radian) +
//            (y - centerY) * std::cos(radian);

//        childTransform->setX(newX);
//        childTransform->setY(newY);
//    }
}

void Transform::setAngle(int angle) {
//    _rotationAngle = angle;
//    auto radian = angleToRadian(angle);
//    for (auto child : _childs) {
//        auto childTransform = child.lock();
//        double centerX = _w / 2 - childTransform->getCenter().x;
//        double centerY = _h / 2 - childTransform->getCenter().y;
//        double x = childTransform->getX();
//        double y = childTransform->getY();
//        double newX = centerX +
//            (x - centerX) * std::cos(radian) -
//            (y - centerY) * std::sin(radian);
//        double newY = centerY +
//            (x - centerX) * std::sin(radian) +
//            (y - centerY) * std::cos(radian);

//        childTransform->setX(std::round(newX));
//        childTransform->setY(std::round(newY));
//    }
}












