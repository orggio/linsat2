#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "i2c.h"



//*****************************************************************
//*	GET_HK_1 (8)
//*
//*
//*
//*****************************************************************
uint8_t PRINT_P31u___GET_HK_1(void){
	uint8_t res = P31u___GET_HK_1();
	if ( res == 0 ){
		printf("\r\n");
		printf("%d mV (0) - Photo-voltaic input voltage\r\n",P31u_hkparam_t.pv[0]);
		printf("%d mV (1) - Photo-voltaic input voltage\r\n",P31u_hkparam_t.pv[1]);
		printf("%d mV (2) - Photo-voltaic input voltage\r\n",P31u_hkparam_t.pv[2]);
		printf("%d mA - Total photo current\r\n",P31u_hkparam_t.pc);
		printf("%d mV - Battery voltage\r\n",P31u_hkparam_t.bv);
		printf("%d mA - Total system current\r\n",P31u_hkparam_t.sc);
		printf("%d C (0) - Temp. of boost converters\r\n",P31u_hkparam_t.temp[0]);
		printf("%d C (1) - Temp. of boost converters\r\n",P31u_hkparam_t.temp[1]);
		printf("%d C (2) - Temp. of boost converters\r\n",P31u_hkparam_t.temp[2]);
		printf("%d C (3) - Temp. of boost converters\r\n",P31u_hkparam_t.temp[3]);
		printf("%d C (0) - External board battery temperatures\r\n",P31u_hkparam_t.batt_temp[0]);
		printf("%d C (1) - External board battery temperatures\r\n",P31u_hkparam_t.batt_temp[1]);
		printf("%d (0) - Number of latch-ups on each output \r\n",P31u_hkparam_t.latchup[0]);
		printf("%d (1) - Number of latch-ups on each output \r\n",P31u_hkparam_t.latchup[1]);
		printf("%d (2) - Number of latch-ups on each output \r\n",P31u_hkparam_t.latchup[2]);
		printf("%d (3) - Number of latch-ups on each output \r\n",P31u_hkparam_t.latchup[3]);
		printf("%d (4) - Number of latch-ups on each output \r\n",P31u_hkparam_t.latchup[4]);
		printf("%d (5) - Number of latch-ups on each output \r\n",P31u_hkparam_t.latchup[5]);
		printf("%d - Cause of last EPS reset\r\n",P31u_hkparam_t.reset);
		printf("%d - Number of EPS reboots\r\n",P31u_hkparam_t.bootcount);
		printf("%d - Number of errors in the eps software\r\n",P31u_hkparam_t.sw_errors);
		printf("%d - .. 0 = Hardware, 1 = MPPT, 2 = Fixed SW PPT\r\n",P31u_hkparam_t.ppt_mode);
		printf("%d - Mask of output channel status, 1=on, 0=off \r\n",P31u_hkparam_t.channel_status);
	} else {
	   switch(res) {
	      case 1  : printf("i2c_write - ERROR\r\n"); break;
	      case 2  : printf("i2c_read - ERROR\r\n"); break;
	      default : printf("unknown - ERROR\r\n");
	   }
	}
	return 0;
}

