#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <SDL2/SDL.h>
#include "component.h"
#include <vector>
#include <memory>

class Transform : public Component {
public:
    enum class CenterPoint { leftUp, up, rightUp, left, center, right, leftDown, down, rightDown };
    struct Coord {
        Coord(float x, float y) : _x(x), _y(y) {}
        Coord operator+(const Coord& c) { return Coord(_x + c._x, _y + c._y); }
        Coord operator-(const Coord& c) { return Coord(_x - c._x, _y - c._y); }

        float _x;
        float _y;
    };

    Transform(Container& container, float x, float y, float w, float h);

    void update() override;

    Coord getScreenCoord(Coord coord) const;

    SDL_Rect getScreenRect() const;
    int getAngle() const;
    bool isMouseOver(int x, int y) const;

    float getX() const { return _x; }
    float getY() const { return _y; }
    float getW() const { return _w; }
    float getH() const { return _h; }
    SDL_Rect getRect() const {
        return {
            static_cast<int>(_x),
            static_cast<int>(_y),
            static_cast<int>(_w),
            static_cast<int>(_h)
        };
    }

    SDL_Point getCenter() const;

    void setX(float value) { _x = value; }
    void setY(float value) { _y = value; }
    void setW(float value) { _w = value; }
    void setH(float value) { _h = value; }

    void setCenterPoint(CenterPoint center) { _center = center; }
    void move(float dx, float dy) { _x += dx; _y += dy; }
    void rotate(int angle);
    void setAngle(int angle);
private:
    CenterPoint _center;
    int _rotationAngle;
    float _x;
    float _y;
    float _w;
    float _h;
};

#endif
