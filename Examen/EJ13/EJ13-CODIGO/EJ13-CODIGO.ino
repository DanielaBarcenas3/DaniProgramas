// Declaración de variables globales
float tempC; // Variable para almacenar la temperatura
const int pinLM35 = A0; // Pin de entrada del sensor

void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Leemos el sensor
  tempC = (5.0 * (float)analogRead(pinLM35) * 100.0) / 1024.0;

  // Enviamos el dato al puerto serial
  Serial.println(tempC);
  
  // Esperamos 1 segundo antes de repetir el ciclo
  delay(1000);
}