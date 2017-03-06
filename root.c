#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "P31u/i2c.h"
#include "P31u/info.h"
#include "STATE_MACHINE.h"


int main(void){
	printf("\r\n\r\n\r\n*** GET_HK_1 (8)***\r\n");
	PRINT_P31u___GET_HK_1();
	//printf("\r\n\r\n\r\n*** GET_HK_2 (8.1)***\r\n");
	//PRINT_P31u___GET_HK_2();
//	printf("\r\n\r\n\r\n*** CONFIG_GET (18)***\r\n");
//	PRINT_P31u___CONFIG_GET();
//	printf("\r\n\r\n\r\n*** CONFIG2_GET (22)***\r\n");
//	PRINT_P31u___CONFIG2_GET();

	//STATE_MACHINE_LOGIC();

	return 0;
}

