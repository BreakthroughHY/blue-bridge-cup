#pragma once

#ifndef __CLONE_GRAPH_H__
#define __CLONE_GRAPH_H__

#include <unordered_map>
#include <queue>
#include "main.h"

// ÀàÉùÃ÷
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class SolutionCloneGraph {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node);

    Node* cloneGraph_(Node* node);
};

int cloningFigure();

#endif // !__CLONE_GRAPH_H__
