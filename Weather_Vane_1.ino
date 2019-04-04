/*  Weather Vane 1
 *  Weather Station Project
 *  by: Doug VanderClute 3/24/19
 *  grampytech@gmail.com
 *  Weather vane will have one or two sensors active. 
 *  Each pin will have a binary weight which is totaled
 *  and tested to give the direction of the wind.
 *  Print direction to serial monitor.
 *    
*/
//********* Global Declarations***********

// Outputs


// Inputs
int pin2 = 2;   //Hall Effect Sensor 1
int pin3 = 3;   //Hall Effect Sensor 2
int pin4 = 4;   //Hall Effect Sensor 3
int pin5 = 5;   //Hall Effect Sensor 4
int pin6 = 6;   //Hall Effect Sensor 5
int pin7 = 7;   //Hall Effect Sensor 6
int pin8 = 8;   //Hall Effect Sensor 7
int pin9 = 9;   //Hall Effect Sensor 8

// Variables

int pinVal2;    //read pin and assign high or low
int pinVal3;    //read pin and assign high or low
int pinVal4;    //read pin and assign high or low
int pinVal5;    //read pin and assign high or low
int pinVal6;    //read pin and assign high or low
int pinVal7;    //read pin and assign high or low
int pinVal8;    //read pin and assign high or low
int pinVal9;    //read pin and assign high or low
int reading;    //total weight less active sensors


//*********** Setup ****************

void setup() {
 // Serial Port 
  Serial.begin(115200);       //turn serial port on
  pinMode(pin2,INPUT_PULLUP); //pin will be high if sensor is not active 
  pinMode(pin3,INPUT_PULLUP); //pin will be high if sensor is not active 
  pinMode(pin4,INPUT_PULLUP); //pin will be high if sensor is not active 
  pinMode(pin5,INPUT_PULLUP); //pin will be high if sensor is not active 
  pinMode(pin6,INPUT_PULLUP); //pin will be high if sensor is not active 
  pinMode(pin7,INPUT_PULLUP); //pin will be high if sensor is not active 
  pinMode(pin8,INPUT_PULLUP); //pin will be high if sensor is not active 
  pinMode(pin9,INPUT_PULLUP); //pin will be high if sensor is not active 
  

}
//************ Main Loop ************

void loop() {
  int pinWt2=1;   //assign binary pin weight 
  int pinWt3=2;   //assign binary pin weight
  int pinWt4=4;   //assign binary pin weight
  int pinWt5=8;   //assign binary pin weight
  int pinWt6=16;  //assign binary pin weight
  int pinWt7=32;  //assign binary pin weight
  int pinWt8=64;  //assign binary pin weight
  int pinWt9=128; //assign binary pin weight
  
  pinVal2 = digitalRead(pin2);    //read pin
    if(pinVal2 == LOW){pinWt2=0;} //test if sensor is active low
  pinVal3 = digitalRead(pin3);    //read pin
    if(pinVal3 == LOW){pinWt3=0;} //test if sensor is active low
  pinVal4 = digitalRead(pin4);    //read pin
    if(pinVal4 == LOW){pinWt4=0;} //test if sensor is active low
  pinVal5 = digitalRead(pin5);    //read pin
    if(pinVal5 == LOW){pinWt5=0;} //test if sensor is active low
  pinVal6 = digitalRead(pin6);    //read pin
    if(pinVal6 == LOW){pinWt6=0;} //test if sensor is active low
  pinVal7 = digitalRead(pin7);    //read pin
    if(pinVal7 == LOW){pinWt7=0;} //test if sensor is active low
  pinVal8 = digitalRead(pin8);    //read pin
    if(pinVal8 == LOW){pinWt8=0;} //test if sensor is active low
  pinVal9 = digitalRead(pin9);    //read pin
    if(pinVal9 == LOW){pinWt9=0;} //test if sensor is active low
    
  reading = (pinWt2+pinWt3+pinWt4+pinWt5+pinWt6+pinWt7+pinWt8+pinWt9);  //add
    //pin weights with active pins equal to 0 
    if(reading==254){Serial.println("N");}  //if weight matches, print direction
     if(reading==252){Serial.println("NNW");}   //if weight matches, print direction
      if(reading==253){Serial.println("NW");}   //if weight matches, print direction
       if(reading==249){Serial.println("WNW");}   //if weight matches, print direction
        if(reading==251){Serial.println("W");}    //if weight matches, print direction
         if(reading==243){Serial.println("WSW");}   //if weight matches, print direction
          if(reading==247){Serial.println("SW");}   //if weight matches, print direction
           if(reading==231){Serial.println("SSW");}   //if weight matches, print direction
            if(reading==239){Serial.println("S");}    //if weight matches, print direction
             if(reading==207){Serial.println("SSE");}   //if weight matches, print direction
              if(reading==223){Serial.println("SE");}   //if weight matches, print direction
               if(reading==159){Serial.println("ESE");}   //if weight matches, print direction
                if(reading==191){Serial.println("E");}    //if weight matches, print direction
                 if(reading==63){Serial.println("ENE");}    //if weight matches, print direction
                  if(reading==127){Serial.println("NE");}   //if weight matches, print direction
                   if(reading==126){Serial.println("NNE");}   //if weight matches, print direction
  
  delay(1000);

}
