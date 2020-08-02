
#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h>     
//  Variables
const int PulseWire = 0;       
const int LED13 = 13;          
int Threshold = 550;   
const int lm35_pin = A1;                                                                 
PulseSensorPlayground pulseSensor;  
void setup() {
    Serial.begin(9600);          
  
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       
  pulseSensor.setThreshold(Threshold); 
  pinMode(10, INPUT); 
  pinMode(11, INPUT); 
 

}

void loop() {
  HR();
  TEMP();
  ECG();
}
void HR() {
   int myBPM = pulseSensor.getBeatsPerMinute();  
 
if (pulseSensor.sawStartOfBeat()) {           
 Serial.print("BPM: ");                        
 Serial.println(myBPM);                        

  delay(20);  
}
}
void TEMP() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);  
  temp_val = (temp_adc_val * 4.88); 
  temp_val = (temp_val/10); 
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
}
void ECG(){
   
if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
Serial.println('!');
}
else{

Serial.println(analogRead(A2));
}

delay(1);
}