//*****************************************************************
//*	GET_HK_2 (8.1)
//*
//*
//*
//*****************************************************************
uint8_t PRINT_P31u___GET_HK_2(void){
	uint8_t res = P31u___GET_HK_2();
	if ( res == 0 ){
		printf("%d mV (0) - Voltage of boost converters PV1\r\n",P31u_eps_hk_t.vboost[0]);
		printf("%d mV (1) - Voltage of boost converters PV2\r\n",P31u_eps_hk_t.vboost[1]);
		printf("%d mV (2) - Voltage of boost converters PV3\r\n",P31u_eps_hk_t.vboost[2]);
		printf("%d mV - Voltage of battery\r\n",P31u_eps_hk_t.vbatt );
		printf("%d mA (0) - Current\r\n",P31u_eps_hk_t.curin[0]);
		printf("%d mA (1) - Current\r\n",P31u_eps_hk_t.curin[1]);
		printf("%d mA (2) - Current\r\n",P31u_eps_hk_t.curin[2]);
		printf("%d mA - Current from boost converters\r\n",P31u_eps_hk_t.cursun);
		printf("%d mA - Current out of battery\r\n",P31u_eps_hk_t.cursys);
		//printf("%d (0) - Reserved for future use\r\n",P31u_eps_hk_t.reserved1);
		printf("%d mA (0) - Current out (switchable outputs)\r\n",P31u_eps_hk_t.curout[0]);
		printf("%d mA (1) - Current out (switchable outputs)\r\n",P31u_eps_hk_t.curout[1]);
		printf("%d mA (2) - Current out (switchable outputs)\r\n",P31u_eps_hk_t.curout[2]);
		printf("%d mA (3) - Current out (switchable outputs)\r\n",P31u_eps_hk_t.curout[3]);
		printf("%d mA (4) - Current out (switchable outputs)\r\n",P31u_eps_hk_t.curout[4]);
		printf("%d mA (5) - Current out (switchable outputs)\r\n",P31u_eps_hk_t.curout[5]);
		printf("%d (0) - Status of outputs\r\n",P31u_eps_hk_t.output[0]);
		printf("%d (1) - Status of outputs\r\n",P31u_eps_hk_t.output[1]);
		printf("%d (2) - Status of outputs\r\n",P31u_eps_hk_t.output[2]);
		printf("%d (3) - Status of outputs\r\n",P31u_eps_hk_t.output[3]);
		printf("%d (4) - Status of outputs\r\n",P31u_eps_hk_t.output[4]);
		printf("%d (5) - Status of outputs\r\n",P31u_eps_hk_t.output[5]);
		printf("%d (6) - Status of outputs\r\n",P31u_eps_hk_t.output[6]);
		printf("%d (7) - Status of outputs\r\n",P31u_eps_hk_t.output[7]);
		printf("%d s  (0) - Time till power on\r\n",P31u_eps_hk_t.output_on_delta[0]);
		printf("%d s  (1) - Time till power on\r\n",P31u_eps_hk_t.output_on_delta[1]);
		printf("%d s  (2) - Time till power on\r\n",P31u_eps_hk_t.output_on_delta[2]);
		printf("%d s  (3) - Time till power on\r\n",P31u_eps_hk_t.output_on_delta[3]);
		printf("%d s  (4) - Time till power on\r\n",P31u_eps_hk_t.output_on_delta[4]);
		printf("%d s  (5) - Time till power on\r\n",P31u_eps_hk_t.output_on_delta[5]);
		printf("%d s  (6) - Time till power on\r\n",P31u_eps_hk_t.output_on_delta[6]);
		printf("%d s  (7) - Time till power on\r\n",P31u_eps_hk_t.output_on_delta[7]);
		printf("%d s  (0) - Time till power off\r\n",P31u_eps_hk_t.output_off_delta[0]);
		printf("%d s  (1) - Time till power off\r\n",P31u_eps_hk_t.output_off_delta[1]);
		printf("%d s  (2) - Time till power off\r\n",P31u_eps_hk_t.output_off_delta[2]);
		printf("%d s  (3) - Time till power off\r\n",P31u_eps_hk_t.output_off_delta[3]);
		printf("%d s  (4) - Time till power off\r\n",P31u_eps_hk_t.output_off_delta[4]);
		printf("%d s  (5) - Time till power off\r\n",P31u_eps_hk_t.output_off_delta[5]);
		printf("%d s  (6) - Time till power off\r\n",P31u_eps_hk_t.output_off_delta[6]);
		printf("%d s  (7) - Time till power off\r\n",P31u_eps_hk_t.output_off_delta[7]);
		printf("%d (0) - Number of latch-ups\r\n",P31u_eps_hk_t.latchup[0]);
		printf("%d (1) - Number of latch-ups\r\n",P31u_eps_hk_t.latchup[1]);
		printf("%d (2) - Number of latch-ups\r\n",P31u_eps_hk_t.latchup[2]);
		printf("%d (3) - Number of latch-ups\r\n",P31u_eps_hk_t.latchup[3]);
		printf("%d (4) - Number of latch-ups\r\n",P31u_eps_hk_t.latchup[4]);
		printf("%d (5) - Number of latch-ups\r\n",P31u_eps_hk_t.latchup[5]);
		printf("%d s - Time left on I2C wdt\r\n",P31u_eps_hk_t.wdt_i2c_time_left);
		printf("%d s - Time left on I2C wdt\r\n",P31u_eps_hk_t.wdt_gnd_time_left);
		printf("%d (0) - Pings left on CSP wdt\r\n",P31u_eps_hk_t.wdt_csp_pings_left[0]);
		printf("%d (1) - Pings left on CSP wdt\r\n",P31u_eps_hk_t.wdt_csp_pings_left[1]);
		printf("%d - Number of WDT I2C reboots\r\n",P31u_eps_hk_t.counter_wdt_i2c);
		printf("%d - Number of WDT GND reboots\r\n",P31u_eps_hk_t.counter_wdt_gnd);
		printf("%d (0) - Number of WDT CSP reboots\r\n",P31u_eps_hk_t.counter_wdt_csp[0]);
		printf("%d (1) - Number of WDT CSP reboots\r\n",P31u_eps_hk_t.counter_wdt_csp[1]);
		printf("%d - Number of EPS reboots\r\n",P31u_eps_hk_t.counter_boot);
		printf("%d C - Temperatures TEMP1\r\n",P31u_eps_hk_t.temp[0]);
		printf("%d C - Temperatures TEMP2\r\n",P31u_eps_hk_t.temp[1]);
		printf("%d C - Temperatures TEMP3\r\n",P31u_eps_hk_t.temp[2]);
		printf("%d C - Temperatures TEMP4\r\n",P31u_eps_hk_t.temp[3]);
		printf("%d C - Temperatures BP4a\r\n",P31u_eps_hk_t.temp[4]);
		printf("%d C - Temperatures BP4b\r\n",P31u_eps_hk_t.temp[5]);
		printf("%d - Cause of last EPS reset\r\n",P31u_eps_hk_t.bootcause);
		printf("%d - Mode for battery 0=initial, 1=undervoltage, 2=safemode, 3=nominal, 4=full\r\n",P31u_eps_hk_t.battmode);
		printf("%d - Mode of PPT tracker [1=MPPT, 2=FIXED]\r\n",P31u_eps_hk_t.pptmode);
		//printf("%d -- (0) - \r\n",P31u_eps_hk_t.reserved2);
	} else {
	   switch(res) {
	      case 1  : printf("i2c_write - ERROR\r\n"); break;
	      case 2  : printf("i2c_read - ERROR\r\n"); break;
	      default : printf("unknown - ERROR\r\n");
	   }
	}
	return 0;
}


