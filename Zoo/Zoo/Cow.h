#pragma once
#include "Animal.h"
class Cow :
    public Animal
{
    std::string GetName() 
    {
        std::string Name = "Cow";
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
};

