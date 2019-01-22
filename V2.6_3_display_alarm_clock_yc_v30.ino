// Copyright (C) 2016 Olivier CROISET. All rights reserved
// Copyright (C) 2017,2018 Elektor Labs (edited). All rights reserverd
/***************************************************************/
/*                     Multidisplay alarm-clock                */
/*                     Olivier CROISET  2016(C)                */
/*                  edited by Elektor Labs 2017(C)             */
/***************************************************************/
/*
-- Modifié YC Novembre 2018 //YC modif V1.0
Ajout traduction en français de tous les textes et ajout période alarme lundi à jeudi et différente valeur chiffrée en déclaration de constante
Le croquis utilise 30162 octets (98%) de l'espace de stockage de programmes. Le maximum est de 30720 octets.
Les variables globales utilisent 1066 octets (52%) de mémoire dynamique, ce qui laisse 982 octets pour les variables locales. Le maximum est de 2048 octets.

-- Modifié YC Novembre 2018 //YC modif V2.0
Ajout LED sur PIN 6 pour affichage alarme activé,
Ajout 2 entrées  A7 et A6 (pour selection cadran avec visu sur ecran des horloges du mode auto , ecran 1 2 3 ou 4, couleur texte écran en mode nuit si mode auto écran en couleur orange ) 
pour selection cadran avec visu sur ecran des horloges du mode auto , ecran 1 2 3 ou 4, couleur texte écran en mode nuit si mode auto écran en couleur orange
AVEC : ___A6_A7_ENABLED___
Le croquis utilise 30720 octets (100%) de l'espace de stockage de programmes. Le maximum est de 30720 octets.
Les variables globales utilisent 1094 octets (53%) de mémoire dynamique, ce qui laisse 954 octets pour les variables locales. Le maximum est de 2048 octets.
SANS : ___A6_A7_ENABLED___
Ajout LED sur PIN 6 pour affichage alarme activé,
add 1 entrée PIN 10 pour selection cadran avec visu sur ecran des horloges du mode auto , ecran 1 2 ou 3, couleur texte écran en mode nuit si mode auto écran en couleur orange
Le croquis utilise 30628 octets (99%) de l'espace de stockage de programmes. Le maximum est de 30720 octets.
Les variables globales utilisent 1093 octets (53%) de mémoire dynamique, ce qui laisse 955 octets pour les variables locales. Le maximum est de 2048 octets.

--Modifié YC Decembre 2018 //V2.1
Renomme divers constante en variable et nom variables différents, suppression de variable non utilisées, passage de lcd.print(F(..)) en lcd.print sans F pour gagner de l'eeprom
et debug alarm en fonction des jours de semaine
SANS : ___A6_A7_ENABLED___
Le croquis utilise 30588 octets (99%) de l'espace de stockage de programmes. Le maximum est de 30720 octets.
Les variables globales utilisent 1471 octets (71%) de mémoire dynamique, ce qui laisse 577 octets pour les variables locales. Le maximum est de 2048 octets.

--Modifié YC Decembre 2018 //V2.2 et 2.3
Ajout ModifyTime pour contrôler si modification date/heure/minute avant d'enregistrer dans DS1302
francais	:	30592 stockage program / 1432 RAM	
english		:	30574 stockage program / 1414 RAM	
german		:	30574 stockage program / 1410 RAM	
italiano 	:  	30546 stockage program / 1394 RAM
spanish 	: 	30620 stockage program / 1442 RAM
Portuguese 	: 	30618 stockage program / 1440 RAM

//V2.4 ( ___FOUR_ALARME___ )
Modif 4 alarmes aux lieu de 9
francais	:	30588 stockage program / 1417 RAM	version 1.8.5 arduino

//V2.5 ( ___INDICATOR__ALARM___ )
Modif ajout disque jaune activation alarm
francais	:	30662 / 30720 stockage program / 1417 RAM	version 1.8.5 arduino

//V2.6 ( __SAVE_EEPROM_CHANGE_SCREEN__ )
Sauvegarde en EEPROM de l'écran en cours de visualisation si écran forcé en manuel
sans version V2.5 et sans __SAVE_EEPROM_CHANGE_SCREEN__
francais	:	30576 / 30720 stockage program / 1417 RAM	version 1.8.5 arduino
sans version V2.5 et avec __SAVE_EEPROM_CHANGE_SCREEN__
francais	:	30632 / 30720 stockage program / 1417 RAM	version 1.8.5 arduino
	avec version V2.5 et sans __SAVE_EEPROM_CHANGE_SCREEN__ et avec ___LED_ALARM___
	francais	:	30650 / 30720 stockage program / 1417 RAM	version 1.8.5 arduino
	avec version V2.5 et sans __SAVE_EEPROM_CHANGE_SCREEN__ et sans ___LED_ALARM___
	francais	:	30624 / 30720 stockage program / 1417 RAM	version 1.8.5 arduino
avec version V2.5 et avec __SAVE_EEPROM_CHANGE_SCREEN__
francais	:	30708 / 30720 stockage program / 1417 RAM	version 1.8.5 arduino

avec version V2.5 et avec __SAVE_EEPROM_CHANGE_SCREEN__ et avec 9 alarmes et sans ___LED_ALARM___
francais	:	30680 / 30720 stockage program / 1432 RAM (69%)	version 1.8.5 arduino
avec version V2.5 et avec __SAVE_EEPROM_CHANGE_SCREEN__ et avec 9 alarmes et avec ___LED_ALARM___
francais	:	30706 / 30720 stockage program / 1432 RAM (69%)	version 1.8.5 arduino


//V2.7 ( ___SETTING_AUTO_HOURS_SCREEN___ )
Modif déclenchement heure paramétrable en auto des différents écrans et modification rectangle effacement caracteres
sans ___LED_ALARM___ et sans __SAVE_EEPROM_CHANGE_SCREEN__
francais	:	32268 / 30720 stockage program / 1545 RAM (75%)	version 1.8.5 arduino	croquis trop gros


/YC modif V2.8
Modif localisation ___INDICATOR__ALARM___ avant texte "Alarm" et clignotement vert/bleu si alarme active, clignotement vert/blanc si mode répétition
Ajustement luminosité toutes les minutes au lieu de toutes les secondes et rafraichissement écran si changement jour ( pour raffraichissement de la date )
Ajout fonction effacement écran, ajout AlerArmed en remplacement de SnoozeOn et BeepOn 
avec ___INDICATOR__ALARM___ et sans __SAVE_EEPROM_CHANGE_SCREEN__ et avec ___FOUR_ALARME___ et sans ___LED_ALARM___
francais	:	29672 / 30720 stockage program / 1401 RAM (68%)	version 1.8.5 arduino

 avec ___SAVE_EEPROM_CHANGE_VALIDATE_ALARM___
francais	:	+ 28 stockage program / + 1 RAM version 1.8.5 arduino

 avec ___LED_ALARM___
francais	:	+ 44 stockage program version 1.8.5 arduino

 avec __SAVE_EEPROM_CHANGE_SCREEN__
francais	:	+ 46 stockage program version 1.8.5 arduino

 avec ___LED_DEBUG___
francais	:	+ 120 stockage program version 1.8.5 arduino

avec ___INDICATOR__ALARM___ et sans __SAVE_EEPROM_CHANGE_SCREEN__ et avec ___FOUR_ALARME___ et sans ___LED_ALARM___ zt avec ___SETTING_AUTO_HOURS_SCREEN___
francais	:	30996 / 30720 stockage program / 1519 RAM (73%)	version 1.8.5 arduino	-->	croquis trop gros
(276 en trop )


//YC modif V2.9
Création fonction StepAdjust() et StepAdjustTime()
avec ___INDICATOR__ALARM___ et sans __SAVE_EEPROM_CHANGE_SCREEN__ et avec ___FOUR_ALARME___ et sans ___LED_ALARM___ zt avec ___SETTING_AUTO_HOURS_SCREEN___
francais	:	29740 / 30720 stockage program / 1477 RAM (72%)	version 1.8.8 arduino

ALL
francais	:	29858	 / 30720 stockage program / 1477 RAM (72%)	version 1.8.8 arduino	

//YC modif V3.0
Création fonction StepAdjustLDR() et debug save LDR en eeprom; ajout debug reste mémoire RAM disponible fonction freeRAM() appelé avec ____DEBUG__PROG____
avec ___INDICATOR__ALARM___ et sans __SAVE_EEPROM_CHANGE_SCREEN__ et avec ___FOUR_ALARME___ et sans ___LED_ALARM___ zt avec ___SETTING_AUTO_HOURS_SCREEN___
francais	:	29836 / 30720 stockage program / 1477 RAM (72%)	version 1.8.5 arduino

ALL
francais	:	29922 ( avec EEPROM update ) / 30720 stockage program / 1477 RAM (72%)	version 1.8.8 arduino	
				30036 (+114 octets) ( avec ____DEBUG__PROG____ renvoi reste mémoire RAM disponible ) / 1481 ( +4 octets ) RAM (72%)
*/

// http://www.RinkyDinkElectronics.com/
// https://github.com/olikraus/lcdlib/wiki/reference
// http://www.proftnj.com/RGB3.htm  for RGB colors definitions
// http://arduiniana.org/libraries/streaming/ for strings concatenation
// Using TimerOne Library
// Consumption:
// ILI 9341     : 25 mA
// Screen LEDs  :  5 mA
// AtMega328    :  7 mA

//#define ___LED_DEBUG___	1	// YC modif V2.8_1
#ifndef 	___LED_DEBUG___
	#define ___LED_ALARM___  1      	//YC modif V2.0	
#endif
#define ___INDICATOR__ALARM___ 1	//YC modif V2.5
#define ___SCREEN_CHANGE___ 1		//YC modif V2.0	
#define ___FOUR_ALARME___ 1		// YC modif V2.4
//#define ___SAVE_EEPROM_CHANGE_VALIDATE_ALARM___ 1 	//YC modif V2.8
//#define __SAVE_EEPROM_CHANGE_SCREEN__ 1	//YC modif V2.6
#define ___SETTING_AUTO_HOURS_SCREEN___ 1 //YC modif V2.7
#define ____DEBUG__PROG____	1	// YC modif V2.8_2 and V3.0
//#define ___SETTING_DISPLAY___ 1 //CROISET modify V7.0
//#define ___A6_A7_ENABLED___  1      //YC modif V2.0
//#define ___SERIAL_DEBUG___ 1		  //YC modif V1.0

 /*
 * Ecran ILI9346 avec interface SPI // horloge DS1302 avec IO & bp 
 * Pin connectés sur Arduino :  
 * ILI9346 SPI SCK  : Pin 13  
 * ILI9346 SPI MISO : Pin 12   
 * ILI9346 SPI MOSI : Pin 11 
 * PB ReadPbScreen (....)      : Pin 10    (INPUT PULLUP) ( if not ___A6_A7_ENABLED___ and if ___SCREEN_CHANGE___)
 * ILI9346 F    : Pin 9   (pwm OUTPUT)  
 * ILI9346 SPI RST  : Pin 8
 * ILI9346 SPI RST  : Pin 7 
 * LED ALARME: Pin 6    (pwm OUTPUT ) //YC modif V2.0
 * ILI9346 SPI CS   : Pin 5  
 * DS 1302  CE    : Pin 4  
 * DS 1302  IO    : Pin 3 
 * DS 1302  SCK   : Pin 2 
 *  
 * ( if ___A6_A7_ENABLED___  )
 * PB ReadPbA7 (....)          : Pin A7  (INPUT, put a resistor on VCC of 47K)  //YC modif V2.0
 * PB ReadPbScreen (....)      : Pin A6  (INPUT, put a resistor on VCC of 47K)  //YC modif V2.0

 * PB ReadPbAlarm (SELECTION)   : Pin A5  (INPUT PULLUP)
 * PB ReadPbLess (--)            : Pin A4  (INPUT PULLUP)
 * PB ReadPbMore (++)            : Pin A3  (INPUT PULLUP)
 * PB ReadPbOk (OK)            : Pin A2  (INPUT PULLUP)
 * LDR                : Pin A1  (INPUT)
 * BUZZER           : Pin A0  (OUTPUT)
 */
 
#include <DS1302.h>
#include <SPI.h>
#include <Streaming.h>
#include "Ucglib.h"
#include "EEPROM.h"
#include "TimerOne.h"

// traduction	//YC modif V1.0	
#define ___francais___  1	/* add // no select french	*/
#ifndef ___francais___	// no select french
	#define ___english___  1	/* add // no select english	*/
	#ifndef ___english___	// no select english
		#define ___deutsch___  1	/* add // no select german	*/
		#ifndef ___deutsch___	// no select german
			#define ___italiano___  1	/* add // no select italiano */
			#ifndef ___italiano___	// no select italiano
				#define ___espanol___ 1	/* add // no select spanish */
				#ifndef ___espanol___	// no select spanish
					#define ___portugues___ 1	//select portuguese
				#endif
			#endif
		#endif
	#endif
#endif

/* IF we need activ printing */
#ifdef ___SERIAL_DEBUG___
	#define DEBUGPRINT( X ) Serial.print( X ) 
#else
	#define DEBUGPRINT( X )  do{ }while( 1 == 0) 
#endif

#define MAX_BEEP_TIME_MIN  ( 15 )

/* Library Streaming (Example):
int h = 14;
int m = 6
lcd << ((h<10)?"0":"") << h << ":" << ((m<10)?"0":"") << m ; endl; // for leading 0 in time format
*/
// Keys for time setting    A4    A3    A2
//                         "-"   "+"   "OK"

#define PinBeeper A0
#define PinLDR A1
#define PinBpOK A2            // Key ReadPbOk = Ok
#define PinBpMore A3            // Key ReadPbMore = Right or "+"    
#define PinBpLess A4            // Key ReadPbLess = Left or "-"
#define PinBpAlarm A5            // Key ReadPbAlarm = ^ or SEL
#ifdef ___A6_A7_ENABLED___  //YC modif V2.0
	#ifdef ___SCREEN_CHANGE___
		#define PinBpScreen A6            // Key ReadPbScreen = change screen  //YC modif V2.0
	#endif
	#define PinPB_A7 A7            // Key ReadPbA7 = available //YC modif V2.0
#endif  //YC modif V2.0   
// keep the pin 0 and 1 free for Rx and Tx    
#define PinDS1302SCLK 2
#define PinDS1302IO 3
#define PinDS1302CE 4
#define PinScreenCS 5
#ifdef ___LED_ALARM___ 
	#define PinLEDAlarm 6   //YC modif V2.0
#elif ___LED_DEBUG___		// YC modif V2.8_1	
	#define PinLEDAlarm 6   //YC modif V2.0
#endif
#define PinScreenRST 7
#define PinScreenDC 8
#define PinScreenLight	9	//YC modif V2.0
#ifndef ___A6_A7_ENABLED___  //YC modif V2.0
	#ifdef ___SCREEN_CHANGE___
		#define PinBpScreen 10     // Key ReadPbScreen = change screen  //YC modif V2.0
	#endif
#endif  //YC modif V2.0
//PinScreen SPI MOSI 11
//PinScreen SPI MISO 12  
//PinScreen SPI SCK  13  
 


// DS1302 Initialisation
// DS1302  rtc(CE, IO, SCLK)
DS1302 rtc(PinDS1302CE, PinDS1302IO, PinDS1302SCLK);
/* If you like to use an other watch here, you need to change the library here */

// Init the TFT screen          lcd( dc, cs, reset)
Ucglib_ILI9341_18x240x320_HWSPI lcd( PinScreenDC,   PinScreenCS,   PinScreenRST);
// The LCD uses the AVR HW SPI ( MOSI, SCK ) and also the three given pins
// MISO is not used, this means we can't read data back from the lcd

/* As we don't change this during runtime we can use a define to save RAM and code */
#define DureeAppui ( 3 )           // Push duration on the keys //old 2 // YC modif V2.0

/* This is for some eeprom positions */
#define EEPLIGHT_ADDR        ( 512 )	//adress configuration tags auto_dimmer
#ifdef ___SAVE_EEPROM_CHANGE_VALIDATE_ALARM___	//YC modif V2.8
	#define EEPALERTONOFF_ADDR   ( 513 )
#endif
#define EEPLDRCALOFFSET_ADDR ( 1000)	// 8 bytes

#ifdef __SAVE_EEPROM_CHANGE_SCREEN__	//YC modif V2.6
	#define EEPDISPLAYROTATION_ADDR  ( 514 ) 
#endif
#ifdef ___SETTING_AUTO_HOURS_SCREEN___	//YC modif V2.7
	#define EEPAUTOHOURSSCRENN_ADDR   ( 520 )	// 6 octets to adress 525
#endif

//======================================= Variables for the DS1302
int16_t myYear;
int8_t myMonth, myDate, myHour, mySec , myMin, myDow;

// int8_t currentHour;	// (not used ) 	//YC modif V2.1
int8_t previousDate ;	//YC modif V2.8
int8_t previousHour, previousMin, previousSec;
int8_t ModifyTime = 0 ; //add YC modif V2.1

#define MaxHours ( 23 )	//YC modif V2.8
#define Ypos ( 30 )
#define Xpos ( 0 )

typedef struct {
	uint8_t Red;
	uint8_t Green;
	uint8_t Blue;
} Color_t;

typedef struct{
	uint16_t LDR_BRIGHT;
	uint16_t INV_LDR_BRIGHT;
	uint16_t LDR_DARK;
	uint16_t INV_LDR_DARK;
} LDR_CAL_t;

/*typedef enum {	// CROISET modify V7.0
	DISPLAY_AUTO=0,
	DISPLAY_ONE,
	DISPLAY_TWO,
	DISPLAY_THREE,
	DISPLAY_SCREEN_CNT
  
} display_screen_t;

typedef struct{		// CROISET modify V7.0
	display_screen_t displaymode;
} display_settings_t;
*/
float angleMin = 0;           // minute hand angle
float angleHour = 0;          // hour hand angle
float angleMinForHour = 0;

// (not used ) 	//YC modif V2.1
//float angleSecPrec;           // second hand angle in triangle shape for SecondeEphemere
//float angleSec = 0;           // second hand angle

// Variables for the CadranAiguilles
// tetragones points of the minutes hand, and erease
int16_t Mhdx, Mhdy, Mhgx, Mhgy, Mbgx, Mbgy, Mbdx, Mbdy;
int16_t Mhdxprec, Mhdyprec, Mhgxprec, Mhgyprec, Mbgxprec, Mbgyprec, Mbdxprec, Mbdyprec;

