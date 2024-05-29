#pragma once
#include "Feline.h"
class Lion :
    public Feline
{
    std::string GetName()
    {
        std::string Name = "Lion";
        return Name;
    }
    bool IsAFish() {

        return false;
    }
    bool IsAMammal()
    {
        return true;
    }
    bool IsABird()
    {
        return false;
    }
    int GetSpeed() {
        int speed = 75;
        return speed;
    }
};

