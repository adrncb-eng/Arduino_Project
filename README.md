# Arduino_Project
============================================================
PROYECTO ARDUINO – SISTEMA DE MONITORIZACION DE TEMPERATURA Y HUMEDAD
============================================================
DESCRIPCION GENERAL
Este proyecto utiliza un Arduino UNO para medir la temperatura y la humedad mediante un sensor DHT11.
La temperatura se muestra en una pantalla LCD 16x2 y un LED RGB indica visualmente el estado térmico:
•	Azul: temperatura baja
•	Verde: temperatura correcta
•	Rojo: temperatura alta
Un potenciómetro permite ajustar el contraste del LCD.
________________________________________
COMPONENTES UTILIZADOS
•	Arduino UNO
•	Sensor DHT11
•	Pantalla LCD 16x2
•	LED RGB cátodo común
•	Resistencias de 220 ohmios
•	Potenciómetro de 10K ohmios
•	Protoboard y cables
________________________________________
CONEXIONES DEL SISTEMA
1.	CONEXIONES DEL LCD 
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2)
LCD pin -> Arduino pin
RS -> 12
EN -> 11
D4 -> 5
D5 -> 4
D6 -> 3
D7 -> 2
VSS -> GND
VDD -> 5V
V0 -> Pin central del potenciómetro
RW -> GND
A -> 5V
K -> GND
2.	CONEXIONES DEL SENSOR DHT11
DHT conectado en pin 6:
DATA -> Pin 6
VCC -> 5V
GND -> GND
3.	CONEXIONES DEL LED RGB
Rojo -> Pin 13 + resistencia 220 ohm
Verde -> Pin 8 + resistencia 220 ohm
Azul -> Pin 7 + resistencia 220 ohm
Cátodo común -> GND
4.	CONEXIONES DEL POTENCIOMETRO
Pin 1 -> 5V
Pin 2 -> V0 del LCD
Pin 3 -> GND
________________________________________
En Tinkercad no existe el sensor combinado DHT11, por lo que en el montaje digital se ha usado un sensor de temperatura simple como referencia.
En el código actual se muestra la temperatura pero no la humedad por pantalla del LCD, debido a cambios de última hora. La humedad se incorporará posteriormente.
________________________________________
FUNCIONAMIENTO DEL SISTEMA
1.	El sensor DHT11 mide la temperatura.
2.	Arduino muestra la Humedad en el LCD.
3.	El valor de la temperatura se muestra en segunda linea.
4.	El LED RGB indica el estado térmico:
o	Menos de 20 grados: azul
o	Entre 20 y 28 grados: verde
o	Mas de 28 grados: rojo
5.	El contraste del LCD se controla con el potenciómetro.
