#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"

/*******************************************************************************
 *                                   Macros                                    *
 *******************************************************************************/
// rows PE 0123
// cols PC 4567

/* Keypad configurations for number of rows and columns */
#define N_col 4
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT 		GPIO_PORTE_BASE_ADDRESS
#define KEYPAD_ROW_PORT_MASK	PORT_E_MASK
#define KEYPAD_COL_PORT 		GPIO_PORTC_BASE_ADDRESS
#define KEYPAD_COL_PORT_MASK	PORT_C_MASK

#define ROW_UPPER_PORT_PINS		/* Use higher 4 bits in the row port */
#define COL_UPPER_PORT_PINS		/* Use higher 4 bits in the column port */

#undef ROW_UPPER_PORT_PINS		/* Use lower 4 bits in the row port */
// #undef COL_UPPER_PORT_PINS		/* Use lower 4 bits in the row port */

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
/* Keypad initialization */
void keypad_Init(void);

/* Function responsible for getting the pressed keypad key */
uint8 KeyPad_getPressedKey(void);

#endif /* KEYPAD_H_ */
