_Este proyecto ha sido creado como parte del currículo de 42 por <ahgutier>_

## Descripción
En este proyecto principal y fundamentalmente hemos aprendido las funciones variádicas, parsing de strings y conversiones de tipos y respresentaciones númericas.
La función (ft_printf) principal o final de este proyecto es una reimplementación parcial de la función 'printf' original de la libc.Admite conversiones o tipos de formato: 
	- %c: Imprime carácter individual (char).
	- %s: Imprime cadena de caracteres (string).
	- %p: Imprime dirección de memoria en la que se encuentra lo solicitado (unsigned long).
	- %d: Imprime número decimal (base 10 (integer)).
	- %i: Imprime entero (int) en base 10.
	- %u: Imprime número entero decimal en base 10 sin signo (unsigned int).
	- %x: Imprime número hexadecimal (base 16) en minúsuclas (unsigned int).
	- %X: Imprime número hexadecimal (base 16) en mayúsculas (unsigned int).
	- %%: Imprime carácter de símbolo de porcentaje (%) literal.
Cabe destacar o señalar que en este proyecto no usamos alocación o gestión manual de memoria y éste no soporta varias funciones de la función 'printf' original como flags, width y precision.

## Instrucciones
El propósito final de estos archivos es que al compilarlos todos resulten en una sola librería estática, que la podrás usar como parte propia de tu programa.
Usa uno de los siguientes para facilitar el proceso de compilación:
	- make: Compila automáticamente todos los archivos incluida la librería generando el archivo de programa.
	- make clean: Borra automáticamente todos los archivos .o dejando el archivo de programa.
	- make fclean: Borra automáticamente todos los archivos incluyendo el archivo de programa.
	- make re: Vuelve a compilar o recompila todo lo necesario automáticamente en caso de haber cambios.
Seguido de la tecla 'Enter' para procedero ejecutar uno de los comandos anteriores.
Incluye en el encabezado de tu archivo el archvio 'ft_printf.h' (#include "ft_printf.h") para usar la librería y llama a la función 'ft_printf' como llamarías normalmente a la función original 'printf' que devolverá internamente el número de caracteres impresos.
Compila tu programa enlazando tus archivos (.c) con la librería (.a).

## Recursos
	- man 3 printf (sección 3 del manual oficial de 'printf')
	- man 3 stdarg (sección 3 del manual oficial de las funciones variádicas)
	- Uso de la IA para:
		- Comprender parte del concepto de funciones variádicas y las conversiones o tipos de formatos.
		- Optimizar el código para que quepa dentro del límite de líneas de la Norminette (norma de legibilidad en 42).
		- Tester de potenciales fallos y correcciones.
		- Orientación, estructuración del algoritmo y claridad en el proyecto.

### Explicación y justificación detallada del algoritmo elegido y la estructura de datos
	1. Se recorre la cadena de texto incrustada (format) carácter a carácter, si éste no es '%' se imprime directamente sin analizar.
	2. Si se presenta el carácter '%', se analiza el carácter que viene a continuación, éste nos indicará el formato (si es que es válido), el proceso para determinar qué hacer según el formato especificado se delega a otra función (handle_format_parser).
Aquí hacemos uso de las funciones variádicas, en la función principal descrita justamente arriba, los argumentos solo se consumen cuando el formato lo requiere, es decir cuando viene un formato válido en forma de carácter precedido por éste '%'.
Ha sido el código del proyecto dividido en varias partes y funciones por cumplir con la norma de éste, mejor legibilidad, facilidad para añadir formatos nuevos (mayor adaptabilidad) y evitar funciones monolíticas.
Conversión númerica
	- Para calcular el número de caracteres impresos en las conversiones númericas, se utiliza el método de divisiones sucesivas. El número se divide repetidamente por la base correspondiente (10 para decimal, 16 para  hexadecimal) hasta que su valor llega a cero, incrementando un contador en cada iteración. Este contador representa el número de dígitos que serán impresos.
	- Los formatos %d y %i comparten la misma lógica de conversión, ya que ambos representan enteros con signo en base decicmal. Por este motivo, se gestionan mediante una única función, evitando duplicación de código y mejorando la mantenibilidad.
	- Los formatos '%x', '%X' y '%p' usan base 16 porque sistema hexadecimal es una forma compacta y legible de representar binario, y en binario trabajan los ordenadores. En el caso del formato '%p', el '0x' añadido es un prefijo estándar para indicar o decir explícitamente que el número a continuación se encuentra en base 16 o formato hexadecimal.

### Gestión de casos especiales
Gestión de punteros a cadenas (strings) nulos, imprimiendo '(null)' o devolviendo NULL según el caso.
Manejo de punteros nulos dejándolos en NULL.
Manejo de 0 devolviendo el mismo.
Comportamiento definido en introducción de formatos desconocidos o inválidos.
Devolución del carácter literal '%' en caso de '%%'