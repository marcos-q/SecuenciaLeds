# SecuenciaLeds
Programación de secuencias de leds

El código que comparto facilita la programación de las secuencias y, además, evita superar la corriente máxima al activar muchos puertos de salida a la vez. El código conmuta los leds de uno en uno para producir el efecto de encendido “simultáneo” de todos ellos.

/*  MplexLeds  v1.0  -  01-12-2018
 *  Marcos Quílez Figuerola
 *  
 *  Programa fácilmente secuencias de leds.
 *  Multiplexa la iluminación de hasta 8 leds. Así, se produce la impresión de iluminar "simultáneamente" varios leds, 
 *  aunque en realidad sólo se activa uno en cada instante. 
 *  
 *  Para encender 8 leds "simultáneamente", por ejemplo, ilumina el primero durante 2 ms. 
 *  Lo apaga y enciende el siguiente led durante otros 2s. Lo apaga y continua con el siguiente hasta el octavo.
 *  Así una y otra vez. Al repetirse el proceso a alta frecuencia, nuestro ojo percibe los leds
 *  iluminados permanente y simultáneamente.
 *  
 *  De esta forma conseguimos activar tantas salidas como necesitemos sin superar la corriente máxima 
 *  de salida y sobrecargar nuestro arduino.
 *  
 *  No os resultará difícil adaptar el código a vuestra aplicación
 *  
 *  El array leds[][] contiene la programación de la secuencia de leds. Las filas representan cada paso de la secuencia.
 *  1:led encendido, 0:led apagado.
 *  
 *  El array tiempo[] indica el tiempo que está encendido cada paso de la secuencia definida en el array leds[][]
 * 
 */