// tetragones points of the hour hand, and erease
int16_t Hhdx, Hhdy, Hhgx, Hhgy, Hbgx, Hbgy, Hbdx, Hbdy;
int16_t Hhdxprec, Hhdyprec, Hhgxprec, Hhgyprec, Hbgxprec, Hbgyprec, Hbdxprec, Hbdyprec;


// (not used ) 	//YC modif V2.1
//float angletick, x1Trait, y1Trait, x2Trait, y2Trait ;	


//======================================= alarm
//AlertArmed  si ==0 (BeepOn=0 and BeepSnooze=0), ==1 (BeepSnooze=1), ==2 (BeepOn=1) , ==3 (BeepOn=1 and BeepSnooze=1) 	modif YC V2.8
typedef struct{
	// allocation de 1 bit en mémoire pour des booléans 	// http://www.tutorialspoint.com/cprogramming/c_bit_fields.htmmodif 
	// declaration 2 états ( boolean ) avec :1
	/*uint8_t BeepOn:1;	//delete modif YC V2.8
	uint8_t SnoozeOn:1;	*/	//delete modif YC V2.8
	uint8_t AlertArmed;   //add YC V2.8
	// uint8_t Reserved:5;	//delete modif YC V2.1
	uint8_t SnoozeHour;
	uint8_t SnoozeMinute;
} AlertBits_t;

volatile uint16_t BeepRunCnt;
volatile AlertBits_t AlertBits;

// Alarm time variables
typedef struct {
	uint8_t Hour;
	uint8_t Minute;
	uint8_t Day;
} Alarm_t;

/* We need 9 to set and one to work with --> USERALARMCNT = 9 alarm + 1  */
#ifdef ___FOUR_ALARME___
	#define USERALARMCNT ( 5 )	//modif to 5 --> YC modif V2.4
#else
	#define USERALARMCNT ( 10  )
#endif
volatile Alarm_t UserAlarm[USERALARMCNT];

// (not used ) 	//YC modif V2.1
//int8_t AlarmIndex = 0;
int8_t Alarmx = 0;
int16_t BlackNext = 0;
int16_t AlarmNext = 0;
boolean NextAlarm;
int16_t AlarmDistance;

boolean ValidateAlarm = true;
boolean ToggleBeeper = true;
boolean refreshScreen = true;
int8_t selectScreen = 0;  //add YC modif V2.0
#define MaxScreen ( 4 ) // addd YC modif V2.6
int8_t SnoozeAddMinute = 10; //repeat after 1 st alarm in minutes //YC modif V2.0
#ifdef ___LED_ALARM___
	boolean toggleLEDAlarm = 0;	// add YC modif V2.1
#elif ___INDICATOR__ALARM___
	boolean toggleLEDAlarm = 0;	// add YC modif V2.5	
#endif

// for the key scanning
volatile uint8_t ReadPbLess;                        // input filtering on ReadPbLess
volatile uint8_t ReadPbMore;                        // input filtering on ReadPbMore
volatile uint8_t ReadPbOk;                        // input filtering on ReadPbOk
volatile uint8_t ReadPbAlarm;                        // input filtering on ReadPbAlarm
#ifdef ___SCREEN_CHANGE___
	volatile uint8_t ReadPbScreen;                        // input filtering on ReadPbScreen //YC modif V2.0
#endif
#ifdef ___A6_A7_ENABLED___  //YC modif V2.0
	volatile uint8_t ReadPbA7;                        // input filtering on ReadPbA7 //YC modif V2.0
#endif  //YC modif V2.0


volatile byte MemoryReadTouch;  // key pressed
#define MemoryReadPbOK ( 3 )	// add YC modif V2.1
#define MemoryReadPbAlarm ( 4 )	// add YC modif V2.1

Time t_temp;

volatile LDR_CAL_t LDR_Calibration; /* LDR Calibration Values for the Devices */
//volatile display_settings_t displaysettings; // CROISET modify V7.0


//char textTypeMonth[nombre de chaines][length of strings, add 1 for the final \0 ]

