
#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"

/*************cd******************************************************************
 *                                 Macros                                      *
 *******************************************************************************/
// PA 567 control
// PD 0123 Data
/* Data bits mode configuration (4 or 8) */
#define DATA_BITS_MODE 4

/* Use higher 4 bits in the data port (if want to use lower 4 bits undef UPPER_PORT_PINS) */
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif

#undef UPPER_PORT_PINS		/* Use lower 4 bits in the data port*/

/* LCD HW Pins [Needs modification] */
#define RS 5						/* Register select: select command register or data register (connected to PA5) */
#define RW 6						/* Read mode: RW = 1, write mode: RW = 0 (connected to PA6) */
#define E  7						/* Enable (connected to PA7) */

#define LCD_CTRL_PORT 		GPIO_PORTA_BASE_ADDRESS
#define LCD_CTRL_PORT_MASK  PORT_A_MASK				/* Mask to enable clock for RS, RW, and E port */
#define LCD_DATA_PORT 		GPIO_PORTD_BASE_ADDRESS
#define LCD_DATA_PORT_MASK  PORT_D_MASK				/* Mask to enable clock for data port */

// #define LCD_CTRL_PORT_DIR DDRC
// #define LCD_DATA_PORT_DIR DDRC

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C						/* Display on, cursor off */
#define CURSOR_ON 0x0E						/* Display on, cursor blinking */
#define SET_CURSOR_LOCATION 0x80

#define SHIFT_CURSOR_TO_LEFT 0x04
#define SHIFT_CURSOR_TO_RIGHT 0x06
#define SHIFT_DISPLAY_RIGHT 0x05
#define SHIFT_DISPLAY_LEFT 0x07

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayCounter(uint32 n_second);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);

#endif /* LCD_H_ */
