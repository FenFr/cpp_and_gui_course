//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		3
// Task:          		1
// Name:          		03_Aufgabe.c
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 128        // buffer size for array


// Ansatz 1 - verkettete Liste

typedef struct cbuf {
    char content;
    struct cbuf *pntr;
} CBUF, *CB;


void read_cbuf(CB list) {
    if ((list->content = getchar()) != '\n'){
        if(!(list->pntr = (CB)malloc(sizeof(CBUF)))) {
                printf("Error: Memory allocation failed");
                exit(1);
            }
            // printf("Allocated %c to %p\n", list->content, list);
            read_cbuf(list->pntr);
    }
    else
        list->pntr = 0;
}


void print_cbuf(CB list) {
    printf("%c", list->content);
    if(list->pntr != 0)
        print_cbuf(list->pntr);
}


void delete_cbuf(CB list) {
    CB temp;
    if (list != 0)              // erstes Element soll übersprungen werden
        list = list->pntr;
    while(list->pntr != 0) {
        temp = list;
        list = list->pntr;
        // printf("Dellocated %p\n", temp);
        free(temp);
    }
}



// Ansatz 2 - dynamisches char Array

typedef struct {
    char *content;
    int content_size;
} STRING, *ST;


void read_string(ST list) {
    char *c;    
    scanf("%s", c);

    list->content_size = sizeof(c);
    if (!(list->content = (char*)malloc(list->content_size))) {
        printf("Error: Memory allocation failed!");
        exit(2);
    }

    for(int i = 0; i < list->content_size; i++) {
        list->content[i] = c[i];
    }
}



// Ansatz 3 - Kombination der Ansätze

typedef struct comb {
    char content[SIZE];
    struct comb *pntr;
} COMB, *CO;


void read_comb(CO list) {
    int i = 0;
    char c;

    while((c = getchar()) != '\n') {
            if (i == SIZE) {
                list->content[i++] = '\0';
                i = 0;
                
                if(!(list->pntr = (CO)malloc(sizeof(COMB)))){
                    printf("Error: Memory allocation failed!");
                    exit(3);
                }
                list = list->pntr;
            }
            list->content[i] = c;
            // printf("Allocated %c  to space %d at %p\n", list->content[i], i, list);
            i++;
        }
        list->content[i] = '\0';
        list->pntr = 0;
        // printf("Allocated \\0 to space %d at %p\n", i, list);
        // printf("Next structure at adress %p\n", list->pntr);
}


void print_comb(CO list) {
    while(list != 0) {
        // printf("Content of %p struct: %s\n", list, list->content);
        printf("%s", list->content);
        list = list->pntr;
    }
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    CBUF var;
    STRING viel;
    COMB mehr;

    printf("Hier einzulesenden Text eingeben: ");  
   
    /*
    read_cbuf(&var);
    print_cbuf(&var);
    delete_cbuf(&var);
    */


    read_string(&viel);
    printf("%s", viel.content);


    /*
    read_comb(&mehr);
    printf("\n");
    print_comb(&mehr);
    */

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////