#define number_day_state 9	// old 8 ==> now 9 "never"  // YC modif V2.0
#ifdef ___francais___   //YC modif V1.0
	// French
	char textTypeMonth[][10] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
	//char textTypeDay[][13] =   {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche", "Lun-Ven", "Jamais"};
	char textTypeDay[][9] =   {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche", "Lun-Jeu", "Lun-Ven", "Inactif"}; //YC modif V1.0
	char textTypeScreenLight[][5]    = {"Auto","Max ","Norm ","Min "}; //YC modif V1.0
#elif ___english___
	// English
	char textTypeMonth[][10]    = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	char textTypeDay[][9]    =    {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Mon-Thu","Mon-Fri", "Never"};
	char textTypeScreenLight[][5]    = {"Auto","Max ","Med ","Low "};
#elif ___deutsch___
	// German
	char textTypeMonth[][10] = {"Januar", "Februar", "Maerz", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"};
	char textTypeDay[][10] =   {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag","Mon-Don", "Mon-Fre", "Nie"};
	char textTypeScreenLight[][5]    = {"Auto","Max ","Par ","Min "}; //YC modif V1.0
#elif ___italiano___
	// Italiano
	char textTypeMonth[][10] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};
	char textTypeDay[][10] =   {"Lunedi", "Martedi", "Mercoledi", "Giovedi", "Venerdi", "Sabato", "Domenica","Lun-Gio", "Lun-Ven", "Mai"};
	char textTypeScreenLight[][5]    = {"Auto","Mass","Par ","Min "}; //YC modif V1.0
#elif ___espanol___
	// Spanish
	char textTypeMonth[][11] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
	char textTypeDay[][10] =   {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo","Lun-Jue","Lun-Vie","Nunca"};
	char textTypeScreenLight[][5]    = {"Auto","Man ","Par ","Min "}; //YC modif V1.0
#elif ___portugues___
	// Portuguese
	char textTypeMonth[][10] = {"Janeiro", "Fevereiro", "Marte", "Abril", "Mayo", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
	char textTypeDay[][11] =   {"Segunda-f.", "Terca-f.", "Quarta-f.", "Quinta-f.", "Sexta-f.", "Sabado", "Domingo", "Seg-Qui", "Seg-Sex", "Sempre"};
	char textTypeScreenLight[][5]    = {"Auto","Man ","Par ","Min "}; //YC modif V1.0
#endif
	char SCREEN[][5]    = {"$aut","$  I","$ II","$III","$ IV"}; //YC modif V2.0

#ifdef ___SETTING_AUTO_HOURS_SCREEN___	//YC modif V2.7	
	typedef struct {
		uint8_t N_11;
		uint8_t N_12;
		uint8_t N_21;
		uint8_t N_22;
		uint8_t N_31;
		uint8_t N_32;
		//uint8_t N_41;
	} HourScreen_t;

	volatile HourScreen_t HourScreen;
#endif

// variables for the LED dimming
volatile bool SecondTick;
volatile bool MinuteTick;
//volatile int8_t last_screen=-1; //delete YC modif V2.1
volatile uint8_t auto_dimmer=0;
volatile int8_t previousScreen=-1;
volatile int8_t newScreen=0;	//add variable YC modif V2.0

/*==================================================*/
// https://www.carnetdumaker.net/articles/lire-et-ecrire-des-donnees-sur-une-carte-sd-avec-une-carte-arduino-genuino/
/* Utilitaire pour calculer la mémoire RAM disponible */
/* Si vous voyez la mémoire RAM disponible descendre en dessous des 128 octets, c’est le signe qu’il va falloir faire attention */
int freeRam() {
  extern int __heap_start, *__brkval;
  int v;
  //_NOP() ; // ajout d'un delay de 1 micro seconde
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

/*==================================================*/
/* ---------------  START OF SETUP  --------------- */ 
/*==================================================*/
void setup()
{
	#ifdef ___LED_ALARM___ 
		pinMode(PinLEDAlarm, OUTPUT); // LED alarm enabled  //YC modif V2.0
	#elif ___LED_DEBUG___		// YC modif V2.8_1
		pinMode(PinLEDAlarm, OUTPUT); // LED debug enabled  //YC modif V2.8
	#else
		pinMode(6, INPUT_PULLUP);     // available //YC modif V1.0
	#endif
	
	#ifdef ___SCREEN_CHANGE___
		pinMode(PinBpScreen, INPUT_PULLUP);      // reserved Touch ReadPbScreen if not ___A6_A7_ENABLED___ sinon disponible
	#else
		pinMode(10, INPUT_PULLUP);      // reserved Touch ReadPbScreen if not ___A6_A7_ENABLED___ sinon disponible	
	#endif

	pinMode(PinBpAlarm, INPUT_PULLUP);   // sets the analog pin A5 as input -> AlarmSwitch ( Multipurpose)  
	pinMode(PinBpLess, INPUT_PULLUP);   // sets the analog pin A4 as input
	pinMode(PinBpMore, INPUT_PULLUP);  // sets the analog pin A3 as input
	pinMode(PinBpOK, INPUT_PULLUP);   // sets the analog pin A2 as input
	pinMode(PinLDR, INPUT_PULLUP);   // sets the analog pin A1 as output -> LDR for screen LEDs control
	pinMode(PinBeeper, OUTPUT);     // sets the analog pin A0 as output -> beeper

	pinMode(PinScreenLight, OUTPUT);    // TFT LED setting pin 9

	// 3,3 V; for the light sensor, for display dimming
	// connect AVCC to Vcc (+ 3,3 Volts)
	// connect AREF to Vcc (+ 3,3 Volts)
	analogReference(DEFAULT);  // = 3,3 volts
	/* Be aware that we are running at 12MHz and this seems done for 16MHz */

	// Not used analogWrite() for digital pins 9 and 10 on Arduino if Timer1 is used
	Timer1.initialize(1000);         // initialize timer1, and set it to 1000 microsecondes --> 1 milli secondes --> 1000Hz
	Timer1.pwm(PinScreenLight, 512); // setup pwm on pin 9, 50% duty cycle
	Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
	// =========================================== end of the Timer1 setting for the key scan

	// Init of the screen ILI9341
	lcd.begin(UCG_FONT_MODE_SOLID);
	ClearScreenDisplay();	// YC modif V2.8
	lcd.setRotate90();  // Rotate in landscape format, connector on the right side
	lcd.setFont  (ucg_font_9x15_tr);               // Font select
	
	// Setting of the values stored in the DS1302
	// Set the clock to run-mode, and disable the write protection
	rtc.halt(false);                               // for clock validation
	rtc.writeProtect(false);

	UserAlarm[0].Hour=0;
	UserAlarm[0].Minute=0;
	UserAlarm[0].Day=number_day_state; // old 8 ==> now 9 "never"  // YC modif V2.0

	/* At this point we should load the settings from EEPROM if they are valid */
	uint8_t* AlPtr;
	AlPtr=(uint8_t*)&UserAlarm[1];
	for(uint8_t i=0;i< ( sizeof(UserAlarm) - sizeof(Alarm_t) );i++){
		*AlPtr=EEPROM.read(i);
		AlPtr++;
	}
	for(uint8_t i=0; i < ( sizeof(UserAlarm)/sizeof(Alarm_t) ) ; i++){
		if( (UserAlarm[i].Hour>MaxHours) || (UserAlarm[i].Minute>59) || (UserAlarm[i].Day>number_day_state) ){ // old (UserAlarm[i].Day>8 ==> now 9 "never"  // YC modif V2.0
			UserAlarm[i].Hour=0;
			UserAlarm[i].Minute=0;
			UserAlarm[i].Day=number_day_state; // old 8 ==> now 9 "never"  // YC modif V2.0
		}
	}
	/* We need to load some settings */
	auto_dimmer = EEPROM.read( EEPLIGHT_ADDR );
	if(auto_dimmer > 4){
		auto_dimmer = 0;
		EEPROM.write( EEPLIGHT_ADDR, 0 );
	}
	
	// CROISET modify V7.0
	/*displaysettings.displaymode = EEPROM.read(EEPDISPLAYROTATION_ADDR);
	if( displaysettings.displaymode >= DISPLAY_SCREEN_CNT ){
		EEPROM.write( EEPDISPLAYROTATION_ADDR, DISPLAY_AUTO );
	} */
	
	// YC modif V2.6
	#ifdef __SAVE_EEPROM_CHANGE_SCREEN__	//YC modif V2.6
		if (EEPROM.read(EEPDISPLAYROTATION_ADDR) <= MaxScreen) {
			selectScreen = EEPROM.read(EEPDISPLAYROTATION_ADDR);
		} else {
			EEPROM.write( EEPDISPLAYROTATION_ADDR, 0 );
		} 
	#endif
	
	uint8_t* LDRCalPtr;
	LDRCalPtr=(uint8_t*)&LDR_Calibration;
	for(uint8_t i=0;i< ( sizeof( LDR_CAL_t ));i++){
		*LDRCalPtr=EEPROM.read(i+EEPLDRCALOFFSET_ADDR);
		LDRCalPtr++;
	}

	if(LDR_Calibration.LDR_BRIGHT != (~LDR_Calibration.INV_LDR_BRIGHT) ){
		/* Brightvalue damaged */
		auto_dimmer=1;
		EEPROM.write( EEPLIGHT_ADDR, 1 );
	}

	if(LDR_Calibration.LDR_DARK != (~LDR_Calibration.INV_LDR_DARK) ){
		/* Brightvalue damaged */
		auto_dimmer=1;
		EEPROM.write( EEPLIGHT_ADDR, 1 );
	}

	#ifdef ___SETTING_AUTO_HOURS_SCREEN___	//YC modif V2.7	
		uint8_t* SrcPtr;
		SrcPtr=(uint8_t*)&HourScreen;
		for(uint8_t i=0;i< ( sizeof( HourScreen_t ));i++){
			*SrcPtr=EEPROM.read(i+EEPAUTOHOURSSCRENN_ADDR);
			SrcPtr++;
		}	
		
		Init_EEPROM_Screen( HourScreen.N_11, 13 , 0 );	//YC modif V2.9
		Init_EEPROM_Screen( HourScreen.N_12, 17 , 1 );	//YC modif V2.9
		Init_EEPROM_Screen( HourScreen.N_21, 9 , 2 );	//YC modif V2.9
		Init_EEPROM_Screen( HourScreen.N_22, 13 , 3 );	//YC modif V2.9
		Init_EEPROM_Screen( HourScreen.N_31, 17 , 4 );	//YC modif V2.9
		Init_EEPROM_Screen( HourScreen.N_32, 21 , 5 );	//YC modif V2.9
	#endif


	#ifdef ___SAVE_EEPROM_CHANGE_VALIDATE_ALARM___	//YC modif V2.8
		ValidateAlarm = EEPROM.read( EEPALERTONOFF_ADDR );  
	#endif
	
	// read time and today's date
	RTC_ReadTime();

	#ifdef ___SERIAL_DEBUG___
		Serial.begin (250000);                         //  = 882 octets
		Serial.println (F("Start of Watch"));
	#endif  
	DEBUGPRINT( F(".") );
	//refreshScreen = true;
	//AlertBits.BeepOn=LOW;	//YC modif V2.8
	AlertBits.AlertArmed = 0; //YC modif V2.8
	/* Load next alert */
	GetNextAlert(true);
}
/*==================================================*/
/* -----------------  END SETUP  ------------------ */ 
/*==================================================*/
void Init_EEPROM_Screen ( uint8_t Tags, uint8_t defaults, uint8_t EEPADD)	//YC modif V2.9
{
	#ifdef ___SETTING_AUTO_HOURS_SCREEN___
		if (Tags>MaxHours) { Tags = defaults; EEPROM.write( EEPAUTOHOURSSCRENN_ADDR + EEPADD , Tags); delay (50);  }
	#endif
}
/*==================================================*/
/* -----VOID callback() CALL TO 0.001 second-------- */ 
/*==================================================*/
// attaches callback() as a timer overflow interrupt
void callback()
{
	/* variable pour stocker la valeur dans la fonction - déclarée avec static et donc conserve la
      valeur entre 2 appels de la fonction et aucune autre fonction ne peut changer sa valeur. */
	static uint8_t prescale_touches = 0;
	static uint8_t prescaler_buzzer = 0;
	
   
	#ifdef ___LED_DEBUG___		// YC modif V2.8_1	
		static uint8_t prescale_debug = 0;	
		
		if (AlertBits.AlertArmed==0) {
				digitalWrite(PinLEDAlarm,0) ; 
		} else {	
			static boolean prescale_led = 0;	
				prescale_debug++;
				if (prescale_debug%10) { prescale_led = not prescale_led ; }
				switch(AlertBits.AlertArmed) {	
					case 1: {
						if (prescale_debug>20) { prescale_led = 0 ; }
					} break;
					case 2: {	
						if (prescale_debug>40) { prescale_led = 0 ; }
					} break;
					case 3: {	
						if (prescale_debug>60) { prescale_led = 0 ; }	
					} break;													
					default:{       
					} break;
				}		
			digitalWrite(PinLEDAlarm,prescale_led) ;
		}
		if ( prescale_debug >= 200 ) { prescale_debug=0 ; }		
	#endif		   
   
	if(prescale_touches>=10){	// 10 ms --> 0.01 second
		MemoryReadTouch = ValueReadTouch();	// CALL TO 0.01 second (100 hz)
		prescale_touches=0;
		prescaler_buzzer++;	// ADD TO 0.01 second (100 hz)
	} else {
		prescale_touches++;
	}

	if(prescaler_buzzer>=100){	/// ADD TO 10 ms  * 100 --> 1 second (1Hz)
		Buzzer();  // CALL TO 1 second (1 hz)
		prescaler_buzzer=0;
	}
	
}
/*==================================================*/
/*----------------END VOID CALLBACK()-------------- */ 
/*==================================================*/


/*==================================================*/
/*                 MAIN LOOP                        */
/*==================================================*/
void loop()
{
	
	RTC_ReadTime();
	
	if(previousSec != mySec){
		SecondTick=true;
		//Backlight();	//delete YC modif V2.8
		//previousSec  = mySec;	//delete YC modif V2.8
		

		#ifdef ___LED_ALARM___ 
			// LED alarm
			toggleLEDAlarm = not toggleLEDAlarm ; 			//YC modif V2.1 
			if ( ValidateAlarm==HIGH && /*AlertBits.SnoozeOn==LOW*/ AlertBits.AlertArmed==0) { //YC modif V2.1 et V2.8
				digitalWrite(PinLEDAlarm,1) ; 
				#ifdef ___INDICATOR__ALARM___
					if (toggleLEDAlarm ) {	//YC modif V2.8
						LcdColorGreen();	//YC modif V2.8
					} else {	
						LcdColorOrange();
					}						
				#endif
			} else if ( /*AlertBits.SnoozeOn==HIGH*/ AlertBits.AlertArmed>0 ) {  //YC modif V2.1 and V2.8	
				digitalWrite(PinLEDAlarm,toggleLEDAlarm ) ; //YC modif V2.1
				#ifdef ___INDICATOR__ALARM___
					if (toggleLEDAlarm ) {	//YC modif V2.5
						LcdColorWhite();
					} else {	//YC modif V2.5
						LcdColorBlue();				
					}	
				#endif
			} else {  
				digitalWrite(PinLEDAlarm,0) ; 
				#ifdef ___INDICATOR__ALARM___
					LcdColorBlack( LOW /* delay(50) */); // black	
				#endif
			} 
			#ifdef ___INDICATOR__ALARM___
				lcd.drawDisc( 10, 10, 7, UCG_DRAW_ALL);	//YC modif V2.8
			#endif
		#elif ___INDICATOR__ALARM___
			// indicator alarm
			toggleLEDAlarm = not toggleLEDAlarm ; 			//YC modif V2.1 
			//YC modif V2.8
			if ( ValidateAlarm==HIGH || /*AlertBits.SnoozeOn==HIGH*/ AlertBits.AlertArmed>0 ) {	//YC modif V2.8
				if (toggleLEDAlarm ) {
					LcdColorGreen(); 	//YC modif V2.8
				} else {
					if ( /*AlertBits.SnoozeOn==HIGH*/ AlertBits.AlertArmed>0 ) {	//add modif YC V2.1 and V2.8
						LcdColorWhite();
					} else {
						LcdColorBlue();
					}
				}	
			} else {  
					LcdColorBlack( LOW /* delay(50) */); // black
			}
			lcd.drawDisc( 10, 10, 7, UCG_DRAW_ALL);	//YC modif V2.8
		#endif
	} 

	if(previousMin !=  myMin){
		MinuteTick=true;
		Backlight();	//new YC modif V2.8
		//previousMin  = myMin;	//del YC modif V2.8
	}
	
	//previousSec  = mySec;	// delete	YC modif V2.1
	//previousMin  = myMin;	// delete YC modif V2.1
	//previousHour = myHour;	// not used YC modif V2.1
	//previousDate = myDate;	// not used YC modif V2.1

	// ========================= TURNING DISPLAY =========================
	//  if (myHour != previousHour ) {  //delete YC modif V2.0  
	if ( previousDate !=  myDate) { //YC modif V2.8
		ClearScreenDisplay();	// YC modif V2.8
		previousDate  = myDate;	//YC modif V2.8
	}
	if ( previousScreen != newScreen && selectScreen ==0 ) { //YC modif V2.8
		ClearScreenDisplay();	// YC modif V2.8
		previousScreen = newScreen;  //YC modif V2.0
	}
	//delete YC modif V2.8
	/*if (myHour!= previousHour) {
		previousHour = myHour;
		ClearScreenDisplay();
	}
	*/
	
	// CROISET modify V7.0
	/*	
	// This will be used to determine which screen / display to show  
	uint8_t screen = 0;	
	//If we are not running in auto mode we need to chage thi here a bit 
	switch ( displaysettings.displaymode ){
		case DISPLAY_AUTO:{
			screen = ( myHour % 3 );
				if( screen > 2 ){
				screen = 0;
				}
		} break;
  
		case DISPLAY_ONE:{
			screen = 0;
		} break;
  
    
		case DISPLAY_TWO:{
			screen = 1;
		} break;
    
		case DISPLAY_THREE: {
			screen = 2;
		} break;
    
		default:{
			screen = 0;
			displaysettings.displaymode = DISPLAY_AUTO;
    }    
  }
*/
	// ======================= selected screen
	#ifdef ___SETTING_AUTO_HOURS_SCREEN___
		if (( myHour >=HourScreen.N_11 && myHour <HourScreen.N_12 && selectScreen ==0 ) || selectScreen == 1 ) {    //YC modif V2.0
			newScreen = 1;
		} else if ((myHour >=HourScreen.N_21 && myHour <HourScreen.N_22 && selectScreen ==0 ) || selectScreen == 2 ) {  //YC modif V2.0  
			newScreen = 2; 
		} else if ((myHour >=HourScreen.N_31 && myHour <HourScreen.N_32 && selectScreen ==0 ) || selectScreen == 3 ) {  //YC modif V2.0  
			newScreen = 3;  
		} else {  //(myHour >=HourScreen.N_41 && myHour <HourScreen.N_21 && selectScreen ==0) || (selectScreen == 4 ) -->  YC modif V2.0  
			newScreen = 4;  
		}     
	#else
		if (( myHour >=13 && myHour <17 && selectScreen ==0 ) || selectScreen == 1 ) {    //YC modif V2.0
			newScreen = 1;	// horloge à aiguille
		} else if ((myHour >=9 && myHour <13 && selectScreen ==0 ) || selectScreen == 2 ) {  //YC modif V2.0  
			newScreen = 2;	// horloge numérique avec disque secteur seconde
		} else if ((myHour >=17 && myHour <21 && selectScreen ==0 ) || selectScreen == 3 ) {  //YC modif V2.0  
			newScreen = 3;  // horloge numérique couleur avec barre horizontale seconde
		} else {  //(myHour >=21 && myHour <9 && selectScreen ==0) || (selectScreen == 4 ) -->  YC modif V2.0  
			newScreen = 4;  // horloge numérique orange avec barre horizontale seconde
		}     
	#endif
	
	// ======================= CadranAiguilles : selected at 13 to 17 hour and manual selected  //YC modif V2.0
	if (newScreen==1 /*&& previousScreen==newScreen // delete modif YC V2.8 */) {    //YC modif V2.0
		/* if(last_screen != 0){
			refreshScreen=true;
			last_screen=0;
		}*/ 	//delete YC modif V2.1
		if (mySec  != previousSec || refreshScreen == true)  {
			AiguilleSecondes();
		}
		if (myMin  != previousMin || refreshScreen == true)  {
			CadranRond();
		}
		if (myHour != previousHour || refreshScreen == true) {
			CadranBlanc();
			CadranRond();
			previousHour = myHour;	// add YC modif V2.8
		}
		AfficherDate();                    // AfficherDate in the CadranAiguilles tab
		CadranNumber(refreshScreen, 193);  //Display auto mode or number in manual screen //add YC modif V2.0
		#ifdef ____DEBUG__PROG____
			Debug_texte (178);
		#endif
	}


	// ======================= Cadran2 : selected at 9 to 13 hour   and manual selected  //add YC modif V2.0
	else if (newScreen==2 /*&& previousScreen==newScreen // delete modif YC V2.8 */) {   //YC modif V2.0
		Color_t Color;
		/*if(last_screen != 1){
			refreshScreen=true;
			last_screen=1;
		} */ 	//YC modif V2.1
		#ifdef ____DEBUG__PROG____
			Debug_texte (130);
		#endif
		if (myMin != previousMin || refreshScreen == true) {
			Cadran2(refreshScreen);
			CadranNumber(refreshScreen, 145);  //Display auto mode or number in manual screen //add YC modif V2.0
		}

		if (myMin != (myMin / 2) * 2) {
			Color.Red = 127;
			Color.Green = 127;
			Color.Blue = 255;
		} else {
			Color.Red = 255;
			Color.Green = 255;
			Color.Blue = 51;
		}
		
		if(  SecondTick==true ){
			SecondeSecteur(Color);   // Display of the 5 seconds   
		}
		
		/*--------------------------------------------------*/
		LcdColorWhite();
		LcdSetPrintPos160_line(165);
		lcd << (textTypeDay[myDow - 1]) << " " << (myDate) ; endl;
		LcdSetPrintPos160_line(185);
		lcd << (textTypeMonth[myMonth - 1]) << " " << (myYear); endl;
	}

	// ======================= SevenSegments : selected at 17 to 21 hour (screen 3 ) and selected at 21 hour PM to 9 hour AM (screen 4)  and manual selected   //YC modif V2.0
	else if (newScreen >=3 /*&& previousScreen==newScreen // delete modif YC V2.8 */) {   //YC modif V2.0

		/*if(last_screen != 2){
			refreshScreen=true;
			last_screen=2;
		}*/ 	//YC modif V2.1
		#ifdef ____DEBUG__PROG____
			Debug_texte (180);
		#endif	
		if(refreshScreen == true){
			LcdColorWhite();
			lcd.setPrintPos(  30, 180); 
			lcd << (textTypeDay[myDow - 1]) << " " << (myDate) << " " << (textTypeMonth[myMonth - 1]) << " " << (myYear); endl;
			CadranNumber(refreshScreen, 195);  //Display auto mode or number in manual screen //YC modif V2.0
		}

		if(true==SecondTick){
			Colon();
			Secondes();
			SecondTick=false;
		}
		
		if (previousMin != myMin || refreshScreen == true) {
			CadranSecondes();  // displays the horizontal bar of seconds
			SevenSegments(refreshScreen);         
		} 

	} //======================= END selected screen 

	if (GetNextAlert( (MinuteTick | refreshScreen ) ) == true ) {
		AffAlarm(true);
	} else {
		AffAlarm(refreshScreen);
	}
	if(MinuteTick == true) { MinuteTick=false; }

	refreshScreen = false;

	if (/*(AlertBits.BeepOn == LOW ) && ( AlertBits.SnoozeOn == LOW)*/ AlertBits.AlertArmed == 0) {	//add YC modif V2.8
		// =============================SCREEN CHANGE MODE ====================================
		// if key ReadPbScreen pressed "scr", then screen change mode
		#ifdef ___SCREEN_CHANGE___
			if(ReadPbScreen >  (DureeAppui + 2 )  ) { //YC modif V2.0
				selectScreen++; //YC modif V2.0
				ClearScreenDisplay();  // Erase the screen before each clock display change
				ReadPbScreen =0; //YC modif V2.0
				if (selectScreen > MaxScreen) { selectScreen =0 ; } //YC modif V2.0 and V2.6 and V2.8
				#ifdef __SAVE_EEPROM_CHANGE_SCREEN__	//YC modif V2.6
					EEPROM.write( EEPDISPLAYROTATION_ADDR, selectScreen );	//YC modif V2.6
				#endif
			}
		#endif
	
		// ============================= TIME SETTING MODE ====================================
		// if key ReadPbOk pressed "ok", then setup mode
		if(ReadPbOk >  DureeAppui  ) {
			/*AlertBits.BeepOn=LOW;	//delete YC modif V2.8
			AlertBits.SnoozeOn=LOW;	//delete YC modif V2.8
			AlertBits.SnoozeHour=0;	//delete YC modif V2.8
			AlertBits.SnoozeMinute=0;	//delete YC modif V2.8
			*/
			SettingTime();
		}   

		// ============================= ALARM SETTING MODE  =============================
		// if key ReadPbMore pressed "+", then alarm mode
		if( (ReadPbMore > DureeAppui) /*&& (AlertBits.BeepOn == LOW ) && ( AlertBits.SnoozeOn == LOW)*/ ) {	//delete YC modif V2.8
			//AlertBits.BeepOn=LOW;	//delete YC modif V2.8
			//AlertBits.SnoozeOn=LOW;	//delete YC modif V2.8
			//AlertBits.SnoozeHour=0;	//delete YC modif V2.8
			//AlertBits.SnoozeMinute=0;	//delete YC modif V2.8
			SettingAlert();	
		}   

		// ============================= DISPLAY SETTING MODE  =============================
		// if key ReadPbLess pressed "-", then display mode*
		#ifdef ___SETTING_DISPLAY___	//CROISET V7.0
		if( ReadPbLess >  DureeAppui  ){
			/*AlertBits.BeepOn=LOW;	//delete YC modif V2.8
			AlertBits.SnoozeOn=LOW;	//delete YC modif V2.8
			AlertBits.SnoozeHour=0;	//delete YC modif V2.8
			AlertBits.SnoozeMinute=0;	*/	//delete YC modif V2.8
			SettingsDisplay(); 
		}
		#endif 
		
		// ============================= DISPLAY SETTING MODE  =============================
		// if key ReadPbLess pressed "-", then display mode*
		#ifdef ___SETTING_AUTO_HOURS_SCREEN___	//YC modif V2.7
		if( ReadPbLess >  DureeAppui  ){
			/*AlertBits.BeepOn=LOW;	//delete YC modif V2.8
			AlertBits.SnoozeOn=LOW;	//delete YC modif V2.8
			AlertBits.SnoozeHour=0;	//delete YC modif V2.8
			AlertBits.SnoozeMinute=0;	*/	//delete YC modif V2.8
			SettingsScreen();
		}
		#endif 
	}
	//=========================== NEXT ALARM ============================ 
	AlertProcess();


	//=========================== DIMMING OF THE TFT SCREEN LEDs ============================
	SecondTick=false;
	
	//=========================== UPDATE MINUTE AND SECONDS ======================== 
	previousMin  = myMin;	// add YC modif V2.8
	previousSec  = mySec;	//ADD YC modif V2.8
	
// ================= END OF MAIN LOOP ======================
}
  
//=============================================================================================

//=============================================================================================
void RTC_ReadTime(){
	/* Adapt this to yout RTC if needed */
	t_temp  = rtc.getTime();
	myYear  = t_temp.year;
	myMonth = t_temp.mon;
	myDate  = t_temp.date;
	myDow   = t_temp.dow;
	myHour  = t_temp.hour;
	myMin   = t_temp.min;
	mySec   = t_temp.sec;
}
//=============================================================================================

//=============================================================================================
void Backlight(){
	int light=0;
	int range=0;
	float scale = 0;
	float backlight_val=0;
	// Read the value of the light cell
	switch(auto_dimmer){
		case 0: {
			light = analogRead(PinLDR);  // -> LDR for screen LEDs control
			DEBUGPRINT(light);

			/* Values range currently from 850(bright) to 1000(dark) */
			/* 850 will be 1023 and 1000 will be 10 */
			/* 250 as delta we got */

			/* On some clocks the value ranges from 80 ( Bright ) to (400 (dark) */
			/* We gont an delta of 320 for this type of sensor */
			/* If we have 80 for bright we want to have 255 as result */
			/* With this we need to scale back to 0 to 255 */
			range = LDR_Calibration.LDR_DARK-LDR_Calibration.LDR_BRIGHT;     
			DEBUGPRINT("\n\r");   
			DEBUGPRINT(range);
			scale = (float)255 / (float)range;
			DEBUGPRINT("\n\r");   
			DEBUGPRINT(scale);

			light = light-LDR_Calibration.LDR_BRIGHT; /* Remove offset */
			backlight_val = light * scale;
			/* here we need to inver the value as a higer one means darker */
			DEBUGPRINT("\n\r");   
			DEBUGPRINT(backlight_val);
			DEBUGPRINT(" ... \n\r");   
			if(backlight_val>255){
				light=0;
			} else {
				light=255-backlight_val;
			}

			if (light > 250) {
				light = 255; // max = 255
			}

			if (light < 25) {
				light = 25; /* Low value must be adjusted */
			} else {
				light=light*4;
			}
			
			Timer1.pwm(PinScreenLight, light);
		} break;

		case 1:{ /* MAX */
			Timer1.pwm(PinScreenLight, 1023);
		} break;

		case 2:{ /* MED (moyen)*/
			Timer1.pwm(PinScreenLight, 512);
		} break;

		case 3:{ /*LOW (bas)*/
			Timer1.pwm(PinScreenLight, 50);
		} break;

		default:{
			Timer1.pwm(PinScreenLight, 1023);
		}
	}
}

//=============================================================================================
//=========================== FIND NEXT ALARME ============================ 
void AlertProcess(){

	// ============================ STOP BEEPER IF NOT PUSH BUTTON "-" TO 15 MINUTES =====
	if( BeepRunCnt > ( 60 * MAX_BEEP_TIME_MIN ) ){
		/*AlertBits.BeepOn=LOW ;	//delete YC modif V2.8
		AlertBits.SnoozeOn=LOW; */	//delete YC modif V2.8
		AlertBits.AlertArmed = 0;	//add YC modif V2.8
		AlertBits.SnoozeHour=0;
		AlertBits.SnoozeMinute=0;  
	}
	
	// ============================== timer BeepRunCnt if stopped beeper ===================
	if(/*AlertBits.BeepOn==LOW*/ AlertBits.AlertArmed<2){
		while( BeepRunCnt != 0){
			BeepRunCnt=0;
		}
	}


	// ============================= STOP BEEPER IF PUSH BUTTON "-" ===========================
	// if key ReadPbLess pressed "-", stop the beeper ringing and NO snooze
	if ((ReadPbLess > DureeAppui) && (/*(AlertBits.BeepOn == HIGH) || (AlertBits.SnoozeOn == HIGH) ) */AlertBits.AlertArmed > 0 ) ) {
		/*AlertBits.BeepOn=LOW ;	//delete YC modif V2.8
		AlertBits.SnoozeOn=LOW; */	//delete YC modif V2.8
		AlertBits.AlertArmed = 0;	//add YC modif V2.8
		AlertBits.SnoozeHour=0;
		AlertBits.SnoozeMinute=0;
		GetNextAlert(true);
		refreshScreen=true;	//add YC modif V2.1
	}

	// ============================= ALARM ACTIVATION ===========================================
	// Beep if alarm time or snooze time matches
	//YC modif V2.1
	if ( (/*AlertBits.SnoozeOn==LOW*/ AlertBits.AlertArmed ==0 ) && ( ValidateAlarm == HIGH ) ) {	
		if ( (UserAlarm[0].Day  == (myDow - 1)) || (UserAlarm[0].Day  == 8 /* Mon-Fri */ && (myDow  <= 5) ) || (UserAlarm[0].Day  == 7 /* Mon-Thu */ && (myDow  <= 4) ) ) {	//add Mon-Thuy YC modif V1.0
			//OK day alarm
			if ( (UserAlarm[0].Hour  == myHour) && (myMin == UserAlarm[0].Minute) ) { 
				if (previousMin != myMin) { /*AlertBits.BeepOn = HIGH; */AlertBits.AlertArmed = 2 ; }	// add AlerArmed YC modif V2.8
			}
		}
	}
	if(  (AlertBits.SnoozeHour  == myHour) && (AlertBits.SnoozeMinute == myMin) && (/*AlertBits.SnoozeOn==HIGH */AlertBits.AlertArmed%2==1) ) {		// add AlerArmed YC modif V2.8
		if(previousMin != myMin){ /*AlertBits.BeepOn = HIGH;*/ AlertBits.AlertArmed = 3; } // add AlerArmed YC modif V2.8  
	}

	// ============================= TURN IN SNOOZE MODE ========================================
	// Pressing the ReadPbMore "+" key keeps the snooze mode : stop the current alarm but keeps the following alarms
	if ((ReadPbMore > DureeAppui) && (/*AlertBits.BeepOn == HIGH*/ AlertBits.AlertArmed>1)) {
		/* we need to determine if we had snoozed for a while ....*/
		if( /*AlertBits.SnoozeOn == HIGH */ AlertBits.AlertArmed==3){	// add AlerArmed YC modif V2.8
			/* we need to copy a bit arround here */
			UserAlarm[0].Minute = AlertBits.SnoozeMinute;
			UserAlarm[0].Hour = AlertBits.SnoozeHour;
		}
		// SnoozeAddMinute == 10 minutes par défaut
		if ((UserAlarm[0].Minute + SnoozeAddMinute) != (UserAlarm[0].Minute + SnoozeAddMinute) % 60)
		{
			AlertBits.SnoozeMinute = ((UserAlarm[0].Minute + SnoozeAddMinute ) % 60);
			AlertBits.SnoozeHour  = UserAlarm[0].Hour + 1;		
		} else {
			AlertBits.SnoozeMinute = (UserAlarm[0].Minute + SnoozeAddMinute);
			AlertBits.SnoozeHour  = UserAlarm[0].Hour;
		}
		/*AlertBits.SnoozeOn = HIGH;	// delete YC modif V2.8
		AlertBits.BeepOn = LOW;*/	// delete YC modif V2.8
		AlertBits.AlertArmed=1;	// add AlerArmed YC modif V2.8
		AffAlarm(true);
	}
	//=========================== RESET THE ALARM ON FOR THE NEXT DAY ============================ 
}
//=========================== END NEXT ALARM ======================== 
//=============================================================================================

//=============================================================================================
//=========================== BEEPER ALARM ========================
// call to 1 second (1 hz) whith fonction callback() 
void Buzzer( ) {
	
	// test if beeper
	if (/*AlertBits.BeepOn==HIGH*/ AlertBits.AlertArmed>1) {
		/* We need a minute counter, or here a second counter ..... */
		if(BeepRunCnt<0xFFFF){
          BeepRunCnt++;
		}
		// set beeper to 2 seconds 
		if (ToggleBeeper == true) {	// bistable management with each call of void buzze()
			ToggleBeeper = false;
			tone(PinBeeper, 1500); // -> beeper ( first period 1 second ON tone (__,1500 hz) )
		} else {
			ToggleBeeper = true;
			noTone(PinBeeper);  // -> beeper ( second period 1 second OFF tone )
		}
    } else {
		// stop beeper if not trigger beeper
		noTone(PinBeeper);
		BeepRunCnt=0;
	}
}
//=============================================================================================


// --------------------------------------------------------------------------------------------
bool GetNextAlert(bool refresh){
	/* 
	 *  This will copy the next Alert into UserAlarm[0];
	 */
	static uint8_t Last_Alert=0;
	uint8_t NextAlert  = 0;
	uint16_t Distance[USERALARMCNT] = {0xFFFF,} ;
	/* We use 0xFFFF to mark the alert as off */
	/* Helper vars */
	int16_t DistDays=0;
	int16_t DistHours=0;
	int16_t DistMinutes=0;
	uint8_t Dow_ZeroStart = myDow-1;
	bool alert=false;

	if( /*( AlertBits.SnoozeOn == HIGH ) || ( AlertBits.BeepOn == HIGH )*/ AlertBits.AlertArmed>0 ){	//YC modif V2.9
	  return false;
	}

	if(refresh==false){
	  return false;
	} else {
	   
	}
 
	for(uint8_t i=1;i<USERALARMCNT;i++){
       
        if( (UserAlarm[i].Day>=0) && ( UserAlarm[i].Day<number_day_state) ){ // old: UserAlarm[i].Day<8 ==> now 9 "never"  // YC modif V2.0 
            //Serial.println("Active");
            if ( (( UserAlarm[i].Day==8 /*Mon-Fri*/) && (Dow_ZeroStart < 5)) || ( (UserAlarm[i].Day==7 /*Mon-Thu*/) && (Dow_ZeroStart < 4) )  ) { /* Mon-Fri || Mon-Thu  // //YC modif V2.0 */
				DistDays=0;                    
            } else {
				if( UserAlarm[i].Day==8 /*Mon-Fri*/ || UserAlarm[i].Day==7 /*Mon-Thu*/){	//YC modif V2.0
					/* We set the alert to monday */
					DistDays= 7-Dow_ZeroStart;
				} else {
					if(UserAlarm[i].Day>=Dow_ZeroStart){                        
						DistDays=UserAlarm[i].Day-Dow_ZeroStart;
					} else {
						DistDays= 7-Dow_ZeroStart + UserAlarm[i].Day ;
					}  
				}
			} /* Days distance done */

			if( myHour <= UserAlarm[i].Hour ){
            /* Sameay alert */
              DistHours = UserAlarm[i].Hour - myHour;
			} else {
				DistHours = UserAlarm[i].Hour + 24 - myHour;
				if(DistDays>0){
					DistDays--;
				} else {
					/* if we have a sameday alert we need to check if this will be active tomorrow */
					if ( ((UserAlarm[i].Day==8 /*Mon-Fri*/) && (Dow_ZeroStart < 4)) || ((UserAlarm[i].Day==7 /*Mon-Thu*/) && (Dow_ZeroStart < 3) )) { //YC modif V2.0
						/* We can ring tomorrow */
						DistDays=0;
					}  else if ( ((UserAlarm[i].Day==8 /*Mon-Fri*/) && (Dow_ZeroStart == 4) ) || ( (UserAlarm[i].Day==7 /*Mon-Thu*/) && (Dow_ZeroStart == 3) ) ){  //YC modif V2.0
						/* We Set the day to monday for distance calculation and must be aware to get one more substarcted */
						DistDays= 7-Dow_ZeroStart; /* Set Day to monday */ 
						if(DistDays > 0){
							DistDays--;
						}
					} else {
                       DistDays=6;
					}
				}		
			}
           

			if( myMin > UserAlarm[i].Minute){
				/* Not same hour */
				DistMinutes = 60 - myMin + UserAlarm[i].Minute;
               
				if(DistHours>0){
					DistHours--;
				} else {
             
					DistHours=MaxHours;
					/* Need to adjust the day */
					if(DistDays>0){
						DistDays--;
					} else {

						if( (UserAlarm[i].Day==8 /*Mon-Fri*/) && (Dow_ZeroStart < 4) || ( (UserAlarm[i].Day==7 /*Mon-Thu*/) && (Dow_ZeroStart < 3) ) ){ //YC modif V2.0
							/* We can ring tomorrow */
							DistDays=0;
						}  else if ( (UserAlarm[i].Day==8 /*Mon-Fri*/) && (Dow_ZeroStart == 4) || ( (UserAlarm[i].Day==7 /*Mon-Fri*/) && (Dow_ZeroStart == 3) ) ){ //YC modif V2.0
                      
							if(DistDays>0){
								DistDays--;
							} else {
								/* tjis gets tricky here as we may have to some stuff again */   
								DistDays= 7-Dow_ZeroStart; /* Set Day to monday */ 
								//Serial.println(F("Adjust days @ Minutes"));
							}
                   
						} else { 
							DistDays=6;
						}
                
					}
				} 

               
			} else {
				/* same hour */
				DistMinutes =  UserAlarm[i].Minute - myMin;        
               
			}
          
			Distance[i] = ( DistDays * 1440 ) + ( DistHours * 60 ) + ( DistMinutes );  // to minutes
        } else {
			Distance[i]=0xFFFF;
        }

	}
	
	NextAlert=0;
	for(uint8_t i=1;i<USERALARMCNT;i++){
		if( Distance[i] < Distance[0] ){
			NextAlert=i;
            Distance[0]= Distance[i];
        }
	}
	if(NextAlert>0){
        UserAlarm[0].Hour    = UserAlarm[NextAlert].Hour;
        UserAlarm[0].Minute  = UserAlarm[NextAlert].Minute;
        UserAlarm[0].Day     = UserAlarm[NextAlert].Day;
        AlarmDistance = Distance[0];
	} else {
        UserAlarm[0].Hour    = 99;
        UserAlarm[0].Minute  = 99;
        UserAlarm[0].Day     = number_day_state; // old 8 ==> now 9 "never"  // YC modif V2.0
       
	}
	
	if(Last_Alert != NextAlert){
		Last_Alert= NextAlert;
		return true;
	} else {
		return false;
	}
  
}
//=============================================================================================

//=============================================================================================
void AlarmSync() {
	uint8_t* AlPtr;
	AlPtr=(uint8_t*)&UserAlarm[1];
	for(uint8_t i=0;i<sizeof(UserAlarm);i++){
		EEPROM.update(i, *(AlPtr));
		AlPtr++;
	}
}
//=============================================================================================

//=============================================================================================
void AffAlarm(bool refresh) /* Used to turn Alarm on and off */
{
	static uint8_t Button_PrevValue=0;
	static uint8_t Prev_Snooze=LOW;

	if(Prev_Snooze != /*AlertBits.SnoozeOn*/ AlertBits.AlertArmed)	{ refresh=true; }
	Prev_Snooze = /*AlertBits.SnoozeOn*/ AlertBits.AlertArmed;
	uint8_t ButtonValue = digitalRead(PinBpAlarm);   // Touch bpAlarm
	
	if( ( ( ButtonValue == LOW ) && ( Button_PrevValue == HIGH)  ) || (refresh == true) )
	{

		if ( /*( ButtonValue == LOW ) && ( Button_PrevValue == HIGH) //YC modif V2.8 */ refresh == false ){
			/*if(ValidateAlarm== HIGH ){
				ValidateAlarm = LOW;
			} else {
				ValidateAlarm = HIGH;
			}*/
			ValidateAlarm = not ValidateAlarm;	//YC modif V2.8
			#ifdef ___SAVE_EEPROM_CHANGE_VALIDATE_ALARM___	//YC modif V2.8
				EEPROM.write( EEPALERTONOFF_ADDR, ValidateAlarm );	
			#endif
		}
		
		#ifndef ___INDICATOR__ALARM___	//YC modif V2.8
		
			/* Process snooze here */
			LcdColorBlack( LOW /* delay(50) */);	//black
			//lcd.drawBox(215, 0, 105, 10); // 320-215 --> 105 : YC modif V2.7
			LcdDrawBox_a_x_y_10(215,0,105);
			//lcd.drawBox(235, 15, 85, 10); // 320-235 --> 85 : YC modif V2.7
			LcdDrawBox_a_x_y_10(235,15,85);
			//lcd.drawBox(0, 0, 80, 10);	//YC modif V2.7
			LcdDrawBox_a_x_y_10(0,0,80);
			
			//lcd.setPrintPos( 0, 10);
			LcdSetPrintPosCol_10(0);
			
			if (ValidateAlarm == LOW) {
				LcdColorGray();		//dimmed if alarm OFF
				#ifdef ___francais___   //YC modif V1.0
					//lcd.print(F("Sans Alarme"));	//YC modif V2.1
					lcd.print(("Sans Alarme"));				
				#elif ___english___
					lcd.print(("Alarm OFF"));
				#elif ___deutsch___	
					lcd.print(("Alarm AUS"));			
				#elif ___italiano___
					lcd.print(("Allarme FERM"));
				#elif ___espanol___
					lcd.print(("Alarma APAG"));
				#elif ___portugues___
					lcd.print(("Alarme DES"));
				#endif
				/*AlertBits.BeepOn=LOW;	// delte YC modif V2.8
				AlertBits.SnoozeOn=LOW;*/	// delte YC modif V2.8
				AlertBits.AlertArmed = 0;	// add AlerArmed YC modif V2.8		
				AlertBits.SnoozeHour=0;
				AlertBits.SnoozeMinute=0;
			} else {
				LcdColorWhite();
				#ifdef ___francais___   //YC modif V1.0
					lcd.print(("Avec Alarme"));   
				#elif ___english___
					lcd.print(("Alarm ON"));
				#elif ___deutsch___	
					lcd.print(("Alarm AN"));			
				#elif ___italiano___
					lcd.print(("Allarme ACC"));
				#elif ___espanol___
					lcd.print(("Alarma ACTI"));
				#elif ___portugues___
					lcd.print(("Alarme LIG"));		
				#endif
			}
		#else	//YC modif V2.8
				/* Process snooze here */
			LcdColorBlack( LOW /* delay(50) */);	//black
			//lcd.drawBox(215, 0, 105, 10); // 320-215 --> 105 : YC modif V2.7
			LcdDrawBox_a_x_y_10(215,0,105);
			//lcd.drawBox(235, 15, 85, 10); // 320-235 --> 85 : YC modif V2.7
			LcdDrawBox_a_x_y_10(235,15,85);
			//lcd.drawBox(30, 5, 60, 10);	// YC modif V2.8
			LcdDrawBox_a_x_y_10(30,5,60);
			lcd.setPrintPos( 30, 15);	//YC modif V2.8
			
			
			if (ValidateAlarm == LOW) {
				LcdColorGray();		//dimmed if alarm OFF
				/*AlertBits.BeepOn=LOW;	// delete YC modif V2.8
				AlertBits.SnoozeOn=LOW;*/	// delete YC modif V2.8
				AlertBits.AlertArmed = 0;	// add AlerArmed YC modif V2.8	
				AlertBits.SnoozeHour=0;
				AlertBits.SnoozeMinute=0;
			} else {
				LcdColorWhite();
			}
			#ifdef ___francais___   
				lcd.print(("Alarme"));   
			#elif ___english___
				lcd.print(("Alarm"));
			#elif ___deutsch___
				lcd.print(("Alarm"));
			#elif ___italiano___
				lcd.print(("Allarme"));
			#elif ___espanol___
				lcd.print(("Alarma"));
			#elif ___portugues___
				lcd.print(("Alarme"));
			#endif
		#endif
		if(/*AlertBits.SnoozeOn==HIGH*/ AlertBits.AlertArmed%2==1 ){
			//lcd.setPrintPos( 220, 10);	//old 235 //YC modif V2.0
			LcdSetPrintPosCol_10(220);
			#ifdef ___francais___   //YC modif V1.0
				lcd << "Repetition" << endl;   
			#elif ___english___
				lcd << "Snooze" << endl;
			#elif ___deutsch___	
				lcd << "Snooze" << endl;			
			#elif ___italiano___
				lcd << "Sonnellino" << endl;
			#elif ___espanol___
				lcd << "Dormitar" << endl;
			#elif ___portugues___
				lcd << "Soneca" << endl;				
			#endif
			   
			//lcd.setPrintPos( 235, 25);
			LcdSetPrintPosCol_25(235);
			lcd << ((AlertBits.SnoozeHour < 10) ? "0" : "") << AlertBits.SnoozeHour  << ":" << ((AlertBits.SnoozeMinute < 10) ? "0" : "") << AlertBits.SnoozeMinute << endl;
		  
		} else {
			if(UserAlarm[0].Day < number_day_state){  // old: UserAlarm[i].Day<8 ==> now 9 "never"  // YC modif V2.0
				//lcd.setPrintPos( 215, 10);	// old 235,10 //YC modif V2.5
				LcdSetPrintPosCol_10(215);
				lcd << textTypeDay[UserAlarm[0].Day] << endl;			
				//lcd.setPrintPos( 235, 25);
				LcdSetPrintPosCol_25(235);
				lcd << ((UserAlarm[0].Hour < 10) ? "0" : "") << UserAlarm[0].Hour << ":" << ((UserAlarm[0].Minute < 10) ? "0" : "") << UserAlarm[0].Minute << endl;
			}
		}
	}
  
	Button_PrevValue = ButtonValue;
}
//=============================================================================================
void LcdSetPrintPos160_70 ( ) {
	LcdSetPrintPos160_line(70);
}
void LcdSetPrintPos160_85 ( ) {
	LcdSetPrintPos160_line(85);
}
void LcdSetPrintPos160_100 ( ) {
	LcdSetPrintPos160_line(100);
}
void LcdSetPrintPos160_115 ( ) {
	LcdSetPrintPos160_line(115);
}
void LcdSetPrintPos160_line ( int line ) {
	lcd.setPrintPos( 160, line);
}
void LcdSetPrintPos250_70 ( ) {
	LcdSetPrintPos250_line(70);
}
void LcdSetPrintPos250_85 ( ) {
	LcdSetPrintPos250_line(85);
}
void LcdSetPrintPos250_100 ( ) {
	LcdSetPrintPos250_line(100);
}
void LcdSetPrintPos250_line ( int line ) {
	lcd.setPrintPos( 250, line);
}
void LcdSetPrintPosCol_10 ( int col ) {
	lcd.setPrintPos( col, 10);
}
void LcdSetPrintPosCol_25 ( int col ) {
	lcd.setPrintPos( col, 25);
}
void LcdSetPrintPos10_line ( int line ) {
	lcd.setPrintPos( 10, line);
}
//=============================================================================================

uint8_t StepAdjust(uint8_t line, uint8_t PrevA, uint8_t tags,uint8_t MAxHelp2,uint8_t MinHelp2, uint8_t a, uint8_t x  ) {	
	do
	{
		LcdColorBlue();                          // Blue
		SettingScreenPrintText(line);
		tags = SettingHelper1(tags);
		tags = SettingHelper2(tags, MAxHelp2, MinHelp2);
		if (tags != PrevA)
		{
		  LcdColorBlack( HIGH /* delay(50) */);                            //
		  LcdDrawBox_a_x_40_10(a,x);
		  LcdColorGreen();
		  lcd.setPrintPos( a, x+10); lcd.print(tags);      // refresh the display in Blue
		  PrevA = tags;
		}
	}
	while (MemoryReadTouch<3);  // while OK and PbAlarm not pressed, else continue
	ClearReadTouch( LOW /* if LOW no clear ReadPbAlarm */);

	LcdColorWhite();                        // Reset to white	
	SettingScreenPrintText(line);
	lcd.setPrintPos( a, x+10); lcd.print(tags); 
	//PrevA = 88;
	
	return tags;
}

//=============================================================================================
void SettingsScreen(  ){
#ifdef ___SETTING_AUTO_HOURS_SCREEN___	//YC modif V2.7
  uint8_t PrevA=88;
  HeadlineHelper();
  PrintCopyright();
  	
	for(uint8_t i=0;i<3;i++){
		SettingScreenPrintText(i);
	}
  
	lcd.setPrintPos(  30,  40);
	#ifdef ___francais___  
		lcd.print(("REGLAGE HORAIRE AUTO ECRANS"));	
	#elif ___english___
		lcd.print(("AUTO HOURS SETTINGS SCREEN"));	
	#elif ___deutsch___	
		lcd.print(("AUTO-STUNDEN-EINSTELLUNGSBILDSCHIRM"));			
	#elif ___italiano___
		lcd.print(("SCHERMATA DELLE IMPOSTAZIONI AUTO ORE"));	
	#elif ___espanol___
		lcd.print(("PANTALLA CONFIGURACION HORAS AUTOMATICAS"));	
	#elif ___portugues___
		lcd.print(("AUTO HORAS DEFINICOES TELA"));				
	#endif
	
	LcdSetPrintPos160_70(); lcd.print(HourScreen.N_11);
	LcdSetPrintPos250_70(); lcd.print(HourScreen.N_12);
	LcdSetPrintPos160_85(); lcd.print(HourScreen.N_21);
	LcdSetPrintPos250_85(); lcd.print(HourScreen.N_22);
	LcdSetPrintPos160_100(); lcd.print(HourScreen.N_31);
	LcdSetPrintPos250_100(); lcd.print(HourScreen.N_32);
	//LcdSetPrintPos160_115(); lcd.print(HourScreen.N_41);
	
	/*===================================================================*/
	/*                   RECORD THE AUTO SETTINGS SCREEN                 */
	/*===================================================================*/	
	// ==================================================== Modify HourScreen.N_xx 
	HourScreen.N_11 = StepAdjust(0,PrevA, HourScreen.N_11, MaxHours, 0, 160, 60  );	// YC modif V2.9	
	HourScreen.N_12 = StepAdjust(0,PrevA, HourScreen.N_12, MaxHours, HourScreen.N_11 + 1, 250, 60  );	// YC modif V2.9
	HourScreen.N_21 = StepAdjust(1,PrevA, HourScreen.N_21, MaxHours, 0, 160, 75  );	// YC modif V2.9
	HourScreen.N_22 = StepAdjust(1,PrevA, HourScreen.N_22, MaxHours, HourScreen.N_21 + 1, 250, 75  );	// YC modif V2.9
	HourScreen.N_31 = StepAdjust(2,PrevA, HourScreen.N_31, MaxHours, 0, 160, 90  );	// YC modif V2.9
	HourScreen.N_32 = StepAdjust(2,PrevA, HourScreen.N_32, MaxHours, HourScreen.N_31 + 1, 250, 90  );	// YC modif V2.9

	ClearScreenDisplay();
	ScreenEEPROM();
	GetNextAlert(true); 
#endif	
}
//=============================================================================================


void ClearScreenDisplay (){	//add YC modif V2.8
	lcd.clearScreen();
	refreshScreen = true;
}
//=============================================================================================
void LcdColorBlue( ) {
	lcd.setColor ( 0, 0, 255);
}
void LcdColorWhite( ) {
	lcd.setColor ( 255, 255, 255);
}
void LcdColorBlack( boolean WhithDelay) {
	if ( WhithDelay ) { delay(50); }
	lcd.setColor ( 0, 0, 0);
}
void LcdColorGreen( ) {
	lcd.setColor ( 0, 255, 0);
}
void LcdColorRed( ) {
	lcd.setColor ( 255, 0, 0);
}
void LcdColorOrange( ) {
	lcd.setColor (255 , 204, 0);
}
void LcdColorLightBlue( ) {
	lcd.setColor (100, 100, 255); // light blue
}
void LcdColorGray( ) {
	lcd.setColor (155, 155, 155);  // gray 
}
//=============================================================================================
void LcdDrawBox_160_x_y_z (int x, int y, int z ) {
	lcd.drawBox (160, x, y, z);
}
void LcdDrawBox_160_x_40_10 (int x ) {
	lcd.drawBox (160, x, 40, 10);
}
void LcdDrawBox_a_x_40_10 (int a, int x ) {
	lcd.drawBox (a, x, 40, 10);
}
void LcdDrawBox_160_x_y_10 (int x, int y ) {
	lcd.drawBox (160, x, y, 10);
}
void LcdDrawBox_250_x_40_10 ( int x ) {
	lcd.drawBox (250, x, 40, 10);
}
void LcdDrawBox_a_x_y_10 (int a, int x, int y ) {
	lcd.drawBox (a, x, y, 10);
}
void LcdDrawBox_a_x_30_20 (int a, int x ) {
	lcd.drawBox (a, x, 30, 20);
}
//=============================================================================================
	
void SettingScreenPrintText(uint8_t txt_id){	//YC modif V2.7
	#ifdef ___SETTING_AUTO_HOURS_SCREEN___	//YC modif V2.7
    switch(txt_id){	
		case 0: {
			//lcd.setPrintPos(  10, 70 );
			LcdSetPrintPos10_line(70);
			#ifdef ___francais___  
				lcd.print(("Ecran   I Début:      Fin:"));
			#elif ___english___
				lcd.print(("Display I Start:      End:"));
			#elif ___deutsch___	
				lcd.print(("Uhr   I Starten:     Ende:"));			
			#elif ___italiano___
				lcd.print(("Orologio I Avvi:      Fine:"));
			#elif ___espanol___
				lcd.print(("Relog I Iniciar:      Fin:"));
			#elif ___portugues___
				lcd.print(("Relogio I Inici:      Fin:"));
			#endif
			
		} break;
		case 1: {
			//lcd.setPrintPos(  10, 85);
			LcdSetPrintPos10_line(85);
			#ifdef ___francais___  
				lcd.print(("Ecran  II Début:      Fin:"));
			#elif ___english___
				lcd.print(("Display 2 Start:      End:"));
			#elif ___deutsch___	
				lcd.print(("Uhr   2 Starten:     Ende:"));			
			#elif ___italiano___
				lcd.print(("Orologio 2 Avvi:     Fine:"));
			#elif ___espanol___
				lcd.print(("Relog 2 Iniciar:      Fin:"));
			#elif ___portugues___
				lcd.print(("Relogio 2 Inici:      Fin:"));
			#endif

		} break;
		case 2: {
			//lcd.setPrintPos(  10, 100);
			LcdSetPrintPos10_line(100);
			#ifdef ___francais___  
				lcd.print(("Ecran III Début:      Fin:"));
			#elif ___english___
				lcd.print(("Display 3 Start:      End:"));
			#elif ___deutsch___	
				lcd.print(("Uhr   3 Starten:     Ende:"));			
			#elif ___italiano___
				lcd.print(("Orologio 3 Avvi:     Fine:"));
			#elif ___espanol___
				lcd.print(("Relog 3 Iniciar:      Fin:"));
			#elif ___portugues___
				lcd.print(("Relogio 3 Inici:      Fin:"));
			#endif
		} break;
		/*case 3: {
			//lcd.setPrintPos(  10, 115);
			LcdSetPrintPos10_line(115);
			lcd.print(("Début Ecran  IV:         "));
		} break;	*/  
		default:{       
		} break;
	}
	#endif
}

//=============================================================================================
void ScreenEEPROM() {	//YC modif V2.7
	#ifdef ___SETTING_AUTO_HOURS_SCREEN___	
		uint8_t* ScPtr;
		ScPtr=(uint8_t*)&HourScreen;
		for(uint8_t i=0;i<sizeof (HourScreen_t);i++){
			EEPROM.update(i + EEPAUTOHOURSSCRENN_ADDR, *(ScPtr));
			ScPtr++;
		}
	#endif
}
//=============================================================================================

//=============================================================================================
void Cadran2( bool refresh ){
	// Numdigit = display horizontal position
	// Flash ROM = 2504 bytes
	// ============= display dozen hours
	static int8_t dozenH_Prev=-1;
	static int8_t unitH_Prev=-1;
	static int8_t dozenM_Prev=-1;
	static int8_t unitM_Prev=-1;
	static int8_t PointDrawn=-1;  

	if(false != refresh ){
		dozenH_Prev=-1;
		unitH_Prev=-1;
		dozenM_Prev=-1;
		unitM_Prev=-1;
		PointDrawn=-1;    
	}

	// ============= display dozen hours
	uint8_t dozenH = myHour / 10;
	uint16_t  Numdigit = 8;
	Color_t Color;
	// white
	Color.Red   = 255;
	Color.Green = 255;
	Color.Blue  = 255;    


	if(dozenH_Prev!=dozenH){
		PointsHelper(dozenH,Numdigit,Color);
		dozenH_Prev=dozenH;
	}

	// ============= display units hours
	uint8_t unitH = myHour % 10;
	Numdigit = 80;
	//red
	Color.Red   = 253;
	Color.Green = 0;
	Color.Blue  = 0;

	if(unitH_Prev != unitH ){
		PointsHelper(unitH,Numdigit,Color);
		unitH_Prev = unitH;
	}
	// ============= deux points
	Numdigit = 153;
	PointsColumn();

	// ============= display dozen minutes
	uint8_t  dozenM = myMin / 10;
	Numdigit = 180;
	//green
	Color.Red   = 0;
	Color.Green = 255;
	Color.Blue  =  0;

	if(dozenM_Prev != dozenM){
		PointsHelper(dozenM,Numdigit,Color);
		dozenM_Prev = dozenM;
	}


	// ============= display units minutes
	uint8_t unitM = myMin % 10;
	Numdigit = 253;
	//purple
	Color.Red   = 127;
	Color.Green = 127;
	Color.Blue  = 255;

	if(unitM_Prev != unitM ){
		PointsHelper(unitM,Numdigit,Color);
		unitM_Prev = unitM;
	}

}
//=============================================================================================

//=============================================================================================
void PointsHelper( uint8_t Val, int16_t offset, Color_t Color){
	LcdColorBlack( LOW /* delay(50) */);                         // ADD YC modif V2.8
	switch (Val) {
		case 0: Points0(offset,Color); break;
		case 1: Points1(offset,Color); break;
		case 2: Points2(offset,Color); break;
		case 3: Points3(offset,Color); break;
		case 4: Points4(offset,Color); break;
		case 5: Points5(offset,Color); break;
		case 6: Points6(offset,Color); break;
		case 7: Points7(offset,Color); break;
		case 8: Points8(offset,Color); break;
		case 9: Points9(offset,Color); break; 
	}
}
//=============================================================================================

//=============================================================================================
void Points0(uint16_t Numdigit, Color_t Color)
// display of 0 ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox (/*0 + */Numdigit,/* 0 + */Ypos, 56, 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(Numdigit/* +  0*/, Ypos/* +  0*/, 14, 84);  // left of 0
	lcd.drawBox(Numdigit + 14, Ypos/* +  0*/, 42, 14);  // top of 0
	lcd.drawBox(Numdigit + 42, Ypos/* +  0*/, 14, 84);  // right of 0
	lcd.drawBox(Numdigit + 14, Ypos + 70, 42, 14);  // bottom of 0
}
//=============================================================================================

//=============================================================================================
void Points1(uint16_t Numdigit, Color_t Color)
// display of 1  ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox (/*0 + */Numdigit, /*0 + */Ypos, 56 , 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(Numdigit + 14, Ypos + 70, 42, 14);  // pied du 1
	lcd.drawBox(Numdigit + 28, /*0 + */Ypos, 14, 70);  // tige du 1
	lcd.drawBox(Numdigit + 14, Ypos + 14, 14, 14);  // bec du 1
}
//=============================================================================================

//=============================================================================================
void Points2(uint16_t Numdigit, Color_t Color)
// display of 2 ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 14);  // up of 2
	lcd.drawBox(Numdigit + 42, Ypos + 14, 14, 14);  // right du 2
	lcd.drawBox(/*0 + */Numdigit, Ypos + 28, 56, 14);  // middle of 2
	lcd.drawBox(/*0 + */Numdigit, Ypos + 28, 14, 42);  // left du 2
	lcd.drawBox(/*0 + */Numdigit, Ypos + 70, 56, 14);  // low of 2
}
//=============================================================================================

//=============================================================================================
void Points3(uint16_t Numdigit, Color_t Color)
// display of 3 ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 14);  // haut du 3
	lcd.drawBox(Numdigit + 42, /*0 + */Ypos, 14, 84);  // tige du 3
	lcd.drawBox(Numdigit + 14, Ypos + 28, 42, 14);  // milieu du 3
	lcd.drawBox(/*0 + */Numdigit, Ypos + 70, 56, 14);  // bas du 3
}
//=============================================================================================

//=============================================================================================
void Points4(uint16_t Numdigit, Color_t Color)
// display of 4 ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 14, 42);  // left du 4
	lcd.drawBox(/*0 + */Numdigit, Ypos + 42, 56, 14);  // milieu du 4
	lcd.drawBox(Numdigit + 28, Ypos + 28, 14, 56);  // pied du 4
}
//=============================================================================================

//=============================================================================================
void Points5(uint16_t Numdigit, Color_t Color)
// display of 5 ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 14);  // haut du 5
	lcd.drawBox(/*0 + */Numdigit, Ypos + 14, 14, 28);  // left du 5
	lcd.drawBox(/*0 + */Numdigit, Ypos + 28, 56, 14);  // milieu du 5
	lcd.drawBox(Numdigit + 42, Ypos + 42, 14, 28);  // right du 5
	lcd.drawBox(/*0 + */Numdigit, Ypos + 70, 56, 14);  // bas du 5
}
//=============================================================================================

