#my_programm:	gcc 03_main.c 04_header_code.c 05_header.h -o my_programm

my_programm: 	main header-code header
				gcc main header-code header -o my_programm

main: 			03_main.c
				gcc 03_main.c -o main

header-code:	04_header-code.c
				gcc 04_header_code.c -o header-code

header:			05_header.h
				gcc 05_header.h -o header