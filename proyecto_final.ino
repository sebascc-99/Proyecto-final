#include <iostream>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include "heltec.h"
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#define DHTPIN 13
#define DHTTYPE DHT11
#define countof(a) (sizeof(a) / sizeof(a[0]))


using namespace std;

#define INLINE inline __attribute__((always_inline))

using SenseType = float;   // user-defined types = ADT = abstract data type
using PortType  = uint8_t; // unsigned int 8-bits = fixed size int


class SensorTemp { // Class = user defined type definition (define-and-use)
private: // default private visibility
    SenseType t,h;
    SenseType moist;
    PortType  port=12;
    DHT *dht ;
public:
    void inicio() { 
       dht = new DHT(DHTPIN, DHTTYPE);
       dht->begin();
    }
    String leer() {
        // DHT11 read ports
        t=dht->readTemperature();
        h=dht->readHumidity(); 
        String hum;
        if (isnan(h) || isnan(t)) {
          Serial.println("Falla al leer el sensor DHT11!");
          hum="Falla al leer el sensor DHT11!";
          return hum;
          } 
        hum=String(h);
        return hum;
    }
    friend ostream& operator << (ostream &os,  SensorTemp &s) {
        os << "Temperatura =  " << s.t << "ºC" << "Humedad =  " << s.h << "%" << endl; // Add humidity value
        return os;
    }
};
class reloj{
private: // default private visibility
    ThreeWire *myWire;
    
    
    
public:
    void inicio() { 
       myWire=new ThreeWire(12,14,27);
       RtcDS1302<ThreeWire> Rtc(*myWire);
       Rtc.Begin();
       RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
       hora(compiled);
       Serial.println();

       if (!Rtc.IsDateTimeValid()) 
       {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing

           Serial.println("RTC lost confidence in the DateTime!");
           Rtc.SetDateTime(compiled);
       }

       if (Rtc.GetIsWriteProtected())
       {
          Serial.println("RTC was write protected, enabling writing now");
          Rtc.SetIsWriteProtected(false);
       }

       if (!Rtc.GetIsRunning())
       {
          Serial.println("RTC was not actively running, starting now");
          Rtc.SetIsRunning(true);
       }

       RtcDateTime now = Rtc.GetDateTime();
       if (now < compiled) 
       {
          Serial.println("RTC is older than compile time!  (Updating DateTime)");
          Rtc.SetDateTime(compiled);
       }
       else if (now > compiled) 
       {
           Serial.println("RTC is newer than compile time. (this is expected)");
       }
       else if (now == compiled) 
       {
           Serial.println("RTC is the same as compile time! (not expected but all is fine)");
       }
       }
    String Hora(){
      String hum;
      myWire=new ThreeWire(12,14,27);
       RtcDS1302<ThreeWire> Rtc(*myWire);
      RtcDateTime now = Rtc.GetDateTime();
      hum=hora(now);
      return hum;
      
    }
    String hora(const RtcDateTime& dt)
    {
      char datestring[20];
      String fe;
      snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
      Serial.print(datestring);
      fe=String(datestring);
     return fe;
    
    }
    };


SensorTemp th; // use = instance = objeto
reloj rj;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Enable*/, true /*Serial Enable*/);
  th.inicio();
  rj.inicio();
}

void loop() {
    String hum=th.leer();
    String fec=rj.Hora();
    imprimir(hum,fec);
    cout << th; // attribute (dot-operator)
    delay(1000);

}
void imprimir(String hum,String fec){
   Heltec.display -> clear();
   Heltec.display -> drawString(2, 0, String(fec));
   Heltec.display -> drawString(0, 30, "Humedad");
   Heltec.display -> drawString(3, 45, String(hum));
   Heltec.display -> drawString(2, 45, "          %");
   Heltec.display -> display();
}
