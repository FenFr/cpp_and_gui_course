//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:            1    		
// Task:          		1
// Name:          		03_Aufgabe.c
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 4

typedef struct{
    int int_val;
    double double_val;
} TAB;


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv){

    // Fehlerüberprüfung
    if(ARR_SIZE <= 0){
        printf("Error: Size of Array does not match!");
        exit(1);
    }
    
    // Definition des Arrays
    TAB wertearray[ARR_SIZE];


    // Werteeigabe des Arrays über die Tastatur
    int cntr = 0;
    while(cntr < ARR_SIZE){
        printf("Eingabe der Werte des %d. Blocks\n", cntr+1);
        printf("Eingabe des Int-Wertes: ");
        scanf("%d", &wertearray[cntr].int_val);
        printf("Eingabe des Float-Wertes: ");
        scanf("%lf", &wertearray[cntr].double_val);
        printf("\n");
        cntr++;
    }


    // Sortierung der Werte
    TAB val_save = wertearray[0];
    cntr = 0;
    while(cntr < ARR_SIZE && ARR_SIZE > 1){
        if(wertearray[cntr].int_val > wertearray[cntr+1].int_val){
            val_save = wertearray[cntr+1];
            wertearray[cntr+1] = wertearray[cntr];
            wertearray[cntr] = val_save;
            if(cntr) cntr--;
        }
        else cntr++;
    }
  

    // Ausgabe der Werte auf dem Bildschirm
    cntr = 0;
    printf("\n");
    while(cntr < ARR_SIZE){
        printf("Ausgabe der Werte des %d. Blocks\n", cntr+1);
        printf("Int: %d\n",    wertearray[cntr].int_val);
        printf("Int: %lf\n\n", wertearray[cntr].double_val);
        cntr++;
    }
    
    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////