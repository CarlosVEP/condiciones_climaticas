# Condiciones climáticas

Para este proyecto se usó un ESP32 con un sensor LDR para detectar la luminosidad y un sensor DHT22 para monitorear la temperatura y humedad. Cuando la luminosidad baja, se activa un LED rojo y cuando la temperatura está a menos de 28 °C, se activa un LED verde, cuando está entre 28 °C y 34 °C, se activa el LED amarillo y cuando pasa los 34 °C, se activará el LED rojo.

## Descripción del proyecto

El sistema realiza lo siguiente:

- Lee datos de cantidad lumínica en el ambiente desde un sensor LDR.
- Lee datos de temperatura y humedad desde un sensor DHT22.
- Activa un LED rojo si detecta baja luminosidad o si la temperatura pasa los 34 °C.
- Activa un LED amarillo si la temperatura está entre 28 °C y 34 °C.
- Activa un LED verde si la temperatura está a menos de 28 °C.

## Hardware utilizado

- ESP32 Devkit C V4
- Sensor LDR
- Sensor DHT32
- Breadboard half
- LEDs rojo, amarillo y verde
- 3 resistencias de 220 Ω

## Conexiones

- DHT22: pin 15 del ESP32
- LDR: pin 34 del ESP32
- LED rojo: pin 27 del ESP32
- LED amarillo: pin 14 del ESP32
- LED verde: pin 12 del ESP32
- GND y 3.3V según la conexión del circuito

## Requisitos

- PlataformIO
- Visual Studio Code
- Biblioteca DHT para ESP32 leído desde repositorio Adafruit

## Estructura del proyecto

- src/main.cpp: lógica principal del programa
- platformio.ini: configuración del entorno PlatformIO
- diagram.json: diagrama de simulación para Wokwi

## Cómo ejecutar

1. Abre el proyecto en PlatformIO.
2. Compila y sube el firmware al ESP32.
3. Abre el monitor serial para ver los datos.
4. Si usas Wokwi, puedes ejecutar la simulación desde el archivo diagram.json.
