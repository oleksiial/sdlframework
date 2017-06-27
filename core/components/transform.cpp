#include "transform.h"
#include <cmath>

Transform::Transform(Container &container, float x, float y, float w, float h)
    : Component(container)
    , _childs()
    , _center(CenterPoint::center)
    , _rotationAngle(0)
    , _x(x)
    , _y(y)
    , _w(w)
    , _h(h){
    _componentType = ComponentType::transform;
    /*if (parent != nullptr) {
        parent->addChild(shared_from_this());
    }*/
}

void Transform::update() {

}

double angleToRadian(int angle) {
    return angle * (M_PI / 180.0);
}


Transform::Coord Transform::getScreenCoord(Coord coord) const {
    /*if (coord._x > _x + _w) {
        coord._x = _x + _w;
    } else if (coord._x < 0) {
        coord._x = 0;
    }

    if (coord._y > _y + _h) {
        coord._y = _y + _h;
    } else if (coord._y < 0) {
        coord._y = 0;
    }*/

//    if (_parent.lock() != nullptr) {
//        return _parent.lock()->getScreenCoord(coord + Coord(_x, _y));
//    } else {
//        int angle = getAngle();
//        /*return coord + Coord(
//            _x * std::cos(angleToRadian(angle)) - _y * std::sin(angleToRadian(angle)),
//            _x * std::sin(angleToRadian(angle)) + _y * std::cos(angleToRadian(angle))
//        );*/
//        return coord + Coord(_x, _y);
//    }
    return coord + Coord(_x, _y);
}

Transform::Coord Transform::getWidgetCoord(Coord coord) const {
//    if (_parent.lock() != nullptr) {
//        return _parent.lock()->getWidgetCoord(coord - Coord(_x, _y));
//    } else {
        return coord - Coord(_x, _y);
//    }
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
    _rotationAngle += angle;
    _rotationAngle %= 360;
    auto radian = angleToRadian(angle);

    for (auto child : _childs) {
        auto childTransform = child.lock();
        double centerX = _w / 2 - childTransform->getCenter().x;
        double centerY = _h / 2 - childTransform->getCenter().y;
        double x = childTransform->getX();
        double y = childTransform->getY();
        double newX = centerX +
            (x - centerX) * std::cos(radian) -
            (y - centerY) * std::sin(radian);
        double newY = centerY +
            (x - centerX) * std::sin(radian) +
            (y - centerY) * std::cos(radian);

        childTransform->setX(newX);
        childTransform->setY(newY);
    }
}

void Transform::setAngle(int angle) {
    _rotationAngle = angle;
    auto radian = angleToRadian(angle);
    for (auto child : _childs) {
        auto childTransform = child.lock();
        double centerX = _w / 2 - childTransform->getCenter().x;
        double centerY = _h / 2 - childTransform->getCenter().y;
        double x = childTransform->getX();
        double y = childTransform->getY();
        double newX = centerX +
            (x - centerX) * std::cos(radian) -
            (y - centerY) * std::sin(radian);
        double newY = centerY +
            (x - centerX) * std::sin(radian) +
            (y - centerY) * std::cos(radian);

        childTransform->setX(std::round(newX));
        childTransform->setY(std::round(newY));
    }
}












