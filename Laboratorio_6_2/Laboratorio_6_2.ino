#include <Arduino.h>

const int ENA = 11; // Pin de habilitación para el puente H
const int motorPin1 = 10; // Pin de control 1 del puente H
const int motorPin2 = 9; // Pin de control 2 del puente H

int velocidadActual = 200; // Variable de velocidad actual
int direccion = 1; // Bandera de dirección (1: adelante, -1: atrás)

void setup() {
pinMode(ENA, OUTPUT); // Configurar el pin ENA como salida para el control
del puente H
pinMode(motorPin1, OUTPUT); // Configurar el pin de control 1 del motor
como salida
pinMode(motorPin2, OUTPUT); // Configurar el pin de control 2 del motor
como salida
}

void loop() {
// Repetir los cambios de velocidad y dirección tres veces
for (int i = 0; i < 3; i++) {
// Establecer la dirección del motor según la bandera de 'dirección'
if (direccion == 1) {
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
} else {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
}

// Establecer la velocidad del motor utilizando la velocidad actual
analogWrite(ENA, velocidadActual);

// Retardo en dirección de avance
int tiempoRetardo = 3000; // tiempo de 3 seg.
delay(tiempoRetardo/2);

// Cambiar de dirección después de un ciclo
direccion *= -1;

// Establecer la velocidad del motor utilizando la velocidad actual
analogWrite(ENA, velocidadActual);

// Retardo en dirección de avance
delay(tiempoRetardo/2);
// agregar aquí las líneas de código indicadas abajo.
}
}

//Código para agregar en la línea indicada
// Establecer la velocidad del motor en cero
//analogWrite(ENA,0);

// Retardo en dirección de avance
//delay(tiempoRetardo);
