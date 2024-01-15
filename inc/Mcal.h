/***********************************************
 * Auther:Ahmed omar 
 * file: include all base addresses 
 * 
*/

#ifndef MCAL_H_
#define MCAL_H_


#include "macros.h"

   #if (STM32F401 == 1)

   #define NO_PR_BITS_IMPLEMENTED             4

   #define IRQ_NO_EXTI0			                6
   #define IRQ_NO_EXTI1		                   7
   #define IRQ_NO_EXTI2			                8
   #define IRQ_NO_EXTI3			                9
   #define IRQ_NO_EXTI4		   	            10
   #define IRQ_NO_EXTI9_5		     	         23
   #define IRQ_NO_EXTI15_10	               40
   #define INVIC_IRQ_PRI0			             0
   #define INVIC_IRQ_PRI15			            15

   /**************************************************************************************************
    *
    *                                              NVIC ISERx
    *
   ****************************************************************************************************/
   #define NVIC_ISER0         ((volatile uint32_t*) 0xE000E100)
   #define NVIC_ISER1         ((volatile uint32_t*) 0xE000E104)
   #define NVIC_ISER2         ((volatile uint32_t*) 0xE000E108)
   #define NVIC_ISER3         ((volatile uint32_t*) 0xE000E10C)




   #define NVIC_ICER0         ((volatile uint32_t*) 0xE000E180)
   #define NVIC_ICER1         ((volatile uint32_t*) 0xE000E184)
   #define NVIC_ICER2         ((volatile uint32_t*) 0xE000E188)
   #define NVIC_ICER3         ((volatile uint32_t*) 0xE000E18C)



   #define NVIC_PR_BASE_ADDR  ((volatile uint32_t*) 0xE000E400)


   /******************************************** END GENERIC MACROS **********************************/

   /**************************************************************************************************
    * 
    *                                              GPIO Pin possible Configration Macros
    * 
   ****************************************************************************************************/

   /*
   * @GPIO_PIN_NUMBERS
   * GPIO PIN NUMBERS
   * 
   */

   #define GPIO_PIN_NO_0      0
   #define GPIO_PIN_NO_1      1
   #define GPIO_PIN_NO_2      2
   #define GPIO_PIN_NO_3      3
   #define GPIO_PIN_NO_4      4
   #define GPIO_PIN_NO_5      5
   #define GPIO_PIN_NO_6      6
   #define GPIO_PIN_NO_7      7
   #define GPIO_PIN_NO_8      8
   #define GPIO_PIN_NO_9      9
   #define GPIO_PIN_NO_10     10
   #define GPIO_PIN_NO_11     11
   #define GPIO_PIN_NO_12     12
   #define GPIO_PIN_NO_13     13
   #define GPIO_PIN_NO_14     14
   #define GPIO_PIN_NO_15     15










   /*
   * @ GPIO_PIN_MODES
   * Mode Configration 
   * 
   * */



   #define GPIO_MODE_IN                0
   #define GPIO_MODE_OUT               1
   #define GPIO_MODE_ALTFN             2
   #define GPIO_MODE_ANALOG            3
   #define GPIO_MODE_IT_FT             4
   #define GPIO_MODE_IT_RT             5
   #define GPIO_MODE_IT_RFT            6



   /*
   *  @Type of output
   * output type Configration 
   * 
   * */



   #define GPIO_OP_TYPE_PP            0
   #define GPIO_OP_TYOE_PP            1



   /*
   * @ GPIO_PIN_SPEED register 
   * output speed Configration 
   * 
   * */

   #define GPIO_SPEED_LOW           0      
   #define GPIO_SPEED_MEDIUM        1
   #define GPIO_SPEED_FAST          2
   #define GPIO_SPEED_HIGH          3

   /*
   * @pullup and pulldown
   * Pull up and pull down Configration 
   * 
   * */

   #define GPIO_NO_PUPD              0
   #define GPIO_PIN_PU               1
   #define GPIO_PIN_PD               2

   /******************************************************************************************************************
    * 
    *                                        Base addresses for memories  STM32F401
    * 
    * ****************************************************************************************************************/

   // -U- Donated as unsigned 
   #define FLASH_BASEADDR                                       0x08000000U                                 /*<size of flash memory 256 kB>*/
   #define SRAM1_BASEADDR                                       0x20000000U                                 /*<size of ram memory 64 kB>*/ 
   #define ROM_BASEADDR                                         0x1FFF0000U                                 /*<size of rom memory 30 kB>*/
   #define SYSTEM_MEMORY                                        ROM_BASEADDR            
   #define SRAM                                                 SRAM1_BASEADDR

   /******************************** End Base addresses for memories  STM32F401 **************************************/





   /*********************************************************************************************************************
    * 
    *                                              Base addresses for Buses STM32F401
    * 
    **********************************************************************************************************************/

   #define PERIPH_BASE                                           0x40000000U                                /*<It oppeset the frist periphral APB1 bus TIM2>*/
   #define APB2PERIPH_BASE                                       0x40010000U                                /*<It oppeset the frist periphral APB2 bus TIM1>*/
   #define AHB1PERIPH_BASE                                       0x40020000U                                /*<It oppeset the frist periphral AHB1 bus GPIOA>*/
   #define AHB2PERIPH_BASE                                       0x50000000U                                /*<It oppeset the frist periphral AHB2 bus USB OTG FS>*/
   #define APB1PERIPH_BASE                                       PERIPH_BASE

   /*********************************************** End Base addresses for Buses STM32F401 ********************************/



   /*********************************************************************************************************************
    * 
    *                  Base addresses for peripherals hanging on APB1 bus domain STM32F401
    * 
    **********************************************************************************************************************/


   #define TIM2_BASEADDR                                         (APB1PERIPH_BASE + 0x0000U)                 /*<It is base address for timer 2 periphral >*/
   #define TIM3_BASEADDR                                         (APB1PERIPH_BASE + 0x0400U)                 /*<It is base address for timer 3 periphral >*/
   #define TIM4_BASEADDR                                         (APB1PERIPH_BASE + 0x0800U)                 /*<It is base address for timer 4 periphral >*/
   #define TIM5_BASEADDR                                         (APB1PERIPH_BASE + 0x0C00U)                 /*<It is base address for timer 5 periphral >*/
   #define RTC_BKP_BASEADDR                                      (APB1PERIPH_BASE + 0x2800U)                 /*<It is base address for RTC & BKP Registers periphral >*/
   #define WWDG_BASEADDR                                         (APB1PERIPH_BASE + 0x2C00U)                 /*<It is base address for WWDG periphral >*/
   #define IWDG_BASEADDR                                         (APB1PERIPH_BASE + 0x3000U)                 /*<It is base address for IWDG periphral >*/
   #define I2S2EXT_BASEADDR                                      (APB1PERIPH_BASE + 0x3400U)                 /*<It is base address for I2S2ext periphral >*/
   #define SPI2_I2S2_BASEADDR                                    (APB1PERIPH_BASE + 0x3800U)                 /*<It is base address for SPI2 / I2S2 periphral >*/
   #define SPI3_I2S3_BASEADDRR                                   (APB1PERIPH_BASE + 0x3C00U)                 /*<It is base address for SPI3 / I2S3 periphral >*/
   #define I2S3EXT_BASEADDR                                      (APB1PERIPH_BASE + 0x4000U)                 /*<It is base address for I2S3ext periphral >*/
   #define USART2_BASEADDR                                       (APB1PERIPH_BASE + 0x4400U)                 /*<It is base address for USART2 periphral >*/
   #define I2C1_BASEADDR                                         (APB1PERIPH_BASE + 0x5400U)                 /*<It is base address for I2C1 periphral >*/
   #define I2C2_BASEADDR                                         (APB1PERIPH_BASE + 0x5800U)                 /*<It is base address for I2C2 periphral >*/
   #define I2C3_BASEADDR                                         (APB1PERIPH_BASE + 0x5C00U)                 /*<It is base address for I2C3 periphral >*/
   #define PWR_BASEADDR                                          (APB1PERIPH_BASE + 0x7000U)                 /*<It is base address for PWR periphral >*/

   /*********************************************** End Base addresses for peripherals hanging on APB1 bus domain STM32F401 ********************************/





   /*********************************************************************************************************************
    * 
    *                  Base addresses for peripherals hanging on APB2 bus domain STM32F401
    * 
    **********************************************************************************************************************/



   #define TIM1_BASEADDR                                         (APB2PERIPH_BASE + 0x0000U)                 /*<It is base address for timer1 periphral >*/
   #define USART1_BASEADDR                                       (APB2PERIPH_BASE + 0x1000U)                 /*<It is base address for USART1 periphral >*/
   #define USART6_BASEADDR                                       (APB2PERIPH_BASE + 0x1400U)                 /*<It is base address for USART6 periphral >*/
   #define ADC1_BASEADDR                                         (APB2PERIPH_BASE + 0x2000U)                 /*<It is base address for ADC1 periphral >*/
   #define SDIO_BASEADDR                                         (APB2PERIPH_BASE + 0x2C00U)                 /*<It is base address for SDIO periphral >*/
   #define SPI1_BASEADDR                                         (APB2PERIPH_BASE + 0x3000U)                 /*<It is base address for SPI1 periphral >*/
   #define SPI4_BASEADDR                                         (APB2PERIPH_BASE + 0x3400U)                 /*<It is base address for SPI4 periphral >*/
   #define SYSCFG_BASEADDR                                       (APB2PERIPH_BASE + 0x3800U)                 /*<It is base address for SYSCFG periphral >*/
   #define EXTI_BASEADDR                                         (APB2PERIPH_BASE + 0x3C00U)                 /*<It is base address for EXTI periphral >*/
   #define TIM9_BASEADDR                                         (APB2PERIPH_BASE + 0x4000U)                 /*<It is base address for TIM9 periphral >*/
   #define TIM10_BASEADDR                                        (APB2PERIPH_BASE + 0x4400U)                 /*<It is base address for TIM10 periphral >*/
   #define TIM11_BASEADDR                                        (APB2PERIPH_BASE + 0x4800U)                 /*<It is base address for TIM11 periphral >*/


   /******************** End Base addresses for peripherals hanging on APB2 bus domain STM32F401 ********************************/

   /*********************************************************************************************************************
    * 
    *                  Base addresses for peripherals hanging on AHB1 bus domain STM32F401
    * 
    **********************************************************************************************************************/


   #define GPIOA_BASEADDR                                        (AHB1PERIPH_BASE + 0x0000U)                 /*<It is base address for GPIOA periphral >*/
   #define GPIOB_BASEADDR                                        (AHB1PERIPH_BASE + 0x0400U)                 /*<It is base address for GPIOB periphral >*/
   #define GPIOC_BASEADDR                                        (AHB1PERIPH_BASE + 0x0800U)                 /*<It is base address for GPIOC periphral >*/
   #define GPIOD_BASEADDR                                        (AHB1PERIPH_BASE + 0x0C00U)                 /*<It is base address for GPIOD periphral >*/
   #define GPIOE_BASEADDR                                        (AHB1PERIPH_BASE + 0x1000U)                 /*<It is base address for GPIOE periphral >*/
   #define GPIOH_BASEADDR                                        (AHB1PERIPH_BASE + 0x1C00U)                 /*<It is base address for GPIOH periphral >*/
   #define CRC_BASEADDR                                          (AHB1PERIPH_BASE + 0x3000U)                 /*<It is base address for CRC periphral >*/
   #define RCC_BASEADDR                                          (AHB1PERIPH_BASE + 0x3800U)                 /*<It is base address for RCC periphral >*/
   #define FLASH_INTERFACE_BASEADDR                              (AHB1PERIPH_BASE + 0x3C00U)                 /*<It is base address for Flash interface register periphral >*/
   #define DMA1_BASEADDR                                         (AHB1PERIPH_BASE + 0x6000U)                 /*<It is base address for GPIOA periphral >*/
   #define DMA2_BASEADDR                                         (AHB1PERIPH_BASE + 0x6400U)                 /*<It is base address for GPIOA periphral >*/


   /***************** End Base addresses for peripherals hanging on AHB1 bus domain STM32F401 ********************************/

   /*********************************************************************************************************************
    * 
    *                  Base addresses for peripherals hanging onAHB2 bus domain STM32F401
    * 
    **********************************************************************************************************************/

   #define USB_OTG_FS_BASEADDR                                   (AHB2PERIPH_BASE + 0x0000U)                 /*<It is base address for USB OTG FS periphral >*/

   /**************** End Base addresses for peripherals hanging on AHB2 bus domain STM32F401 ********************************/


   /*********************************************************************************************************************
    * 
    *                                         Peripheral register definition structures
    * 
    **********************************************************************************************************************/


   /*===================== GPIO definition strucure==============*/
   typedef struct{
      volatile uint32_t MODER;                                                                              /*<It is GPIO port mode register  @GPIO_PIN_MODES    >*/                                     
      volatile uint32_t OTYPER;                                                                             /*<It is GPIO port output type register              >*/
      volatile uint32_t OSPEEDR;                                                                            /*<It is GPIO port output @GPIO_PIN_SPEED register   >*/
      volatile uint32_t PUPDR;                                                                              /*<It is GPIO port pull-up/pull-down register        >*/
      volatile uint32_t IDR;                                                                                /*<It is GPIO port input data register               >*/
      volatile uint32_t ODR;                                                                                /*<It is GPIO port output data register              >*/
      volatile uint32_t BSRR;                                                                               /*<It is GPIO port bit set/reset register            >*/
      volatile uint32_t LCKR;                                                                               /*<It is GPIO port configuration lock register       >*/
      volatile uint32_t AFR[2];                                                                             /*<It is GPIO port alternate H, L function register  >*/
   }GPIO_RegDef_t;

   /*===================== End GPIO definition strucure ==============*/

   /*===================== SYSCFG definition strucure==============*/
   typedef struct{
      volatile uint32_t MEMRMP;                                                                              /*<It is GPIO port mode register  @GPIO_PIN_MODES    >*/
      volatile uint32_t PMC;                                                                             /*<It is GPIO port output type register              >*/
      volatile uint32_t EXTICR[4];                                                                            /*<It is GPIO port output @GPIO_PIN_SPEED register   >*/
      uint32_t RESERVED[2];
      volatile uint32_t CMPCR;                                                                               /*<It is GPIO port bit set/reset register            >*/

   }SYSCFG_RegDef_t;




