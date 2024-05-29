#pragma once
#pragma once
#include "Animal.h"
class Shark:
    public Animal
{
    std::string GetName()
    {
        std::string Name = "Shark";
        return Name;
    }
    bool IsAFish() {

        return true;
    }
    bool IsAMammal()
    {
        return false;
    }
    bool IsABird()
    {
        return false;
    }
};

