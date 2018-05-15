#include "Nodes.hpp"

Nodes::Nodes() {}

Nodes::Nodes(int width, int height, int x1, int y1) : width(width), height(height), x1(x1), y1(y1) {}

void    Nodes::search_node2(vector<string> str) {
    for (int i = x1 + 1; i < width + 1; i++) {
        if (i != width && str[y1][i] == '0') {
            x2 = i;
            y2 = y1;
            break ;
        }
        else
            x2 = y2 = -1;
    }
}

void    Nodes::search_node3(vector<string> str) {
    for (int i = y1 + 1; i < height + 1; i++) {
        if (i != height && str[i][x1] == '0') {
            y3 = i;
            x3 = x1;
            break ;
        }
        else
            y3 = x3 = -1;
    }
}

void    Nodes::nodes_out() {
    cout << x1 << " " << y1 << " ";
    cout << x2 << " " << y2 << " ";
    cout << x3 << " " << y3 << endl;
}