/*===================== RCC definition strucure==============*/
typedef struct{
   volatile uint32_t CR;                                                                                /*<It is RCC clock control register                     >*/                                     
   volatile uint32_t PLLCFGR;                                                                           /*<It is RCC PLL configuration register                 >*/
   volatile uint32_t CFGR;                                                                              /*<It is RCC clock configuration register               >*/
   volatile uint32_t CIR;                                                                               /*<It is RCC clock interrupt register                   >*/
   volatile uint32_t AHB1RSTR;                                                                          /*<It is RCC AHB1 peripheral reset register             >*/
   volatile uint32_t AHB2RSTR;                                                                          /*<It is RCC AHB2 peripheral reset register             >*/
   volatile uint32_t RESERVED1[2];                                                                      /*<It is RCC Reserved register                          >*/
   volatile uint32_t APB1RSTR;                                                                          /*<It is RCC APB1 peripheral reset register             >*/
   volatile uint32_t APB2RSTR;                                                                          /*<It is RCC APB2 peripheral reset register             >*/
   volatile uint32_t RESERVED2[2];                                                                      /*<It is RCC Reserved2 register                         >*/
   volatile uint32_t AHB1ENR;                                                                           /*<It is RCC AHB1 peripheral clock enable register     >*/
   volatile uint32_t AHB2ENR;                                                                           /*<It is GPIO port alternate H, L function register     >*/
   volatile uint32_t RESERVED3[2];                                                                      /*<It is RCC Reserved3 register                         >*/
   volatile uint32_t APB1ENR;                                                                           /*<It is GPIO port alternate H, L function register     >*/
   volatile uint32_t APB2ENR;                                                                           /*<It is GPIO port alternate H, L function register     >*/
   volatile uint32_t RESERVED4[2];                                                                      /*<It is RCC Reserved4 register                         >*/
   volatile uint32_t AHB1LPENR;                                                                         /*<It is GPIO port alternate H, L function register     >*/
   volatile uint32_t AHB2LPENR;                                                                         /*<It is GPIO port alternate H, L function register     >*/
   volatile uint32_t RESERVED5[2];                                                                      /*<It is RCC Reserved5 register                         >*/
   volatile uint32_t APB1LPENR;                                                                         /*<It is GPIO port alternate H, L function register     >*/
   volatile uint32_t APB2LPENR;                                                                         /*<It is GPIO port alternate H, L function register     >*/
   volatile uint32_t RESERVED6[2];                                                                      /*<It is RCC Reserved6 register                         >*/
   volatile uint32_t BDCR;                                                                              /*<It is GPIO port mode register                        >*/                                     
   volatile uint32_t CSR;                                                                               /*<It is GPIO port mode register                        >*/                                     
   volatile uint32_t RESERVED7[2];                                                                      /*<It is RCC Reserved7 register                         >*/
   volatile uint32_t SSCGR;                                                                             /*<It is GPIO port mode register                        >*/                                     
   volatile uint32_t PLLI2SCFGR;                                                                        /*<It is GPIO port mode register                        >*/                                     
   volatile uint32_t RESERVED8;                                                                         /*<It is RCC Reserved8 register                         >*/
   volatile uint32_t DCKCFGR;                                                                           /*<It is GPIO port alternate H, L function register     >*/
}RCC_RegDef_t;