//=============================================================================================
void Points6(uint16_t Numdigit, Color_t Color)
// display of 6 ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56 , 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 14);  // haut du 6
	lcd.drawBox(/*0 + */Numdigit, Ypos + 14, 14, 70);  // left du 6
	lcd.drawBox(/*0 + */Numdigit, Ypos + 28, 56, 14);  // milieu du 6
	lcd.drawBox(Numdigit + 42, Ypos + 42, 14, 28);  // right du 6
	lcd.drawBox(/*0 + */Numdigit, Ypos + 70, 56, 14);  // bas du 6
}
//=============================================================================================

//=============================================================================================
void Points7(uint16_t Numdigit, Color_t Color)
// display of 7 ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 14);  // haut du 7
	lcd.drawBox(Numdigit + 42, Ypos + 14, 14, 14);  // right du 7
	lcd.drawBox(Numdigit + 28, Ypos + 28, 14, 28);  // milieu du 7
	lcd.drawBox(Numdigit + 14, Ypos + 56, 14, 28);  // bas du 7
}
//=============================================================================================

//=============================================================================================
void Points8(uint16_t Numdigit, Color_t Color)
// display of 8 ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 14, 84);  // left du 8
	lcd.drawBox(Numdigit + 14, /*0 + */Ypos, 42, 14);  // haut du 8
	lcd.drawBox(Numdigit + 14, Ypos + 28, 42, 14);  // milieu du 8
	lcd.drawBox(Numdigit + 14, Ypos + 70, 42, 14);  // bas du 8
	lcd.drawBox(Numdigit + 42, /*0 + */Ypos, 14, 84);  // right du 8
}
//=============================================================================================

