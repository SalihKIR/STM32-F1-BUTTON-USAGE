#include "stm32f10x.h"// Device header
int button=0;
int sayac=0;
int flag=0;

void sistemayr(){
	GPIO_InitTypeDef GPIOInitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	//LED
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOInitStructure);
	
	//Button
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_Init(GPIOC,&GPIOInitStructure);

}
void Delay(uint32_t time){
	while(time--);
}
int main(){
sistemayr();
while(1){
button=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
	//while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)!=0);
	if(button==1){
		sayac++;
			if(flag==0){
					flag=1;
					GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
			}else{
				flag=0;
				GPIO_ResetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
				sayac=0;
			}
			Delay(3600000);
	}
}
}