/*===================== End GPIO definition strucure ==============*/

/*===================== EXTI definition strucure==============*/
typedef struct{
   volatile uint32_t IMR;                                                                              /*<It is Interrupt mask register                        >*/
   volatile uint32_t EMR;                                                                              /*<It is Event mask register                            >*/
   volatile uint32_t RTSR;                                                                             /*<It is Rising trigger selection register              >*/
   volatile uint32_t FTSR;                                                                             /*<It is Falling trigger selection register             >*/
   volatile uint32_t SWIER;                                                                            /*<It is Software interrupt event register              >*/
   volatile uint32_t PR;                                                                               /*<It is Pending register                               >*/
}EXTI_RegDef_t;




/************************** End Peripheral register definition structures ********************************/




/*===================== Casting GPIO definition ==============*/
#define GPIOA                                               ((GPIO_RegDef_t*)GPIOA_BASEADDR)            /*<It is  casting for GPIOA  struct                     >*/   
#define GPIOB                                               ((GPIO_RegDef_t*)GPIOB_BASEADDR)            /*<It is  casting for GPIOB  struct                     >*/
#define GPIOC                                               ((GPIO_RegDef_t*)GPIOC_BASEADDR)            /*<It is  casting for GPIOC  struct                     >*/
#define GPIOD                                               ((GPIO_RegDef_t*)GPIOD_BASEADDR)            /*<It is  casting for GPIOD  struct                     >*/
#define GPIOE                                               ((GPIO_RegDef_t*)GPIOE_BASEADDR)            /*<It is  casting for GPIOE  struct                     >*/
#define GPIOH                                               ((GPIO_RegDef_t*)GPIOH_BASEADDR)            /*<It is  casting for GPIOH  struct                     >*/
/*===================== End Casting GPIO definition ==============*/