//=============================================================================================
void Points9(uint16_t Numdigit, Color_t Color)
// display of 9 ==================================
{
	//LcdColorBlack( LOW /* delay(50) */);	// Set to black	// delete YC modif V2.8
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 56, 84);

	lcd.setColor(Color.Red , Color.Green, Color.Blue);                // Set the color
	lcd.drawBox(/*0 + */Numdigit, /*0 + */Ypos, 14, 42);  // left du 9
	lcd.drawBox(Numdigit + 14, /*0 + */Ypos, 42, 14);  // haut du 9
	lcd.drawBox(Numdigit + 14, Ypos + 28, 42, 14);  // milieu du 9
	lcd.drawBox(/*0 + */Numdigit, Ypos + 70, 56, 14);  // bas du 9
	lcd.drawBox(Numdigit + 42, /*0 + */Ypos, 14, 84);  // right du 9
}
//=============================================================================================

//=============================================================================================
void PointsColumn()
// display of : ==================================
{
	uint8_t Red = 255;
	uint8_t Green  = 255;
	uint8_t Blue  = 255;
	int DP = 150;                                   // horizontal position of ":"

	LcdColorBlack( LOW /* delay(50) */);                          // Set to black
	lcd.drawBox(DP, /*0 + */Ypos, 25, 84);
	lcd.setColor(Red , Green, Blue);                // Set the color
	lcd.drawBox(/*0 + */DP, Ypos + 28, 14, 14);         // point du haut de ":"
	lcd.drawBox(/*0 + */DP, Ypos + 56, 14, 14);         // point du bas de ":"
}
//=============================================================================================

//=============================================================================================

int16_t ext_radius_cos_lut[12]={  0 , 25 , 43 , 50 , 43, 25,  0, -25, -43, -50, -43, -25 };
int16_t ext_radius_sin_lut[12]={ -50, -43, -25,   0, 25, 43, 50,  43,  25,  0,  -25, -43 };

int16_t int_radius_cos_lut[12]={   0,  20,  35, 40,  35, 20,  0, -20, -35, -40, -35, -20 };
int16_t int_radius_sin_lut[12]={ -40, -35, -20,  0,  20, 35, 40,  35,  20,  0,  -20, -35 };

int16_t prec_ext_radius_cos_lut[12]={ -22,   4, 28,   45, 50, 41, 22,  -4, -28, -45, -50, -41 };
int16_t prec_ext_radius_sin_lut[12]={ -45, -50, -41, -22,  4, 28, 45,  50,  41,  22,  -4, -28 };

