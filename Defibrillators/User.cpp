#include "User.hpp"

User::User() : longitude(0), latitude(0) {}

User::User(string LAT, string LON) {

    int pos = LAT.find(',');
    LAT[pos] = '.';
    pos = LON.find(',');
    LON[pos] = '.';

    latitude = stod(LAT);
    longitude = stod(LON);
}

double User::distance(const User& a, const User& b) {
    
    double x = (b.longitude - a.longitude) * cos((a.latitude + b.latitude) / 2);
    double y = b.latitude - a.latitude;
    double d = sqrt(pow(x,2) + pow(y,2)) * 6371;
    
    return d;
}