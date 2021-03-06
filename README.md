# Task #1
Обычно я пишу код в VSCode, но для небольших проектов использую Vim, как сейчас.
1. Исходный файл - task1.c. Простая программа берет char array как аргумент и аллоцирует его копию.
2. Компиляция с arm-linux-gnueabi-gcc compiler:

	```console
	foo@bar:~$ arm-linux-gnueabi-gcc task1.c -o task1
	```

	Можем посмотреть ELF header и убедиться, что исполняемый файл - для архитектуры ARM:

	```console
	foo@bar:~$ readelf -h task1
	Machine:	ARM
	```

У меня на системе стоит также aarch64-elf-gcc компилятор, который я могла бы использовать, чтобы скомпилировать 64-битный бинарник специально для ARMv8. Чтобы программа могла запускаться на ARMv7 и ARMv8, нужно, чтобы программа была 32-битной. Поэтому я использую ARM 32bit toolchain gcc-arm-linux-gnueabihf.
Бинарник называется task1.
3. Использовала Ghidra для binary analysis. Еще мне нравится Radare2. Файл с анализом дизассемблера - Task1_analysis.pdf.
_________________________________________________________________________________________________________________________

# Task #2
## Способ 1.
1. Файл с исходным кодом - task2.c.
2. Сборка. Скомпилировала программу:

	```console
	foo@bar:~$ arm-linux-gnueabi-gcc -g task2.c -o task2
	```

Так как в исходнике одна функция не используется, пришлось немного изменить код и добавить флаг -g, чтобы Ghidra нашла функцию в режиме Raw binary; компилятор не соптимизировал код и не убрал multiply_by8.
Бинарник называется task2.
3. Для патчинга использовала Ghidra.
Суть в поиске нужного адреса первой инструкции нужной функции и его подстановке в операнд инструкции. Процесс патчинга описываю в файле Task2_patching.
Пропатченный бинарник - task2.bin.

## Способ 2.
1. Файлы лежат в папке task2_2. Я разделила два исходника - один с функцией bubble_sort (task2.c), другой с multiply_by8 (task2_nobubble.c).
2. Скомпилировала оба исходника:

	```console
	foo@bar:~$ arm-linux-gnueabi-gcc task2.c -o task2
	foo@bar:~$ arm-linux-gnueabi-gcc task2_nobubble.c -o task2_no
	```

3. Процесс патчинга описываю в том же файле Task2_patching.pdf.
Как-то я практиковалась шифровать функции прошивки. Вспомнила про этот опыт и решила, что технику можно адаптировать под патчинг.
Пропатченный бинарник - task2_new.
Возможно, это не совсем то, что требовалось, но мне показалось, что способ удобный и простой.
_________________________________________________________________________________________________________________________
