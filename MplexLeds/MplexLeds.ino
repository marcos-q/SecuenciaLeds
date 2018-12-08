/*  MplexLeds  v1.0  -  01-12-2018
 *  Marcos Quílez Figuerola
 *  
 *  Programa fácilmente secuencias de leds.
 *  Multiplexa la iluminación de hasta 8 leds. Así, se produce la impresión de iluminar "simultáneamente" varios leds, 
 *  aunque en realidad sólo se activa uno en cada instante. 
 *  
 *  Para encender 8 leds "simultáneamente", por ejemplo, ilumina el primero durante 2 ms. 
 *  Lo apaga y enciende el siguiente led durante otros 2s. Lo apaga y continua con el siguiente hasta el octavo.
 *  Así una y otra vez. Al repetirse el proceso a alta frecuencia, nuestro ojo percibe los lec iluminados permanente y simultáneamente.
 *  
 *  De esta forma conseguimos activar tantas salidas como necesitemos sin superar la corriente máxima de salida y sobrecargar nuestro arduino.
 *  
 *  No os resultará difícil adaptar el código a vuestra aplicación
 *  
 *  El array leds[][] contiene la programación de la secuencia de leds. Las filas representan cada paso de la secuencia.
 *  1:led encendido, 0:led apagado.
 *  
 *  El array tiempo[] indica el tiempo que está encendido cada paso de la secuencia definida en el array leds[][]
 * 
 */

byte pin[8]={2,3,4,5,6,7,8,9}; //Estos son los pines donde conectamos nuestros leds. Si necesitas más leds puedes añadirlos. Tendrás que añadir una columna por cada les en el array leds[][]

const int numLineas=31;        //Esta variable indica el número de filas del array leds[] y del array tiempo[]. Es decir, el número de pasos de la secuencia de luces que programamos.

// Modifica este array para definer tu secuencia de luces. La primera columna corresponde al pin[0] (pin 2 en este caso) y la última corresponde a pin[7] (pin 9 en este caso)
bool leds[numLineas][8]={{1,1,1,1,1,1,1,1},
                         {0,0,0,0,0,0,0,0},
                         {1,1,1,1,1,1,1,1},
                         {0,0,0,0,0,0,0,0},                         
                         {1,1,1,1,1,1,1,1},
                         {0,0,0,0,0,0,0,0},                                                  
                         {1,1,1,0,0,0,0,0},
                         {0,0,0,1,1,1,0,0},
                         {0,0,0,0,0,0,1,1},
                         {0,0,0,0,0,0,0,0},
                         {1,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0},
                         {1,1,1,0,0,0,0,0},
                         {0,1,1,1,0,0,0,0},
                         {0,0,1,1,1,0,0,0},
                         {0,0,0,1,1,1,0,0},
                         {0,0,0,0,1,1,1,0},
                         {0,0,0,0,0,1,1,1},
                         {0,0,0,0,0,0,1,1},
                         {0,0,0,0,0,0,0,1},
                         {0,0,0,0,0,0,0,0},

                         {0,1,0,0,0,0,0,0},
                         {0,1,1,0,0,0,0,0},
                         {0,1,1,1,0,0,0,0},
                         {0,0,1,1,0,0,0,0},
                         {0,0,0,1,0,0,0,0},
                         {0,0,0,1,0,1,0,0},
                         {0,0,0,1,0,1,0,1},
                         {0,0,0,0,0,1,0,1},
                         {0,0,0,0,0,0,0,1},
                         {0,0,0,0,0,0,0,0},
                         };

// Pon es este array la duración de cada fila de las que has definido anteriormente
int tiempo[numLineas]={500,
                       100,
                       500,
                       100,
                       500,
                       500,
                       600,
                       600,
                       600,
                       600,
                       100,
                       100,
                       100,
                       100,
                       100,
                       100,
                       100,
                       100,
                       100,
                       100,
                       500,
                       
                       100,
                       100,
                       100,
                       100,
                       100,
                       100,
                       100,
                       100,
                       100,
                       500                       
                       };

void setup() {
  //definimos los pines como salidas
  for (int i=0; i<8;i++){
    pinMode(pin[i],OUTPUT);
  }

}

void loop() {
  for (int i=0;i<numLineas;i++){    //recorremos cada fila de la secuencia de luces
    ilumina(leds[i],tiempo[i]);     //llamamos a la función de encendido multiplexado de leds
  }

}

/////////////////////////////////////////////////////

// Esta función multiplexa el encendido de los leds
void ilumina(bool grupoLeds[],int duracion){
  int retardo=2;
  long int ultimoCrono=millis();

  while (millis()<ultimoCrono+duracion){
    for (int i=0;i<8;i++){
      digitalWrite(pin[i],grupoLeds[i]);
      delay(retardo);
      digitalWrite(pin[i],0);  
    }  
  }


}

