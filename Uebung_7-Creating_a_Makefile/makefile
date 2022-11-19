my_program:	main.o header_code.o header.o
			gcc -o my_program main.o header_code.o header.o

main.o:			03_main.c
				gcc -c 03_main.c

header_code.o:	04_header-code.c
				gcc -c 04_header-code.c

header.o:		05_header.h
				gcc -c 05_header.h