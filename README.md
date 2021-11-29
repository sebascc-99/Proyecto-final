# Proyecto-final
#Resumen del proyecto

El proyecto consiste en crear un prototipo que ayude a la sanitización de la silla de dentistas para tener el área de trabajo lo más limpia posible.
La idea es crear un aparato que desinfecte el área designada apoyándose en algunos sensores para lograr el mejor trabajo, usando un sensor de humedad para apoyarme con la cantidad de sanitizante que se esta usando y con eso regular la aplicación del mismo tratando de crear un aparato que sea de lo mas sencillo, para que sea de fácil operación.

#Introducción

#Motivación

Con lo mal que nos está afectando la pandemia la necesidad de aumentar las medidas de higiene son cada vez más alta para evitar su propagación, de aquí surgió mi idea de crear un aparato que ayude y pueda garantizar que el área donde se use este lo más desinfectada posible.

#Objetivo
Crear un aparto que pueda desinfectar un área designada y garantice un cierto nivel de desinfección, manteniendo su funcionamiento lo mas sencillo posible para que su uso sea de lo más sencillo.


#Desarrollo
Diagrama de conexiones el/los circuitos(s).
Estos son los componentes que utilice:
•	Sensor DHT11
•	Bomba de Agua de 6v
•	Fuente de poder de 5v
•	Reloj de tiempo real RTC DS1302
•	PushButton
•	Protoboard
•	ESP32
 
Uso esta fuente para alimentar todo mi circuito usando el puerto de tierra y los voltajes de 3.3v para el sensor DHT11 y el de 5v para el resto del circuito.
Quedando de la siguiente manera:

![image](https://user-images.githubusercontent.com/80295696/143788569-72650ccd-159d-4dce-8daa-6a9bf3ae65cc.png)

 
Después mande los 5v y la tierra a la proto en sus respectivos lugares, 5v a la terminal + y la tierra a la terminal – para alimentar el resto del circuito.

![image](https://user-images.githubusercontent.com/80295696/143788578-18f1c727-73c3-4eeb-bd6e-8aec82caf92b.png)


#La conexión de los componentes es sencilla:
Este es el diagrama de mi terminal ESP32:
![image](https://user-images.githubusercontent.com/80295696/143788594-6476bfdc-cfeb-4f2f-9e26-b651f06079d1.png)

 
#DHT11:

![image](https://user-images.githubusercontent.com/80295696/143788606-a5d13620-012f-4934-acc0-8fc87f158ab6.png)

 
Mande la terminal negativa a tierra y la positiva directamente a la fuente de poder a 3.3v mientras que la salida de datos lo mande al puerto 13 de la ESP32.

Bomba de Agua 6v:

![image](https://user-images.githubusercontent.com/80295696/143788617-16f109e2-459d-48f7-8741-6391bdab9b97.png)

 
Solo cuenta con dos conexiones la negativa la mande a tierra en la protoboard y la parte positiva al puerto 17 en la ESP32.
Reloj de tiempo real RTC DS1302:

![image](https://user-images.githubusercontent.com/80295696/143788627-b398a4a8-0185-4b75-9d66-4cb0a7845d30.png)

 
Este componente es el que más salidas tiene, como es obvio mande la salida de GND y de VCC a la parte negativa y positiva de mi protoboard mientras la salida CLK la mande al puerto 14, la salida DAT al puerto 12 y la salida RST al puerto 27 de la ESP32.



Push Button:

![image](https://user-images.githubusercontent.com/80295696/143788643-84e1dca4-772d-4fa7-a163-2a23de574880.png)

 
Este componente es el más sencillo su conexión es simple una parte se manda a tierra y la otra al puerto 36 en la ESP32.


#Evidencias

![20211128_181652](https://user-images.githubusercontent.com/80295696/143795130-a82bba65-b4c5-43fd-85fb-f5cca1d23932.jpg)


![20211128_172500](https://user-images.githubusercontent.com/80295696/143795183-c7898085-b2df-431b-ba3e-97aa188f5c11.jpg)


![20211128_160249](https://user-images.githubusercontent.com/80295696/143795198-3c067964-3734-423f-a063-7e446b9327bb.jpg)






Resultados
#Problemas encontrados

•	Mi idea original era agregar un componente i2c para implementar el uso de un teclado matricial de 4x4 para darle mayor utilidad al proyecto, pero no pude hacer funcionar el i2c por lo cual opté por el uso de un push button de 2 pines para meter la interrupción con ese componente.
•	El mayor problema que tuve es que mi ESP32 no tiene los pines soldados por lo cual al momento de trabajar con ella es muy incomodo e impráctico ya que requiere que yo haga el contacto con los pines de forma manual.

•	Para la implantación del reloj tuve problemas con la pila que viene, pero eso se soluciono de manera muy sencilla al cambiar la pila, la otra dificultad fue implementar el uso de este componente en el programa.

#Resultados obtenidos
El prototipo no funciona de la manera que yo esperaba por los problemas con los pines por lo cual opte por mostrar videos de los componentes funcionando de manera individual y mostrar un poco el como funcionaria todos los componentes en conjunto.

#Conclusiones
El trabajar a fondo en todo este mundo me gusto demasiado, aprendí mucho a lo largo del curso cosas como el leer las librerías que uso y checar su funcionamiento, así como el como buscar, implementar y mejorar el uso de estas con ayuda de programación avanzada en C.
Aun estoy lejos de dominar esta área, pero con lo visto en este curso tengo las herramientas necesarias para seguir aprendiendo.
