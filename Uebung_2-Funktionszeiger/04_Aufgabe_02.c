//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		2
// Task:          		2
// Name:          		04_Aufgabe_02.c
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>


double ident(double x);                                                             // Die zu integrierende Funktion

double integrate(double xmin, double xmax, int slices, double (*func)(double));     // Funktion zur Flächeberechnung


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv){

    double (*a_function)(double) = &ident;

    double surface = integrate(0,5,5,a_function);
    printf("Area = %lf",surface);

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////


double ident(double x){
    return x;
}


double integrate(double xmin, double xmax, int slices, double (*func)(double)){
    if (slices<=0 || xmin==xmax){
        printf("Error in the integration fuction!");
        exit(1);
    }
    
    double delta_x = (xmax-xmin)/slices;
    double sampling_point[slices];
    double area[slices];
    double whole_area = 0;

    for(int i=0; i<slices; i++){
        if(i) sampling_point[i] = sampling_point[i-1] + delta_x;
        else  sampling_point[i] = (delta_x/2) + xmin;
        //printf("Sampling point %d = %lf\n", i, sampling_point[i]);

        area[i] = func(sampling_point[i]) * delta_x;
        whole_area += area[i];
        //printf("Area %d = %lf\n", i, area[i]);
    }

    //printf("\nWhole Area = %lf", whole_area);
    return whole_area;
}