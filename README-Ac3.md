# ReadMe y análisis de complejidad

Evidencia de competencias (3)

El archivo "books.txt" contiene 17 de los libros más vendidos del presente año,

mientras que el archivo "casosprueba.txt", incluye algunos casos de prueba

el programa incluye un menú con funciones como:

----- 1. Leer arhivo: ------

Esta funcion, como lo dice su nombre, lee el archivo e imprime el resultado.

El análsis de complejidad sería de O(n) para el peor de los casos, ya que 

realiza la lectura línea por línea

----- 2. Order por título ------

Es una funicón Sort, por medio el atributo título, tipo Selection Sort pero incluyendo apuntadores 

por lo que su análisis de complejidad sería de O(n^2) para todos los casos.

Esta opción tiene la opción de imprimir o guardar en un archivo nuevo. 

------ 3. Ordenar por Autor ------

Igual que en caso anterior, se utilizó un sort, con atributo Autor

el análisis de complejidad sería igual que en el caso anterior O(n^2) 

De igual manera incluye la opción de imprimir o guardar en un archivo nuevo los resultados.

------4. y 5. Búsqueda por autor y título-----

Ambas tienen una complejidad de O(log(n)) ya que busca en los elementos dados

----- 6. Encontrar repeticiones -----

Para este caso se utilizó la estructura de una árbol de búsqueda binaria o BST

Por lo que el análisis de complejidad sería de O(log(n)) para todos los casos.


