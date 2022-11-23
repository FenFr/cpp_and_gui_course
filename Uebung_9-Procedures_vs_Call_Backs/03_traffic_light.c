//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		9
// Task:          		1
// Name:          		03_traffic_light.c
// Description:   		Creates a traffic light and prints its cycles
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct {
    char *light;
    int   phase;
} TL;


void traffic_light();

void change_traffic(TL *tl);


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    traffic_light();

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////


void traffic_light() {
    TL traffic;
    traffic.light = "R _ _";
    traffic.phase =  1;

    int cntr = 4*1;

    while(0 < cntr--) {
        printf("Light : %s\nPhase : %d\n\n", traffic.light, traffic.phase);
        change_traffic(&traffic);
        // sleep(1);
    }
}


void change_traffic(TL *tl) {
        switch(tl->phase) {
            case  1 :   tl->light = "R Y _";
                        tl->phase =  2;
                        break;

            case  2 :   tl->light = "_ _ G";
                        tl->phase =  3;
                        break;

            case  3 :   tl->light = "_ Y _";
                        tl->phase =  4;
                        break;

            default :   tl->light = "R _ _";
                        tl->phase =  1;
        }
}