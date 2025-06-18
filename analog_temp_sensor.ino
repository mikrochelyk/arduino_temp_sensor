const int sensorPin = A0;
const float baselineTemp = 20.0;

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

float voltage = (sensorVal/1024.0) * 5.0;

Serial.print(", Volts: ");
Serial.print(voltage); 
}
