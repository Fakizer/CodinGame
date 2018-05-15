#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;

class   User {

public:
    double latitude;
    double longitude;

    User();
        
    User(string LAT, string LON);
        
    static double distance(const User& a, const User& b);
};
    

#endif