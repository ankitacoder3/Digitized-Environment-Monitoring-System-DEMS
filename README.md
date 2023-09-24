<a name="readme-top"></a>

# Digitized-Environment-Monitoring-System-DEMS

<details>
  <summary color= blue >Table of Contents</summary>
<li>Introduction</li>
<li> Prerequisites and Techstack</li>
<li> Cicuit diagram</li>
<li> Screenshots of the output</li>
</details>
</br>

## Introduction
 
-	Environment monitoring systems are used to garner data and provide weather information of a certain area. It is mainly used to measure and forecast weather conditions.

-	The Arduino based Digitized Environment Monitoring System, can show you ambient temperature, humidity, pressure, dust density, light intensity, altitude and much more data from your surroundings, which can be used to predict weather from home or any other place at your convenience.

-	This project, DEMS, is built around Arduino, which is called the brain of the weather station which collects and processes lots of data from various sensors and uses the WIFI module (ESP8266 NODEMCU) to post it on the ThingSpeak platform for visualization.

-	The best part of this project is that with the help of ThingSpeak platform we can visualize the weather related data in any browser.

-	The circuit consists of ‘Four sensors’:

 1.	Temperature & Humidity sensor (DHT22):
 It is a 4-pin sensor, which senses temperature and humidity from the surroundings and passes it to the Arduino.

 2.	Barometric sensor (BMP180): 
  It measures atmospheric pressure, altitude and temperature (we neglect temperature measurement from this sensor as we have a dedicated sensor for measuring ambient temperature).

 3.	Dust sensor (GP2Y1010AU0F):
 It is an air monitoring module which monitors the air quality and detects fine particles like dust (particle larger than 0.8micrometer).

 4.	Light sensor (LDR): 
 This 3-pin LDR  sensor detects ambient brightness & light intensity .

-	The above mentioned sensors collect relevant data and passes it to the Arduino.

-	The data obtained from the Arduino board is sent to the ESP8266 NODEMCU through serial communication, which is then passed on to ThingSpeak via Wi-Fi. 

-	For Wi-Fi networking we use a Wi-Fi module (ESP8266 NODEMCU) which connects to internet to fetch or upload data. Using this module we transfer the data to ThingSpeak platform for convenient and easier visualization.

  <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>


## Prerequisites and Techstack

- C
- C++
- Prerequisites: Arduino, Temperature & Humidity sensor (DHT22),	Barometric sensor (BMP180), Dust sensor (GP2Y1010AU0F),	Light sensor (LDR).

  <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>




## Circuit Diagram

  <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>

## Screenshots of output


<!-- - Serial Monitor (arduino code):

- Serial Monitor (NODEMCU ESP8266_01):-->

 
- Working- circuit:

 


- Working- circuit and ThingSpeak:

 


- Working-compilation: 

 

- ThingSpeak plots: 

 
    -Temperature (ThinkSpeak Visualization):

 

    -Humidity (ThinkSpeak Visualization):

  
    -Dust Density (ThinkSpeak Visualization):

 

     -Light Intensity (ThinkSpeak Visualization):

 
