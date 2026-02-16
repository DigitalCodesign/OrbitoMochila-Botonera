// Se incluyen las librerias necesarias
#include <OrbitoBotonera.h>

// Se declara el objeto Botonera
OrbitoBotonera Botonera;

void setup() {
  // Se inicializa el robot
  Orbito.begin();
  // Se inicializa el monitor serial
  Serial.begin(9600);
  Serial.println("Iniciando test botonera");
}

void loop() {
  // Mostrar mensaje por el monitor serial si se presiona el boton central de la cruceta
  if(Botonera.leerPulsador(Botonera.cruceta.centro)){
    Serial.println("Se ha presionado el boton central de la cruceta");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton superior de la cruceta
  if(Botonera.leerPulsador(Botonera.cruceta.arriba)){
    Serial.println("Se ha presionado el boton superior de la cruceta");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton inferior de la cruceta
  if(Botonera.leerPulsador(Botonera.cruceta.abajo)){
    Serial.println("Se ha presionado el boton inferior de la cruceta");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton izquierdo de la cruceta
  if(Botonera.leerPulsador(Botonera.cruceta.izquierda)){
    Serial.println("Se ha presionado el boton izquierdo de la cruceta");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton derecho de la cruceta
  if(Botonera.leerPulsador(Botonera.cruceta.derecha)){
    Serial.println("Se ha presionado el boton derecho de la cruceta");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton 1 del panel
  if(Botonera.leerPulsador(Botonera.panel.Pulsador1)){
    Serial.println("Se ha presionado el boton 1 del panel");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton 2 del panel
  if(Botonera.leerPulsador(Botonera.panel.Pulsador2)){
    Serial.println("Se ha presionado el boton 2 del panel");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton 3 del panel
  if(Botonera.leerPulsador(Botonera.panel.Pulsador3)){
    Serial.println("Se ha presionado el boton 3 del panel");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton 4 del panel
  if(Botonera.leerPulsador(Botonera.panel.Pulsador4)){
    Serial.println("Se ha presionado el boton 4 del panel");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton 5 del panel
  if(Botonera.leerPulsador(Botonera.panel.Pulsador5)){
    Serial.println("Se ha presionado el boton 5 del panel");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton 6 del panel
  if(Botonera.leerPulsador(Botonera.panel.Pulsador6)){
    Serial.println("Se ha presionado el boton 6 del panel");
    // Retardo para no saturar el monitor serial
    delay(500);
  }

  // Mostrar mensaje por el monitor serial si se presiona el boton 7 del panel
  if(Botonera.leerPulsador(Botonera.panel.Pulsador7)){
    Serial.println("Se ha presionado el boton 7 del panel");
    // Retardo para no saturar el monitor serial
    delay(500);
  }
}
