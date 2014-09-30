#include <pebble.h>
#include "data_framework.h"
	
char balance_buffer[20];
	
void set_balance_buffer(char *string){
	snprintf(balance_buffer, sizeof(balance_buffer), "%s", string);
}

char *get_balance_buffer(){
	return balance_buffer;
}