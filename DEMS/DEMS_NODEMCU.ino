
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//D6 = Rx & D5 = Tx
SoftwareSerial nodemcu(D6, D5);
#include <ESP8266WiFi.h>
 
String apiKey = "xxxx";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "yyyyy";     // Replace with your wifi ssid and wpa2 key
const char *pass =  "*****";     
const char* server = "api.thingspeak.com";



WiFiClient client;

void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  delay(10);
  Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
  nodemcu.begin(9600);
  while (!Serial) continue;
}

void loop() {
  
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(nodemcu);

  if (data == JsonObject::invalid()) {
    //Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
  }

  Serial.println("JSON Object Recieved");
  Serial.print("Recieved Humidity:  ");
  float hum = data["humidity"];
  Serial.println(hum);
  Serial.print("Recieved Temperature:  ");
  float temp = data["temperature"];
  Serial.println(temp);
  Serial.print("Recieved dust density:  ");
  float dustDensity = data["dust"];
  Serial.println(dustDensity);
  Serial.print("Recieved light density:  ");
  float lightDensity = data["light"];
  Serial.println(lightDensity);
  Serial.println("-----------------------------------------");

  if (isnan(hum) || isnan(temp)) 
                 {
                     Serial.println("Failed to read from DHT sensor!");
                      return;
                 }

                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(temp);
                             postStr +="&field2=";
                             postStr += String(hum);
                             postStr +="&field3=";
                             postStr += String(dustDensity);
                             postStr +="&field4=";
                             postStr += String(lightDensity);
                            
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(temp);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(hum);
                             Serial.print(" %, Dust: ");
                             Serial.print(dustDensity);
                             Serial.print(" ug/m^3, Light: ");
                             Serial.print(lightDensity);
                             Serial.println(". Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);
}






















