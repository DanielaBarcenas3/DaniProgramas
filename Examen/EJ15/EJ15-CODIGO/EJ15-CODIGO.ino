// Definición de pines
const int trigPin = 9;   // Pin para enviar el pulso ultrasónico
const int echoPin = 10;  // Pin para recibir el eco
const int ledPin = 7;    // Pin donde está conectado el LED

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Inicializar la comunicación serial
}

void loop() {
  long duration;
  float distance;

  // Enviar un pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir el tiempo del eco
  duration = pulseIn(echoPin, HIGH);

  // Convertir tiempo a distancia en cm (velocidad del sonido = 343 m/s)
  distance = (duration * 0.0343) / 2;

  // Mostrar la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Si la distancia es menor a 10 cm, encender el LED
  if (distance < 10.0 && distance > 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500); // Pequeña pausa para estabilidad
}