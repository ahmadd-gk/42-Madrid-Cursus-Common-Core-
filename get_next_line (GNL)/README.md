Este proyecto ha sido creado como parte del currículo de 42 por "ahgutier".

This project has been created as part of the 42 curriculum by "ahgutier".

このプロジェクトは、42のカリキュラムの一環として「ahgutier」によって作成されました。

هالمشروع معمول كجزء من منهاج 42 بواسطة "ahgutier".

---------------------------------------------------------------------------------------  ES  --------------------------------------------------------------------------------------------------
DESCRIPCIÓN
En este proyecto nos piden que escribamos una función que devuelve una línea de un 'file descriptor (fd). El 'fd' es una referencia que apunta a un archivo que está en abierto en ese momento en tu dispositivo. Entonces, le pasamos esa referencia y de esa manera va hacia el archivo objetivo, y la función 'get_next_line' deberá de devolver una línea entera en forma de string del contenido del archivo, que será la línea que ha leído con el 'read' y almacenado respectivamente en el stash. Se meterá la función en un bucle hacia el mismo archivo y dependiendo del número de líneas que quieras sacar lo especificas en éste, por cada llamada = una línea leída del archivo, es decir, la primera llamada a la función 'get_next_line' leerá y te mostrará o devolverá la línea nº 1, la segunda llamada la línea nº 2... y así sucesivamente. Si ha llegado ya hacia el final del archivo y no hay o queda nada más que leer, o hay o ha ocurrido un error mientras la función está corriendo, ésta devolverá 'NULL'. La función 'open' se puede usar en el 'main' para acceder al archivo y operar con él.

INSTRUCCIONES
Las funciones externas que se pueden usar para proceder con la ejecución de este proyecto son 'read', 'malloc' y 'free'. 3 archivos: 'get_next_line.c', 'get_next_line_utils.c' y 'get_next_line.h' y 1a variable estática. Con la función 'read' vamos leyendo el archivo y almacenando en el buffer hasta completarse una sola línea, al tenerla, ésta se traslada al stash y así sucesivamente, cada vez que se pasan el número de bytes solicitados al stash revisamos si en uno de ellos es el '\n', si es encontrada, todo lo anterior, desde el salto de línea hasta el principio de ella, es almacenada en una variable de línea que habremos creado y ésta es devuelta al mismo tiempo que deberá de ser eliminada o borrada del stash (actualizar el stash) y dejar solo lo sobrante (lo posterior que queda), si hay, se queda en el stash hasta que se completa la línea siguiente (ya en otra llamada de la función principal) de la misma manera que lo hizo con la anterior. La variable de stash obviamente tendrá que ser estática (el valor es guardado entre llamada y llamada) porque al hacer otra llamada, lo sobrante mencionado anteriormente, tendrá que ser conservado para devolver el contenido original del mismo archivo al que se está accediendo (al igual que la función 'read' guarda también su posición actual en el archivo, y si también el stash no es guardado, se perderá contenido).

