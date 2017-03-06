#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
//#########################################
#include "i2c.h"
//#########################################
#define P31U_I2C_ADDRESS		0x58
//#########################################

void i2cOpen();
void i2cClose();
void i2cSetAddress(int address);
//#########################################
int g_i2cFile; // I2C Linux device handle
//#########################################
hkparam_t		P31u_hkparam_t;		//(8  )
eps_hk_t		P31u_eps_hk_t;		//(8.1)
eps_config_t	P31u_eps_config_t;	//(18)
eps_config2_t	P31u_eps_config2_t;	//(22)
//#########################################






//*****************************************************************
//*	GET_HK_1 (8)
//*
//*
//*
//*****************************************************************
uint8_t P31u___GET_HK_1(void){


	i2cOpen();
	i2cSetAddress(P31U_I2C_ADDRESS);
	//////////////////////////////////////////////////
	uint8_t data[256];
	data[0] = 8;
	data[1] = 0;
	data[2] = 0;
	if (write(g_i2cFile, data, 1) != 1) {
		i2cClose(); return 1; //OK
	}
	//////////////////////////////////////////////////
	int a1=0;
	for(a1 = 0; a1 < 10000000; a1++){
	}
	/////////////////////////////////////////////////
	if (read(g_i2cFile, data, 45) != 45) {
		i2cClose(); return 2; //OK
	}else{
		printf("P31u RESPONSE... PORT:(%d) ERROR CODE:(%d)\n\r\n",data[0],data[1]);
		P31u_hkparam_t.pv[0]   		   = data[2]*256  + data[3];
		P31u_hkparam_t.pv[1]   		   = data[4]*256  + data[5];
		P31u_hkparam_t.pv[2]   		   = data[6]*256  + data[7];
		P31u_hkparam_t.pc 	   		   = data[8]*256  + data[9];
		P31u_hkparam_t.bv      		   = data[10]*256 + data[11];
		P31u_hkparam_t.sc              = data[12]*256 + data[13];
		P31u_hkparam_t.temp[0]         = data[14]*256 + data[15];
		P31u_hkparam_t.temp[1]         = data[16]*256 + data[17];
		P31u_hkparam_t.temp[2]         = data[18]*256 + data[19];
		P31u_hkparam_t.temp[3]         = data[20]*256 + data[21];
		P31u_hkparam_t.batt_temp[0]    = data[22]*256 + data[23];
		P31u_hkparam_t.batt_temp[1]    = data[24]*256 + data[25];
		P31u_hkparam_t.latchup[0]      = data[26]*256 + data[27];
		P31u_hkparam_t.latchup[1]      = data[28]*256 + data[29];
		P31u_hkparam_t.latchup[2]      = data[30]*256 + data[31];
		P31u_hkparam_t.latchup[3]      = data[32]*256 + data[33];
		P31u_hkparam_t.latchup[4]      = data[34]*256 + data[35];
		P31u_hkparam_t.latchup[5]      = data[36]*256 + data[37];
		P31u_hkparam_t.reset           = data[38];
		P31u_hkparam_t.bootcount       = data[39]*256 + data[40];
		P31u_hkparam_t.sw_errors       = data[41]*256 + data[42];
		P31u_hkparam_t.ppt_mode        = data[43];
		P31u_hkparam_t.channel_status  = data[44];
	}
	//////////////////////////////////////////////////
	i2cClose(); return 0; //OK
}

