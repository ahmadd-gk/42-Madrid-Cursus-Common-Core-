* _Este proyecto ha sido creado como parte del currículo de 42 por "ahgutier"_
* _This project was created as part of the 42 curriculum by "ahgutier"_
* _Ce projet a été créé dans le cadre du cursus de 42 par "ahgutier"_
* _Dieses Projekt wurde als Teil des 42-Curriculums von "ahgutier" erstellt_
* _Этот проект был создан в рамках учебной программы 42 пользователем "ahgutier"_
* _هالمشروع انعمل كجزء من منهج 42 من قبل "ahgutier"_
* _本项目是 42 课程体系的一部分，由 "ahgutier" 创建_
* _このプロジェクトは、42のカリキュラムの一環として「ahgutier」によって作成されました_

# ES
## Descripción
En este proyecto principal y fundamentalmente hemos aprendido las funciones variádicas, parsing de strings y conversiones de tipos y respresentaciones númericas.
La función (ft_printf) principal o final de este proyecto es una reimplementación parcial de la función 'printf' original de la libc. Admite conversiones o tipos de formato: 

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
**Conversión númerica**
	- Para calcular el número de caracteres impresos en las conversiones númericas, se utiliza el método de divisiones sucesivas. El número se divide repetidamente por la base correspondiente (10 para decimal, 16 para  hexadecimal) hasta que su valor llega a cero, incrementando un contador en cada iteración. Este contador representa el número de dígitos que serán impresos.
	- Los formatos %d y %i comparten la misma lógica de conversión, ya que ambos representan enteros con signo en base decicmal. Por este motivo, se gestionan mediante una única función, evitando duplicación de código y mejorando la mantenibilidad.
	- Los formatos '%x', '%X' y '%p' usan base 16 porque sistema hexadecimal es una forma compacta y legible de representar binario, y en binario trabajan los ordenadores. En el caso del formato '%p', el '0x' añadido es un prefijo estándar para indicar o decir explícitamente que el número a continuación se encuentra en base 16 o formato hexadecimal.

### Gestión de casos especiales
Gestión de punteros a cadenas (strings) nulos, imprimiendo '(null)' o devolviendo NULL según el caso.
Manejo de punteros nulos dejándolos en NULL.
Manejo de 0 devolviendo el mismo.
Comportamiento definido en introducción de formatos desconocidos o inválidos.
Devolución del carácter literal '%' en caso de '%%'

# EN
## Description
In this main and fundamental project we have learned variadic functions, string parsing, and type conversions and numerical representations.
The main or final function (ft_printf) of this project is a partial reimplementation of the original 'printf' function from libc. It supports the following conversions or format types:

	- %c: Prints a single character (char).
	- %s: Prints a string of characters (string).
	- %p: Prints the memory address where the requested item is located (unsigned long).
	- %d: Prints a decimal number (base 10 (integer)).
	- %i: Prints an integer (int) in base 10.
	- %u: Prints an unsigned decimal integer in base 10 (unsigned int).
	- %x: Prints a hexadecimal number (base 16) in lowercase (unsigned int).
	- %X: Prints a hexadecimal number (base 16) in uppercase (unsigned int).
	- %%: Prints the literal percent symbol character (%).

It should be noted or pointed out that in this project we do not use allocation or manual memory management, and it does not support several features of the original 'printf' function such as flags, width, and precision.

## Instructions
The final purpose of these files is that when compiling all of them they result in a single static library, which you will be able to use as part of your own program.
Use one of the following to facilitate the compilation process:

- 'make': Automatically compiles all files including the library, generating the program file.
- 'make clean': Automatically deletes all '.o' files, leaving the program file.
- 'make fclean': Automatically deletes all files including the program file.
- 'make re': Recompiles or recompiles everything necessary automatically in case there have been changes.

Followed by pressing the 'Enter' key to proceed to execute one of the above commands.
Include the 'ft_printf.h' file in your file header ('#include "ft_printf.h"') to use the library and call the 'ft_printf' function as you would normally call the original 'printf' function, which will internally return the number of characters printed.
Compile your program by linking your '.c' files with the library ('.a').

## Resources
	- 'man 3 printf' (section 3 of the official 'printf' manual)
	- 'man 3 stdarg' (section 3 of the official manual for variadic functions)
	- Use of AI for:
  		- Understanding part of the concept of variadic functions and format conversions or types.
  		- Optimizing the code so that it fits within the Norminette line limit (42 readability standard).
  		- Testing for potential failures and corrections.
  		- Guidance, algorithm structuring, and project clarity.

### Explanation and detailed justification of the chosen algorithm and data structure
1. The embedded text string ('format') is traversed character by character; if the character is not '%', it is printed directly without analysis.
2. If the '%' character appears, the character that follows is analyzed; this will indicate the format (if it is valid). The process to determine what to do according to the specified format is delegated to another function ('handle_format_parser').

Here we make use of variadic functions. In the main function described just above, arguments are only consumed when the format requires it, that is, when a valid format appears in the form of a character preceded by '%'.
The project code has been divided into several parts and functions in order to comply with its standard, improve readability, make it easier to add new formats (greater adaptability), and avoid monolithic functions.
**Numerical conversion**
	- To calculate the number of characters printed in numerical conversions, the method of successive divisions is used. The number is repeatedly divided by the corresponding base (10 for decimal, 16 for hexadecimal) until its value reaches zero, incrementing a counter at each iteration. This counter represents the number of digits that will be printed.
	- The '%d' and '%i' formats share the same conversion logic, since both represent signed integers in base decimal. For this reason, they are handled by a single function, avoiding code duplication and improving maintainability.
	- The '%x', '%X', and '%p' formats use base 16 because the hexadecimal system is a compact and readable way to represent binary, and computers operate in binary. In the case of the '%p' format, the added '0x' is a standard prefix to indicate or explicitly state that the number that follows is in base 16 or hexadecimal format.

### Handling of special cases
Handling of null string pointers, printing '(null)' or returning NULL depending on the case.
Handling of null pointers by leaving them as NULL.
Handling of 0 by returning it as is.
Defined behavior when introducing unknown or invalid formats.
Returning the literal '%' character in the case of '%%'.