/*===================== Casting RCC definition ==============*/
#define RCC                                              ((RCC_RegDef_t*)RCC_BASEADDR)                  /*<It is  casting for GPIOA  struct                     >*/   
/*===================== Casting RCC definition ==============*/




/*===================== Casting EXTI definition ==============*/
#define EXTI                                              ((EXTI_RegDef_t*)EXTI_BASEADDR)                  /*<It is  casting for GPIOA  struct                     >*/
/*===================== Casting EXTI definition ==============*/

/*===================== Casting SYSCFG definition ==============*/
#define SYSCFG                                            ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)                  /*<It is  casting for GPIOA  struct                     >*/
/*===================== Casting SYSCFG definition ==============*/






/*================================================================ Macro For AHB1 enable clock =============================================================================*/
#define GPIOA_PCLK_EN()                                   (RCC->AHB1ENR |= (1 << 0))                  /*<It is  ENABLE CLOCK For GPIOA                          >*/  
#define GPIOB_PCLK_EN()                                   (RCC->AHB1ENR |= (1 << 1))                  /*<It is  ENABLE CLOCK For GPIOB                          >*/ 
#define GPIOC_PCLK_EN()                                   (RCC->AHB1ENR |= (1 << 2))                  /*<It is  ENABLE CLOCK For GPIOC                          >*/  
#define GPIOD_PCLK_EN()                                   (RCC->AHB1ENR |= (1 << 3))                  /*<It is  ENABLE CLOCK For GPIOD                          >*/         
#define GPIOE_PCLK_EN()                                   (RCC->AHB1ENR |= (1 << 4))                  /*<It is  ENABLE CLOCK For GPIOE                          >*/  
#define GPIOH_PCLK_EN()                                   (RCC->AHB1ENR |= (1 << 7))                  /*<It is  ENABLE CLOCK For GPIOH                          >*/  
#define CRC_PCLK_EN()                                     (RCC->AHB1ENR |= (1 << 12))                 /*<It is  ENABLE CLOCK For CRC                            >*/ 
#define DMA1_PCLK_EN()                                    (RCC->AHB1ENR |= (1 << 21))                 /*<It is  ENABLE DMA1 clock enable                        >*/
#define DMA2_PCLK_EN()                                    (RCC->AHB1ENR |= (1 << 22))                 /*<It is  ENABLE DMA2 clock enable                        >*/

