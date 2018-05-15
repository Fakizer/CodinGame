

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 #include "VirusDefender.hpp"

int main() {
    auto* virus = new VirusDefender();
    
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        cerr << N1 << " " << N2 << "||";
        virus->addLink(N1, N2);
    }
    cerr << endl;
    vector<int> exits;
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        virus->setGatewayTo(EI);
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        
        cout << virus->setVirusTo(SI) << endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        // cout << "0 1" << endl;
        // cout << "2 3" << endl;
    }
}