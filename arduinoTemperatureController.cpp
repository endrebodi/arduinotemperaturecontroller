// Wiring
// Sensor: D2, 3.3V, GND
// Relay: D8, 5V, GND

#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

int relay=8;
// Set temperature range
int bottomTemp = 58;
int topTemp = 62;

void setup() { 
	Serial.begin(9600); 
	sensors.begin();
    	pinMode(relay, OUTPUT);
} 
void loop() { 
	sensors.requestTemperatures();
	int currentTemp = sensors.getTempCByIndex(0)

	delay(1000); 

	if(currentTemp > bottomTemp && currentTemp < topTemp) {
		digitalWrite(relay, HIGH);
		Serial.println("Relay is on..."); 
	} else {
		digitalWrite(relay, LOW);
		Serial.println("Relay is off..."); 
	}
}
