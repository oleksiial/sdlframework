#ifndef RESOURCECONTAINER_H
#define RESOURCECONTAINER_H

#include <map>

class SDL_Texture;

class ResourceContainer {
public:
    static std::map<std::string, SDL_Texture*> imageContainer;
};

#endif // RESOURCECONTAINER_H