//*****************************************************************
//*	GET_HK_2 (8.1)
//*
//*
//*
//*****************************************************************
uint8_t P31u___GET_HK_2(void){
	i2cOpen();
	i2cSetAddress(P31U_I2C_ADDRESS);
	//////////////////////////////////////////////////
	uint8_t data[256];
	data[0] = 8;
	data[1] = 1;
	data[2] = 0;
	if (write(g_i2cFile, data, 2) != 2) {
		i2cClose(); return 1; //OK
	}
	//////////////////////////////////////////////////
	int a1=0;
	for(a1 = 0; a1 < 100000000; a1++){
	}
	/////////////////////////////////////////////////
	if (read(g_i2cFile, data, 133) != 133) {
		i2cClose(); return 2; //OK
	}else{
		printf("P31u RESPONSE... PORT:(%d) ERROR CODE:(%d)\n\r\n",data[0],data[1]);
		P31u_eps_hk_t.vboost[0] = data[2]*256   + data[3]; 		//! (0) Voltage of boost converters [mV] [PV1, PV2, PV3]
		P31u_eps_hk_t.vboost[1] = data[4]*256   + data[5]; 		//! (1) Voltage of boost converters [mV] [PV1, PV2, PV3]
		P31u_eps_hk_t.vboost[2] = data[6]*256   + data[7]; 		//! (2) Voltage of boost converters [mV] [PV1, PV2, PV3]
		P31u_eps_hk_t.vbatt 	= data[8]*256   + data[9]; 		//! Voltage of battery [mV]
		P31u_eps_hk_t.curin[0]  = data[10]*256  + data[11]; 	//! (0) Current in [mA]
		P31u_eps_hk_t.curin[1]  = data[12]*256  + data[13]; 	//! (1) Current in [mA]
		P31u_eps_hk_t.curin[2]  = data[14]*256  + data[15]; 	//! (2) Current in [mA]
		P31u_eps_hk_t.cursun    = data[16]*256  + data[17]; 	//! Current from boost converters [mA]
		P31u_eps_hk_t.cursys    = data[18]*256  + data[19]; 	//! Current out of battery [mA]
		P31u_eps_hk_t.reserved1 = data[20]*256  + data[21]; 	//! Reserved for future use
		P31u_eps_hk_t.curout[0] = data[22]*256  + data[23]; 	//! (0) Current out (switchable outputs) [mA]
		P31u_eps_hk_t.curout[1] = data[24]*256  + data[25]; 	//! (1) Current out (switchable outputs) [mA]
		P31u_eps_hk_t.curout[2] = data[26]*256  + data[27]; 	//! (2) Current out (switchable outputs) [mA]
		P31u_eps_hk_t.curout[3] = data[28]*256  + data[29]; 	//! (3) Current out (switchable outputs) [mA]
		P31u_eps_hk_t.curout[4] = data[30]*256  + data[31]; 	//! (4) Current out (switchable outputs) [mA]
		P31u_eps_hk_t.curout[5] = data[32]*256  + data[33]; 	//! (5) Current out (switchable outputs) [mA]
		P31u_eps_hk_t.output[0] = data[34]; 					//! (0) Status of outputs**
		P31u_eps_hk_t.output[1] = data[35]; 					//! (1) Status of outputs**
		P31u_eps_hk_t.output[2] = data[36]; 					//! (2) Status of outputs**
		P31u_eps_hk_t.output[3] = data[37]; 					//! (3) Status of outputs**
		P31u_eps_hk_t.output[4] = data[38]; 					//! (4) Status of outputs**
		P31u_eps_hk_t.output[5] = data[39]; 					//! (5) Status of outputs**
		P31u_eps_hk_t.output[6] = data[40]; 					//! (6) Status of outputs**
		P31u_eps_hk_t.output[7] = data[41]; 					//! (7) Status of outputs**
		P31u_eps_hk_t.output_on_delta[0]  = data[42]*256  + data[43];	//! (0) Time till power on** [s]
		P31u_eps_hk_t.output_on_delta[1]  = data[44]*256  + data[45];	//! (1) Time till power on** [s]
		P31u_eps_hk_t.output_on_delta[2]  = data[46]*256  + data[47];	//! (2) Time till power on** [s]
		P31u_eps_hk_t.output_on_delta[3]  = data[48]*256  + data[49];	//! (3) Time till power on** [s]
		P31u_eps_hk_t.output_on_delta[4]  = data[50]*256  + data[51];	//! (4) Time till power on** [s]
		P31u_eps_hk_t.output_on_delta[5]  = data[52]*256  + data[53];	//! (5) Time till power on** [s]
		P31u_eps_hk_t.output_on_delta[6]  = data[54]*256  + data[55];	//! (6) Time till power on** [s]
		P31u_eps_hk_t.output_on_delta[7]  = data[56]*256  + data[57];	//! (7) Time till power on** [s]
		P31u_eps_hk_t.output_off_delta[0] = data[58]*256  + data[59];	//! (0) Time till power off** [s]
		P31u_eps_hk_t.output_off_delta[1] = data[60]*256  + data[61];	//! (1) Time till power off** [s]
		P31u_eps_hk_t.output_off_delta[2] = data[62]*256  + data[63];	//! (2) Time till power off** [s]
		P31u_eps_hk_t.output_off_delta[3] = data[64]*256  + data[65];	//! (3) Time till power off** [s]
		P31u_eps_hk_t.output_off_delta[4] = data[66]*256  + data[67];	//! (4) Time till power off** [s]
		P31u_eps_hk_t.output_off_delta[5] = data[68]*256  + data[69];	//! (5) Time till power off** [s]
		P31u_eps_hk_t.output_off_delta[6] = data[70]*256  + data[71];	//! (6) Time till power off** [s]
		P31u_eps_hk_t.output_off_delta[7] = data[72]*256  + data[73];	//! (7) Time till power off** [s]
		P31u_eps_hk_t.latchup[0] = data[74]*256  + data[75];  			//! (0) Number of latch-ups
		P31u_eps_hk_t.latchup[1] = data[76]*256  + data[77];  			//! (1) Number of latch-ups
		P31u_eps_hk_t.latchup[2] = data[78]*256  + data[79];  			//! (2) Number of latch-ups
		P31u_eps_hk_t.latchup[3] = data[80]*256  + data[81];  			//! (3) Number of latch-ups
		P31u_eps_hk_t.latchup[4] = data[82]*256  + data[83];  			//! (4) Number of latch-ups
		P31u_eps_hk_t.latchup[5] = data[84]*256  + data[85];  			//! (5) Number of latch-ups
		P31u_eps_hk_t.wdt_i2c_time_left     = data[86]*16777216  + data[87]*65536  + data[88]*256  + data[89];  		//! Time left on I2C wdt [s]
		P31u_eps_hk_t.wdt_gnd_time_left     = data[90]*16777216  + data[91]*65536  + data[92]*256  + data[93];  		//! Time left on I2C wdt [s]
		P31u_eps_hk_t.wdt_csp_pings_left[0] = data[94];   //! (0) Pings left on CSP wdt
		P31u_eps_hk_t.wdt_csp_pings_left[1] = data[95];   //! (1) Pings left on CSP wdt
		P31u_eps_hk_t.counter_wdt_i2c       = data[96]*16777216  + data[97]*65536  + data[98]*256  + data[99];  		//! Number of WDT I2C reboots
		P31u_eps_hk_t.counter_wdt_gnd       = data[100]*16777216  + data[101]*65536  + data[102]*256  + data[103];  		//! Number of WDT GND reboots
		P31u_eps_hk_t.counter_wdt_csp[0]    = data[104]*16777216  + data[105]*65536  + data[106]*256  + data[107]; 		//! (0) Number of WDT CSP reboots
		P31u_eps_hk_t.counter_wdt_csp[1]    = data[108]*16777216  + data[109]*65536  + data[110]*256  + data[111]; 		//! (1) Number of WDT CSP reboots
		P31u_eps_hk_t.counter_boot 		    = data[112]*16777216  + data[113]*65536  + data[114]*256  + data[115];   			//! Number of EPS reboots
		P31u_eps_hk_t.temp[0]   = data[116]*256  + data[117];	//! (0) Temperatures [degC] [0 = TEMP1, TEMP2, TEMP3, TEMP4, BP4a, BP4b]
		P31u_eps_hk_t.temp[1]   = data[118]*256  + data[119];	//! (1) Temperatures [degC] [0 = TEMP1, TEMP2, TEMP3, TEMP4, BP4a, BP4b]
		P31u_eps_hk_t.temp[2]   = data[120]*256  + data[121];	//! (2) Temperatures [degC] [0 = TEMP1, TEMP2, TEMP3, TEMP4, BP4a, BP4b]
		P31u_eps_hk_t.temp[3]   = data[122]*256  + data[123];	//! (3) Temperatures [degC] [0 = TEMP1, TEMP2, TEMP3, TEMP4, BP4a, BP4b]
		P31u_eps_hk_t.temp[4]   = data[124]*256  + data[125];	//! (4) Temperatures [degC] [0 = TEMP1, TEMP2, TEMP3, TEMP4, BP4a, BP4b]
		P31u_eps_hk_t.temp[5]   = data[126]*256  + data[127];	//! (5) Temperatures [degC] [0 = TEMP1, TEMP2, TEMP3, TEMP4, BP4a, BP4b]
		P31u_eps_hk_t.bootcause = data[128]; 					//! Cause of last EPS reset
		P31u_eps_hk_t.battmode  = data[129]; 					//! Mode for battery [0 = initial, 1 = undervoltage,  2 = safemode, 3 = nominal, 4=full]
		P31u_eps_hk_t.pptmode   = data[130]; 					//! Mode of PPT tracker [1=MPPT, 2=FIXED]
		P31u_eps_hk_t.reserved2 = data[131]*256  + data[132];

	}
	//////////////////////////////////////////////////
	i2cClose(); return 0; //OK
}


