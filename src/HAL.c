#include "HAL.h"

#if (STM32F401 == 1)
/*************************************************************************************************************
 *                                  APIs supported by the driver
 *                                    the function definitions                         
 * 
****************************************************************************************************************/

/* ======================== GPIO APIs =============================*/


/*
 * Periphral Clock Setup
 */

/************************************************************************
 * @fn              -GPIO_PeriClockControl
 * 
 * @brief            - This function use to enable OR disable clock for GPIO PORT
 * @Param[in]        -  Base address of GPIO Peripheral.{GPIOA,GPIOB, GPIOC, GPIOD, GPIOE, GPIOH}
 * @Param[in]        -  ENABLE or DISABLE Macro
 *
 * 
 * @return           -  None
 *  
 * @Note             -  None
 * 
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)

{
    if(EnorDi == ENABLE){
        if(pGPIOx == GPIOA){
             GPIOA_PCLK_EN();
        }else if(pGPIOx == GPIOB){
            GPIOB_PCLK_EN();
        }else if(pGPIOx == GPIOC){
            GPIOC_PCLK_EN();
        }else if(pGPIOx == GPIOD){
            GPIOD_PCLK_EN();
        }else if(pGPIOx == GPIOE){
            GPIOE_PCLK_EN();
        }else if(pGPIOx == GPIOH){
            GPIOH_PCLK_EN();
        }
    }else{
        if(pGPIOx == GPIOA){
            GPIOA_PCLK_DI();
        }else if(pGPIOx == GPIOB){
            GPIOB_PCLK_DI();
        }else if(pGPIOx == GPIOC){
            GPIOC_PCLK_DI();
        }else if(pGPIOx == GPIOD){
            GPIOD_PCLK_DI();
        }else if(pGPIOx == GPIOE){
            GPIOE_PCLK_DI();
        }else if(pGPIOx == GPIOH){
            GPIOH_PCLK_DI();
        }

    }

}



/*
 * Intializion & Deintializing GPIO
 */

/************************************************************************
 * @fn              -GPIO_Init
 * 
 * @brief            - This function use to initialazing port  
 * @Param[in]        -  Configration .{mode,speed, pull up /pull down, alt_function}
 *
 * 
 * @return           -  None
 *  
 * @Note             -  None
 * 
 */

void GPIO_INIT(GPIO_Handle *pGPIO_Handle)
{
    uint32_t temp = 0;
    //1. Configure the mode of gpio pin
    if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
        // non intruppt mode
        temp = (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
        pGPIO_Handle->pGPIOx->MODER &= ~(0x3 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);                                           /*<It's clearing two bits before writing on it>*/
        pGPIO_Handle->pGPIOx->MODER |= temp;

    }else{
	// interrupt mode
    	    if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT){
				EXTI->FTSR |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
				EXTI->RTSR &= ~(1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
			}else if (pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT){
				EXTI->RTSR |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
				EXTI->FTSR &= ~(1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
			}else if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode ==GPIO_MODE_IT_RFT){
				EXTI->FTSR |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
				EXTI->RTSR |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
			}

			uint8_t temp1 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber / 4;
			uint8_t temp2 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber % 4;
			uint8_t PORTCODE = GPIO_BASE_ADDR_TO_CODE(pGPIO_Handle->pGPIOx);
			SYSCFG->EXTICR[temp1] = PORTCODE << (temp2 * 4);                                                                            /*<It is GPIO port output @GPIO_PIN_SPEED register   >*/

			EXTI->IMR |= 1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber;
    	    }

    temp = 0;

    // configure the speed
    temp = (pGPIO_Handle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIO_Handle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);                                          /*<It's clearing two bits before writing on it>*/
    pGPIO_Handle->pGPIOx->OSPEEDR |= temp;
    temp = 0;

    //3. configration the pupd
    temp = (pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIO_Handle->pGPIOx->PUPDR &= ~(0x3 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);                                            /*<It's clearing two bits before writing on it>*/
    pGPIO_Handle->pGPIOx->PUPDR |= temp;

    //4. configuration the optype.
    temp = 0; 
    temp = (pGPIO_Handle->GPIO_PinConfig.GPIO_PinOPType << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIO_Handle->pGPIOx->OTYPER &= ~(0x1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);                                           /*<It's clearing two bits before writing on it>*/
    pGPIO_Handle->pGPIOx->OTYPER |= temp;

    // 5. configure the alt function reg
    if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
        uint8_t temp1, temp2;
        temp1 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber / 8;
        temp2 = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber % 8;
        pGPIO_Handle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));                                                                   /*<It's clearing two bits before writing on it>*/
        pGPIO_Handle->pGPIOx->AFR[temp1] |= (pGPIO_Handle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));

    }
}


void GPIO_DE_INIT(GPIO_RegDef_t *pGPIOx)
{
   
    if(pGPIOx == GPIOA){
       GPIOA_PCLK_DI();
    }else if(pGPIOx == GPIOB){
        GPIOB_PCLK_DI();
    }else if(pGPIOx == GPIOC){
        GPIOC_PCLK_DI();
    }else if(pGPIOx == GPIOD){
        GPIOD_PCLK_DI();
    }else if(pGPIOx == GPIOE){
        GPIOE_PCLK_DI();
    }else if(pGPIOx == GPIOH){
        GPIOH_PCLK_DI();
    }
}


/*
 * Read & Write GPIO pin & port
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)  ((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}



uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t) pGPIOx->IDR ;
	return value;
}



void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if (Value == 1){
		pGPIOx->ODR |= (1<<PinNumber);
	}else{
		pGPIOx->ODR &= ~(1<<PinNumber);
	}
}


void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}


void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1<< PinNumber);
}


/*
 *  IRQ configration and ISR handling 
 */
void GPIO_IRQConfig(uint8_t GPIO_IRQNumber, uint8_t IRQPriorty, uint8_t EnorDi)
{
    if(EnorDi == ENABLE){
        if(GPIO_IRQNumber <= 31){
            *NVIC_ISER0 |= 1<<  (GPIO_IRQNumber);
        }else if(GPIO_IRQNumber > 31 && GPIO_IRQNumber <= 64){
            *NVIC_ISER1 |= 1<<  (GPIO_IRQNumber % 32);
        }else if(GPIO_IRQNumber > 64 && GPIO_IRQNumber <= 96)
            *NVIC_ISER2 |= 1<<  (GPIO_IRQNumber % 32);
    }else{
        if(GPIO_IRQNumber <= 31){
            *NVIC_ICER0 |= 1<<  (GPIO_IRQNumber);
        }else if(GPIO_IRQNumber > 31 && GPIO_IRQNumber <= 64){
            *NVIC_ICER1 |= 1<<  (GPIO_IRQNumber % 32);
        }else if(GPIO_IRQNumber > 64 && GPIO_IRQNumber <= 96)
            *NVIC_ICER2 |= 1<<  (GPIO_IRQNumber % 32);
    }

    uint8_t iprx = GPIO_IRQNumber/ 4;
    uint8_t iprx_section =  GPIO_IRQNumber % 4;
    uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
    *( (iprx*4) + NVIC_PR_BASE_ADDR) |= (IRQPriorty << shift_amount);
}


void GPIO_Handling(uint8_t PinNumber)
{
    if(EXTI-> PR & (1 << PinNumber)){
        EXTI->PR |= (1 << PinNumber);
    }
}


#endif/*END STM32F401*/