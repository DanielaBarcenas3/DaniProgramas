const int sensorPin = 2;  // Pin del sensor de inclinación
const int buzzerPin = 8;  // Pin del buzzer

void setup() {
  pinMode(sensorPin, INPUT);   // Configurar sensor como entrada
  pinMode(buzzerPin, OUTPUT);  // Configurar buzzer como salida
  Serial.begin(9600);
}

void loop() {
  int estadoSensor = digitalRead(sensorPin);  // Leer estado del sensor

  if (estadoSensor == LOW) {  // Sensor inclinado (contacto cerrado)
    digitalWrite(buzzerPin, HIGH);  // Activar buzzer
    Serial.println("Sensor inclinado");
  } else {  // Sensor en posición vertical (contacto abierto)
    digitalWrite(buzzerPin, LOW);  // Apagar buzzer
    Serial.println("Sensor estable");
  }

  delay(1000);  // Pequeño retraso para estabilidad
}