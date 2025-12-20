Este proyecto ha sido creado como parte del currículo de 42 por "ahgutier".
This project has been created as part of the 42 curriculum by "ahgutier".
このプロジェクトは、42のカリキュラムの一環として「ahgutier」によって作成されました。
تم إنشاء هذا المشروع كجزء من منهج 42 بواسطة "ahgutier".

-------------------------------------------------------------  ES  -------------------------------------------------------
DESCRIPCIÓN
En este proyecto nos piden que escribamos una función que devuelve una línea de un 'file descriptor (fd). El 'fd' es una referencia que apunta a un archivo que está en abierto en ese momento en tu dispositivo. Entonces, le pasamos esa referencia y de esa manera va hacia el archivo objetivo, y la función 'get_next_line' deberá de devolver una línea entera en forma de string del contenido del archivo, que será la línea que ha leído con el 'read' y almacenado respectivamente en el stash. Se meterá la función en un bucle hacia el mismo archivo y dependiendo del número de líneas que quieras sacar lo especificas en éste, por cada llamada = una línea leída del archivo, es decir, la primera llamada a la función 'get_next_line' leerá y te mostrará o devolverá la línea nº 1, la segunda llamada la línea nº 2... y así sucesivamente. Si ha llegado ya hacia el final del archivo y no hay o queda nada más que leer, o hay o ha ocurrido un error mientras la función está corriendo, ésta devolverá 'NULL'. La función 'open' se puede usar en el 'main' para acceder al archivo y operar con él.

INSTRUCCIONES
Las funciones externas que se pueden usar para proceder con la ejecución de este proyecto son 'read', 'malloc' y 'free'. 3 archivos: 'get_next_line.c', 'get_next_line_utils.c' y 'get_next_line.h' y 1a variable estática. Con la función 'read' vamos leyendo el archivo y almacenando en el buffer hasta completarse una sola línea, al tenerla, ésta se traslada al stash y así sucesivamente, cada vez que se pasan el número de bytes solicitados al stash revisamos si en uno de ellos es el '\n', si es encontrada, todo lo anterior, desde el salto de línea hasta el principio de ella, es almacenada en una variable de línea que habremos creado y ésta es devuelta al mismo tiempo que deberá de ser eliminada o borrada del stash (actualizar el stash) y dejar solo lo sobrante (lo posterior que queda), si hay, se queda en el stash hasta que se completa la línea siguiente (ya en otra llamada de la función principal) de la misma manera que lo hizo con la anterior. La variable de stash obviamente tendrá que ser estática (el valor es guardado entre llamada y llamada) porque al hacer otra llamada, lo sobrante mencionado anteriormente, tendrá que ser conservado para devolver el contenido original del mismo archivo al que se está accediendo (al igual que la función 'read' guarda también su posición actual en el archivo, y si también el stash no es guardado, se perderá contenido).

RECURSOS
[understanding get_next_line (english subtitles) - from Nikito, YouTube](https://youtu.be/-Mt2FdJjVno?si=rTMTt7MnU9814Zrj)

SECCIONES ADICIONALES
La función 'read' devuelve el número (ssize_t)  de bytes leídos, requerirá como parámetros el 'fd', un buffer, y el número de bytes a leer (en 'size_t'), si se hace una llamada de ella y ya ha llegado hasta el final desde la anterior llamada, devovlerá un 0 (EOF), si ha ocurrido un error, devolverá -1. Y el número de bytes leído será almacenado en una variable. Visualízalo como si fuera la barra vertical de cursor típico del ratón de un documento de texto moviéndose por él. Si quieres leer por ejemplo 5 bytes, avanzará 5 caracteres hacia adelante, 'Hola mundo' = 'Hola ', y los almacenará en el buffer o hueco temporal que le hayamos pasado.
El tamaño del buffer o bytes a leer será definido a la hora de la compilación, asi que ésta puede variar.

-------------------------------------------------------------  EN  -------------------------------------------------------
This project has been created as part of the 42 curriculum by "ahgutier".
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

-------------------------------------------------------------  JP  -------------------------------------------------------
日本語 (Japanese)
このプロジェクトは、42のカリキュラムの一環として「ahgutier」によって作成されました。
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

-------------------------------------------------------------  AR  -------------------------------------------------------
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
