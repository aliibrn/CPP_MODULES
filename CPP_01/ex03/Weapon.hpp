#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;
    public:
        Weapon();
        Weapon(const std::string &input_type);
        const std::string &getType()const;
        void    setType(const std::string &type);
};


#endif