RECURSOS
[understanding get_next_line (english subtitles) - from Nikito, YouTube](https://youtu.be/-Mt2FdJjVno?si=rTMTt7MnU9814Zrj)

SECCIONES ADICIONALES
La función 'read' devuelve el número (ssize_t)  de bytes leídos, requerirá como parámetros el 'fd', un buffer, y el número de bytes a leer (en 'size_t'), si se hace una llamada de ella y ya ha llegado hasta el final desde la anterior llamada, devovlerá un 0 (EOF), si ha ocurrido un error, devolverá -1. Y el número de bytes leído será almacenado en una variable. Visualízalo como si fuera la barra vertical de cursor típico del ratón de un documento de texto moviéndose por él. Si quieres leer por ejemplo 5 bytes, avanzará 5 caracteres hacia adelante, 'Hola mundo' = 'Hola ', y los almacenará en el buffer o hueco temporal que le hayamos pasado.
El tamaño del buffer o bytes a leer será definido a la hora de la compilación, asi que ésta puede variar.

---------------------------------------------------------------------------------------  EN  --------------------------------------------------------------------------------------------------
DESCRIPTION
In this project, we are asked to write a function that returns a line from a file descriptor (fd). The fd is a reference that points to a file that is currently open on your device. By passing this reference, the function accesses the target file, and the get_next_line function must return a complete line as a string from the file’s contents. This line is the one read using read and stored accordingly in the stash.

The function is called repeatedly in a loop on the same file, and depending on how many lines you want to retrieve, you specify this in the loop. Each call equals one line read from the file. That is, the first call to get_next_line will read and return line number 1, the second call line number 2, and so on.

If the end of the file has been reached and there is nothing left to read, or if an error occurs while the function is running, it will return NULL. The open function can be used in main to access the file and operate on it.

INSTRUCTIONS
The external functions allowed to complete this project are read, malloc, and free. There are 3 files: get_next_line.c, get_next_line_utils.c, and get_next_line.h, and 1 static variable.

Using the read function, we read from the file and store data in the buffer until a full line is completed. Once a line is obtained, it is transferred to the stash, and the process continues. Each time the requested number of bytes is added to the stash, we check whether one of them is \n. If it is found, everything from the beginning of the stash up to and including the newline is stored in a line variable that we have created, which is then returned. At the same time, this part must be removed from the stash (updating the stash), leaving only the remaining content, if any.

That remaining content stays in the stash until the next line is completed (in another call to the main function), following the same process as before. The stash variable must obviously be static (its value is preserved between calls), because when another call is made, the remaining content mentioned above must be kept in order to return the original contents of the same file being accessed. This works similarly to how the read function also keeps track of its current position in the file. If the stash were not preserved, data would be lost.

RESOURCES
Understanding get_next_line (English subtitles) - from Nikito, YouTube

ADDITIONAL SECTIONS
The read function returns the number of bytes read (ssize_t). It requires the fd, a buffer, and the number of bytes to read (size_t) as parameters. If it is called and the end of the file has already been reached since the previous call, it will return 0 (EOF). If an error occurs, it will return -1. The number of bytes read is stored in a variable.

You can visualize it as the typical vertical text cursor moving through a text document. If you want to read, for example, 5 bytes, it will advance 5 characters forward:
"Hola mundo" → "Hola "
and store them in the buffer or temporary space you provided.

The buffer size or number of bytes to read is defined at compile time, so it may vary.

---------------------------------------------------------------------------------------  JA  --------------------------------------------------------------------------------------------------
説明
このプロジェクトでは、ファイルディスクリプタ（fd）から1行を返す関数を作成することが求められます。fd は、デバイス上で現在開かれているファイルを指す参照です。この参照を渡すことで、対象のファイルにアクセスでき、get_next_line 関数はファイル内容から1行分を文字列として返す必要があります。この行は read によって読み込まれ、stash に保存されたものです。

同じファイルに対してこの関数をループ内で繰り返し呼び出すことで、取得したい行数を指定できます。1回の呼び出しにつき1行が読み取られます。つまり、get_next_line の最初の呼び出しでは1行目、2回目では2行目…というように順番に返されます。

ファイルの終端（EOF）に到達してこれ以上読み取る内容がない場合、または関数の実行中にエラーが発生した場合、NULL が返されます。open 関数は main 内でファイルにアクセスし、操作するために使用できます。

指示
このプロジェクトで使用できる外部関数は read、malloc、free のみです。必要なファイルは3つあり、get_next_line.c、get_next_line_utils.c、get_next_line.h、そして1つの静的変数を使用します。

read 関数を使ってファイルを読み込み、1行分が完成するまでバッファにデータを格納します。1行が完成したら、それを stash に移し、同じ処理を繰り返します。指定されたバイト数が stash に追加されるたびに、その中に \n が含まれているかを確認します。

改行文字が見つかった場合、stash の先頭から改行文字までのすべてを、新しく作成した行用の変数に格納し、それを返します。同時に、その部分は stash から削除され（stash を更新）、残りのデータがあれば、それは stash に残されます。

この残りのデータは、次の関数呼び出しで次の行が完成するまで stash に保持されます。stash 変数は、呼び出し間で値を保持する必要があるため、必ず static でなければなりません。これは read 関数がファイル内の現在位置を保持しているのと同じ考え方です。stash が保持されなければ、データは失われてしまいます。

リソース
Understanding get_next_line（英語字幕）- Nikito, YouTube

追加セクション
read 関数は、読み取ったバイト数（ssize_t）を返します。引数として、fd、バッファ、読み取るバイト数（size_t）が必要です。前回の呼び出しですでにファイルの終端に到達している場合、0（EOF）を返します。エラーが発生した場合は -1 を返します。読み取られたバイト数は変数に保存されます。

これは、テキストエディタ内でカーソルが前に進んでいく様子としてイメージできます。たとえば5バイト読み取る場合、5文字分前に進みます。
「Hola mundo」 → 「Hola 」
この内容は、指定したバッファや一時的な領域に格納されます。

バッファサイズ、または読み取るバイト数はコンパイル時に定義されるため、変更される可能性があります。

---------------------------------------------------------------------------------------  AR (SY)  --------------------------------------------------------------------------------------------------
الوصف
بهالمشروع مطلوب منّا نكتب دالة بترجّع سطر واحد من واصف ملف (fd). الـ fd هو مرجع بيدلّ على ملف مفتوح حاليًا على الجهاز. لما نمرّر هالمرجع، الدالة بتوصل للملف المطلوب، ودالة get_next_line لازم ترجع سطر كامل على شكل string من محتوى الملف. هالسطر هو اللي انقرأ باستخدام read وانخزّن بالـ stash.

الدالة بتنادى جوّا loop على نفس الملف، وبحسب عدد الأسطر اللي بدّك تطلعها بتحدّد هالشي باللوب. كل نداء للدالة = سطر واحد مقروء من الملف. يعني أول مرة بتنادي get_next_line بترجع السطر الأول، المرة التانية السطر التاني… وهيك دواليك.

إذا وصلنا لنهاية الملف وما عاد في شي ينقرأ، أو صار خطأ أثناء تنفيذ الدالة، بترجع NULL. فيك تستخدم دالة open جوّا main لتفتح الملف وتشتغل عليه.

التعليمات
الدوال الخارجية المسموح استخدامها بهالمشروع هي: read و malloc و free.
المشروع فيه 3 ملفات:
get_next_line.c، get_next_line_utils.c، و get_next_line.h، بالإضافة لمتغير واحد static.

باستخدام دالة read منقرأ من الملف ومنخزّن البيانات بالـ buffer لحد ما يكتمل سطر كامل. لما يكتمل السطر، بيننقل على الـ stash، وبتكمّل العملية بنفس الطريقة. كل مرة منضيف عدد البايتات المطلوبة على الـ stash، منشيّك إذا في بينهم محرف \n.

إذا لقينا الـ \n، فكل المحتوى من بداية الـ stash لحد محرف السطر الجديد بينخزّن بمتغير السطر اللي أنشأناه، وبيترجع. بنفس الوقت لازم نحذف هالجزء من الـ stash (نحدّثه) ونخلّي بس اللي ضل بعده، إذا كان موجود.

البيانات اللي بتضل بالـ stash بتبقى فيه لحد ما يكتمل السطر اللي بعده (بنداء جديد للدالة)، بنفس الطريقة اللي اشتغلنا فيها على السطر السابق. متغير الـ stash لازم يكون static، لأن قيمته لازم تضل محفوظة بين النداءات. لما ننادي الدالة مرة تانية، لازم نكون محتفظين بالباقي اللي ضل، مشان نرجّع المحتوى الصح لنفس الملف. هالشي مشابه لطريقة عمل read اللي بتتذكر موقعها الحالي جوّا الملف. إذا الـ stash ما كان محفوظ، المحتوى رح يضيع.

المصادر
Understanding get_next_line (ترجمة إنجليزية) - Nikito, YouTube

أقسام إضافية
دالة read بترجع عدد البايتات اللي انقرت (ssize_t). بتحتاج كمعاملات:
الـ fd، و buffer، وعدد البايتات المراد قراءتها (size_t).
إذا ناديناها ووصلنا لنهاية الملف من النداء السابق، بترجع 0 (EOF). وإذا صار خطأ، بترجع -1. عدد البايتات المقروءة بينخزّن بمتغير.

تخيّل الموضوع متل مؤشر الكتابة بمستند نصي عم يتحرك لقدّام. مثلاً إذا بدّك تقرأ 5 بايتات، المؤشر بيتقدّم 5 محارف:
"Hola mundo" → "Hola "
وبينخزّنوا بالـ buffer أو بالمساحة المؤقتة اللي مرّرتها.

حجم الـ buffer أو عدد البايتات المقروءة بيتحدّد وقت الـ compilation، لذلك ممكن يختلف.

______________________________________________________________   ES   _____________________________________________________________

<<< FLUJO PRINCIPAL DEL PROGRAMA >>>
1. 'ft_get_next_line'
2. 'ft_read_stash'
3. 'ft_extract_line'
4. 'ft_update_stash'

<<< DETALLES / ESPECIFICACIONES DEL CÓDIGO / TRADUCIDO A LENGUAJE HUMANO >>>

FUNCIÓN PARA CALCULAR LONGITUD DE UNA CADENA (Acepta como parámetro la cadena (char *))
1. Creamos una variable tipo número para devolverla al final como longitud de la cadena analizada
2. Inicializamos la variable creada previamente a 0, e inicializamos un bucle tomando como referencia como índice la misma variable anterior (mejor no mover punteros), con la condición de que exista, iteramos hasta que ésta sea completada y enteramente leída, finalmente devolvemos la variable de longitud

FUNCIÓN PARA COPIAR DE UNA CADENA ORIGEN Y PEGAR EL CONTENIDO DE ELLA EN UNA CADENA DE DESTINO (Acepta como parámetros la cadena de texto de destino, la cadena de origen, y la cantidad de contenido a copiar)
1. Declaramos una variable tipo índice
2. Si no existe la cadena de origen Ó la cadena de destino devolvemos 0
3. Inicializamos la variable anteriormente creada tipo índice, y con ello inicializamos una condición en la que ponemos como condición que la cantidad (del parámetro) sea mayor a 0, si se da el caso, dentro, iniciamos un bucle y se cumplirá mientras que exista la cadena de origen o quede algo en ella Y la cadena haya llegado a 1 menos el la cantidad total (para dejar espacio para el terminador nulo). Ya dentro del bucle, copiamos el contenido de la cadena origen a la de destino, una vez hecho esto, sumamos el índice para avanzar hacia el siguiente carácter, elemento o valor. Una vez terminado el bucle por incumplimiento de una de las dos anteriores condiciones mencionadas, colocamos en la última posición el terminador nulo para cerrar la cadena de texto. Iniciamos un último bucle para contar la longitud total de la cadena de origen (propia de la función 'strlcpy', puede ser innecesaria en este proyecto).
4. Devolvemos la variable de índice. Lo importante aquí o en esta función es devolver un número verdadero y la copia interna que se da lugar. Peor lo mejor es las funciones auxiliares deben ser correctas, reutilizables y cumplir su contrato aunque el proyecto no las use plenamente

FUNCIÓN PARA DETERMINAR SI SE ENCUENTRA O NO UN SALTO DE LÍNEA (\n) Y SU POSICIÓN (en tipo número) EN CASO DE HABERLO (Acepta / Recibe como parámetro la cadena de texto)
1. Creamos una variable índice que será el valor que devolvamos en caso de encontrar un salto de línea, todavía no la inicializamos.
2. Manejamos la inexistencia del parámetro recibido, en caso de ser así devolvemos NULL
3. Inicializamos la variable índice a 0 (para no tener valor basura), iniciamos el bucle con la condición de comenzar con la cadena y tomando de referencia el índice, mientras esto sea así entramos en el bucle, dentro creamos una condición en la que comprueba cada vez que itera si el valor actual de la cadena es el salto de línea ('\n'), si se da el caso en alguna de las iteraciones, éste devuelve el valor de la variable index o de índice, que será el número de la posición ubicado el salto de línea para luego en otras funciones poder tomarlo como referencia, vamos aumentando en uno la variable índice por cada iteración
4. Finalmente, si ha terminado o concluido con el bucle y no ha entrado en el condicional, ésto significa que no ha habido salto de línea o éste no se ha dado a lugar, devolvemos '-1' en una línea fuera del bucle para indicar eso

FUNCIÓN PARA INCIAR EL STASH CON EL TAMAÑO DEL BUFFER (Ésta acepta como parámetro el buffer en formato (char *) porque es una cadena de texto del archivo que vamos a analizar)
1. Declaramos dos variables, una para el nuevo stash que será necesario para almacenarlo en un espacio que reservaremos manualmente para él y otra la longitud, en la que será necesaria para conocer el tamaño total del buffer y por ende saber cuánto espacio es necesario reservar exactamente
2. Manejamos la inexistencia del buffer, poniendo que si ésto ocurre devolvemos NULL (no hay nada que pasar, solo vacío)
3. Inicializamos ahora sí (siempre mejor y más eficiente después del manejo de errores) ambas variables creadas al inicio, la primera, de la longitud en tipo número, calculamos, con la función de longitud que anteriormente creamos, la longitud total del buffer, guardamos el resultado respectivamente en la variable. En la segunda variable, del nuevo stash, reservamos con alocación de memoria (malloc) con el valor númerico de la variable más 1 (para reservar espacio para terminador nulo (\0) o fin de string). Si falla el malloc u ocurre cualquier otra anomalía inesperada, manejamos esto devolviendo el valor de NULL en caso de ocurrir
4. Usamos la función de copiar una cadena de texto origen y pegarla en la de destino en la que devuelve la longitud del proceso, ponemos en sus parámetros como destino la variable del nuevo stash, como origen la variable temporal del buffer, y como longitud a copiar, la variable de longitud de esta función más el 1 (para incluir el terminador nulo)
5. Devolvemos la variable del nuevo stash

FUNCIÓN PARA PASAR EL CONTENIDO DEL VIEJO STASH A UN NUEVO BUFFER TEMPORAL Y LIBERAR ÉSE (Acepta o recibe como parámetro el stash viejo y un buffer ya existente)
1. Creamos una variable tipo (char *) para almacenar el contenido del nuevo buffer, y dos variables, una para la longitud del stash antiguo y otra para la longitud del buffer existente, juntos en total (más 1 para el '\0'), concatenados, formarían el espacio para el nuevo buffer
2. A continuación, manejamos el caso en el que el buffer que se nos es pasado está vacío, si se da el caso, devolvemos NULL
3. Si el stash que se nos es pasado está vacío o no existe pero el buffer no, devolvemos la función de crear un nuevo stash con el bufer que se nos es dado.
4. De lo contrario, si ninguno de ambos casos anteriores se ha cumplido le asignamos a una de las variables de longitud la longitud (con la función de calcular la longitud) del buffer y a la otra la longitud del stash, con esto si sumamos ambos más el 1 tendríamos el espacio listo para asignárselo a la variable con malloc de nuevo buffer, manejamos el caso de posibles o potenciales errores por malloc.
5. Ahora sí para copiar y concatenar ambos el viejo stash y buffer antiguo en el nuevo buffer, llamamos la función de copiar dos veces, una para pasar el viejo stash al nuevo buffer, y otra para pasar el viejo buffer al nuevo, en la primera llamada, como parámetros, en el de destino (primer parámetro) ponemos el nuevo buffer, el de origen (segundo parámetro) el stash antiguo, y en el tercer parámetro como tamaño establecemos la variable de longitud calculada anteriormente correspondiente al stash antiguo + 1 reservado para el terminador nulo, en la segunda llamada, como parámetros, en el de destino (primer parámetro) ponemos el nuevo buffer MÁS la longitud del stash antiguo, el de origen (segundo parámetro) el buffer de antaño, y en el tercer parámetro como tamaño establecemos la variable de longitud calculada anteriormente correspondiente al buffer antiguo + 1 reservado para el terminador nulo.
6. Liberamos el stash antiguo (ya tenemos el mismo contenido en el nuevo buffer) y devolvemos la variable del nuevo buffer

FUNCIÓN PARA ACTUALIZAR EL STASH O DEJAR SU SOBRANTE NADA MÁS (Acepta como parámetro el stash en cadena de texto)
1. Declaramos 5 variables en total al comenzar con esta función:
	- Para el nuevo stash a devolver
	- Para determinar o saber la posición del salto de línea (para luego quedarse con el resto de stash a partir del salto de línea)
	- Una para medir la longitud del stash
	- Dos variables de índice
2. Manejamos el caso en el que el stash no exista devolvemos NULL
3. Guardamos la posición del salto de línea en la variable que previamente creamos para ello mediante llamando su función y poniendo el stash antiguo como objetivo. Si no se ha encontrado un salto de línea, liberamos el antiguo stash y devolvemos NULL para indicarlo
4. Calculamos la longitud del antiguo stash y con ello reservamos o asignamos a la nueva variable de stash como alocación de memoria el resultado que da de la resta entre la longitud total del stash antiguo que guardamos justamente anterior menos la posición en donde se encuentra el salto de línea (Ej: "Hola\n qué tal" (13 - 5 = 8), se quedaría solamente el nuevo stash con el espacio para "qué tal"). Manjenamos el caso en el que la alocación de memoria falle o haya fallado devolviendo NULL.
5. Inicializamos la primera variable de índice desede la primera posición a partir del salto de línea, esto lo hacemos mediante sumándole a la posición de salto de línea un uno (porque el salto de línea no lo queremos incluir). La segunda variable de índice la inicializamos en 0 porque será la posición desde donde comience el nuevo stash.
6. Inciamos un bucle, mientras que la primera variable de índice sea menor (no igual, por espacio al terminador nulo) a la longitud total del antiguo stash, vamos copiando de la variable de stash antiguo hacia el nuevo y sumando en uno seguidamente la posición. Finalmente, al salirnos del bucle, añadimos el terminador nulo en la última posición.
7. Liberamos el stash antiguo (ya es innecesario) y devolvemos el nuevo stash actualizado.

FUNCIÓN PARA LA EXTRACCIÓN DE LÍNEA EXACTA INDIVIDUAL SOLICITADA DEL STASH (Acepta como único parámetro a recibir el stash)
1. Declaramos tres variables, una en la que vamos a guardar la línea extraída, otra en la que guardaremos la posición índice del salto de línea que se nos es dada de su respectiva función para devolver solamente la línea contenida hasta el salto de línea, y la última variable servirá como índice para luego ir copiando del contenido desde el stash a la nueva variable de línea creada en esta misma función.
2. Manejamos el caso en el que no haya memoria para stash o no exista (!stash) Ó stash quede vacío (Ej: "" (!stash[0]) (no debe devolver una línea vacía)) y devolvemos con ello NULL.
3. Guardamos en la variable que hemos designado anteriormente el índice o posición en el que se encuentra el saldo de línea (si lo hay) en el stash, esto lo hacemos mediante llamando la función externa que se encarga de encontrar la posición del salto de línea (le introducimos como parámetro el stash) dentro de la variable asignada, devolverá un número, y ese será el espacio a medida que reservaremos con alocación de memoria para la variable de línea a posteriori. Si no se ha encontrado el salto de línea y la función a devuelto el valor respectivo, procedemos pues a calcular la longitud total del stash igualmente para poder reservar el espacio para la línea.
4. Reservamos con alocación de memoria el tamaño justo y necesario para la variable de línea a devolver al final de esta función, con esto incrustamos dentro de 'malloc' la variable anterior que se encargaba de calcular o determinar hasta qué posición el salto de línea existía o se encontraba, o si no fuera así, el tamaño total o entero de stash, y le sumamos 2, uno para el salto de línea (el índice empieza en 0 y la longitud de la cadena empieza en 1, por l que siempre será la posición un dígito menor de la longitud actual) y otro para el terminador nulo. Manejamos el caso en el que la alocación de memoria de la variable línea falle.
5. Inicializamos la variable de índice, y con ello abrimos un bucle que se encargará de pasar el contenido solicitado por el usuario (una línea, ni más ni menos), en el que ponemos como condición mientras que la variable de índice sea menor o igual a la variable que teníamos dedicada para encontrar el salto de línea Y exista stash. Dentro del bucle vamos copiando con la varíable de índice el valor actual de stash y reemplazando con ello el valor actual de la variable de línea, sumamos la variable de índice en cada iteración. Una vez terminado el bucle, al encontrarnos en la última posición, añadimos el terminador nulo.
6. Finalmente, devolvemos la variable de línea.

FUNCIÓN PARA LEER DEL STASH (acepta como parámetro el descriptor de archivo o 'file descriptor' en tipo número y el stash en tipo 'string' o cadena de texto)
1. Declaramos dos variables, una para el buffer de tipo cadena de texto y otra para guardar los bytes leídos de la función 'read'
2. Reservamos espacio de memoria con el macro que hemos definido por defecto en el código, o bien el que nos pasarían a la hora de la compilación más uno para el terminador nulo. Manejamos el caso en el que la alocación de memoria falle devolviendo por ende NULL.
3. Inicializamos el valor de la variable de bytes leídos o a leer con 1 (valor de control verdadero) y con ello iniciamos un bucle, éste tiene o tendrá como condiciones que mientras no se haya encontrado un salto de línea (la función que se encarga de encontrarlo devuelve el valor adecuado) Y el número de bytes leído es mayor a 0 (es verdadero, hay o quedan bytes por leer) hacemos lo siguiente:
	1- En la variable de leer bytes, guardamos la llamada a la función 'read' en la que insertamos como parámetros, primero el descriptor o 'file descriptor' de archivo (el archvio objetivo o siendo accedido en ese momento), segundo el buffer que previamente hemos creado, y tercero la cantidad de ese buffer a ser rellenado.
	2- Una condición en la que determinamos si el número de bytes leídos es menor que 0 (error), devolvemos el buffer liberado de memoria, el stash liberado y NULL
	3- Una vez leídos y puestos todos los bytes del primer paso, ponemos en la última posición o al final el terminador nulo del buffer.
	4- En la variable de stash que nos pasan como parámetro, guardamos la llamada a la función que se encarga de juntar o unir el buffer con el stash y crear uno nuevo de ambos. Si el stash no existe o la previa función ha fallado, liberamos el buffer y devolvemos NULL.
4. Liberamos el espacio de memoria para el buffer (ya no es necesario y éste es temporal). Finalmente, devolvemos stash.
**(Si se da el caso de que el stash es justamente igual a 0 o EOF no se lee, procesa lo que queda y se devolvería automáticamente el stash).

FUNCIÓN DE GET NEXT LINE
1. Creamos la variable estática de stash que preservará el valor entre llamada y llamada. Y creamos la variable de la línea que vamos a devolver.
2. Si el descriptor de archivos es menor a 0 (error) o el tamaño de buffer es nulo (0 o menor (no hay espacio)) devolvemos NULL.
3. Guardamos en la variable estática de stash que justamente creamos en esta función la lectura de bytes por la funciónn 'read' que acepta como parámetro el descriptor de archivos y el stash. Y en la variable de línea, la llamada a la función que llamamos que se encarga de extraer o sacar la línea exacta. Si no existe la ésta variable anterior o falló algo en su función, se libera el espacio de memoria para el stash, se le asigna al stash NULL, y se devuelve finalmente NULL.
4. Una vez leído anteriormente el stash, guardamos en éste la llamada a función que se encarga de actualizarlo o elminar lo inncesario (ya hemos guardado la línea necesaria en la variable de línea).
5. Finamente, devolvemos la variable de línea para ser mostrada ante el usuario que la requiere.

______________________________________________________________   EN   _____________________________________________________________

<<< **MAIN PROGRAM FLOW** >>>

1. `ft_get_next_line`
2. `ft_read_stash`
3. `ft_extract_line`
4. `ft_update_stash`

<<< **DETAILS / CODE SPECIFICATIONS / TRANSLATED TO HUMAN LANGUAGE** >>>

---

### FUNCTION TO CALCULATE THE LENGTH OF A STRING

*(Takes the string (char *) as a parameter)*

1. We create a numeric variable to return it later as the length of the analyzed string.
2. We initialize the variable to 0 and start a loop using that same variable as an index (better not to move pointers). As long as the character exists, we iterate until the string has been completely read. Finally, we return the length variable.

---

### FUNCTION TO COPY FROM A SOURCE STRING INTO A DESTINATION STRING

*(Takes as parameters the destination string, the source string, and the amount to copy)*

1. We declare an index variable.
2. If either the source or destination string doesn’t exist, we return `0`.
3. We initialize the index variable and set a condition that the given amount must be greater than 0. If so, we enter a loop that continues **while the source exists and we have not reached the maximum amount minus 1** (leaving space for the null terminator). Inside the loop, we copy each character, increasing the index each iteration. After exiting the loop, we append the null terminator. We then run a final loop to count the full length of the source string (as `strlcpy` would do — possibly unnecessary for this project).
4. We return the index variable. What matters here is returning a valid number and actually performing the copy. Ideally, helper functions must be correct, reusable, and fulfill their contract even if the project does not fully rely on them.

---

### FUNCTION TO CHECK IF A NEWLINE EXISTS AND RETURN ITS POSITION

*(Takes the text string as a parameter)*

1. We create an index variable that will be returned if a newline is found.
2. If the parameter does not exist, return `NULL`.
3. Initialize the index to 0. Loop while characters remain. If the current character is a newline (`'\n'`), return the index (newline position). Increase index each iteration.
4. If the loop completes without finding a newline, return `-1`.

---

### FUNCTION TO INIT THE STASH WITH THE BUFFER SIZE

*(Accepts the buffer as `(char *)` from the file we are reading)*

1. We declare two variables: one for the new stash and one for the length of the buffer.
2. If the buffer does not exist, return `NULL`.
3. We calculate the buffer length and store it. Then we allocate memory for the new stash (length + 1 for `\0`). If allocation fails, return `NULL`.
4. We copy the buffer into the new stash using the copy function (length + 1 to include `\0`).
5. We return the newly created stash.

---

### FUNCTION TO MERGE OLD STASH WITH A NEW TEMPORARY BUFFER

*(Receives the old stash and the existing buffer)*

1. We create a `(char *)` variable for the new merged buffer, plus two length variables (stash and buffer).
2. If the buffer is empty, return `NULL`.
3. If the stash does not exist but the buffer does, create a new stash using the buffer and return it.
4. Otherwise, we calculate both lengths, allocate space for the sum + 1 (`\0`). Handle allocation failures.
5. Copy stash to the new buffer, then copy the buffer after the stash’s length (concatenation).
6. Free the old stash and return the new merged buffer.

---

### FUNCTION TO UPDATE THE STASH (ONLY KEEP THE REMAINDER)

*(Takes the stash as a parameter)*

1. We declare 5 variables:

   * the new stash to return
   * the newline position
   * stash length
   * two index variables
2. If the stash does not exist, return `NULL`.
3. Get the newline position using its helper function. If no newline exists, free stash and return `NULL`.
4. Calculate stash length, allocate memory for the remainder (`total_length - newline_position`). Handle allocation failures.
5. Set the first index to the character after the newline; set the second index to 0 (new stash’s start).
6. Loop to copy all remaining stash content into the new stash. Append null terminator.
7. Free the old stash and return the updated stash.

---

### FUNCTION TO EXTRACT A SINGLE LINE FROM THE STASH

*(Takes the stash as its only parameter)*

1. Declare three variables: one for the extracted line, one for the newline position, and one index for copying.
2. If stash does not exist or is empty (`!stash[0]`), return `NULL`.
3. Store the newline index in the designated variable. If not found, use the full stash length.
4. Allocate memory for the exact line size + 2 (`newline` + `\0`). Handle memory failure.
5. Loop to copy characters until the newline position. Append null terminator.
6. Return the extracted line.

---

### FUNCTION TO READ INTO THE STASH

*(Takes file descriptor (int) and stash (char *) as parameters)*

1. Declare a buffer variable (string) and a variable for bytes read.
2. Allocate memory using the defined buffer size macro + 1 (`\0`). If allocation fails, return `NULL`.
3. Initialize `bytes_read` to 1 (true).
   Loop while **no newline** is found **and** `bytes_read > 0`:

   1. Call `read(fd, buffer, BUFFER_SIZE)`
   2. If `bytes_read < 0` → free buffer & stash → return `NULL`
   3. Place null terminator at the end of the buffer
   4. Concatenate buffer into stash using the helper function. If it fails → free buffer → return `NULL`
4. Free the temporary buffer. Return stash.
   **(If EOF and stash still contains data, it will be returned normally.)**

---

### **GET NEXT LINE FUNCTION**

1. We create a static stash variable to persist across calls, and a variable for the line to return.
2. If file descriptor < 0 or buffer size <= 0 → return `NULL`.
3. Read into stash. Extract the line. If extraction fails → free stash, set to `NULL`, return `NULL`.
4. Update stash to remove the returned line.
5. Return the extracted line to the user.

______________________________________________________________   JA   _____________________________________________________________

<<< **プログラムのメインフロー** >>>

1. `ft_get_next_line`
2. `ft_read_stash`
3. `ft_extract_line`
4. `ft_update_stash`

---

<<< **詳細 / コード仕様 / 人間の言葉で説明** >>>

---

### 文字列の長さを計算する関数

（パラメータとして文字列 *(char *)* を受け取る）

1. 結果として返すための数値型変数を用意する
2. その変数を0で初期化し、（ポインタを動かさないため）同じ変数をインデックスとしてループを開始する
   　文字が存在する間ループし、すべて読み終えたら変数の値を返す

---

### 文字列をコピーして別の文字列に貼り付ける関数

（宛先文字列、元の文字列、コピーするサイズをパラメータとして受け取る）

1. インデックス変数を宣言する
2. 元文字列または宛先文字列が存在しない場合は `0` を返す
3. インデックスを初期化し、**サイズが 0 より大きい**場合に処理を行う
   　- 元文字列が存在し、かつコピーサイズ-1まではループでコピー
   　- コピー後、ヌル終端を追加
   　- 最後に元文字列の長さを数える（`strlcpy`仕様。今プロジェクトでは不要かもしれない）
4. インデックスの値を返す（正しいコピーと、有効な戻り値が重要）

---

### 改行（\n）があるかどうか確認し、その位置を返す関数

（文字列をパラメータとして受け取る）

1. 改行位置を返すためのインデックス変数を宣言
2. パラメータが無い場合は `NULL` を返す
3. インデックスを0で初期化し、各文字が改行かどうか確認
   　見つかった場合はその位置を返す
4. 見つからなければ `-1` を返す

---

### スタッシュをバッファのサイズで初期化する関数

（バッファ *(char *)* をパラメータとして受け取る）

1. 新しいスタッシュ用変数とバッファ長の変数を宣言
2. バッファが無い場合は `NULL` を返す
3. バッファ長を計算し、その長さ+1（`\0`のため）を `malloc`
   　失敗したら `NULL` を返す
4. コピー関数で内容をスタッシュへコピー
5. 新しいスタッシュを返す

---

### 古いスタッシュとバッファを結合し、新しい領域にコピーする関数

（古いスタッシュと既存バッファをパラメータとして受け取る）

1. 新しい結合用バッファ、スタッシュ長、バッファ長の3変数を宣言
2. バッファが空なら `NULL`
3. スタッシュが無くバッファがあるなら、新規スタッシュとして返す
4. 両方ある場合は長さを取得し、合計長+1で `malloc`
5. コピー関数を2回使い連結
6. 古いスタッシュを解放し、新バッファを返す

---

### スタッシュの更新（改行以降の余りだけを残す）関数

（スタッシュをパラメータとして受け取る）

1. 合計5つの変数を宣言

   * 新しいスタッシュ
   * 改行位置
   * スタッシュ長
   * インデックス2つ
2. スタッシュが無ければ `NULL`
3. 改行位置を取得。なければスタッシュを解放して `NULL`
4. 残りの必要サイズを計算し、`malloc`
5. 改行の次からコピー開始
6. コピー後 `\0` を追加
7. 古いスタッシュを解放し、新スタッシュを返す

---

### スタッシュから1行だけ抽出する関数

（スタッシュを唯一のパラメータとして受け取る）

1. 行用変数、改行位置変数、インデックスの3変数を宣言
2. スタッシュが `NULL` または空文字なら `NULL`
3. 改行位置を取得。なければ全体の長さを使用
4. 必要サイズ+2（改行 + `\0`）を確保
5. 改行位置までコピーし、最後に `\0`
6. 行を返す

---

### スタッシュへ読み込む関数

（ファイルディスクリプタ int とスタッシュ char* を受け取る）

1. バッファ変数と読み込んだバイト数変数を宣言
2. `BUFFER_SIZE + 1` で `malloc`、失敗なら `NULL`
3. `bytes_read = 1` で開始
   　- 改行が見つからず
   　- 読み込みが続く間
   　以下を行う：

   1. `read(fd, buffer, BUFFER_SIZE)` を実行
   2. 読み込みが負数 → buffer解放＋stash解放＋`NULL`
   3. 最後に `\0`
   4. スタッシュへ結合（失敗時はbuffer解放＋NULL）
4. bufferを解放してスタッシュを返す
   ※ EOFでもスタッシュに残りがあれば返す

---

### **GET NEXT LINE 関数**

1. スタッシュ（static）と返却する行の変数を作る
2. fd < 0 または buffer size <= 0 → `NULL`
3. スタッシュを更新し、行を抽出
   失敗時はスタッシュ解放し `NULL`
4. 使い終わったライン部分を消すためスタッシュ更新
5. 抽出した行を返す



<<< **التدفّق الرئيسي للبرنامج** >>>

1. `ft_get_next_line`
2. `ft_read_stash`
3. `ft_extract_line`
4. `ft_update_stash`

______________________________________________________________   AR   _____________________________________________________________

<<< **التفاصيل / مواصفات الكود / تبسيط بلغة بشرية** >>>

---

### دالّة حساب طول سلسلة نصية

(تستقبل سلسلة نصية *(char *)* كوسيطة)

1. إنشاء متغيّر عددي لحفظ الطول وإرجاعه لاحقًا
2. تهيئته بالقيمة 0 وبدء حلقة تكرار باستخدامه كفهرس (بدون تحريك المؤشّر)
   نستمر حتى نهاية السلسلة ثم نُعيد قيمة المتغيّر

---

### دالّة لنسخ سلسلة نصية ولصقها في سلسلة أخرى

(الوسائط: سلسلة الوجهة، سلسلة المصدر، وعدد المحارف المطلوب نسخها)

1. إعلان متغيّر فهرس
2. إذا كانت سلسلة المصدر أو الوجهة غير موجودة → تُعاد القيمة `0`
3. تهيئة الفهرس، وإذا كان العدد > 0:

   * نسخ المحارف من المصدر إلى الوجهة حتى الحد المطلوب ناقص 1 (لتركيب `\0`)
   * وضع مُنهي السلسلة النصية
   * حساب طول المصدر (سلوك `strlcpy` — قد لا يكون ضروريًا هنا)
4. إعادة قيمة الفهرس

---

### دالّة للبحث عن سطر جديد `\n` وتحديد موقعه إن وُجد

(تستقبل سلسلة نصية كوسيطة)

1. إعلان متغيّر فهرس لموضع السطر الجديد
2. إذا كانت الوسيطة غير موجودة → إعادة `NULL`
3. بدء الفهرس بـ 0 والبحث عبر كل محرف
   إذا وُجد `\n` → نعيد الفهرس
4. إن لم يُعثر عليه → نعيد `-1`

---

### دالّة لتهيئة الـ *stash* وفق حجم الـ buffer

(تستقبل الـ buffer كـ *(char *)*)

1. إعلان متغيّر *stash* جديد ومتغيّر لطول الـ buffer
2. إن لم يوجد الـ buffer → نعيد `NULL`
3. حساب الطول، ثم استخدام `malloc` بالطول + 1 لـ `\0`
   في حال فشل الحجز → `NULL`
4. نسخ محتوى الـ buffer إلى الـ stash
5. إعادة الـ stash الجديد

---

### دالّة لدمج الـ stash القديم مع buffer جديد

(تستقبل stash قديمًا وbuffer جديدًا)

1. إعلان buffer جديد + متغيّرين لطول كل من الـ stash والـ buffer
2. إذا كان الـ buffer فارغًا → `NULL`
3. إذا كان stash فارغًا وbuffer موجودًا → نعيد stash جديدًا مبنيًا على buffer
4. إن وُجدا معًا: نحجز مساحة بالطولين + 1
5. نسخ الـ stash ثم الـ buffer في المساحة الجديدة
6. تحرير الـ stash القديم ثم إعادة buffer الجديد

---

### دالّة تحديث الـ stash مع الاحتفاظ فقط بما بعد السطر الجديد

(تستقبل الـ stash)

1. إعلان 5 متغيّرات:

   * stash جديد
   * موضع السطر الجديد
   * طول الـ stash
   * فهرسين للنسخ
2. إذا لم يوجد الـ stash → `NULL`
3. البحث عن موضع السطر الجديد، وإن لم يوجد → تحرير القديم ثم `NULL`
4. حساب الطول المتبقي بعد السطر الجديد وحجزه بـ `malloc`
5. النسخ بدءًا من المحرف التالي لـ `\n`
6. إضافة `\0` في النهاية
7. تحرير الـ stash القديم ثم إعادة الجديد

---

### دالّة استخراج السطر المطلوب من الـ stash

(تستقبل stash كوسيطة وحيدة)

1. إعلان متغيّر للسطر + موضع `\n` + فهرس
2. إذا كان stash غير موجود أو فارغًا → `NULL`
3. الحصول على موضع `\n` أو استخدام الطول الكامل عند عدم وجوده
4. حجز الذاكرة بالطول المطلوب + 2 (`\n` + `\0`)
5. نسخ السطر المطلوب وإضافة `\0`
6. إعادة السطر

---

### دالّة قراءة البيانات داخل الـ stash

(تستقبل واصف ملف **fd** ومتغيّر stash)

1. إعلان buffer وعدد البايتات المقروءة
2. حجز buffer بحجم `BUFFER_SIZE + 1`، وعند فشل الحجز → `NULL`
3. بدء القراءة ما دام لم يتم العثور على `\n` وعدد البايتات > 0:
   1- `read(fd, buffer, BUFFER_SIZE)`
   2- إذا الناتج < 0 → تحرير buffer وstash ثم `NULL`
   3- وضع `\0` في نهاية buffer
   4- دمجه مع stash، وإن فشل الدمج → تحرير buffer و`NULL`
4. تحرير buffer وإعادة stash
   ※ عند الـ EOF، إذا بقي محتوى في stash، تتم معالجته وإعادته

---

### **دالّة GET NEXT LINE**

1. إنشاء stash ثابت (static) للحفاظ على البيانات بين الاستدعاءات + متغيّر للسطر
2. إذا كان fd < 0 أو `BUFFER_SIZE <= 0` → `NULL`
3. تحديث stash بالقراءة ثم استخراج السطر
   عند الفشل → تحرير stash وإسناده لـ `NULL` ثم إعادة `NULL`
4. تحديث stash بحذف السطر المستخرج
5. إعادة السطر للبرنامج المستدعي
