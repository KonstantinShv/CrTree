#pragma once
#include "port.hpp"

class IPinToggle
{
  public:
    virtual void Toggle() = 0;
};

class IPinGet 
{
  public:
      virtual bool IsSet() = 0;
};

class Pin: public IPinToggle, public IPinGet
{
public:
  Pin(std::uint8_t num, IPort& aPort): number(num),  port(aPort)
    {
      
    }
  void Toggle() override
  {
    port.Toggle(number);
  }
  
  bool IsSet() override
  {
    return ((port.Get() & (1 << number)) != 0U);
  }
private: 
  std::uint8_t number;
  IPort& port;
};