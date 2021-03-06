//#################################################################

typedef struct {
	uint16_t pv[3];			// Photo-voltaic input voltage [mV]
	uint16_t pc;			// Total photo current [mA]
	uint16_t bv;			// Battery voltage [mV]
	uint16_t sc;			// Total system current [mA]
	int16_t  temp[4];		// Temp. of boost converters (1,2,3) and onboard battery [degC]
	int16_t  batt_temp[2]; 	// External board battery temperatures [degC];
	uint16_t latchup[6]; 	// Number of latch-ups on each output 5V and +3V3 channel
							// Order[5V1 5V2 5V3 3.3V1 3.3V2 3.3V3]
							// Transmit as 5V1 first and 3.3V3 last
	uint8_t  reset; 		// Cause of last EPS reset
	uint16_t bootcount;		// Number of EPS reboots
	uint16_t sw_errors;		// Number of errors in the eps software
	uint8_t  ppt_mode;		// 0 = Hardware, 1 = MPPT, 2 = Fixed SW PPT.
	uint8_t  channel_status;
							// Mask of output channel status, 1=on, 0=off
							// MSB - [QH QS 3.3V3 3.3V2 3.3V1 5V3 5V2 5V1] - LSB
							// QH = Quadbat heater, QS = Quadbat switch
} hkparam_t;



typedef struct {
	uint16_t vboost[3]; 			//! Voltage of boost converters [mV] [PV1, PV2, PV3]
	uint16_t vbatt; 				//! Voltage of battery [mV]
	uint16_t curin[3]; 				//! Current in [mA]
	uint16_t cursun; 				//! Current from boost converters [mA]
	uint16_t cursys; 				//! Current out of battery [mA]
	uint16_t reserved1; 			//! Reserved for future use
	uint16_t curout[6]; 			//! Current out (switchable outputs) [mA]
	uint8_t  output[8]; 			//! Status of outputs**
	uint16_t output_on_delta[8];	//! Time till power on** [s]
	uint16_t output_off_delta[8];	//! Time till power off** [s]
	uint16_t latchup[6];  			//! Number of latch-ups
	uint32_t wdt_i2c_time_left;  	//! Time left on I2C wdt [s]
	uint32_t wdt_gnd_time_left;  	//! Time left on I2C wdt [s]
	uint8_t  wdt_csp_pings_left[2]; //! Pings left on CSP wdt
	uint32_t counter_wdt_i2c;  		//! Number of WDT I2C reboots
	uint32_t counter_wdt_gnd;  		//! Number of WDT GND reboots
	uint32_t counter_wdt_csp[2]; 	//! Number of WDT CSP reboots
	uint32_t counter_boot;   		//! Number of EPS reboots
	int16_t  temp[6];				//! Temperatures [degC] [0 = TEMP1, TEMP2, TEMP3, TEMP4, BP4a, BP4b]
	uint8_t  bootcause; 			//! Cause of last EPS reset
	uint8_t  battmode; 				//! Mode for battery [0 = initial, 1 = undervoltage,  2 = safemode, 3 = nominal, 4=full]
	uint8_t  pptmode; 				//! Mode of PPT tracker [1=MPPT, 2=FIXED]
	uint16_t reserved2;
} eps_hk_t;

typedef struct {
	uint8_t  ppt_mode;  		 		   //! Mode for PPT [1 = AUTO, 2 = FIXED]
	uint8_t  battheater_mode;  		       //! Mode for battheater [0 = Manual, 1 = Auto]
	int8_t   battheater_low;   		       //! Turn heater on at [degC]
	int8_t   battheater_high;  		       //! Turn heater off at [degC]
	uint8_t  output_normal_value[8];       //! Nominal mode output value
	uint8_t  output_safe_value[8];  	   //! Safe mode output value
	uint16_t output_initial_on_delay[8];   //! Output switches: init with these on delays [s]
	uint16_t output_initial_off_delay[8];  //! Output switches: init with these off delays [s]
	uint16_t vboost[3];   				   //! Fixed PPT point for boost converters [mV]
} eps_config_t;


typedef struct {
	uint16_t batt_maxvoltage;
	uint16_t batt_safevoltage;
	uint16_t batt_criticalvoltage;
	uint16_t batt_normalvoltage;
	uint32_t reserved1[2];
	uint8_t  reserved2[4];
} eps_config2_t;


//#################################################################
uint8_t P31u___GET_HK_1(void);		//(8  )
uint8_t P31u___GET_HK_2(void);		//(8.1)
uint8_t P31u___CONFIG_GET(void);	//(18)
uint8_t P31u___CONFIG2_GET(void);	//(22)
//#################################################################

extern hkparam_t    P31u_hkparam_t;
extern eps_hk_t	    P31u_eps_hk_t;
extern eps_config_t P31u_eps_config_t;
extern eps_config2_t P31u_eps_config2_t;
//#################################################################