int16_t prec_int_radius_cos_lut[12]={ -17,   3,  23, 36,  40, 33, 17,  -3, -23, -36, -40, -33 };
int16_t prec_int_radius_sin_lut[12]={ -36, -40, -33,-17,   3, 23, 36,  40,  33,  17,  -3, -23 };
//=============================================================================================

//=============================================================================================
void SecondeSecteur(Color_t Color)
{
	// display of the seconds in a circle made of sectors
	uint8_t idx=0;
	int ext_radius = 50;
	int int_radius = 40;
	int xcenter = 70;
	int ycenter = 190;
	int x_ext_Sec, y_ext_Sec, xSecPrec, ySecPrec, x_int_Sec, y_int_Sec, x_ext_SecPrec, y_ext_SecPrec, x_int_SecPrec, y_int_SecPrec;             // coordinates of the seconds sectors

	if (mySec % 5 == 0) {
		idx= (mySec / 5) +1 ;
		if(idx>11){
			idx=0;
		}
		//    angleSec = ((mySec * PI) / 30) - (PI / 2);
		//    angleSecPrec = ((mySec * PI) / 30) - (PI / 2) + (PI / 7); //   PI/7 rather than PI/6 will separate the 5 secondes sectors

		x_ext_Sec = ext_radius_cos_lut[idx]; x_ext_Sec = x_ext_Sec + xcenter ;
		y_ext_Sec = ext_radius_sin_lut[idx]; y_ext_Sec = y_ext_Sec + ycenter ;
		x_int_Sec = int_radius_cos_lut[idx]; x_int_Sec = x_int_Sec + xcenter ;
		y_int_Sec = int_radius_sin_lut[idx]; y_int_Sec = y_int_Sec + ycenter ;

		x_ext_SecPrec = prec_ext_radius_cos_lut[idx]; x_ext_SecPrec = x_ext_SecPrec + xcenter ;
		y_ext_SecPrec = prec_ext_radius_sin_lut[idx]; y_ext_SecPrec = y_ext_SecPrec + ycenter ;
		x_int_SecPrec = prec_int_radius_cos_lut[idx]; x_int_SecPrec = x_int_SecPrec + xcenter ;
		y_int_SecPrec = prec_int_radius_sin_lut[idx]; y_int_SecPrec = y_int_SecPrec + ycenter ;


		lcd.setColor(Color.Red, Color.Green, Color.Blue);
		lcd.drawTetragon(x_ext_Sec, y_ext_Sec, x_int_Sec, y_int_Sec, x_int_SecPrec, y_int_SecPrec, x_ext_SecPrec, y_ext_SecPrec);

	}
}
//=============================================================================================

//=============================================================================================
void CadranRond()
{
	// set to black, invisible the previous hour hand
	int16_t x1M = 160;  //120                                            // center of the screen x and y
	int16_t y1M = 120;

	// save the previous values of minutes
	Mhdxprec = Mhdx;
	Mhdyprec = Mhdy;
	Mhgxprec = Mhgx;
	Mhgyprec = Mhgy;
	Mbgxprec = Mbgx;
	Mbgyprec = Mbgy;
	Mbdxprec = Mbdx;
	Mbdyprec = Mbdy;


	// save the previous values for the hour hand
	Hhdxprec = Hhdx;
	Hhdyprec = Hhdy;
	Hhgxprec = Hhgx;
	Hhgyprec = Hhgy;
	Hbgxprec = Hbgx;
	Hbgyprec = Hbgy;
	Hbdxprec = Hbdx;
	Hbdyprec = Hbdy;


	angleMinForHour = ((myMin * PI) / 30);
	angleMin = ((myMin * PI) / 30) - (PI / 2);
	angleHour = ((myHour * PI) / 6) - (PI / 2) + (angleMinForHour / 12);

	Hhgx = -17 * cos(angleHour - 0.67); Hhgx = Hhgx + x1M;           // point hg top line
	Hhgy = -17 * sin(angleHour - 0.67); Hhgy = Hhgy + y1M;
	Hhdx =  70 * cos(angleHour + 0.10); Hhdx = Hhdx + x1M;           // point hd top line
	Hhdy =  70 * sin(angleHour + 0.10); Hhdy = Hhdy + y1M;

	Hbgx = -17 * cos(angleHour + 0.67); Hbgx = Hbgx + x1M;           // point bg bottom line
	Hbgy = -17 * sin(angleHour + 0.67); Hbgy = Hbgy + y1M;
	Hbdx =  70 * cos(angleHour - 0.10); Hbdx = Hbdx + x1M;           // point bd bottom line
	Hbdy =  70 * sin(angleHour - 0.10); Hbdy = Hbdy + y1M;


	Mhgx = -15 * cos(angleMin - 0.55); Mhgx = Mhgx + x1M;            // point g top line
	Mhgy = -15 * sin(angleMin - 0.55); Mhgy = Mhgy + y1M;
	Mhdx =  95 * cos(angleMin + 0.05); Mhdx = Mhdx + x1M;            // point d top line
	Mhdy =  95 * sin(angleMin + 0.05); Mhdy = Mhdy + y1M;

	Mbgx = -15 * cos(angleMin + 0.55); Mbgx = Mbgx + x1M;            // point g bottom line
	Mbgy = -15 * sin(angleMin + 0.55); Mbgy = Mbgy + y1M;
	Mbdx =  95 * cos(angleMin - 0.05); Mbdx = Mbdx + x1M;            // point d bottom line
	Mbdy =  95 * sin(angleMin - 0.05); Mbdy = Mbdy + y1M;

	LcdColorBlack( LOW /* delay(50) */);                              // erase the minute hand in black
	lcd.drawTetragon( Mhgxprec, Mhgyprec, Mhdxprec, Mhdyprec, Mbdxprec, Mbdyprec, Mbgxprec, Mbgyprec);     // minute hand
	lcd.drawTetragon( Hhgxprec, Hhgyprec, Hhdxprec, Hhdyprec, Hbdxprec, Hbdyprec, Hbgxprec, Hbgyprec);     // hour hand

	LcdColorRed();           
	lcd.drawTetragon( Hhgx, Hhgy, Hhdx, Hhdy, Hbdx, Hbdy, Hbgx, Hbgy);    // new hand

	LcdColorGreen();
	lcd.drawTetragon( Mhgx, Mhgy, Mhdx, Mhdy, Mbdx, Mbdy, Mbgx, Mbgy);    // new hand
}
//=============================================================================================

//=============================================================================================
void CouleurPoints()    // color of the 5 seconds dots
{
	if (myMin == (myMin / 2) * 2) {
		LcdColorLightBlue();
	} else  {
		LcdColorWhite();
	}
}
//=============================================================================================

//=============================================================================================
int16_t SinTable[12]={-110,-95,-55,  0,55, 95,110, 95, 55,   0,-55,-95};
int16_t CosTable[12]={   0, 55, 95,110,95, 55,  0,-55,-95,-110,-95,-55};
//=============================================================================================

//=============================================================================================
void AiguilleSecondes()
{
	// display white/blue points each 5 second
	int x2Trait, y2Trait;

	int16_t x1M = 160;	// center of screen x and y
	int16_t y1M = 120;
	// draw seconds
	if(mySec % 5 == 0 ) {
		uint8_t idx = ( mySec / 5 );
		if(idx < 12 ){
			CouleurPoints();	// point to Red
			lcd.drawDisc( CosTable[idx]+x1M, SinTable[idx]+y1M, 7, UCG_DRAW_ALL);	// dessin des points de 5 minutes sur le cadran
		}
	}
}
//=============================================================================================

//=============================================================================================
void CadranBlanc()
{
	int16_t x1M = 160;                
	int16_t y1M = 120;                
			   
	for(uint8_t i=0;i<12;i++){
		if(i*5 < mySec){
			if (myMin == (myMin / 2) * 2) {
				LcdColorLightBlue();
			} else  {
				LcdColorWhite();
			}

		} else {
			if (myMin != (myMin / 2) * 2) {
				LcdColorLightBlue();
			} else  {
				LcdColorWhite();
			}
		}
		lcd.drawDisc( CosTable[i]+x1M, SinTable[i]+y1M, 7, UCG_DRAW_ALL);       // dessin des points de 5 minutes sur le cadran
	}
	// end of CadranBlanc
}
//=============================================================================================

//=============================================================================================
void AfficherDate()
{
	LcdColorWhite();
	//lcd.setPrintPos(  10, 215);
	LcdSetPrintPos10_line(215);
	lcd.print(myDate);
	//lcd.setPrintPos(  10, 237);
	LcdSetPrintPos10_line(237);
	lcd.print(textTypeDay[myDow - 1]);
	lcd.setPrintPos( 280, 215); lcd.print(myYear);
	lcd.setPrintPos( 235, 237); lcd.print(textTypeMonth[myMonth - 1]);
}
//=============================================================================================

//=============================================================================================
// appel tous les 0.01 seconde (100 hz) par fonction callback()
uint8_t ValueReadTouch()
{
	uint8_t Result =0 ;
	/* Buttons are inverted !" */
	uint8_t BpLess = !digitalRead(PinBpLess);
	uint8_t BpMore = !digitalRead(PinBpMore);
	uint8_t BpOk = !digitalRead(PinBpOK);
	uint8_t BpAlarm = !digitalRead(PinBpAlarm);
	
	#ifdef ___A6_A7_ENABLED___  //YC modif V2.0
		#ifdef ___SCREEN_CHANGE___
			uint16_t BpScreen = analogRead(PinBpScreen);   //YC modif V2.0
		#endif
		uint16_t Bp_A7 = analogRead(PinPB_A7);   //YC modif V2.0
	#else
		#ifdef ___SCREEN_CHANGE___
			uint8_t BpScreen = !digitalRead(PinBpScreen);    //YC modif V2.0
		#endif
	#endif    //YC modif V2.0

	if( (BpLess!=LOW) && (BpMore==LOW ) && ( BpOk==LOW) && ( BpAlarm == LOW) ){
		if(ReadPbLess <255) { ReadPbLess++; }
	} else { ReadPbLess=0; }

	if( (BpLess==LOW) && (BpMore!=LOW ) && ( BpOk==LOW) && ( BpAlarm == LOW) ){
		if(ReadPbMore <255) { ReadPbMore++; }
	} else { ReadPbMore=0; }

	if( (BpLess==LOW) && (BpMore==LOW ) && ( BpOk!=LOW) && ( BpAlarm == LOW) ){
		if(ReadPbOk <255) { ReadPbOk++; }
	} else { ReadPbOk=0; }

	if( (BpLess==LOW) && (BpMore==LOW ) && ( BpOk==LOW) && ( BpAlarm == HIGH) ){
		if(ReadPbAlarm <255) { ReadPbAlarm++; }
	} else { ReadPbAlarm=0; }

	//YC modif V2.0
	#ifdef ___A6_A7_ENABLED___  //YC modif V2.0
		#ifdef ___SCREEN_CHANGE___
			if( (BpLess==LOW) && (BpMore==LOW ) && ( BpOk==LOW) && ( BpAlarm == LOW) && (BpScreen <= 512) ){
				if(ReadPbScreen <255) { ReadPbScreen++; }
			} else { ReadPbScreen=0; }
			if( (BpLess==LOW) && (BpMore==LOW ) && ( BpOk==LOW) && ( BpAlarm == LOW) && (BpScreen > 512) && (Bp_A7 <= 512) ){
				if(ReadPbA7 <255) { ReadPbA7++; }
			} else { ReadPbA7=0; }  
		#else
			if( (BpLess==LOW) && (BpMore==LOW ) && ( BpOk==LOW) && ( BpAlarm == LOW) && (Bp_A7 <= 512) ){
				if(ReadPbA7 <255) { ReadPbA7++; }
			} else { ReadPbA7=0; }  
		#endif
	#else
		#ifdef ___SCREEN_CHANGE___
			if( (BpLess==LOW) && (BpMore==LOW ) && ( BpOk==LOW) && ( BpAlarm == LOW) && (BpScreen == HIGH) ){
				if(ReadPbScreen <255) { ReadPbScreen++; }
			} else { ReadPbScreen=0; }  
		#endif
	#endif

	if (ReadPbLess > DureeAppui) {
		Result = 1;
	} else if (ReadPbMore > DureeAppui) {
		Result = 2;
	} else if (ReadPbOk > DureeAppui) {
		Result = 3;
	} else if (ReadPbAlarm > DureeAppui) {
		Result = 4;
	} else  {
		Result = 0;	// delete ifdef ___A6_A7_ENABLED___	//YC modif V2.0 
	}
	/* The problem here we can only have one button tuched at a time as result*/

	return Result;
}
//=============================================================================================

//=============================================================================================
void HeadlineHelper(){
	ClearScreenDisplay();	// YC modif V2.8
	LcdColorWhite();                        // White
	lcd.drawFrame(  0,  0,  320, 220);                    // Frame for the settings
	//lcd.setColor( 255, 255, 255);                         // White
	//lcd.setPrintPos(  10,  20);
	LcdSetPrintPos10_line(20);
	lcd.print(("v      -       +      ok"));
}
//=============================================================================================

//=============================================================================================
void AlertHelper(){
	#ifdef ___francais___   //YC modif V1.0
		lcd.print(("  Heure:   Minute:   Jour:")); 
	#elif ___english___
		lcd.print(("   Hour:   Minute:   Day:"));
	#elif ___deutsch___	
		lcd.print(("   Stun:   Protok:   Tag:"));		
	#elif ___italiano___
		lcd.print(("    Ora:   Minuti:   Gio:"));
	#elif ___espanol___
		lcd.print(("   Hora:   Minuto:   Dia:"));
	#elif ___portugues___
		lcd.print(("   Hora:   Minuto:   Dia:"));					
	#endif
  
}
//=============================================================================================

//=============================================================================================
void PrintCopyright(){
	lcd.setPrintPos( 5, 236);   
	#ifdef ___francais___   //YC modif V1.0
		lcd.print(("Auteur:O.CROISET/Y.C 2018 Rev:263v9"));
	#elif ___english___
		lcd.print(("Author:O.CROISET/Y.C 2018 Rev:263v9")); 
	#elif ___deutsch___	
		lcd.print(("Autor:O.CROISET/Y.C 2018 Rev:263v9")); 
	#elif ___italiano___
		lcd.print(("Autore:O.CROISET/Y.C 2018 Rev:263v9")); 
	#elif ___espanol___
		lcd.print(("Autor:O.CROISET/Y.C 2018 Rev:263v9")); 
	#elif ___portugues___
		lcd.print(("Autor:O.CROISET/Y.C 2018 Rev:263v9")); 						
	#endif
}
//=============================================================================================

