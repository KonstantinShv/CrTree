#pragma once
#include "port.hpp"
#include "pin.hpp"
#include "gpiocregisters.hpp"
#include "gpioaregisters.hpp"
#include "led.hpp"

inline Port<GPIOC> PortC;                                                              //????????  ??????? ?????? ????
inline Port<GPIOA> PortA;

inline Pin led1Pin(5, PortC);

inline Pin led2Pin(8, PortC);
inline Pin led3Pin(9, PortC);
inline Pin led4Pin(5, PortA);