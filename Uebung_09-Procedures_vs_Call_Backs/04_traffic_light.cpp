//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
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
        short int phase;

        void change_light ();

    public:
        TL();
        TL(int phase_in);
//       ~TL();

        void iterate_light();
        void print_light  ();
};


TL :: TL() {
    this->phase = 1;
    change_light();
    print_light ();
}


TL :: TL(int phase_in) {
    this->phase = phase_in;        
    change_light();
    print_light ();
}


void TL :: change_light() {
    
    switch(this->phase) {
        default :   this->phase = 1;

        case  1 :   this->light = "R _ _";
                    break;

        case  2 :   this->light = "R Y _";
                    break;

        case  3 :   this->light = "_ _ G";
                    break;

        case  4 :   this->light = "_ Y _";
                    break;
    }
}


void TL :: iterate_light() {
    this->phase++;
    change_light();
    print_light ();
}


void TL :: print_light() {
    printf("Phase : %d\nLight : %s\n\n", this->phase, this->light);
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    TL tl;
    
    for(int i = 3*4-1; 0 < i; i--){
        tl.iterate_light();
    }

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////