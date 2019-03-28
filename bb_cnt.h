#ifndef  _bb_cnt_h
#define  _bb_cnt_h 1
typedef  unsigned int   U16;
typedef  unsigned char   U8;
typedef void (*Counter_Callback_Routine_Type) (void);

typedef const struct Counter_Block_Struct_Tag
{
      /*counter_expired should point to a flag that indicates if the counter is expired.*/
    	U8     *counter_expired;
    	/*counter_value should point to a variable that holds the current count value.*/
 	U16   *counter_value;
 	/*counter_terminate_value should point to a variable that holds the highest value that the counter can reach before expiration.*/
	U16   *counter_terminate_value;
	/*counter_expire_callback should point to a callback  function.*/
	Counter_Callback_Routine_Type  counter_expire_callback;
}   Counter_Type;

extern void BB_Initialize_Counter(register Counter_Type *counter);
extern void BB_Reset_Counter(register Counter_Type *counter);
extern void BB_Service_Counter(register Counter_Type *counter);
extern U16 BB_Read_Counter(register Counter_Type *counter);

#endif   

/* End of bb_cnt.h */

/*Note:   In embedded software, const type variables are stored in ROM.*/
