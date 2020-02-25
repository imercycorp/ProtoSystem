#include "Arduino.h"

////////////////////////
// ARDUINO NANO_MLED //
//////////////////////

    // Définition PIN Matrice Coté Gauche
#define MCG_DATA 8
#define MCG_CS 9
#define MCG_CLK 10

    // Définition PIN Matrice Coté Droit
#define MCD_DATA 4
#define MCD_CLK 3
#define MCD_CS 2

    // Définition Nombre Matrice
#define MCG_NB 7
#define MCD_NB 7

    // Définiton PIN LED
#define LED_CG 6
#define LED_CD 5

    // Définition PIN Capteur IR
#define PIN_IR_L 12
#define PIN_IR_R 11

    // Définition PIN BLE
#define BLE_TX 21
#define BLE_TX 20

//////////////////////////
// ARDUINO NANO SYSTEM //
////////////////////////

    // Défintion PIN SS
#define SS_TMP 14
#define SS_RAD 9

    // Défintion TMP Vitale
#define SS_VIT_T 28
#define SS_CRIT 35

    // Définition I2C PIN
#define I_SDA 18
#define I_SCL 19

    // Définition Servo PIN
#define SERVO_SDA 16
#define SERVO_SCL 17
#define SERVO_OE 20
