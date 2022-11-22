//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenja Freitag
// Exercise:      		9
// Task:          		3
// Name:          		04_traffic_light.c
// Description:   		Creates a traffic light and prints its cycles,
//                      but in c++
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdio.h>
#include <stdlib.h>


class TL {
    private:
        const char *light;
        int   phase;

    public:
        TL();
        TL(int phase_in);
//       ~TL();

        void change_light (int phase_in);
        void iterate_light();
        void print_light  ();
};


TL :: TL() {
    change_light(this->phase = 1);
    print_light ();
}


TL :: TL(int phase_in) {
    change_light(this->phase = phase_in);
    print_light ();
}


void TL :: change_light(int phase_in) {
    
    this->phase = (phase_in > 4) ? 1 : phase_in;

    switch(this->phase) {
        case  1 :   this->light = "R _ _";
                    break;

        case  2 :   this->light = "R Y _";
                    break;

        case  3 :   this->light = "_ _ G";
                    break;

        default :   this->light = "_ Y _";
    }
}


void TL :: iterate_light() {
    change_light(++this->phase);
    print_light ();
}


void TL :: print_light() {
    printf("Phase : %d\nLight : %s\n\n", this->phase, this->light);
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    TL tl(1);
    
    for(int i = 3*4-1; 0 < i; i--){
        tl.iterate_light();
    }

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////