//*****************************************************************
//*	CONFIG_GET (18)
//*
//*
//*
//*****************************************************************
uint8_t P31u___CONFIG_GET(void){
	i2cOpen();
	i2cSetAddress(P31U_I2C_ADDRESS);
	//////////////////////////////////////////////////
	uint8_t data[256];
	data[0] = 18;
	data[1] = 0;
	data[2] = 0;
	if (write(g_i2cFile, data, 1) != 1) {
		i2cClose(); return 1; //OK
	}
	//////////////////////////////////////////////////
	int a1=0;
	for(a1 = 0; a1 < 100000000; a1++){
	}
	/////////////////////////////////////////////////
	if (read(g_i2cFile, data, 60) != 60) {
		i2cClose(); return 2; //OK
	}else{
		printf("P31u RESPONSE... PORT:(%d) ERROR CODE:(%d)\n\r\n",data[0],data[1]);
		P31u_eps_config_t.ppt_mode                = data[2];     //! Mode for PPT [1 = AUTO, 2 = FIXED]
		P31u_eps_config_t.battheater_mode         = data[3];     //! Mode for battheater [0 = Manual, 1 = Auto]
		P31u_eps_config_t.battheater_low          = data[4];     //!-/+ Turn heater on at [degC]
		P31u_eps_config_t.battheater_high         = data[5];     //!-/+ Turn heater off at [degC]
		P31u_eps_config_t.output_normal_value[0]  = data[6];     //! (0) Nominal mode output value
		P31u_eps_config_t.output_normal_value[1]  = data[7];     //! (1) Nominal mode output value
		P31u_eps_config_t.output_normal_value[2]  = data[8];     //! (2) Nominal mode output value
		P31u_eps_config_t.output_normal_value[3]  = data[9];     //! (3) Nominal mode output value
		P31u_eps_config_t.output_normal_value[4]  = data[10];    //! (4) Nominal mode output value
		P31u_eps_config_t.output_normal_value[5]  = data[11];    //! (5) Nominal mode output value
		P31u_eps_config_t.output_normal_value[6]  = data[12];    //! (6) Nominal mode output value
		P31u_eps_config_t.output_normal_value[7]  = data[13];    //! (7) Nominal mode output value
		P31u_eps_config_t.output_safe_value[0]    = data[14];  	 //! (0) Safe mode output value
		P31u_eps_config_t.output_safe_value[1]    = data[15];  	 //! (1) Safe mode output value
		P31u_eps_config_t.output_safe_value[2]    = data[16];  	 //! (2) Safe mode output value
		P31u_eps_config_t.output_safe_value[3]    = data[17];  	 //! (3) Safe mode output value
		P31u_eps_config_t.output_safe_value[4]    = data[18];  	 //! (4) Safe mode output value
		P31u_eps_config_t.output_safe_value[5]    = data[19];  	 //! (5) Safe mode output value
		P31u_eps_config_t.output_safe_value[6]    = data[20];  	 //! (6) Safe mode output value
		P31u_eps_config_t.output_safe_value[7]    = data[21];  	 //! (7) Safe mode output value
		P31u_eps_config_t.output_initial_on_delay[0] = data[22]*256  + data[23];   //! (0) Output switches: init with these on delays [s]
		P31u_eps_config_t.output_initial_on_delay[1] = data[24]*256  + data[25];   //! (1) Output switches: init with these on delays [s]
		P31u_eps_config_t.output_initial_on_delay[2] = data[26]*256  + data[27];   //! (2) Output switches: init with these on delays [s]
		P31u_eps_config_t.output_initial_on_delay[3] = data[28]*256  + data[29];   //! (3) Output switches: init with these on delays [s]
		P31u_eps_config_t.output_initial_on_delay[4] = data[30]*256  + data[31];   //! (4) Output switches: init with these on delays [s]
		P31u_eps_config_t.output_initial_on_delay[5] = data[32]*256  + data[33];   //! (5) Output switches: init with these on delays [s]
		P31u_eps_config_t.output_initial_on_delay[6] = data[34]*256  + data[35];   //! (6) Output switches: init with these on delays [s]
		P31u_eps_config_t.output_initial_on_delay[7] = data[36]*256  + data[37];   //! (7) Output switches: init with these on delays [s]
		P31u_eps_config_t.output_initial_off_delay[0] = data[38]*256  + data[39];  //! (0) Output switches: init with these off delays [s]
		P31u_eps_config_t.output_initial_off_delay[1] = data[40]*256  + data[41];  //! (1) Output switches: init with these off delays [s]
		P31u_eps_config_t.output_initial_off_delay[2] = data[42]*256  + data[43];  //! (2) Output switches: init with these off delays [s]
		P31u_eps_config_t.output_initial_off_delay[3] = data[44]*256  + data[45];  //! (3) Output switches: init with these off delays [s]
		P31u_eps_config_t.output_initial_off_delay[4] = data[46]*256  + data[47];  //! (4) Output switches: init with these off delays [s]
		P31u_eps_config_t.output_initial_off_delay[5] = data[48]*256  + data[49];  //! (5) Output switches: init with these off delays [s]
		P31u_eps_config_t.output_initial_off_delay[6] = data[50]*256  + data[51];  //! (6) Output switches: init with these off delays [s]
		P31u_eps_config_t.output_initial_off_delay[7] = data[52]*256  + data[53];  //! (7) Output switches: init with these off delays [s]
		P31u_eps_config_t.vboost[0]  = data[54]*256  + data[55];   				   //! (0) Fixed PPT point for boost converters [mV]
		P31u_eps_config_t.vboost[1]  = data[56]*256  + data[57];   				   //! (1) Fixed PPT point for boost converters [mV]
		P31u_eps_config_t.vboost[2]  = data[58]*256  + data[59];   				   //! (2) Fixed PPT point for boost converters [mV]


	}
	//////////////////////////////////////////////////
	i2cClose(); return 0; //OK
}

