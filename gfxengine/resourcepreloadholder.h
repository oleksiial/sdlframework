#ifndef RESOURCEPRELOADHOLDER_H
#define RESOURCEPRELOADHOLDER_H

#include <vector>

class ResourcePreloadHolder {
public:
    void addImage(const std::string& path, const std::string& id) { _images.emplace_back(path, id); }
    const auto& getImages() const { return _images; }
private:
    std::vector<std::pair<std::string, std::string>> _images;
};

#endif
