#pragma once
#include "Feline.h"
class Tiger:
    public Feline
{
    std::string GetName()
    {
        std::string Name = "Tiger";
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
        int speed = 80;
        return speed;
    }
};