//*****************************************************************
//*	CONFIG2_GET (22)
//*
//*
//*
//*****************************************************************
uint8_t P31u___CONFIG2_GET(void){
	i2cOpen();
	i2cSetAddress(P31U_I2C_ADDRESS);
	//////////////////////////////////////////////////
	uint8_t data[256];
	data[0] = 22;
	data[1] = 0;
	data[2] = 0;
	if (write(g_i2cFile, data, 1) != 1) {
		i2cClose(); return 1; //OK
	}
	//////////////////////////////////////////////////
	int a1=0;
	for(a1 = 0; a1 < 100000000; a1++){
	}
	/////////////////////////////////////////////////P31u_eps_config2_t
	if (read(g_i2cFile, data, 22) != 22) {
		i2cClose(); return 2; //OK
	}else{
		printf("P31u RESPONSE... PORT:(%d) ERROR CODE:(%d)\n\r\n",data[0],data[1]);
		P31u_eps_config2_t.batt_maxvoltage      = data[2]*256  + data[3];
		P31u_eps_config2_t.batt_safevoltage     = data[4]*256  + data[5];
		P31u_eps_config2_t.batt_criticalvoltage = data[6]*256  + data[7];
		P31u_eps_config2_t.batt_normalvoltage   = data[8]*256  + data[9];
		P31u_eps_config2_t.reserved1[0]         = data[10]*16777216  + data[11]*65536  + data[12]*256  + data[13];
		P31u_eps_config2_t.reserved1[1]         = data[14]*16777216  + data[15]*65536  + data[16]*256  + data[17];
		P31u_eps_config2_t.reserved2[0]         = data[18];
		P31u_eps_config2_t.reserved2[1]         = data[19];
		P31u_eps_config2_t.reserved2[2]         = data[20];
		P31u_eps_config2_t.reserved2[3]         = data[21];
	}
	//////////////////////////////////////////////////
	i2cClose(); return 0; //OK
}









//#################################################################
//##	i2c high level
//#################################################################

// set the I2C slave address for all subsequent I2C device transfers
void i2cSetAddress(int address){
	if (ioctl(g_i2cFile, I2C_SLAVE, address) < 0) {
		perror("i2cSetAddress");
		exit(1);
	}else{
		printf("i2cSetAddress %d  OK\r\n",address);
	}
}

// open the Linux device
void i2cOpen(){
	g_i2cFile = open("/dev/i2c-1", O_RDWR);
	if (g_i2cFile < 0) {
		perror("i2cOpen");
		exit(1);
	}else{
		printf("i2cOpen OK\r\n");
	}
}

// close the Linux device
void i2cClose(){
	close(g_i2cFile);
	printf("i2cClose OK\r\n");
}