/*================================================================ Macro For AHB2 enable clock =============================================================================*/
#define OTGFS_PCLK_EN()                                   (RCC->AHB2ENR |= (1 << 7))                  /*<It is  USB OTG FS clock enabled                        >*/ 


/*================================================================ Macro For APB1 enable clock =============================================================================*/
#define TIM2_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 0))                  /*<It is  ENABLE CLOCK For TIME2                          >*/  
#define TIM3_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 1))                  /*<It is  ENABLE CLOCK For TIME3                          >*/  
#define TIM4_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 2))                  /*<It is  ENABLE CLOCK For TIME4                          >*/  
#define TIM5_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 3))                  /*<It is  ENABLE CLOCK For TIME5                          >*/  
#define TIM5_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 3))                  /*<It is  ENABLE CLOCK For TIME5                          >*/ 
#define WWDG_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 11))                 /*<It is  ENABLE CLOCK For WWDG                           >*/  
#define SPI2_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 14))                 /*<It is  ENABLE CLOCK For SPI2                           >*/  
#define SPI3_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 15))                 /*<It is  ENABLE CLOCK For SPI3                           >*/  
#define USART2_PCLK_EN()                                  (RCC->APB1ENR |= (1 << 17))                 /*<It is  ENABLE CLOCK For USART2                         >*/  
#define I2C1_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 21))                 /*<It is  ENABLE CLOCK For I2C1                           >*/  
#define I2C2_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 22))                 /*<It is  ENABLE CLOCK For I2C2                           >*/ 
#define I2C3_PCLK_EN()                                    (RCC->APB1ENR |= (1 << 23))                 /*<It is  ENABLE CLOCK For I2C3                           >*/ 
#define PWR_PCLK_EN()                                     (RCC->APB1ENR |= (1 << 28))                 /*<It is  ENABLE CLOCK For Power interface                >*/  

