#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "P31u/i2c.h"
#include "P31u/info.h"
#include "STATE_MACHINE.h"


//####################################################################
uint8_t STEP = 0;
//####################################################################
#define GOTO_STEP		STEP
#define STEP__start                     0         // dasawyisi
#define STEP__exit                      200       // STATE_MACHINE_LOGIC -dan gamosvla
//####################################################################


//**************************************************************************
//*
//*		GOTO_STEP = STEP__start;
//*
//*
//*
//*
//**************************************************************************
uint8_t STATE_MACHINE_LOGIC (void){
	GOTO_STEP = 0;
    while (1)
    {
        switch(STEP) {
            //******************************************************************
            //*
            //******************************************************************
            case STEP__start :
                printf("\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r");
                printf("Hello guys :) I was created by David Chkhaidze (2016)\n\r\n\r\n\r");
                GOTO_STEP = STEP__exit;
                break;
            //******************************************************************
            //*
            //******************************************************************
            case STEP__exit :
            	return 0; break;
			//******************************************************************
			//*
			//******************************************************************
            default :
                break;
        }
    }
    return 0;
}


