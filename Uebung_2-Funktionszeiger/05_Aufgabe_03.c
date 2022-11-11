//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenja Freitag
// Exercise:      		2
// Task:          		3
// Name:          		05_Aufgabe_03.c
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
    double a;
    double b;
    double (*pntr)(double, double, double);
} values;


double f_step(double x, double a, double b);

double f_cos(double x, double a, double b);


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv){

    //printf("Ausgabe: %lf\n", f_step(0,1,2));
    //printf("Ausgabe: %lf\n", f_cos(1,1,2));
    
    values nr_one;
    nr_one.a = 2;
    nr_one.b = 5;
    nr_one.pntr = &f_step;

    printf("Ausgabe: %lf\n", nr_one.pntr(0, nr_one.a, nr_one.b));

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////


double f_step(double x, double a, double b){
    return (x >= a) ? b: 0;
}

double f_cos(double x, double a, double b){
    return a*cos(x+b);
}