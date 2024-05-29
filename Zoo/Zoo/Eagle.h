#pragma once
#include "Animal.h"
class Eagle :
    public Animal
{
    std::string GetName()
    {
        std::string Name = "Eagle";
        return Name;
    }
    bool IsAFish() {

        return false;
    }
    bool IsAMammal()
    {
        return false;
    }
    bool IsABird()
    {
        return true;
    }
};

