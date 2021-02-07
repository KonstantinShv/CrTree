#pragma once
#include "pin.hpp"

class Led
{
  public:
    Led(IPinToggle& aPin): pin(aPin)
    {
      
    }
    void Toggle()
    {
      pin.Toggle();
    }
  private: 
     IPinToggle& pin;
     
};