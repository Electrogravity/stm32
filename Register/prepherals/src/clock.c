/*
 * clock.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Ali
 */


#include "clock.h"
static __IO uint32_t msticks=0;
void clock_config (void)
{

	 // stm32f4 clock is configured as follow (according to your project and device)
	  //	system clock source  = PLL (HSE)
	  //HSE frequency (Hz)     =8000000
	  //SYSCLK (Hz)            = 180000000
	  //HCLK (Hz)              = 180000000
	  //AHP Prescaler          = 1
	  //APB1 Prescaler         = 4
	  //APB2 Prescaler         = 2
	  //PLL_M                  = 4
      //PLL_N                  = 180
      //PLL_P                  = 2
    #define PLL_M  4
    #define PLL_P  0  // 2
    #define PLL_N 180


	//1 turn on the HSI and wait for HSI to be ready
	RCC->CR |= (1<<16);
	while (!(RCC->CR & (1<<16) ));

	//2 Enable power clock and voltage regulator
	RCC->APB1ENR |= (1<<28);
	PWR->CR |= (3<<14);    // or  PWR->CR |= (1<<14);  PWR->CR |= (1<<15);

   //3 flash latency and it's setting
	FLASH->ACR = (1<<8) | (1<<9) | (1<<10) | (3<<0);

    //4 AHB
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

	//5 APB1
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;

    //6 APB2
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;

	//7 configure the main pll
	RCC->PLLCFGR |= (PLL_M << 0) | (PLL_N << 6) | (PLL_P<<16) | (1<<22);

	//8 enable the pll and wait for flag to be ready
	RCC->CR |= (1<<24);
	while (!(RCC->CR & (1<<25)));

	//9 select the clock source and wait to be set
	RCC->CFGR |= (1<<1);
	while (!(RCC->CFGR & (1<<3)));

}

void clock_Systickconfig (uint32_t array)
{
	// 1 reset control register

 SysTick -> CTRL = 0;  // 0;	 reset

 //2 set reload value

 SysTick -> LOAD = array - 1 ;

 //3 set priority systick intrupt (NVIC)

 NVIC_SetPriority (SysTick_IRQn , 0);
 // 4 reset systick value to 0
 SysTick -> VAL = 0;

 // 5 enable systick
 SysTick -> CTRL |= SysTick_CTRL_CLKSOURCE_Msk;     // SysTick -> CTRL |=(1<<2 );
 SysTick -> CTRL |= SysTick_CTRL_TICKINT_Msk;       // SysTick -> CTRL |=(1<<1 );
 SysTick -> CTRL |= SysTick_CTRL_ENABLE_Msk;       // SysTick -> CTRL |=(1<<0 );
}


void clock_msinitticks (void){

	msticks++;
}
uint32_t  clock_msgetticks (void){

	 return msticks;
}
void clock_msdelay (uint32_t ms){
	uint32_t starticks = clock_msgetticks();
	while ((clock_msgetticks() - starticks ) < ms );

}

void systick_handeler (void){

	NVIC_ClearPendingIRQ (SysTick_IRQn);
	clock_msinitticks ();
}
