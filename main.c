#include <stdint.h>

#define  RCC_AHB1ENR        *((volatile uint32_t*)0x40023830)
#define  GPIOA_MODER        *((volatile uint32_t*)0x40020000)
#define  GPIOA_ODR          *((volatile uint32_t*)0x40020014)

int main(void)
{
	// Enable Clock GPIOA 	(RCC->AHB1ENR)
     RCC_AHB1ENR |= (1<<0);
	// PA5 Output			(GPIOA->MODER)
    GPIOA_MODER |= (1<<10);

	while(1){
		for(uint32_t i = 0 ; i<100000; i++);
		// Toggle PA5		(GPIOA->ODR)	
      GPIOA_ODR  ^=(1<<5); 

	}
}