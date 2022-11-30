//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		2
// Task:          		1
// Name:          		03_Aufgabe_01.c
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>


double square (double input);       // Funktion zum Quadrieren


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv){

    // Zeiger fp auf Funktion square
    double (*fp)(double) = &square;


    // Ausgabe und Berechung der Quadrate
    double i = -4;
    while(i<=4){
        printf("(%.1lf)^2 = %.2lf\n", i, (*fp)(i));
        i += 0.5;
    }

    printf("\nAdress of the fuction: %p", &square);

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////


double square (double input){
    return input * input;
}