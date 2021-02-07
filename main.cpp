#include "port.hpp"
#include "pin.hpp"
#include "gpiocregisters.hpp"
#include "gpioaregisters.hpp"
#include "rccregisters.hpp"
#include <cstdint>
#include "tim5registers.hpp"
#include <iostream>
#include <bitset>
#include "led.hpp"
#include "button.hpp"
#include "garlands.hpp"
#include "nvicregisters.hpp"

extern "C"
{
  int __low_level_init(void)
  {
    RCC::CR::HSEON::On::Set();
    while (!RCC::CR::HSERDY::Ready::IsSet())
    {
    }
    RCC::CFGR::SW::Hse::Set();
    while (!RCC::CFGR::SWS::Hse::IsSet())
    {
    }
    RCC::CR::HSION::Off::Set();                                                 //Отключаем внешний источник тактирования
    RCC::AHB1ENR::GPIOCEN::Enable::Set();                                       
    RCC::AHB1ENR::GPIOAEN::Enable::Set();
    GPIOC::MODER::MODER5::Output::Set();                                        //Светодиоды на выход
    GPIOA::MODER::MODER5::Output::Set();
    GPIOC::MODER::MODER9::Output::Set();                                        
    GPIOC::MODER::MODER8::Output::Set();                                        
    GPIOC::MODER::MODER13::Input::Set();            //Таймер на вход                            //Кнопка на выход
                                            
    
    RCC::APB1ENR::TIM5EN::Enable::Set();
    
    TIM5::PSC::Write(7999U);
    TIM5::ARR::Write(50U);
    TIM5::CNT::Write(0U);
    NVIC::ISER1::Write(1U << 18U);
    TIM5::DIER::UIE::Value1::Set();
    TIM5::SR::UIF::NoInterruptPending::Set();
     
    
    
    return 1;
  }
}


Pin buttonPin(13, PortC);


Button button(buttonPin);
Garlands<void> garlands(button);

int main()
{
  TIM5::CR1::CEN::Enable::Set();
  for(;;)
  {
 
  std::cout <<"Статус кнопки: " <<  button.IsPressed() << std::endl;
  }
  return 0;
}
