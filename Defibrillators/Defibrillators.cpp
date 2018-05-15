
#include "Defibrilateur.hpp"

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define RAD = M_PI / 180;
 
int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    
    User user(LAT, LON);
    
    int N;
    cin >> N; cin.ignore();
    
    vector<Defibrilateur*> d;
    
    // cerr << LON << " " << LAT << N << endl << endl;
    
    
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
       
        d.push_back(new Defibrilateur(DEFIB));
       
    }
    
    double min = -1;
    string addr;
    
    for (int i = 0; i < N; i++) {
        double dist = user.distance(user, d[i]->loc);
        
        if((min == -1) or (dist < min)) {
            min = dist;
            addr = d[i]->name;
        }
    }
    
    cout << addr << endl;
    
    for (int i = 0; i < N; i++) 
        delete d[i];
    
    return 0;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


}