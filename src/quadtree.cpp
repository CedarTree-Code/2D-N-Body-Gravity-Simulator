#include "quadtree.h"

Node::Node(float s, Vector2f midpt, int n, int l) {
    size = s; lvl = l; 
    midpoint = midpt;
    indices.reserve(n);
    for(int i=0; i<n; i++) 
        indices.push_back(i);
    has_subnodes = false;
}

void Node::make(std::vector<Vector2f> things) {
    has_subnodes = true;
    subnode[0] = new Node(size/2, Vector2f(midpoint.x - size/4, midpoint.y - size/4), 0, lvl+1);
    subnode[1] = new Node(size/2, Vector2f(midpoint.x + size/4, midpoint.y - size/4), 0, lvl+1);
    subnode[2] = new Node(size/2, Vector2f(midpoint.x - size/4, midpoint.y + size/4), 0, lvl+1);
    subnode[3] = new Node(size/2, Vector2f(midpoint.x + size/4, midpoint.y + size/4), 0, lvl+1);

    for(int i : indices) {
        int k=0;
        if(things[i].x > midpoint.x) ++k;
        if(things[i].y > midpoint.y) ++++k; 
        subnode[k]->indices.push_back(i);
    }

    for(int i=0; i<4; i++) 
        if (subnode[i]->indices.size() > MAX_PER_NODE_COUNT)
            subnode[i]->make(things);
}

void Node::draw(RenderWindow& window) {

    RectangleShape box({size, size});
    box.setOrigin({size/2, size/2});
    box.setFillColor(Color::Transparent);
    box.setOutlineThickness(-BOX_THICKNESS);

    box.setPosition({midpoint.x, midpoint.y});
    window.draw(box);

    if(has_subnodes == true)
        for(int i=0; i<4; i++) 
            subnode[i]->draw(window);
}
