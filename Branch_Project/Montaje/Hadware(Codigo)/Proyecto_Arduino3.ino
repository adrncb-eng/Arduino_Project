#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 6     // Digital pin connected to the DHT sensor 
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN,DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


// int pinTMP = 6;
int ledRojo = 13;
int ledVerde = 8;
int ledAzul = 7;


int lectura;
float voltaje;
float temperatura;
float humedad;        
String sensorTipo;    

void setup() {


  Serial.begin(9600);
  dht.begin();
#if DHTTYPE == DHT11
  sensorTipo = "DHT11";
#elif DHTTYPE == DHT22
  sensorTipo = "DHT22";
#elif DHTTYPE == DHT21
  sensorTipo = "DHT21";
#else
  sensorTipo = "Desconocido";
#endif

  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);


  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("   Sistema OK");
  delay(1000);
  lcd.clear();
}

void loop() {

  temperatura = dht.readTemperature();
  lectura = analogRead(2);
  voltaje = (lectura * 5.0) / 1023.0;
  // temperatura = (voltaje - 0.5) * 100.0;
  humedad = dht.readHumidity();


  Serial.print("Lectura: ");
  Serial.print(lectura);
  Serial.print("  Voltaje: ");
  Serial.print(voltaje);
  Serial.print(" V");
  Serial.print("  Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  lcd.clear();
  
  lcd.setCursor(0, 0);
lcd.print(sensorTipo);
lcd.print(" H:");
lcd.print(humedad, 0);
lcd.print("%");


  lcd.setCursor(0, 1);
lcd.print("Temp: ");
lcd.print(temperatura);
lcd.print(" C");


  if (temperatura < 20) {
    encenderAzul();
  }
  else if (temperatura >= 20 && temperatura <= 28) {
    encenderVerde();
  }
  else {
    encenderRojo();
  }

  int i = 0;
  while (i < 5) {
    delay(200);
    i++;
  }
}


void apagarLED() {
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, LOW);
}

void encenderRojo() {
  apagarLED();
  digitalWrite(ledRojo, HIGH);
}

void encenderVerde() {
  apagarLED();
  digitalWrite(ledVerde, HIGH);
}

void encenderAzul() {
  apagarLED();
  digitalWrite(ledAzul, HIGH);
}