/*================================================================ Macro For APB2 enable clock =============================================================================*/
#define TIM1_PCLK_EN()                                    (RCC->APB2ENR |= (1 << 0))                  /*<It is  ENABLE CLOCK For TIME1                          >*/ 
#define USART1_PCLK_EN()                                  (RCC->APB2ENR |= (1 << 4))                  /*<It is  ENABLE CLOCK For USART1                         >*/  
#define USART6_PCLK_EN()                                  (RCC->APB2ENR |= (1 << 5))                  /*<It is  ENABLE CLOCK For USART6                         >*/  
#define ACD1_PCLK_EN()                                    (RCC->APB2ENR |= (1 << 8))                  /*<It is  ENABLE CLOCK For ACD1                           >*/
#define SDIO_PCLK_EN()                                    (RCC->APB2ENR |= (1 << 11))                 /*<It is  ENABLE CLOCK For SDIO                           >*/  
#define SPI1_PCLK_EN()                                    (RCC->APB2ENR |= (1 << 12))                 /*<It is  ENABLE CLOCK For SPI1                           >*/  
#define SPI4_PCLK_EN()                                    (RCC->APB2ENR |= (1 << 13))                 /*<It is  ENABLE CLOCK For SPI4                           >*/  
#define SYSCFG_PCLK_EN()                                  (RCC->APB2ENR |= (1 << 14))                 /*<It is  ENABLE CLOCK For System configuration           >*/  
#define TIM9_PCLK_EN()                                    (RCC->APB2ENR |= (1 << 16))                 /*<It is  ENABLE CLOCK For TIME9                          >*/ 
#define TIM10_PCLK_EN()                                   (RCC->APB2ENR |= (1 << 17))                 /*<It is  ENABLE CLOCK For TIME10                         >*/ 
#define TIM11_PCLK_EN()                                   (RCC->APB2ENR |= (1 << 18))                 /*<It is  ENABLE CLOCK For TIME11                         >*/ 

