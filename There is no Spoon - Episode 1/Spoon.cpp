#include "Nodes.hpp"

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    // int nb_nodes;
    vector<string> str;
    
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        str.push_back(line);
        // for (int j = 0; j < line.size(); j++)
        //     if (line[i] == '0')
        //         nb_nodes++;
    }
    
    // Nodes *Spoon = new Nodes[nb_nodes];
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (str[i][j] == '0') {
                Nodes *Spoon = new Nodes(width, height, j, i);
                Spoon->search_node2(str);
                Spoon->search_node3(str);
                Spoon->nodes_out();
            }
        }
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    // cout << "0 0 1 0 0 1" << endl;
}