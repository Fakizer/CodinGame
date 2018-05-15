#ifndef DEFIBRILATEUR_HPP
#define DEFIBRILATEUR_HPP

#include "User.hpp"

class Defibrilateur {
    
public:
    Defibrilateur(string DEFIB);
    string id, name, address, tel;
    User loc;
};

#endif