/*================================================================ End Macro For enable clock =========================================================================*/




   /*================================================================  Macro For Disable clock =========================================================================*/



   /*================================================================ Macro For AHB1 Disable clock =============================================================================*/
   #define GPIOA_PCLK_DI()                                   (RCC->AHB1ENR &= ~(1 << 0))                  /*<It is  ENABLE CLOCK For GPIOA                          >*/  
   #define GPIOB_PCLK_DI()                                   (RCC->AHB1ENR &= ~(1 << 1))                  /*<It is  ENABLE CLOCK For GPIOB                          >*/ 
   #define GPIOC_PCLK_DI()                                   (RCC->AHB1ENR &= ~(1 << 2))                  /*<It is  ENABLE CLOCK For GPIOC                          >*/  
   #define GPIOD_PCLK_DI()                                   (RCC->AHB1ENR &= ~(1 << 3))                  /*<It is  ENABLE CLOCK For GPIOD                          >*/         
   #define GPIOE_PCLK_DI()                                   (RCC->AHB1ENR &= ~(1 << 4))                  /*<It is  ENABLE CLOCK For GPIOE                          >*/  
   #define GPIOH_PCLK_DI()                                   (RCC->AHB1ENR &= ~(1 << 7))                  /*<It is  ENABLE CLOCK For GPIOH                          >*/  
   #define CRC_PCLK_DI()                                     (RCC->AHB1ENR &= ~(1 << 12))                 /*<It is  ENABLE CLOCK For CRC                            >*/ 
   #define DMA1_PCLK_DI()                                    (RCC->AHB1ENR &= ~(1 << 21))                 /*<It is  ENABLE DMA1 clock enable                        >*/
   #define DMA2_PCLK_DI()                                    (RCC->AHB1ENR &= ~(1 << 22))                 /*<It is  ENABLE DMA2 clock enable                        >*/

   /*================================================================ Macro For AHB2 Disable clock =============================================================================*/
   #define OTGFS_PCLK_DI()                                   (RCC->AHB2ENR &= ~(1 << 7))                  /*<It is  USB OTG FS clock enabled                        >*/ 


   /*================================================================ Macro For APB1 Disable clock =============================================================================*/
   #define TIM2_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 0))                  /*<It is  ENABLE CLOCK For TIME2                          >*/  
   #define TIM3_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 1))                  /*<It is  ENABLE CLOCK For TIME3                          >*/  
   #define TIM4_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 2))                  /*<It is  ENABLE CLOCK For TIME4                          >*/  
   #define TIM5_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 3))                  /*<It is  ENABLE CLOCK For TIME5                          >*/  
   #define TIM5_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 3))                  /*<It is  ENABLE CLOCK For TIME5                          >*/ 
   #define WWDG_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 11))                 /*<It is  ENABLE CLOCK For WWDG                           >*/  
   #define SPI2_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 14))                 /*<It is  ENABLE CLOCK For SPI2                           >*/  
   #define SPI3_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 15))                 /*<It is  ENABLE CLOCK For SPI3                           >*/  
   #define USART2_PCLK_DI()                                  (RCC->APB1ENR &= ~(1 << 17))                 /*<It is  ENABLE CLOCK For USART2                         >*/  
   #define I2C1_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 21))                 /*<It is  ENABLE CLOCK For I2C1                           >*/  
   #define I2C2_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 22))                 /*<It is  ENABLE CLOCK For I2C2                           >*/ 
   #define I2C3_PCLK_DI()                                    (RCC->APB1ENR &= ~(1 << 23))                 /*<It is  ENABLE CLOCK For I2C3                           >*/ 
   #define PWR_PCLK_DI()                                     (RCC->APB1ENR &= ~(1 << 28))                 /*<It is  ENABLE CLOCK For Power interface                >*/  

   /*================================================================ Macro For APB2 Disable clock =============================================================================*/
   #define TIM1_PCLK_DI()                                    (RCC->APB2ENR &= ~(1 << 0))                  /*<It is  ENABLE CLOCK For TIME1                          >*/ 
   #define USART1_PCLK_DI()                                  (RCC->APB2ENR &= ~(1 << 4))                  /*<It is  ENABLE CLOCK For USART1                         >*/  
   #define USART6_PCLK_DI()                                  (RCC->APB2ENR &= ~(1 << 5))                  /*<It is  ENABLE CLOCK For USART6                         >*/  
   #define ACD1_PCLK_DI()                                    (RCC->APB2ENR &= ~(1 << 8))                  /*<It is  ENABLE CLOCK For ACD1                           >*/
   #define SDIO_PCLK_DI()                                    (RCC->APB2ENR &= ~(1 << 11))                 /*<It is  ENABLE CLOCK For SDIO                           >*/  
   #define SPI1_PCLK_DI()                                    (RCC->APB2ENR &= ~(1 << 12))                 /*<It is  ENABLE CLOCK For SPI1                           >*/  
   #define SPI4_PCLK_DI()                                    (RCC->APB2ENR &= ~(1 << 13))                 /*<It is  ENABLE CLOCK For SPI4                           >*/  
   #define SYSCFG_PCLK_DI()                                  (RCC->APB2ENR &= ~(1 << 14))                 /*<It is  ENABLE CLOCK For System configuration           >*/  
   #define TIM9_PCLK_DI()                                    (RCC->APB2ENR &= ~(1 << 16))                 /*<It is  ENABLE CLOCK For TIME9                          >*/ 
   #define TIM10_PCLK_DI()                                   (RCC->APB2ENR &= ~(1 << 17))                 /*<It is  ENABLE CLOCK For TIME10                         >*/ 
   #define TIM11_PCLK_DI()                                   (RCC->APB2ENR &= ~(1 << 18))                 /*<It is  ENABLE CLOCK For TIME11                         >*/ 

   /*================================================================ End Macro For Disable clock =========================================================================*/

   #define GPIO_BASE_ADDR_TO_CODE(x)      ( (x == GPIOA)?0:\
                                          (x == GPIOB)?1:\
                                          (x == GPIOC)?2:\
                                          (x == GPIOD)?3:\
                                          (x == GPIOE)?4:\
                                          (x == GPIOH)?7:0)






   #endif /* end stm32f401*/
#endif /*End mcal file */