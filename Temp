// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

// This #include statement was automatically added by the Particle IDE.
#include <ThingSpeak.h>

/*
	Send temperature and Humidity information to the Thingspeak Server 
	by interfacing DHT11 Sensor with Particle Photon.
	http://www.electronicwings.com
*/

TCPClient client;

unsigned long myChannelNumber = 2090985;		/*Thingspeak channel id*/
const char * myWriteAPIKey = "0H8QFZA0LWNGHPBW";/*Channel's write API key*/

DHT dht(D2, DHT11);

void setup() {
    ThingSpeak.begin(client);
    dht.begin();
}

void loop() {
    
    delay(500);
    
    /*Read humidity*/
    float humidity = dht.getHumidity();
    /* Read temperature as Celsius */
    float temperature = dht.getTempCelcius();

    /* Check if any reads failed and exit early (to try again)*/
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
	return;
	}

    /* Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different pieces of information in a channel.  */
    /*Here, we write Humidity to field 1 and temperature to field 2*/
    ThingSpeak.writeField(myChannelNumber, 1, humidity, myWriteAPIKey);
    delay(15000); /* ThingSpeak will only accept updates every 15 seconds*/
  
    ThingSpeak.writeField(myChannelNumber, 2, temperature, myWriteAPIKey);
    delay(15000); /* ThingSpeak will only accept updates every 15 seconds.*/
  
    Serial.print("Humidity= ");
    Serial.println(humidity);
    Serial.print("Temperature= ");
    Serial.println(temperature);
}
