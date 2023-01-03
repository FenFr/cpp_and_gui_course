//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		13
// Task:          		1
// Name:          		traffic_light.cpp
// Description:   		Creates a traffic light and prints its cycles
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "traffic_light.h"


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

        case  1 :   // this->light = "R _ _";
                    check_for_changed_color(1, 0, 0);
                    break;

        case  2 :   // this->light = "R Y _";
                    check_for_changed_color(1, 1, 0);
                    break;

        case  3 :   // this->light = "_ _ G";
                    check_for_changed_color(0, 0, 1);
                    break;

        case  4 :   // this->light = "_ Y _";
                    check_for_changed_color(0, 1, 0);
                    break;
    }
}


void TL :: check_for_changed_color(int r, int g, int b) {
    if(color_state[0] != r) {
        emit redChanged   (this->color_state[0] = r);
    }

    if(color_state[1] != g) {
        emit greenChanged (this->color_state[1] = g);
    }

    if(color_state[2] != b) {
        emit blueChanged  (this->color_state[2] = b);
    }        
}


void TL :: iterate_light() {
    this->phase++;
    change_light();
    // print_light ();
}


/*
void TL :: print_light() {
    printf("Phase : %d\nLight : %s\n\n", this->phase, this->light);
}
*/