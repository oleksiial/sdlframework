#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <string>
class SDL_Renderer;

class ResourceLoader {
public:
    ResourceLoader(SDL_Renderer *renderer);
    void loadImage(const std::string& path, const std::string& id) const;
private:
    SDL_Renderer *_renderer;
};

#endif // RESOURCELOADER_H
