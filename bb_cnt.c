#include "bb_cnt.h"

/*All functions have a parameter of counter type.  In this way, these routines can support all different counters.

The parameters in these functions are defined as register type.  Most compilers, by default, let functions to pass parameters using stack.
 If the number of parameters is low (less than 5), some microprocessors can use register to pass parameters.  
 Using register to pass  parameters is much faster in execution than using the stack.
 
 The keyword “register” is a keyword in ANSI C.  
 The keyword register forces the function to pass the parameter using a register if it is supported by the microprocessor.  
 If a microprocessor does not support passing parameters using registers, the compiler will just ignore the word “register”.

Since the unit of memory storage is byte, we use a byte for the flag counter_expired.  
If more flags are need to expand the functionality of counter, up to eight flags can share the same byte. 
*/
void BB_Initialize_Counter(register Counter_Type *counter)
{
      *(counter->counter_expired) = !0; 
}

void BB_Reset_Counter(register Counter_Type *counter)
{
      if(*(counter->counter_terminate_value) != (U16) 0)
	{	
		*(counter->counter_expired) =  (U8) 0; 
		*(counter->counter_value) = (U16) 0;
	}
}

/*When a counter is serviced, the counter’s value is advanced by 1. 
If the counter’s value is equal to the its terminate value, 
the expire flag is set and the callback function is called through the function pointer. 
*/
void BB_Service_Counter( register Counter_Type *counter)
{
  	if (*(counter->counter_expired) == 0) {
		(*(counter->counter_value)) += (U16) 1;
 		if(*(counter->counter_value) >= 
			*(counter->counter_terminate_value)) 
		{
          		*(counter->counter_expired) = !0;
			(*counter->counter_expire_callback)();
		}
	}
} /* End of bb_cnt.c */