//=============================================================================================
void SettingAlert()
{
	uint8_t PrevA=88;
	/*AlertBits.BeepOn = LOW;  */ // stop the beeper if ringing		// delete YC modif V2.8
	if (AlertBits.AlertArmed == 2 ) { AlertBits.AlertArmed = 0; }	// add AlertArmed YC modif V2.8
	if (AlertBits.AlertArmed == 3 ) { AlertBits.AlertArmed = 1; }	// add AlertArmed YC modif V2.8
	MemoryReadTouch = 0;               // RaZ de MemoryReadTouch

	/*ALARM DISPLAY*/

	NextAlarm = true;
	Alarmx = 1;
	AlarmNext = 70;
	BlackNext = 55;

	HeadlineHelper();
	PrintCopyright();
	lcd.setPrintPos(  150,  40);	// old 10,40 //YC modif V2.1
	#ifdef ___francais___   //YC modif V1.0
		//lcd.print(("       REGLAGE"));	//YC modif V2.1
		lcd.print(("REGLAGE"));	//YC modif V2.1
	#elif ___english___
		//lcd.print(("       SETTINGS"));	//YC modif V2.1
		lcd.print(("SETTINGS"));	//YC modif V2.1
	#elif ___deutsch___	
		lcd.print(("EINSTELLUNG"));	//YC modif V2.1
	#elif ___italiano___
		lcd.print(("REGISTRAZIONE"));	//YC modif V2.1
	#elif ___espanol___
		lcd.print(("AJUSTE"));	//YC modif V2.1
	#elif ___portugues___
		lcd.print(("AJUSTE"));	//YC modif V2.1			
	#endif
	//lcd.setPrintPos(  10,  55);
	LcdSetPrintPos10_line(55);
	#ifdef ___francais___   //YC modif V1.0
		lcd.print(("ALARME"));	//YC modif V2.1
	#elif ___english___
		lcd.print(("ALARM"));	//YC modif V2.1
	#elif ___deutsch___	
		lcd.print(("ALARM"));	//YC modif V2.1
	#elif ___italiano___
		lcd.print(("ALLARME"));	//YC modif V2.1
	#elif ___espanol___
		lcd.print(("ALARMA"));	//YC modif V2.1
	#elif ___portugues___
		lcd.print(("ALARME"));	//YC modif V2.1			
	#endif

	for (int i = 1 ; i < USERALARMCNT ; i++) {
		//lcd.setPrintPos( 10, (55 + (i * 15)));
		LcdSetPrintPos10_line( (55 + (i * 15)) );
		lcd.print(i);
		//lcd.setPrintPos( 10, (55 + (i * 15))); 
		LcdSetPrintPos10_line( (55 + (i * 15)) );
		AlertHelper();
	}

	lcd.setColor  ( 0,   0,    0,   0);      // Black box
	lcd.drawFrame ( 0, 230,  319, 239);      // Draw box for the author
	LcdColorWhite();	
	lcd.setPrintPos( 5, 236);    


	/* Only nine alarm */
	for (uint8_t i = 1 ; i <= (USERALARMCNT-1) ; i++) {
		lcd.setPrintPos( 83,  (55 + (i * 15))); lcd.print(UserAlarm[i].Hour);
		lcd.setPrintPos( 172,  (55 + (i * 15))); lcd.print(UserAlarm[i].Minute);
		lcd.setPrintPos( 237,  (55 + (i * 15))); lcd.print(textTypeDay[UserAlarm[i].Day]);
	}

	while (Alarmx != USERALARMCNT)
	{
		MemoryReadTouch = ValueReadTouch();
		LcdColorBlue();	//blue
		//lcd.setPrintPos( 10, AlarmNext);
		LcdSetPrintPos10_line(AlarmNext);
		lcd.print(Alarmx);
		//lcd.setPrintPos( 10, AlarmNext);
		LcdSetPrintPos10_line(AlarmNext);
		AlertHelper();
		LcdColorBlack( LOW /* delay(50) */);
		//lcd.drawBox (80, BlackNext, 30, 20);
		LcdDrawBox_a_x_30_20(80, BlackNext);
		do {
			UserAlarm[Alarmx].Hour = SettingHelper1(UserAlarm[Alarmx].Hour);
			UserAlarm[Alarmx].Hour = SettingHelper2(UserAlarm[Alarmx].Hour, MaxHours, 0);
			if (UserAlarm[Alarmx].Hour != PrevA && NextAlarm == true)
			{
				//delay(50);
				LcdColorBlack( HIGH /* delay(50) */);
				//lcd.drawBox (80, BlackNext, 30, 20);
				LcdDrawBox_a_x_30_20(80, BlackNext);
				LcdColorGreen();	//green
				lcd.setPrintPos( 83,  AlarmNext); lcd.print(UserAlarm[Alarmx].Hour); // refresh the display in red
				PrevA = UserAlarm[Alarmx].Hour;
			}
		}
		while (/*MemoryReadTouch != MemoryReadPbOK  && MemoryReadTouch != MemoryReadPbAlarm */ MemoryReadTouch<3 && NextAlarm != false);  // while OK and PbAlarm not pressed, else continue
		
		if (MemoryReadTouch == MemoryReadPbAlarm) {
			NextAlarm = false;
		} else {
			delay(100);
		}
		
		//MemoryReadTouch = 0; ReadPbOk = 0; ReadPbAlarm = 0;
		ClearReadTouch( HIGH /* if LOW no clear ReadPbAlarm */);
		LcdColorWhite();	//white
		lcd.setPrintPos( 83,  AlarmNext); lcd.print(UserAlarm[Alarmx].Hour);
		PrevA = 88;
		do {
			UserAlarm[Alarmx].Minute = SettingHelper1(UserAlarm[Alarmx].Minute);
			UserAlarm[Alarmx].Minute = SettingHelper2(UserAlarm[Alarmx].Minute, 59, 0);
			if (UserAlarm[Alarmx].Minute != PrevA && NextAlarm == true)
			{
				//delay(50);
				LcdColorBlack( HIGH /* delay(50) */);
				//lcd.drawBox (170, BlackNext, 30, 20);
				LcdDrawBox_a_x_30_20(170, BlackNext);
				LcdColorGreen();	//green
				lcd.setPrintPos( 172,  AlarmNext); lcd.print(UserAlarm[Alarmx].Minute); // refresh the display in red
				PrevA = UserAlarm[Alarmx].Minute;
			}
		}
		while (/*MemoryReadTouch != MemoryReadPbOK  && MemoryReadTouch != MemoryReadPbAlarm */ MemoryReadTouch<3 && NextAlarm != false);	// while OK and PbAlarm not pressed, else continue
		
		if (MemoryReadTouch == MemoryReadPbAlarm) {
			NextAlarm = false;
		} else {
			delay(100);
		}
		//MemoryReadTouch = 0; ReadPbOk = 0; ReadPbAlarm = 0;
		ClearReadTouch( HIGH /* if LOW no clear ReadPbAlarm */);                                  // reset the ReadPbOk counter
		LcdColorWhite();	//white
		lcd.setPrintPos( 172,  AlarmNext); lcd.print(UserAlarm[Alarmx].Minute);
		PrevA = 88;
		do {
			UserAlarm[Alarmx].Day = SettingHelper1(UserAlarm[Alarmx].Day);
			UserAlarm[Alarmx].Day = SettingHelper2(UserAlarm[Alarmx].Day, number_day_state, 0);	// old: SettingHelper2(UserAlarm[Alarmx].Day, 8, 0) ==> now 9 "never"  // YC modif V2.0
			if (UserAlarm[Alarmx].Day != PrevA && NextAlarm == true)
			{
				//delay(50);
				LcdColorBlack( HIGH /* delay(50) */);
				lcd.drawBox (233, BlackNext, 84, 20);
				LcdColorGreen();	//green
				lcd.setPrintPos( 237,  AlarmNext); lcd.print(textTypeDay[UserAlarm[Alarmx].Day]);
				PrevA = UserAlarm[Alarmx].Day;
			}
		}
		while (/*MemoryReadTouch != MemoryReadPbOK  && MemoryReadTouch != MemoryReadPbAlarm */ MemoryReadTouch<3 && NextAlarm != false); // while OK and PbAlarm not pressed, else continue
		
		NextAlarm = true;
		//MemoryReadTouch = 0; ReadPbOk = 0; ReadPbAlarm = 0;
		ClearReadTouch( HIGH /* if LOW no clear ReadPbAlarm */);
		LcdColorWhite();	//black
		//lcd.setPrintPos( 10, AlarmNext);
		LcdSetPrintPos10_line(AlarmNext);
		lcd.print(Alarmx);
		//lcd.setPrintPos( 10, AlarmNext);
		LcdSetPrintPos10_line(AlarmNext);
		AlertHelper();
		lcd.setPrintPos( 83,  AlarmNext); lcd.print(UserAlarm[Alarmx].Hour);
		lcd.setPrintPos( 172,  AlarmNext); lcd.print(UserAlarm[Alarmx].Minute);
		lcd.setPrintPos( 237,  AlarmNext); lcd.print(textTypeDay[UserAlarm[Alarmx].Day]);
		PrevA = 88;
		Alarmx++;
		AlarmNext = AlarmNext + 15;
		BlackNext = BlackNext + 15;
	}
	//------------------------------------------- end of alerts --------------------------------------------//
	ClearScreenDisplay();	// YC modif V2.8
	AlarmSync();
	GetNextAlert(true);
}
//=============================================================================================
void ClearReadTouch ( boolean clearReadAlarm) {	//YC modif V2.8
	MemoryReadTouch = 0; ReadPbOk = 0; 
	if ( clearReadAlarm ) { ReadPbAlarm = 0; }
}

//=============================================================================================
void SettingTimePrintText(uint8_t txt_id){
    switch(txt_id){
		case 0:
		case 2:{
			//lcd.setPrintPos(  10, 70);
			LcdSetPrintPos10_line(70);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("  Annee        :         "));
			#elif ___english___
				lcd.print(("  Year         :         "));
			#elif ___deutsch___	
				lcd.print(("  Jahr         :         "));
			#elif ___italiano___
				lcd.print(("  Anno         :         "));
			#elif ___espanol___
				lcd.print(("  Ano          :         "));
			#elif ___portugues___
				lcd.print(("  Ano          :         "));	
			#endif  
		}break;

		case 1:{
			//lcd.setPrintPos(  10,  55);
			LcdSetPrintPos10_line(55);
			#ifdef ___francais___   //YC modif V1.0  
				lcd.print(("HORLOGE"));
			#elif ___english___
				lcd.print(("CLOCK"));
			#elif ___deutsch___	
				lcd.print(("UHR"));
			#elif ___italiano___
				lcd.print(("OROLOGIO"));
			#elif ___espanol___
				lcd.print(("RELOJ"));
			#elif ___portugues___
				lcd.print(("RELOGIO"));
			#endif          
		}break;

		/*case 2:{
			//lcd.setPrintPos(  10, 70);
			LcdSetPrintPos10_line(70);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("   Annee       :         "));
			#else
				lcd.print(("   Year        :         "));
			#endif  
		}break;*/

		case 3:{
			//lcd.setPrintPos(  10, 85);
			LcdSetPrintPos10_line(85);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("  Mois         :         "));
			#elif ___english___
				lcd.print(("  Month        :         "));
			#elif ___deutsch___	
				lcd.print(("  Monat        :         "));
			#elif ___italiano___
				lcd.print(("  Mese         :         "));
			#elif ___espanol___
				lcd.print(("  Mes          :         "));
			#elif ___portugues___
				lcd.print(("  Mes          :         "));	
			#endif        
		}break;

		case 4:{
			//lcd.setPrintPos(  10, 100);
			LcdSetPrintPos10_line(100);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("  Jour semaine :         "));  // day of week : monday to sunday
			#elif ___english___
				lcd.print(("  Day of week  :         "));  
			#elif ___deutsch___	
				lcd.print(("  Wochentage   :         "));
			#elif ___italiano___
				lcd.print(("  Giorno sett  :         "));
			#elif ___espanol___
				lcd.print(("  Dia semana   :         "));
			#elif ___portugues___
				lcd.print(("  Dia semana   :         "));		
			#endif        
		}break;

		case 5:{
			//lcd.setPrintPos(  10, 115);
			LcdSetPrintPos10_line(115);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("  Date         :         "));    // day of week : monday to sunday
			#elif ___english___
				lcd.print(("  Date         :         "));  
			#elif ___deutsch___	
				lcd.print(("  Datum        :         "));
			#elif ___italiano___
				lcd.print(("  Data         :         "));
			#elif ___espanol___
				lcd.print(("  Fecha        :         "));
			#elif ___portugues___
				lcd.print(("  Data         :         "));	
			#endif
		}break;

		case 6:{
			//lcd.setPrintPos(  10, 130);
			LcdSetPrintPos10_line(130);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("  Heure        :         "));
			#elif ___english___
				lcd.print(("  Hour         :         "));
			#elif ___deutsch___	
				lcd.print(("  Zeit         :         "));
			#elif ___italiano___
				lcd.print(("  Data         :         "));
			#elif ___espanol___
				lcd.print(("  Hora         :         "));
			#elif ___portugues___
				lcd.print(("  Tempo        :         "));	
			#endif       
		}break;

		case 7:{
			//lcd.setPrintPos(  10, 145);
			LcdSetPrintPos10_line(145);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("  Minute       :         "));
			#elif ___english___
				lcd.print(("  Minute       :         "));
			#elif ___deutsch___	
				lcd.print(("  Minute       :         "));
			#elif ___italiano___
				lcd.print(("  Data         :         "));
			#elif ___espanol___
				lcd.print(("  Minuto       :         "));
			#elif ___portugues___
				lcd.print(("  Minuto       :         "));	
			#endif       				
		}break;

		case 8:{
			//lcd.setPrintPos(  10, 160);
			LcdSetPrintPos10_line(160);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("RETRO-ECLAIRAGE"));
			#elif ___english___
				lcd.print(("BACKLIGHT"));
			#elif ___deutsch___	
				lcd.print(("HINTERGRUNDBELEUCHTUNG")); 
			#elif ___italiano___
				lcd.print(("CONTROLUCE"));
			#elif ___espanol___
				lcd.print(("ILUMINACION"));
			#elif ___portugues___
				lcd.print(("LUZ DE FUNDO"));		
			#endif              
		}break;

		case 9:{
			//lcd.setPrintPos(  10, 175);
			LcdSetPrintPos10_line(175);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("  Luminosite   :         "));
			#elif ___english___
				lcd.print(("  Brightness   :         "));
			#elif ___deutsch___	
				lcd.print(("  Helligkeit   :         "));
			#elif ___italiano___
				lcd.print(("  Luminosità   :         "));
			#elif ___espanol___
				lcd.print(("  Brillo       :         "));
			#elif ___portugues___
				lcd.print(("  Brilho       :         "));			
			#endif        
		}break;

		case 10:{
			//lcd.setPrintPos(  10, 190);
			LcdSetPrintPos10_line(190);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("  LDR Clair    :         ")); 
			#elif ___english___
				lcd.print(("  LDR Bright   :         ")); 
			#elif ___deutsch___	
				lcd.print(("  LDR Hell     :         "));
			#elif ___italiano___
				lcd.print(("  LDR Luminos  :         "));
			#elif ___espanol___
				lcd.print(("  LDR Luminos  :         "));
			#elif ___portugues___
				lcd.print(("  LDR Claro    :         "));		
			#endif       
		} break;

		case 11:{
			//lcd.setPrintPos(  10, 205);
			LcdSetPrintPos10_line(205);
			#ifdef ___francais___   //YC modif V1.0
				lcd.print(("  LDR Sombre   :         ")); 
			#elif ___english___
				lcd.print(("  LDR Dark     :         ")); 
			#elif ___deutsch___	
				lcd.print(("  LDR Dunkel   :         "));
			#elif ___italiano___
				lcd.print(("  LDR Oscuro   :         "));
			#elif ___espanol___
				lcd.print(("  LDR Oscuro   :         "));
			#elif ___portugues___
				lcd.print(("  LDR Sombrio  :         "));		
			#endif          
		} break;

		default:{       
		} break;

    }
    
}
//=============================================================================================
uint8_t StepAdjustTime(uint8_t line, uint8_t PrevA, uint8_t tags,uint8_t MAxHelp2,uint8_t MinHelp2, uint8_t x  ) {	
	do
	{
		LcdColorBlue();                          // Blue
		SettingTimePrintText(line);
		tags = SettingHelper1(tags);
		tags = SettingHelper2(tags, MAxHelp2, MinHelp2);
		if (tags != PrevA)
		{
			LcdColorBlack( HIGH /* delay(50) */);	// to erase the previous characters
			LcdDrawBox_160_x_40_10(x);
			LcdColorGreen();
			LcdSetPrintPos160_line(x+10); lcd.print(tags);      // refresh the display in Blue
			PrevA = tags;
		}
	}
	while (MemoryReadTouch<3);  // while OK and PbAlarm not pressed, else continue

	ClearReadTouch( LOW /* if LOW no clear ReadPbAlarm */);
	LcdColorWhite();                        // Reset to white
	SettingTimePrintText(line);
	LcdSetPrintPos160_line(x+10); lcd.print(tags);
	
	return tags;
}	
//=============================================================================================
uint16_t StepAdjustLDR(uint8_t line, uint8_t x, uint16_t read /*, uint16_t work */  ) {	
	do
	{
		LcdColorBlue();          
		SettingTimePrintText(line);		// Blue
		if(MemoryReadTouch==MemoryReadPbOK){
			delay(50);
			while(MemoryReadTouch==MemoryReadPbOK){
				/* Wait till released */
				delay(50); 
			}
			/* Do untill pressed */
			while(MemoryReadTouch!=MemoryReadPbOK){
				LcdColorBlack( LOW /* delay(50) */);                         //
				//lcd.drawBox (160, x, 60, 10);                 // to erase the previous characters
				LcdDrawBox_160_x_y_10(x, 60 );
				LcdColorGreen();
				LcdSetPrintPos160_line(x + 10); 
				read = analogRead(PinLDR);  // -> LDR for screen LEDs control
				//work = ~read;	//Bitwise operators > Bitwisenot
				lcd.print(read);
				delay(75);
			}
			while(MemoryReadTouch==MemoryReadPbOK){
				/* Wait till released */ 
				delay(50);
			}
		}

	}
	while ( MemoryReadTouch != MemoryReadPbAlarm );  
	
	return read;
}
//=============================================================================================
void SettingTime(  ){
	uint8_t prev_dimmer=0;
	uint16_t PrevA=0xFFFF;
	//lcd.clearScreen();	// included in HeadlineHelper()
	HeadlineHelper();
	PrintCopyright();
	for(uint8_t i=0;i<12;i++){
		SettingTimePrintText(i);
	}
	myHour  = t_temp.hour;
	myMin   = t_temp.min;
	ModifyTime=LOW;	//ADD YC modif V2.2
	
	LcdSetPrintPos160_70(); lcd.print(myYear);
	LcdSetPrintPos160_85(); lcd.print(myMonth);	//lcd.print(textTypeMonth[myMonth - 1]);
	LcdSetPrintPos160_100(); lcd.print(myDow);	//lcd.print(textTypeDay[myDow - 1]);
	LcdSetPrintPos160_115(); lcd.print(myDate);
	LcdSetPrintPos160_line(130); lcd.print(myHour);
	LcdSetPrintPos160_line(145); lcd.print(myMin);
	LcdSetPrintPos160_line(175); lcd.print(textTypeScreenLight[auto_dimmer]);
	LcdSetPrintPos160_line(190); lcd.print(LDR_Calibration.LDR_BRIGHT);
	LcdSetPrintPos160_line(205); lcd.print(LDR_Calibration.LDR_DARK);

	/*===================================================================*/
	/*                  TIME AND GRADE LDR                               */
	/*===================================================================*/
	/*             RECORD THE DATE AND TIME IN THE DS1302 CHIP           */
	/*===================================================================*/	
	
	// ==================================================== Modify the year
	do
	{
		LcdColorBlue();                          // Blue
		SettingTimePrintText(2);
		myYear = SettingHelper1(myYear);
		if (myYear != PrevA)
		{
		  LcdColorBlack( HIGH /* delay(50) */);  
		  LcdDrawBox_160_x_40_10(60);
		  LcdColorGreen();   
		  LcdSetPrintPos160_70(); lcd.print(myYear);      // refresh the display in Blue
		  PrevA = myYear;
		}
	}
	while (MemoryReadTouch<3);  // while OK and PbAlarm not pressed, else continue

	ClearReadTouch( LOW /* if LOW no clear ReadPbAlarm */);
	t_temp.year = myYear;
	LcdColorWhite();                        // Reset to white
	SettingTimePrintText(2);
	LcdSetPrintPos160_70(); lcd.print(myYear);

	// ==================================================== Modify the month
	uint8_t PrevB = 88;
	myMonth = StepAdjustTime (3,PrevB, myMonth, 12, 1, 75  );
	//lcd.print(textTypeMonth[myMonth - 1]);
	// ==================================================== Modify the day of week (Monday..Sunday)
	myDow = StepAdjustTime (4,PrevB, myDow, 7, 1, 90  );
	//lcd.print(textTypeDay[myDow - 1]);
	// ==================================================== Modify the date (1..31)
	myDate = StepAdjustTime (5,PrevB, myDate, 31, 1, 105  );
	// ======================================================= Modify hour
	myHour = StepAdjustTime (6,PrevB, myHour, MaxHours, 0, 120  );
	// ===================================================== Modify minute
	myMin   = t_temp.min;
	myMin = StepAdjustTime (6,PrevB, myMin, 59, 0, 135  );
	
	if 	(ModifyTime==HIGH) {	//ADD ModifyTime --> YC modif V2.2
		/*===================================================================*/
		/*                   Record date in the DS1302                   */		
		rtc.setDate( myDate, myMonth, myYear);        // date,  month , year
		rtc.setDOW ( myDow );                               // Day Of Week
		/*                   Record the hour in the DS1302                   */
		rtc.setTime(myHour, myMin, mySec);                  // Set the time
		/*===================================================================*/
	}
	
	// ==================================================== SETTING LIGHT LCD AND RECORD IN EEPROM
	//PrevA = 88;
	/* Backlight on off */
	prev_dimmer = 255;
	do {
		Backlight();
		LcdColorBlue();                          // Blue
		SettingTimePrintText(9);
		auto_dimmer = SettingHelper1(auto_dimmer);
		auto_dimmer = SettingHelper2(auto_dimmer, 3, 0);
		if (prev_dimmer != auto_dimmer)
		{
			//delay(50);
			LcdColorBlack( HIGH /* delay(50) */);                        //
			//lcd.drawBox (160, 165, 160, 10);    //YC V2.7 old 40,10)                  // to erase the previous characters
			LcdDrawBox_160_x_y_10(165, 160 );
			LcdColorGreen();
			Backlight();
			LcdSetPrintPos160_line(175); lcd.print(textTypeScreenLight[auto_dimmer]);
			prev_dimmer = auto_dimmer;
		}
	}
	while (/*MemoryReadTouch != MemoryReadPbOK  && MemoryReadTouch != MemoryReadPbAlarm */ MemoryReadTouch<3); // while OK and PbAlarm not pressed, else continue
	
	EEPROM.update( EEPLIGHT_ADDR, auto_dimmer );
	LcdColorWhite();                          // White
	SettingTimePrintText(9);
	LcdSetPrintPos160_line(175); lcd.print(textTypeScreenLight[auto_dimmer]);

	/* This is for the LDR calibration */
	prev_dimmer = auto_dimmer;
	auto_dimmer = 1;
	Backlight();
	// ==================================================== GRADE LDR AND RECORD IN EEPROM
	//YC modif V3.0
	LDR_Calibration.INV_LDR_BRIGHT = ~LDR_Calibration.LDR_BRIGHT;	//Bitwise operators > Bitwisenot
	LDR_Calibration.LDR_BRIGHT = StepAdjustLDR (10, 180, LDR_Calibration.LDR_BRIGHT/*, LDR_Calibration.INV_LDR_BRIGHT */ );
	
	LcdColorWhite();                          // White
	SettingTimePrintText(10);
	LcdSetPrintPos160_line(190); 
	lcd.print(LDR_Calibration.LDR_BRIGHT);

	//YC modif V3.0
	LDR_Calibration.INV_LDR_DARK = ~LDR_Calibration.LDR_DARK;	//Bitwise operators > Bitwisenot
	LDR_Calibration.LDR_DARK = StepAdjustLDR (11, 195, LDR_Calibration.LDR_DARK/*, LDR_Calibration.INV_LDR_DARK */ );
	
	auto_dimmer=prev_dimmer;
	Backlight();
	
	//YC modif V3.0
	if( (LDR_Calibration.LDR_BRIGHT != (~LDR_Calibration.INV_LDR_BRIGHT)) || (LDR_Calibration.LDR_DARK != (~LDR_Calibration.INV_LDR_DARK) )  ){
		LDR_Calibration.INV_LDR_BRIGHT = ~LDR_Calibration.LDR_BRIGHT;	//Bitwise operators > Bitwisenot
		LDR_Calibration.INV_LDR_DARK = ~LDR_Calibration.LDR_DARK;	//Bitwise operators > Bitwisenot

		Backlight_Cal_Sync();
	}

	// and erase the screen to return to display the clock screen
	ClearScreenDisplay();	// YC modif V2.8
	GetNextAlert(true);
}

