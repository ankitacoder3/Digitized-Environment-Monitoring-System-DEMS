
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>


//Constants
#define DHTPIN 2   // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define seaLevelPressure_hPa 1013.25
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
Adafruit_BMP085 bmp;

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
 int measurePin = 1; //Connect dust sensor to Arduino A0 pin
int ledPower = 2;   //Connect 3 led driver pins of dust sensor to Arduino D2

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
int sensorValue = 0;

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(ledPower,OUTPUT);
  pinMode(A0, INPUT);  
  pinMode(9, OUTPUT); 
  if (!bmp.begin()) 
  {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
}

void loop()
{
    delay(100);
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    digitalWrite(ledPower,LOW); // power on the LED
    delayMicroseconds(samplingTime);

    voMeasured = analogRead(measurePin); // read the dust value
    
    delayMicroseconds(deltaTime);
    digitalWrite(ledPower,HIGH); // turn the LED off
    delayMicroseconds(sleepTime);
    
    // 0 - 5V mapped to 0 - 1023 integer values
    // recover voltage
    calcVoltage = voMeasured * (5.0 / 1024.0);
    
    // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
    // Chris Nafis (c) 2012
    dustDensity = 170 * calcVoltage - 0.1;
    
    Serial.print("Dust density: ");
    Serial.println(dustDensity); // unit: ug/m3
    sensorValue = analogRead(A0); 
    Serial.print("Light density: ");
    Serial.println(sensorValue); 
    analogWrite(9, map(sensorValue,0,1023,0,255)); 

    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");
   
    Serial.println(); 
    delay(1000); 
}
