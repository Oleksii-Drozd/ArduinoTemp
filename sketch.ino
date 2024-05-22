#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define term_power 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void) 
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(term_power, OUTPUT);
}

float temperature()
{
  digitalWrite(term_power, HIGH);
  delay(100);
  sensors.requestTemperatures();
  delay(500);
  sensors.requestTemperatures();
  float t = float(sensors.getTempCByIndex(0));
  digitalWrite(term_power, LOW);
  delay(400);
  return (t);
}


void loop(void) 
{
  Serial.println(temperature(), 1);  
}
