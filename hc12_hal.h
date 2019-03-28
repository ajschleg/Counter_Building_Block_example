/*  Channel naming ( use the same names as the chip manual for easily check the hardware) */
//#include <iob32.h>    /* iob32.h is the register file of HC12 */ 
/*or link with mc9s12e128.c*/
/* Define bit masks for 8 bit registers  */
typedef unsigned char    UBYTE;
#define  _B0_   (UBYTE) 0x01   /* B0 is the lsb of an 8 bit register*/
#define  CHAN1   1    /* Define CHAN1 as the 1st logical channel. User can use either the logical channel number (1) or physical channel symbol (CHAN1) to index a channel */
/* Map each discrete I/O channel to register or register bit field */ 

/* Channel 1 */
#define CHAN_ENB_1  	      PTS  /*  Dummy enable register*/
#define CHAN_DIR_1    	    DDRS    /*  Direction register of PS0*/
#define CHAN_PORT_1 	    PTS  /*  PORTA is data register */
#define CHAN_MASK_1	    _B0_      /*  The bit field of PS0 */
#define CHAN_ENMASK_1    	0xFF     /* Dummy enable operator */

/* Abstraction layer, map the parameters of macros to the register names */

#define CHAN_TO_ENB(n)      	CHAN_ENB_##n 
#define CHAN_TO_DIR(n)          CHAN_DIR_##n	
#define CHAN_TO_PORT(n)    		CHAN_PORT_##n  
#define CHAN_TO_MASK(n)     	CHAN_MASK_##n 
#define CHAN_TO_ENMASK(n) 		CHAN_ENMASK_##n
                                               

/* Abstraction layer, definitions of I/O operations */

#define DIO_CHAN_ENB(n) 	((CHAN_TO_ENB(n)) &= CHAN_TO_ENMASK(n))
#define DIO_CHAN_IN(n)		((CHAN_TO_DIR(n)) &=~CHAN_TO_MASK(n))
#define DIO_CHAN_OUT(n)		((CHAN_TO_DIR(n)) |=CHAN_TO_MASK(n))
#define DIO_CHAN_READ(n) 	((CHAN_TO_PORT(n)) &= CHAN_TO_MASK(n))
#define DIO_CHAN_HI(n)   	((CHAN_TO_PORT(n)) |= CHAN_TO_MASK(n))
#define DIO_CHAN_LO(n)    	((CHAN_TO_PORT(n)) &= ~CHAN_TO_MASK(n))
