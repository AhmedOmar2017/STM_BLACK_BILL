#ifndef HAL_H_
#define HAL_H_

#include "Mcal.h"

#if (STM32F401 == 1)

/*============================= This is Configration Structure For a GPIO PIN ==========================*/
typedef struct 
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;                               /*<It is GPIO port mode register  @GPIO_PIN_MODES    >*/
    uint8_t GPIO_PinSpeed;                              /*<It is GPIO port output @GPIO_PIN_SPEED register   >*/
    uint8_t GPIO_PinPuPdControl;                        /*<It is GPIO port @pullup and pulldown              >*/            
    uint8_t GPIO_PinOPType;                             /*<It is GPIO port @Type of output                   >*/
    uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t; /* End Configration Structure For a GPIO PIN*/


/*============================= This is handle Structure For a GPIO PIN ==========================*/


typedef struct{
    GPIO_RegDef_t *pGPIOx;                  /*< THIS HOLD  THE BASE ADDRESS OF THE GPIO  TO WHICH PIN BELONG >*/
    GPIO_PinConfig_t GPIO_PinConfig;        /*< THIS HOLD  THE GPIO PIN CONFEGRATION SETTING  >*/
}GPIO_Handle;  /* End Configration Structure For a GPIO PIN*/





/*************************************************************************************************************
 *                                  APIs supported by the driver
 *                  For more information about the APIs check the function definitions                         
 * 
****************************************************************************************************************/
/* ======================== GPIO APIs =============================*/


/*
 * Periphral Clock Setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *PGPIOx, uint8_t EnorDi);

/*
 * Intializion & Deintializing GPIO
 */
void GPIO_INIT(GPIO_Handle *pGPIO_Handle);
void GPIO_DE_INIT(GPIO_RegDef_t *pGPIOx);


/*
 * Read & Write GPIO pin & port
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 *  IRQ configration and ISR handling 
 */
void GPIO_IRQConfig(uint8_t GPIO_IRQNumber, uint8_t IRQPriorty, uint8_t EnorDi);
void GPIO_Handling(uint8_t PinNumber);



#endif/*END STM32F401*/


#endif /*end HAL.H FILE*/