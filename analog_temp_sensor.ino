const int sensorPin = A0;
const float baselineTemp = 25.0;

bool notified26 = false;
bool notified28 = false;
bool notified30 = false;

void setup(){
  Serial.begin(9600); // opens a serial port with baudrate 9600 (bits per sec)

  for(int pinNumber = 2; pinNumber<5; pinNumber++){ // instead of describing each one of pins, for int goes through all sequentially
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, INPUT);
  }
}


void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  // put your main code here, to run repeatedly:

float voltage = (sensorVal/1024.0) * 5.0; // converting the analog to digital converter (ADC) readings to voltage

Serial.print(", Volts: ");
Serial.print(voltage);

Serial.print(", degrees C: ");
float temperature = (voltage - .5) * 100; // line which converts voltage to temperature in degrees
Serial.println(temperature);

if(temperature < baselineTemp+1){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
//notification fallback if the temperature readings has went lower than first value
  notified26 = false;
  notified28 = false;
  notified30 = false;

}else if(temperature >= baselineTemp+1 && temperature < baselineTemp+4){
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

  if (!notified26){
    Serial.println("Warning: Temperature has reached 26 degrees. First LED is turning ON.");
  }
}else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  if (!notified28){
    Serial.println("Warning: Temperature has reached 28 degrees. Second LED is turning ON.");
  }
}else if(temperature >= baselineTemp+6){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  delay(100);
  if (!notified30){
    Serial.println("Safety alert, temperature is over 30 degrees. Third LED is turning ON");
  }
}
delay(1000);
}