//*****************************************************************
//*	CONFIG_GET (18)
//*
//*
//*
//*****************************************************************
uint8_t PRINT_P31u___CONFIG_GET(void){
	uint8_t res = P31u___CONFIG_GET();
	if ( res == 0 ){
		printf("%d - Mode for PPT [1 = AUTO, 2 = FIXED]\r\n",P31u_eps_config_t.ppt_mode);
		printf("%d - Mode for battheater [0 = Manual, 1 = Auto]\r\n",P31u_eps_config_t.battheater_mode);
		printf("%d C - -/+ Turn heater on\r\n",P31u_eps_config_t.battheater_low);
		printf("%d C - -/+ Turn heater off\r\n",P31u_eps_config_t.battheater_high);
		printf("%d (0) - Nominal mode output value\r\n",P31u_eps_config_t.output_normal_value[0]);
		printf("%d (1) - Nominal mode output value\r\n",P31u_eps_config_t.output_normal_value[1]);
		printf("%d (2) - Nominal mode output value\r\n",P31u_eps_config_t.output_normal_value[2]);
		printf("%d (3) - Nominal mode output value\r\n",P31u_eps_config_t.output_normal_value[3]);
		printf("%d (4) - Nominal mode output value\r\n",P31u_eps_config_t.output_normal_value[4]);
		printf("%d (5) - Nominal mode output value\r\n",P31u_eps_config_t.output_normal_value[5]);
		printf("%d (6) - Nominal mode output value\r\n",P31u_eps_config_t.output_normal_value[6]);
		printf("%d (7) - Nominal mode output value\r\n",P31u_eps_config_t.output_normal_value[7]);
		printf("%d (0) - Safe mode output value\r\n",P31u_eps_config_t.output_safe_value[0]);
		printf("%d (1) - Safe mode output value\r\n",P31u_eps_config_t.output_safe_value[1]);
		printf("%d (2) - Safe mode output value\r\n",P31u_eps_config_t.output_safe_value[2]);
		printf("%d (3) - Safe mode output value\r\n",P31u_eps_config_t.output_safe_value[3]);
		printf("%d (4) - Safe mode output value\r\n",P31u_eps_config_t.output_safe_value[4]);
		printf("%d (5) - Safe mode output value\r\n",P31u_eps_config_t.output_safe_value[5]);
		printf("%d (6) - Safe mode output value\r\n",P31u_eps_config_t.output_safe_value[6]);
		printf("%d (7) - Safe mode output value\r\n",P31u_eps_config_t.output_safe_value[7]);
		printf("%d s (0) - Output switches: init with these on delays\r\n",P31u_eps_config_t.output_initial_on_delay[0]);
		printf("%d s (1) - Output switches: init with these on delays\r\n",P31u_eps_config_t.output_initial_on_delay[1]);
		printf("%d s (2) - Output switches: init with these on delays\r\n",P31u_eps_config_t.output_initial_on_delay[2]);
		printf("%d s (3) - Output switches: init with these on delays\r\n",P31u_eps_config_t.output_initial_on_delay[3]);
		printf("%d s (4) - Output switches: init with these on delays\r\n",P31u_eps_config_t.output_initial_on_delay[4]);
		printf("%d s (5) - Output switches: init with these on delays\r\n",P31u_eps_config_t.output_initial_on_delay[5]);
		printf("%d s (6) - Output switches: init with these on delays\r\n",P31u_eps_config_t.output_initial_on_delay[6]);
		printf("%d s (7) - Output switches: init with these on delays\r\n",P31u_eps_config_t.output_initial_on_delay[7]);
		printf("%d s (0) - Output switches: init with these off delays\r\n",P31u_eps_config_t.output_initial_off_delay[0]);
		printf("%d s (1) - Output switches: init with these off delays\r\n",P31u_eps_config_t.output_initial_off_delay[1]);
		printf("%d s (2) - Output switches: init with these off delays\r\n",P31u_eps_config_t.output_initial_off_delay[2]);
		printf("%d s (3) - Output switches: init with these off delays\r\n",P31u_eps_config_t.output_initial_off_delay[3]);
		printf("%d s (4) - Output switches: init with these off delays\r\n",P31u_eps_config_t.output_initial_off_delay[4]);
		printf("%d s (5) - Output switches: init with these off delays\r\n",P31u_eps_config_t.output_initial_off_delay[5]);
		printf("%d s (6) - Output switches: init with these off delays\r\n",P31u_eps_config_t.output_initial_off_delay[6]);
		printf("%d s (7) - Output switches: init with these off delays\r\n",P31u_eps_config_t.output_initial_off_delay[7]);
		printf("%d mV (0) - Fixed PPT point for boost converters\r\n",P31u_eps_config_t.vboost[0]);
		printf("%d mV (1) - Fixed PPT point for boost converters\r\n",P31u_eps_config_t.vboost[1]);
		printf("%d mV (2) - Fixed PPT point for boost converters\r\n",P31u_eps_config_t.vboost[2]);
	} else {
	   switch(res) {
	      case 1  : printf("i2c_write - ERROR\r\n"); break;
	      case 2  : printf("i2c_read - ERROR\r\n"); break;
	      default : printf("unknown - ERROR\r\n");
	   }
	}
	return 0;
}

