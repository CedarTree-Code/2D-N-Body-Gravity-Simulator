#pragma once

#include <SFML/Graphics.hpp>

#include "const.h"

using namespace sf;

class Node {
    std::vector<int> indices;
    int lvl;
    float size;
    Vector2f midpoint;
    bool has_subnodes;
    Node* subnode[4];

    public:
    Node(float s, Vector2f midpt, int n = 0, int l = 0);
    void make(std::vector<Vector2f> points);
    void draw(RenderWindow& window);
};