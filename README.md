<a name="readme-top"></a>

# Digitized-Environment-Monitoring-System-DEMS
```DEMS```, also termed as ```'Digitized-Environment-Monitoring-System'```, is an Arduino-based project.

```DEMS``` aids to monitor the environment, by gathering ```realtime-data``` from the ```Arduino``` and various ```sensors```, like Temperature & Humidity sensor,Barometric sensor, etc.

```DEMS``` also generates ```plots``` based on the various ```Environment conditions``` or parameters, like Temperature, Pressure, etc. These plots can be used for further analysis and predictions.

<br>
<details>
  <summary color= blue >Table of Contents</summary>
<li>Introduction</li>
  <li> Prerequisites and Techstack</li>
<li> DEMS Working Details </li>

<li> Circuit</li>
<li> Screenshots of output</li>
</details>
</br>

  
## Introduction
 
-	Environment monitoring systems are used to garner data and provide weather information of a certain area.	It is mainly used to measure and forecast weather conditions.

-	The Arduino based Digitized Environment Monitoring System, can show you ambient temperature, humidity, pressure, dust density, light intensity, altitude and much more data from your surroundings. These observations can be used to predict weather from home or any other place at your convenience.


- The project DEMS has 2 files:
    1. ```DEMS.ino``` : This is contains the ```Arduino Code```.
    2. ```DEMS_NODEMCU.ino``` : This is contains the code for the ```Wi-fi``` module, ```ESP8266 NODEMCU```.

- Furthermore, the project DEMS, also uses many sensors. The working of these are provided below, under the ```DEMS Working Details``` section.

  <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>


## Prerequisites and Techstack

- Software and Programming languages used:
  - Arduino IDE
  - ThingSpeak platform
  - C
  - C++
    
- Prerequisites or Hardware used:
  - Arduino
  - Temperature & Humidity sensor (DHT22)
  - Barometric sensor (BMP180)
  - Dust sensor (GP2Y1010AU0F)
  - Light sensor (LDR)
  - Wi-Fi module (ESP8266 NODEMCU)

  <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>

  

## Circuit Diagram

- Working-circuit
  ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/0913bfe5-2c7b-473e-a7da-ddb9aa8f0dac)

- Diagram
  ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/f8b9cc13-78a8-42cb-992b-3619c31b0272)


  <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>

## DEMS Working Details

-	DEMS is built around Arduino, which is called the brain of the weather station.
-	It collects and processes huge amount of data from various sensors.
-	Finally, it uses the WIFI module (ESP8266 NODEMCU) to post it on the ThingSpeak platform for visualization.

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

-	For Wi-Fi networking we use a Wi-Fi module (ESP8266 NODEMCU) which connects to internet to fetch or upload data.
-	Using this module we transfer the data to ThingSpeak platform for convenient and easier visualization.

  <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>



## Screenshots of output


- Serial Monitor (Arduino code)
  ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/77b4d5f4-8ba5-4561-9495-8c48ced0ada1)


- Serial Monitor (NODEMCU ESP8266_01)
  ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/ebb8def5-d0a1-42ab-87ef-b3f85aa9f5b8)


   <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>
 
- Working- circuit
  ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/65f08380-b350-4576-bc25-4da1df15f4bb)

 


- Working- circuit and ThingSpeak
  ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/a9d97afe-a74b-4b61-90ca-8299b3f60f6f)

 

   <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>

- Working-compilation
  ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/0c4dc23f-ace5-4f0d-b48b-ef8b9ff494d3)


 

- ThingSpeak plots
  ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/8307e495-2eab-4b7e-9bfc-9297c0373aa3)

 
   <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>
  
    - Temperature (ThinkSpeak Visualization)
      ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/4b76196f-57bf-4f31-b213-b76ce3ccb89e)


 

    - Humidity (ThinkSpeak Visualization)
      ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/ad549bbe-e45a-4bac-8a86-80e77b1bacb3)

  
   <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>
  
    - Dust Density (ThinkSpeak Visualization)
     ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/0a33b803-f536-46b4-aa30-85e8f23382a5)

 

     - Light Intensity (ThinkSpeak Visualization)
       ![image](https://github.com/ankitacoder3/Digitized-Environment-Monitoring-System-DEMS/assets/73939061/9b7fefdc-354e-4ea8-8d0b-ba2d47b0b996)

 
  <p align="right">(<a href="#readme-top">back to top</a>)</p>
  </br>
<p> Thank you for exploring the DEMS project. </p>

###