//*****************************************************************
//*	CONFIG_GET (18)
//*
//*
//*
//*****************************************************************
uint8_t PRINT_P31u___CONFIG2_GET(void){
	uint8_t res = P31u___CONFIG2_GET();
	if ( res == 0 ){
		printf("%d mV - batt_maxvoltage\r\n",P31u_eps_config2_t.batt_maxvoltage);
		printf("%d mV - batt_safevoltage\r\n",P31u_eps_config2_t.batt_safevoltage);
		printf("%d mV - batt_criticalvoltage\r\n",P31u_eps_config2_t.batt_criticalvoltage);
		printf("%d mV - batt_normalvoltage\r\n",P31u_eps_config2_t.batt_normalvoltage);
		//printf("%d - (0) reserved1\r\n",P31u_eps_config2_t.reserved1[0]);
		//printf("%d - (1) reserved1\r\n",P31u_eps_config2_t.reserved1[1]);
		//printf("%d - (0) reserved2\r\n",P31u_eps_config2_t.reserved2[0]);
		//printf("%d - (1) reserved2\r\n",P31u_eps_config2_t.reserved2[1]);
		//printf("%d - (2) reserved2\r\n",P31u_eps_config2_t.reserved2[2]);
		//printf("%d - (3) reserved2\r\n",P31u_eps_config2_t.reserved2[3]);
	} else {
	   switch(res) {
	      case 1  : printf("i2c_write - ERROR\r\n"); break;
	      case 2  : printf("i2c_read - ERROR\r\n"); break;
	      default : printf("unknown - ERROR\r\n");
	   }
	}
	return 0;
}
