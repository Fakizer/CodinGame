#ifndef NODES_HPP
#define NODES_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class   Nodes {
public:
    int x1, x2, x3;
    int y1, y2, y3;
    int width, height;
    
    Nodes();
    Nodes(int width, int height, int x1, int y1);
    
    void    search_node2(vector<string> str);
    void    search_node3(vector<string> str);
    
    void    nodes_out();
    
};

#endif