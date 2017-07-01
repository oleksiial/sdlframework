#ifndef INPUT_H
#define INPUT_H

#include <functional>

union SDL_Event;

struct MousePos {
    int x;
    int y;
};

class Input {
public:
    static Input& getInstance();
    ~Input();

    void processEvent(const SDL_Event& event);
    bool get(int id) const;
    bool getEnter(int id) const;
    bool getLeave(int id) const;
    const MousePos& getMousePos() const;
    void endFrame();
private:
    Input();

    MousePos _mousePos;
    bool _keyboard[255];
    bool _keyboardEnter[255];
    bool _keyboardLeave[255];
};



#endif // INPUT_H
