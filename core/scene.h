#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>
#include <functional>

class Entity;

template<typename T>
class Node {
public:
    Node(std::shared_ptr<T> data, std::shared_ptr<Node> parent)
    : _data(data)
    , _parent(parent) {

    }

    void add(std::shared_ptr<Node<T>> node) {
        _children.push_back(node);
    }

    std::shared_ptr<Entity> _data;
    std::shared_ptr<Node> _parent;
    std::vector<std::shared_ptr<Node<T>>> _children;
};

template<typename T>
class Tree {
public:
    void initialize(std::shared_ptr<T> root) {
        _root = std::make_shared<Node<T>>(root, nullptr);
    }

    void addNode(std::shared_ptr<T> data, std::shared_ptr<T> parent) {
        auto parentNode = findNode(parent);
        parentNode->add(std::make_shared<Node<T>>(data, parentNode));
    }

    std::shared_ptr<Node<T>> findNode(std::shared_ptr<T> data) {
        return doFindNode(data, _root);
    }

    template<typename F, typename C>
    void forEachIf(F function, C condition) {
        if (_root != nullptr && condition(_root->_data)) {
            doForEachIf(function, condition, _root);
        }
    }

private:
    std::shared_ptr<Node<T>> _root;

    std::shared_ptr<Node<T>> doFindNode(std::shared_ptr<T> data, std::shared_ptr<Node<T>> root) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->_data == data) {
            return _root;
        }

        for (auto& node : root->_children) {
            if (doFindNode(data, node) != nullptr) {
                return node;
            }
        }

        return nullptr;
    }

    template<typename F, typename C>
    void doForEachIf(F function, C condition, std::shared_ptr<Node<T>> node) {
        if (condition(node->_data)) {
            function(node->_data);
            for(auto child : node->_children) {
                doForEachIf(function, condition, child);
            }
        }
    }
};

class Scene {
public:
    Scene();

    void registerEntity(std::shared_ptr<Entity> entity, std::shared_ptr<Entity> parent = nullptr);

    Scene* run();
private:
    //std::vector<std::shared_ptr<Entity>> _objects;
    Tree<Entity> _objects;

    Scene *_nextScreen;
    bool _exit;
};

#endif // SCENE_H
