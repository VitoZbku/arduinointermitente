#include <Arduino.h>

const int botonActivadorPin = 2; // El pin digital al que está conectado el botón
const int indicadorPin = 3;      // El pin digital al que está conectado el indicador LED

volatile boolean accagain = false;
volatile int activado = 0;
unsigned long previousTime = 0;
unsigned long interval = 1000; // Intervalo de parpadeo de 1 segundo

void setup() {
  pinMode(botonActivadorPin, INPUT);
  pinMode(indicadorPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(botonActivadorPin), activarIntermitente, RISING);

  Serial.begin(9600);
}

void loop() {
  // Verificar si ha pasado suficiente tiempo para cambiar el estado del indicador LED
  unsigned long currentTime = millis();
  if (currentTime - previousTime >=  1000) {
    digitalWrite(indicadorPin,LOW); // Cambiar el estado del LED
  }
}

void activarIntermitente() {
  if (activado >= 1) {
    accagain = true;
  }
  digitalWrite(indicadorPin, HIGH);
  activado += 1;
  previousTime = millis(); // Inicializar previousTime al activar el LED
}
