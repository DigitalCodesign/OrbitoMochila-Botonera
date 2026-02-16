# OrbitoBotonera
## Descripción
Esta libreria esta pensada para ser usadada junto con el modulo mochila botonera y el robot Orbito. Con esta se pueden controlar y obtener el estado de los pulsadores de la mochila
## Caracteristicas
Esta libreria permite obtener el estado de los pulsadores de la botonera. Debido a la cantidad de botones, se han separado estos en dos zonas bien diferenciadas, una cruceta, con 5 pulsadores y un panel, con 7 pulsadores. Para leer el estado de un pulsador se debe utilizar el método `leerPulsador(...)`
## Modo de empleo
1. **Instalación**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "OrbitoBotonera" e instálala.
    * Asegurate de tener todas las dependencias:
      * `OrbitoBotonera`en la versión **1.0.0** o superior
      * `Orbito` en la versión **1.0.0** o superior
      * `Adafruit GFX Library` en la versión **1.12.4** o superior
      * `Adafruit BusIO` en la versión **1.17.4** o superior
      * `Adafruit ST7735 and ST7789 Library` en la versión **1.10.3** o superior
2. **Ejemplo Básico**
```c++
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
}

```
## Constructor y métodos básicos
### Constructor
* `OrbitoBotonera` crea un objeto de esta clase con el nombre indicado
### SubClases
* `Cruceta` Clase que agrupa todos los atributos referentes a los pulsadores de la cruceta
* `Panel` Clase que agrupa todos los atributos referentes a los pulsadores del panel
### Métodos
* `leerPulsador()` devuelve el valor de temperatura en grados centígrados (ºC)
### Atributos
* `arriba` Selecciona el pulsador superior de la cruceta
* `abajo` Selecciona el pulsador inferior de la cruceta
* `izquierda` Selecciona el pulsador izquierdo de la cruceta
* `derecha` Selecciona el pulsador derecho de la cruceta
* `centro` Selecciona el pulsador central de la cruceta
* `Pulsador1` Selecciona el pulsador 1 del panel
* `Pulsador2` Selecciona el pulsador 2 del panel
* `Pulsador3` Selecciona el pulsador 3 del panel
* `Pulsador4` Selecciona el pulsador 4 del panel
* `Pulsador5` Selecciona el pulsador 5 del panel
* `Pulsador6` Selecciona el pulsador 6 del panel
* `Pulsador7` Selecciona el pulsador 7 del panel