//=============================================================================================
void SettingsDisplay(  ){	
  /*
  // CROISET modify V7.0
  
  uint16_t PrevA=0xFFFF;
  //lcd.clearScreen();	// included in HeadlineHelper()
  HeadlineHelper();
  PrintCopyright();

  //lcd.setPrintPos(  10, 70);  lcd.print(("   Displaymode    :         "));

  do
  {
    LcdColorBlue();                          // Blue
    lcd.setPrintPos(  10, 70);  lcd.print(("   Displaymode :             "));
    displaysettings.displaymode = SettingHelper1( displaysettings.displaymode );
    displaysettings.displaymode = SettingHelper2(displaysettings.displaymode, DISPLAY_THREE, DISPLAY_AUTO);
   
    if (displaysettings.displaymode != PrevA)
    {
     
      //delay(50);
      LcdColorBlack( HIGH );
      lcd.drawBox (160, 50, 140 , 20);                 // to erase the previous characters
      LcdColorGreen();
      lcd.setPrintPos( 160, 70); 
        switch(displaysettings.displaymode){
          case DISPLAY_AUTO: {
            lcd.print(("Automatic"));
          } break;
                
          case DISPLAY_ONE: {
            lcd.print(("clock 1"));
          } break;

          case DISPLAY_TWO: {
             lcd.print(("clock 2"));
          } break;
          
          case DISPLAY_THREE: {
             lcd.print(("clock 3"));
          } break;

          default:{
             displaysettings.displaymode = DISPLAY_AUTO;
             
          } break;
        }
          
         
      PrevA = displaysettings.displaymode;
    }
  }
  while (MemoryReadTouch != MemoryReadPbOK  && MemoryReadTouch != MemoryReadPbAlarm);	// while OK and PbAlarm not pressed, else continue

// CROISET modify V7.0
  
  //MemoryReadTouch = 0; ReadPbOk = 0; ReadPbAlarm = 0;
  ClearReadTouch( HIGH // if LOW no clear ReadPbAlarm );
  LcdColorWhite();                        // Reset to white
  
  EEPROM.write( EEPDISPLAYROTATION_ADDR, displaysettings.displaymode );
  ClearScreenDisplay();	
  GetNextAlert(true); */
}

//=============================================================================================
void Backlight_Cal_Sync(){
	uint8_t* u8Ptr;
	u8Ptr=(uint8_t*)&LDR_Calibration;
	for(uint8_t i=0;i<sizeof(LDR_CAL_t);i++){
		EEPROM.update(EEPLDRCALOFFSET_ADDR+i, *(u8Ptr));
		u8Ptr++;
	}
}
//=============================================================================================

//=============================================================================================
/* 
 *  A Pointer would be too much ... :-(  
 *  and a bool in return if something has pressed 
 *  
*/
int16_t SettingHelper1(int16_t Aspect) {
	if(ReadPbLess > (DureeAppui)) {
		Aspect--;  // left
		ReadPbLess = 0;
		ModifyTime = HIGH;	/* ADD modify YC modif V2.2 */
	}
	if (ReadPbMore > (DureeAppui)) {
		Aspect++;  // right
		ReadPbMore = 0;
		ModifyTime = HIGH;	/* ADD modify YC modif V2.2 */
	}
	return Aspect;
}
//=============================================================================================

//=============================================================================================
int8_t SettingHelper2(int8_t Aspect, int8_t timeAspect1, int8_t timeAspect2) {
	if (Aspect > timeAspect1) {	Aspect = timeAspect2 ; }
	if (Aspect < timeAspect2 ) { Aspect = timeAspect1; }
	return Aspect;
}
//=============================================================================================

//=============================================================================================
void SevenSegments(bool refresh)
{
	// Flash ROM = ??? bytes (3614 bytes in a previous non-optimized version)
	// https://github.com/olikraus/ucglib/wiki
	// http://www.proftnj.com/RGB3.htm    for the segments colours definition
	// http://www.fond-ecran-image.com/galerie-membre,horloge,horloge-de-garejpg.php : horloge Part-Dieu LYON
	static uint8_t SegmenValue[4]={255,255,255,255};

	// ============= display each digit in a "for" loop
	uint16_t Numdigit;
	uint8_t digit;         // value of each digit to display
	uint8_t  i; 
	// digit counter, 1 (= left, dozenH) to 4 (= right, unitM)

	uint8_t Red=0;
	uint8_t Green=0;
	uint8_t Blue=0;

	// Numdigit is the X position of the 7 segments
	//                 [chiffre, Numdigit, Red, Green, Blue] [..] [..] [..]
	uint8_t Values[][5] = {{(myHour / 10),    8,  51, 255, 153},  //light blue
						{(myHour % 10),   80, 255,   0,  51}, //light red
						{(myMin  / 10),  180, 255, 204,   0}, //orange
						{(myMin  % 10),  248, 127, 127, 255} }; //purple


	for ( i = 0; i < 4; i++){

		digit = Values[i][0]; 
		if( ( refresh != false ) || (digit != SegmenValue[i]) ){
			SegmenValue[i]=digit;
			Numdigit = Values[i][1];
			if (newScreen != 3) {	// color orange  //YC modif V2.8
				Red = 255; Green =  204; Blue =0; //YC modif V2.0
			} else { //YC modif V2.0 			
				Red = Values[i][2]; Green = Values[i][3]; Blue = Values[i][4];
			} //YC modif V2.0  
				
			LcdColorBlack( LOW /* delay(50) */);
			switch (digit) { // read and display the numerical value (1) for each digit position (i)
				case 0: {
					Segment('G',Numdigit);
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('A',Numdigit);
					Segment('B',Numdigit);
					Segment('C',Numdigit);
					Segment('D',Numdigit);
					Segment('E',Numdigit);
					Segment('F',Numdigit);
					
				} break;
		  
				case 1: {
		  
					Segment('A',Numdigit);
					Segment('D',Numdigit);
					Segment('E',Numdigit);
					Segment('F',Numdigit);
					Segment('G',Numdigit);
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('B',Numdigit);
					Segment('C',Numdigit);
					
					
				} break;
		  
				case 2: {
					Segment('C',Numdigit);
					Segment('F',Numdigit);
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('A',Numdigit);
					Segment('B',Numdigit);
					Segment('D',Numdigit);
					Segment('E',Numdigit);
					Segment('G',Numdigit);
					
					
				} break;
		  
				case 3: {
					Segment('E',Numdigit);
					Segment('F',Numdigit);
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('A',Numdigit);
					Segment('B',Numdigit);
					Segment('C',Numdigit);
					Segment('D',Numdigit);
					Segment('G',Numdigit);
					
				} break;
		  
				case 4: {              
					Segment('A',Numdigit);
					Segment('D',Numdigit);
					Segment('E',Numdigit);
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('B',Numdigit);
					Segment('C',Numdigit);
					Segment('F',Numdigit);
					Segment('G',Numdigit);
				} break;
		  
				case 5: {             
					Segment('B',Numdigit);
					Segment('E',Numdigit);
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('A',Numdigit);
					Segment('C',Numdigit);
					Segment('D',Numdigit);
					Segment('F',Numdigit);
					Segment('G',Numdigit);
					
				} break;
		  
				case 6: {
					Segment('B',Numdigit);
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('A',Numdigit);
					Segment('C',Numdigit);
					Segment('D',Numdigit);
					Segment('E',Numdigit);
					Segment('F',Numdigit);
					Segment('G',Numdigit);
					
				} break;
		  
				case 7: {
					Segment('D',Numdigit);
					Segment('E',Numdigit);
					Segment('F',Numdigit);
					Segment('G',Numdigit);
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('A',Numdigit);
					Segment('B',Numdigit);
					Segment('C',Numdigit);
					
				} break;
		  
				case 8: {
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('A',Numdigit);
					Segment('B',Numdigit);
					Segment('C',Numdigit);
					Segment('D',Numdigit);
					Segment('E',Numdigit);
					Segment('F',Numdigit);
					Segment('G',Numdigit);
				} break;
		  
				case 9: {
					Segment('E',Numdigit);
					lcd.setColor(Red, Green, Blue);        // Set the color
					Segment('A',Numdigit);
					Segment('B',Numdigit);
					Segment('C',Numdigit);
					Segment('D',Numdigit);
					Segment('F',Numdigit);
					Segment('G',Numdigit);
				  
				} break;
			}                // end of switch
		} // end of if
	}                  // end of for_i loop
}                    // end of SevenSegments
//=============================================================================================

//=============================================================================================
// ============= two points
void Colon()
{
	int8_t c1, c2, c3 ;  // dots color definition
	int colonXpos;
	int colonYpos;

	if (newScreen != 3) {	//YC modif V2.8
		c1 = 255; c2 = 204; c3 =0; // color orange  	//YC modif V2.1
	} else {
		c1 = 255; c2 = 255; c3 = 255;	// color white
	}
	colonXpos = 160;
	colonYpos = 70;
	if (newScreen == 3) {	//YC modif V2.7
		if( (mySec%2) == 0){
			lcd.setColor(0, c2, c3);
		} else {
			lcd.setColor(c1,   0,   0);
		}
	} else {	//YC modif V2.1
		lcd.setColor(c1,   c2,   c3);	//YC modif V2.1
	}
	lcd.drawDisc(colonXpos, colonYpos, 7, UCG_DRAW_ALL );        // upper dot
	colonYpos = 110;  
	if (newScreen == 3) {	//YC modif V2.7
		if( (mySec%2) == 0){
			lcd.setColor(c1,   0,   0);		
		} else {
			lcd.setColor(0, c2, c3);
		}
	} else {	//YC modif V2.1
		lcd.setColor(c1,   c2,   c3);	//YC modif V2.1
	}	
	lcd.drawDisc(colonXpos, colonYpos, 7, UCG_DRAW_ALL);         // lower dot
}
//=============================================================================================

//=============================================================================================
//       -a-
//    f |    |  b
//        -g-
//    e |    |  c
//       -d-     dp
//
void Segment( uint8_t idx, uint16_t offset){

	uint16_t x0 = 0;
	uint16_t y0 = 0;
	uint16_t x1 = 0;
	uint16_t y1 = 0;
	uint16_t x2 = 0;
	uint16_t y2 = 0;
	uint16_t x3 = 0;
	uint16_t y3 = 0;


	switch(idx){
		case 'A':{
		x0 = Xpos +  4 + offset;
		y0 = /*0 + */Ypos;
		x1 = Xpos + 56 + offset;
		y1 = /*0 + */Ypos;
		x2 = Xpos + 45 + offset;
		y2 = Ypos + 11;
		x3 = Xpos + 14 + offset;
		y3 = Ypos + 11;

		} break;

		case 'B':{
			x0 = Xpos + 60 + offset;
			y0 = Ypos + 1;
			x1 = Xpos + 60 + offset;
			y1 = Ypos + 59;
			x2 = Xpos + 50 + offset;
			y2 = Ypos + 49;
			x3 = Xpos + 50 + offset;
			y3 = Ypos + 11;

		} break;

		case 'C':{

			x0 = Xpos + 60 + offset;
			y0 = Ypos + 61;
			x1 = Xpos + 60 + offset;
			y1 = Ypos + 119;
			x2 = Xpos + 50 + offset;
			y2 = Ypos + 109;
			x3 = Xpos + 50 + offset;
			y3 = Ypos + 71;
		  
		} break;

		case 'D':{

			x0 = Xpos + 56 + offset;
			y0 = Ypos + 120;
			x1 = Xpos +  3 + offset;
			y1 = Ypos + 120;
			x2 = Xpos + 12 + offset;
			y2 = Ypos + 111;
			x3 = Xpos + 47 + offset;
			y3 = Ypos + 111;

		} break;

		case 'E':{

			x0 = Xpos /*+  0*/ + offset;
			y0 = Ypos + 61;
			x1 = Xpos + 10 + offset;
			y1 = Ypos + 71;
			x2 = Xpos + 10 + offset;
			y2 = Ypos + 109;
			x3 = Xpos /*+  0*/ + offset;
			y3 = Ypos + 119;

		} break;

		case 'F':{

			x0 = Xpos /*+  0*/ + offset;
			y0 = Ypos +  1;
			x1 = Xpos + 10 + offset;
			y1 = Ypos + 11;
			x2 = Xpos + 10 + offset;
			y2 = Ypos + 49;
			x3 = Xpos /*+  0*/ + offset;
			y3 = Ypos + 59;
			  
		} break;

		case 'G':{

			x0 = Xpos + 10 + offset;
			y0 = Ypos + 55;
			x1 = Xpos + 49 + offset;
			y1 = Ypos + 55;
			x2 = Xpos + 55 + offset;
			y2 = Ypos + 60;
			x3 = Xpos +  5 + offset;
			y3 = Ypos + 60;

			lcd.drawTetragon(x0, y0, x1, y1, x2, y2, x3, y3);  // segment g upper part

			x0 = Xpos +  5 + offset;
			y0 = Ypos + 60;
			x1 = Xpos + 55 + offset;
			y1 = Ypos + 60;
			x2 = Xpos + 50 + offset;
			y2 = Ypos + 65;
			x3 = Xpos + 10 + offset;
			y3 = Ypos + 65;

		} break;

	}
	
	lcd.drawTetragon(x0, y0, x1, y1, x2, y2, x3, y3);  
}
//=============================================================================================

//=============================================================================================
void Secondes()
{
	// affiche les points des secondes
	int xposSec;
	xposSec = (mySec * 5);
	if (newScreen != 3) {	//YC modif V2.8
		LcdColorOrange();  	//YC modif V2.1
	} else {
		LcdColorWhite();
	}
	lcd.drawBox(xposSec + 6, 201, 4, 9);
}
//=============================================================================================

//=============================================================================================
void CadranSecondes()
{
	int i;
	LcdColorBlack( LOW /* delay(50) */);
	lcd.drawBox (  11, 199, 302, 11);             // inside of the secondes frame
	if (newScreen != 3) {	//YC modif V2.8
		LcdColorOrange();  	//YC modif V2.1
	} else {
		LcdColorWhite();
	}
	lcd.drawFrame( 10, 200, 302, 11);             // secondes frame
	for (i = 1; i <= 60; i++) {
		lcd.drawVLine( (5 * i) + 5, 201, 9);  // secondes separator
	}
}
//=============================================================================================

//=============================================================================================
void CadranNumber(bool refresh, uint16_t pos ) //YC modif V2.0
{
	if (refresh != false) {  //YC modif V2.0
		lcd.setColor(255 , 100, 100); //color pink   //YC modif V2.0
		lcd.setPrintPos( 280, pos); lcd.print(SCREEN[selectScreen]);  //YC modif V2.0
	} //YC modif V2.0
}
//=============================================================================================

//=============================================================================================
void Debug_texte ( uint16_t pos ) //YC modif V2.8_2 and V3.0
{
	#ifdef ____DEBUG__PROG____
		LcdColorGray();  //YC modif V2.8_2
		lcd.setPrintPos( 280, pos); 
		//lcd << Tags << endl;
		lcd.print ( freeRam() );
	#endif
}


