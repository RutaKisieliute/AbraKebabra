run: cmake
	main-prog.exe
cmake: main.c funkc.c cssGenerator.c htmlGenerator.c
	gcc -o main-prog main.c funkc.c cssGenerator.c htmlGenerator.c