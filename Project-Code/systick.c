#include "systick.h"
#include "tm4c123gh6pm_registers.h"
#include "std_types.h"

// the systick handler should be moved from this file to the file where it will be used (main.c or app.c for example)
/*******************************************************************************************************************/
/* Global variable to determine the number of systick interrupt (number of seconds) */
// volatile uint32 ticks_num = 0;

// /* SysTick Timer ISR ... No need to clear the trigger flag (COUNT) bit ... it cleared automatically by the HW */
// void SysTick_Handler(void)
// {
//     ticks_num++; /* increment the number of ticks */
    
// }
/*******************************************************************************************************************/

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
/************************************************************************************
* Function Name: SysTick_Init
* Parameters (in): None
* Parameters (out): None
* Return value: None
* Description: Enable the SystTick Timer to run using the System Clock with Frequency
               16Mhz and generate interrupt every 1 second.
************************************************************************************/
void SysTick_Init(void)
{
	/* Enable Interrupts and Exceptions */
    Enable_Interrupts();
    Enable_Exceptions();

    SYSTICK_CTRL_REG    = 0;               /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG  = 15999999;        /* Set the Reload value with 15999999 to count 1 Second */
    SYSTICK_CURRENT_REG = 0;               /* Clear the Current Register value */
    /* Configure the SysTick Control Register 
     * Enable the SysTick Timer (ENABLE = 1) (bit 0)
     * Enable SysTick Interrupt (INTEN = 1) (bit 1)
     * Choose the clock source to be System Clock (CLK_SRC = 1) (bit 2) */
    SYSTICK_CTRL_REG |= 0x07;
    /* Assign priority level 3 to the SysTick Interrupt */
    NVIC_SYSTEM_PRI3_REG =  (NVIC_SYSTEM_PRI3_REG & SYSTICK_PRIORITY_MASK) | (SYSTICK_INTERRUPT_PRIORITY << SYSTICK_PRIORITY_BITS_POS);
}

/************************************************************************************
* Function Name: SysTick_Disable
* Parameters (in): None
* Parameters (out): None
* Return value: None
* Description: Function to disable systick timer.
************************************************************************************/
void SysTick_Disable(void)
{
	SYSTICK_CTRL_REG &= ~0x00000001;	/* Disable the SysTick Timer by Clear the ENABLE Bit */
}

/************************************************************************************
* Function Name: SysTick_Enable
* Parameters (in): None
* Parameters (out): None
* Return value: None
* Description: Function to enable systick timer to start over.
************************************************************************************/
void SysTick_Enable(void)
{
	SYSTICK_CTRL_REG |= 0x00000001;		/* Enable the SysTick Timer by set the ENABLE Bit */
	SYSTICK_RELOAD_REG = 15999999;		/* Set the Reload value with 15999999 to count 1 Second */
}
