#include "Defibrilateur.hpp"

Defibrilateur::Defibrilateur(string DEFIB) {

    vector<string> fields;
    stringstream ss(DEFIB);
    string field;
    
    while (getline(ss, field, ';')) {
        fields.push_back(field);
    }
    

    this->id = fields[0];
    this->name = fields[1];
    this->address = fields[2];
    this->tel = fields[3];
    string longitude = fields[4];
    string latitude = fields[5];
    User p(latitude, longitude);
    this->loc = p;
}
