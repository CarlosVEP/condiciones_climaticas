#include <Arduino.h>
#include <DHT.h>

//no recomendable usar define ya que lo que hace es reemplazar el texto en el preprocesador, es mejor usar const
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);

const int pinLDR = 34;
const int ledRojo = 27;
const int ledAmarillo = 14;
const int ledVerde = 12;

void setup()
{
  Serial.begin(115200);
  dht.begin();
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop()
{
  int valorLDR = analogRead(pinLDR);
  Serial.print("Valor LDR: ");
  Serial.println(valorLDR);
  if(valorLDR > 2500){
    digitalWrite(ledRojo, HIGH);
    Serial.println("Estado: Oscuridad detectada. LED ENCENDIDO");
  }else{
    digitalWrite(ledRojo, LOW);
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
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarillo, LOW);
    if(valorLDR < 2500){
      digitalWrite(ledRojo, LOW);
    }
    Serial.println("Estado: clima agradable");
  }else if(temperatura >= 28.0 && temperatura <= 34.0){
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    if(valorLDR < 2500){
      digitalWrite(ledRojo, LOW);
    }
    Serial.println("Estado: clima moderado");
  }else{
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, HIGH);
    Serial.println("Estado: clima caluroso");
  }
  delay(2000);
}