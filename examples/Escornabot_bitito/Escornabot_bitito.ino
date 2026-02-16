// Declaración de las librerias necesarias
#include <Orbito.h>
#include <Motores.h>
#include <OrbitoBotonera.h>

// Parametros modificables del código 
#define SECUENCIA_DISTANCIA_CM 1000
#define MAX_MOVIMIENTOS 20
#define TONO_IZQUIERDA 1000
#define TONO_AVANZAR 1300
#define TONO_DERECHA 1600
#define TONO_ATRAS 1900
#define TONO_CONFIRMAR 2800
#define TONO_DURACION 100

// Parametros del codigo
#define GIR_IZQ 1
#define AVANZAR 2
#define GIR_DER 3
#define RETROCEDER 4

// Se crean los objetos Botonera y Motores
OrbitoBotonera Botonera;
Motores Motores; 

// Se definen las variables necesarias para el codigo
uint8_t position = 0;
uint8_t movements[MAX_MOVIMIENTOS];

// Esta funcion detecta la pulsación de los 4 pulsadores de la cruceta
// y guarda la pulsacion en el array de movimientos del robot
void detect_button(){
  if(Botonera.leerPulsador(Botonera.cruceta.izquierda)){
    Serial.println("Pulsador Izquierdo Presionado");
    movements[position] = GIR_IZQ;
    Orbito.System.tone(TONO_IZQUIERDA, TONO_DURACION);
    // Esperar hasta que se deje de presionar el pulsador para no hacer multiples medidas
    while(Botonera.leerPulsador(Botonera.cruceta.izquierda)){
      delay(10); // Retardo para no saturar las comunicaciones
    }
    position++;
  }
  else if(Botonera.leerPulsador(Botonera.cruceta.arriba)){
    Serial.println("Pulsador Superior Presionado");
    movements[position] = AVANZAR;
    Orbito.System.tone(TONO_AVANZAR, TONO_DURACION);
    // Esperar hasta que se deje de presionar el pulsador para no hacer multiples medidas
    while(Botonera.leerPulsador(Botonera.cruceta.arriba)){
      delay(10); // Retardo para no saturar las comunicaciones
    }
    position++;
  }
  else if(Botonera.leerPulsador(Botonera.cruceta.derecha)){
    Serial.println("Pulsador Derecho Presionado");
    movements[position] = GIR_DER;
    Orbito.System.tone(TONO_DERECHA, TONO_DURACION);
    // Esperar hasta que se deje de presionar el pulsador para no hacer multiples medidas
    while(Botonera.leerPulsador(Botonera.cruceta.derecha)){
      delay(10); // Retardo para no saturar las comunicaciones
    }
    position++;
  }
  else if(Botonera.leerPulsador(Botonera.cruceta.abajo)){
    Serial.println("Pulsador Inferior Presionado");
    movements[position] = RETROCEDER;
    Orbito.System.tone(TONO_ATRAS, TONO_DURACION);
    // Esperar hasta que se deje de presionar el pulsador para no hacer multiples medidas
    while(Botonera.leerPulsador(Botonera.cruceta.abajo)){
      delay(10); // Retardo para no saturar las comunicaciones
    }
    position++;
  }

}

// Esta funcion recorre el array de movimientos y llama a una funcion que ejecute 
// los movimientos almacenad0os en cada posicion
void executeSecuency(){
  Serial.println("Ejecutando secuencia");
  for(int i = 0; i < position; i++){
    executeMove(movements[i]);
  }

}

// Esta funcion ejecuta un movimiento en funcion del parametro recibido
void executeMove(uint8_t move_id){
  switch(move_id){
    case GIR_IZQ:
      Orbito.System.tone(TONO_IZQUIERDA, TONO_DURACION);
      Motores.rotarRobot(Motores.izquierda, SECUENCIA_DISTANCIA_CM);
      delay(10);
      Serial.println("Girando a la izquierda");
      // Esperar a que el robot deje de moverse
      while(Motores.robotDetenido()){
        delay(10); // Retardo para no saturar las comunicaciones
      }
      break;
    case AVANZAR:
      Orbito.System.tone(TONO_AVANZAR, TONO_DURACION);
      Motores.moverRobot(Motores.adelante, SECUENCIA_DISTANCIA_CM);
      delay(10);
      Serial.println("Moviendose hacia adelante");
      // Esperar a que el robot deje de moverse
      while(Motores.robotDetenido()){
        delay(10); // Retardo para no saturar las comunicaciones
      }
      break;
    case GIR_DER:
      Orbito.System.tone(TONO_DERECHA, TONO_DURACION);
      Motores.rotarRobot(Motores.derecha, SECUENCIA_DISTANCIA_CM);
      delay(10);
      Serial.println("Girando a la derecha");
      // Esperar a que el robot deje de moverse
      while(Motores.robotDetenido()){
        delay(10); // Retardo para no saturar las comunicaciones
      }
      break;
    case RETROCEDER:
      Orbito.System.tone(TONO_ATRAS, TONO_DURACION);
      Motores.moverRobot(Motores.atras, SECUENCIA_DISTANCIA_CM);
      delay(10);
      Serial.println("Moviendose hacia atras");
      // Esperar a que el robot deje de moverse
      while(Motores.robotDetenido()){
        delay(10); // Retardo para no saturar las comunicaciones
      }
      break;
  }
}



void setup() {
  // Inicializar el robot 
  Orbito.begin();
  Orbito.System.tone(1000, 100);
  // Se inicializa el monitor serial
  Serial.begin(9600);
  Serial.println("Iniciando modo Escornabot");
}

void loop() {
  detect_button();
  // Ejecutar la secuencia si se presiona el pulsador central de la cruceta
  if(Botonera.leerPulsador(Botonera.cruceta.centro)){
    // Esperar a que se deje de presionar el pulsador
    while(Botonera.leerPulsador(Botonera.cruceta.centro)){
      delay(10); // Retardo para no saturar las comunicaciones
    }
    Orbito.System.tone(TONO_CONFIRMAR, TONO_DURACION);
    executeSecuency();
    position = 0;
  }

}
