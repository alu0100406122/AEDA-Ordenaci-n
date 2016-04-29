# AEDA

## Práctica 5 - Ordenación

Desarrollar en lenguaje C++ diferentes algoritmos de ordenación y realizar un análisis de
rendimiento de los algoritmos implementados.


Algoritmos de ordenación:
* Inserción.
* Burbuja.
* Por incrementos decrecientes (ShellSort), debe permitir seleccionar la constante de reducción alfa, siendo 0<alfa<1.
* QuickSort.
* MergeSort.


La implementación de cada método de ordenación se realizará mediante una plantilla de función en la que se especificará el tipo de los elementos a ordenar, y la función recibirá
como parámetros la secuencia a ordenar y su tamaño: Funcion(secuencia, tamaño).

Las secuencias a ordenar se generarán de forma aleatoria, y estarán formadas por valores de claves del tipo DNI (clase definida en el enunciado de la práctica 4). La clase DNI
tendrá sobrecargadas todas las operaciones de comparación necesarias para aplicar los algoritmos de ordenación.


Se deben realizar dos programas para ejecutar el código implementado:

* Modo demostración: 

Se utilizan secuencias pequeñas (de hasta 25 elementos) para comprobar el funcionamiento de un algoritmo determinado.

* Modo Estadísticas:

El programa cuenta el número de comparaciones necesarias para ordenar los elementos en cada uno de los algoritmos. 