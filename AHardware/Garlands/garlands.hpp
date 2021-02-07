#pragma once
#include <cstdint> //??? ???32, ???8
#include <cassert>
#include "led.hpp"
#include "button.hpp"
#include <array>
#include "pinscfg.h"

template <typename Timer>
class Garlands  
{
  public:
    Garlands(Button& aButton): button(aButton), leds{
                                                     Led(led1Pin),
                                                     Led(led2Pin),
                                                     Led(led3Pin),
                                                     Led(led4Pin)
                                                     }
    {
     }
    void Update() 
    {
      
    }
    
    void HandleInterrupt() 
    {
      leds[i++ & 0x3].Toggle();
      
    }
private: 
   std::array<Led, 4> leds;
   Button& button;
   int i = 0;
};