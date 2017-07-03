#ifndef GFXENGINE_H
#define GFXENGINE_H

class SDL_Window;
class SDL_Renderer;

class Transform;
class Sprite;
class ResourcePreloadHolder;

class GfxEngine {
public:
    static GfxEngine& getInstance();
    ~GfxEngine();

    bool init();
    void loadResources(const ResourcePreloadHolder& resourcePreloadHolder);

    void startFrame();
    void drawSprite(const Sprite *sprite, const Transform *transform);
    void endFrame();
private:
    GfxEngine();

    SDL_Window *_window;
    SDL_Renderer *_renderer;
};

#endif // GFXENGINE_H
