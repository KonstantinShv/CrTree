#pragma once
#include "pin.hpp"

class Button
{
  public:
    Button(IPinGet& aButton): pin(aButton)
    {
      
    }
    bool IsPressed()
    {      
      return (!pin.IsSet());
    }
  private: 
     IPinGet& pin;
     
};