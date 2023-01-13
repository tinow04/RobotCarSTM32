// connection to app 
// I used "BluetoothforArduino" on IPadOS

void BLE_call (void) {  
    if (SerialBT.available()){                        // data available?
        message = SerialBT.readString();              // text from app is read and saved in string message
        Serial.println(message);
        
        if  (message == "PWM\n") {                    // if message is "PWM"
            lcd.clear();
            M1dutyCycle = 25000;                      // PWM Motor 1 25000
            M2dutyCycle = 25000;                      // PWM Motor 2 25000
        
            I2C_LCD("PWM is 25000");                  // print LCD
        }
        
        if  (message == "forward\n") {                // if message is "forward"
            lcd.clear();
            analogWrite(PINMOTOR1PWM, M1dutyCycle);   // motor 1 is on
            digitalWrite(PINMOTOR1DIRECTION, HIGH);   // direction
            analogWrite(PINMOTOR2PWM, M2dutyCycle);   // motor 2 is on
            digitalWrite(PINMOTOR2DIRECTION, LOW);    // direction
        
            I2C_LCD("forward");                       // print LCD
        }
        
        if (message == "back\n") {                    // if message is "back"
            lcd.clear();
            analogWrite(PINMOTOR1PWM, M1dutyCycle);   
            digitalWrite(PINMOTOR1DIRECTION, LOW);    
            analogWrite(PINMOTOR2PWM, M2dutyCycle);   
            digitalWrite(PINMOTOR2DIRECTION, HIGH);
        
            blinkTimer.attachInterrupt(ISR_Timer);    // activate Timer IR
            blinkTimer.resume();                      // start Timer
            
            I2C_LCD("back");                          // print LCD
        }
        
        if  (message == "stop\n") {                   // if message is "stop"
            lcd.clear();
            analogWrite(PINMOTOR1PWM, LOW);
            digitalWrite(PINMOTOR1DIRECTION, LOW);
            analogWrite(PINMOTOR2PWM, LOW);
            digitalWrite(PINMOTOR2DIRECTION, LOW);
        
            blinkTimer.pause();                       // stop Timer 
            digitalWrite(LED, LOW);                   // LED LOW
            
            I2C_LCD("stop");                          // print LCD
        }
          
        if (message == "left\n"){                     // if message is "left"
            lcd.clear();
            analogWrite(PINMOTOR1PWM, LOW);
            digitalWrite(PINMOTOR1DIRECTION, HIGH);
            analogWrite(PINMOTOR2PWM, M2dutyCycle);
            digitalWrite(PINMOTOR2DIRECTION, LOW);
            
            I2C_LCD("left");                          // print LCD
        }
        
        if (message == "right\n") {                   // if message is "right"
            lcd.clear();
            analogWrite(PINMOTOR1PWM, M1dutyCycle);
            digitalWrite(PINMOTOR1DIRECTION, HIGH);
            analogWrite(PINMOTOR2PWM, LOW);
            digitalWrite(PINMOTOR2DIRECTION, LOW);
        
            I2C_LCD("right");                         // print LCD
        }
    }  
}
