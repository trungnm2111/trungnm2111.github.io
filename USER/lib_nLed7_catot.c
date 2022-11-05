#include "stm32f10x.h"                  // Device header
#include "lib_nLed7.h"

unsigned int chusoK[4]; 
unsigned int maQuetK[] = {0xfffe , 0xfffd , 0xfbff , 0xf7ff };
unsigned char soK[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void tachChuSoK(unsigned long temp, int soled)
{
	int i;
	for(i=0 ; i< soled ; i++ )// 
	{
		chusoK[i] = temp%10;
		temp = temp /10;
	}
}

void quetLedK(int soled)
{
	int i, j;
	for(i =0 ; i< 10; i++) // toc do thay doi gt 1 led
	{
		for(j = 0; j < soled ; j++) // quet led 
		{	
			GPIOB->ODR = 0xffff;
			GPIOB->ODR = maQuetK[j];		 		// cong b lam nv quet led 
			GPIOA->ODR = soK[chusoK[j]];		 // so duoc quet truyen cho cong a;	
			delay(1);
		}
	}	
}

int demk;
void run_catot(void)
{
	for(demk =0; demk <9999; demk++)
	{
		tachChuSoK(demk, 4);
		quetLedK(4);
	}
}