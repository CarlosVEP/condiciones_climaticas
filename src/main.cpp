#include <Arduino.h>
#include <DHT.h>

//no recomendable usar define ya que lo que hace es reemplazar el texto en el preprocesador, es mejor usar const
constexpr int DHTPIN = 15;
constexpr char DHTTYPE = DHT22;
DHT dht(DHTPIN,DHTTYPE);

//Si el valor se conoce en tiempo de compilación, suele preferirse constexpr para declarar constantes, ya que permite al compilador optimizar el código y mejorar la seguridad del tipo de datos.
constexpr int PIN_LDR = 34;
constexpr int LED_ROJO = 27;
constexpr int LED_AMARILLO = 14;
constexpr int LED_VERDE = 12;
bool oscuridadDetectada = false;

void setup()
{
  Serial.begin(115200);
  dht.begin();
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void loop()
{
  int valorLDR = analogRead(PIN_LDR);
  Serial.print("Valor LDR: ");
  Serial.println(valorLDR);
  if(valorLDR > 2500){
    digitalWrite(LED_ROJO, HIGH);
    oscuridadDetectada = true;
    Serial.println("Estado: Oscuridad detectada. LED ENCENDIDO");
  }else{
    digitalWrite(LED_ROJO, LOW);
    oscuridadDetectada = false;
    Serial.println("Estado: Hay luz ambiental. LED APAGADO");
  }

  float temperatura = dht.readTemperature();
  
  if(isnan(temperatura)){
    Serial.println("Error al leer el sensor DHT22");
    return;
  }
  Serial.print("Temperatura actual: ");
  Serial.println(temperatura);
  if(temperatura < 28.0){
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARILLO, LOW);
    if(!oscuridadDetectada){
      digitalWrite(LED_ROJO, LOW);
    }
    Serial.println("Estado: clima agradable");
  }else if(temperatura >= 28.0 && temperatura <= 34.0){
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    if(!oscuridadDetectada){
      digitalWrite(LED_ROJO, LOW);
    }
    Serial.println("Estado: clima moderado");
  }else{
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);
    Serial.println("Estado: clima caluroso");
  }
  delay(2000);
}