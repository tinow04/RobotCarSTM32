#include <SoftwareSerial.h> 
#include <LiquidCrystal_PCF8574.h>


#define LED                 D13
#define BTRX                D2 
#define BTTX                D3 
#define PINMOTOR1PWM        D9 
#define PINMOTOR1DIRECTION  D7
#define PINMOTOR2PWM        D10
#define PINMOTOR2DIRECTION  D8


    SoftwareSerial SerialBT(BTRX, BTTX);
    LiquidCrystal_PCF8574 lcd (0x27);
    static HardwareTimer blinkTimer = HardwareTimer(TIM2);  // create Timer

int M1dutyCycle, M2dutyCycle;
String message; 
volatile bool toggle;

void setup() {
  
    Serial.begin(115200);
    SerialBT.begin(9600);  
    Serial.println("Bluetooth connection...");
    Serial.println("End Setup");
    I2C_LCD_init();
  
    pinMode(D9, OUTPUT);
    pinMode(D7, OUTPUT);
    pinMode(PINMOTOR2PWM, OUTPUT);
    pinMode(PINMOTOR2DIRECTION, OUTPUT);
    pinMode(LED, OUTPUT);


    //PWM speed
    analogWriteResolution(16);
    analogWriteFrequency(200);

    //Timer speed
    blinkTimer.setOverflow(50000);       // 0-65535;
    blinkTimer.setPrescaleFactor(320);   // 0-65535;
}

void loop() {
    BLE_call();   // call method
}  
