//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		4
// Task:          		-
// Name:          		06_classes_example_1.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <math.h>

using namespace std;

class KLASSE {
    private:
        int x,y;

    public:
         KLASSE(int x_in, int y_in);
        ~KLASSE();

         void set_x(int x_in);
         void set_y(int y_in);

         int get_x();
         int get_y();

         double calc_rad();
};



KLASSE :: KLASSE(int x_in, int y_in) {
    this->x = x_in;
    this->y = y_in;
}

KLASSE :: ~KLASSE() {
    this->x = 0;
    this->y = 0;
}

void KLASSE :: set_x(int x_in) {
    this->x = x_in;
}

void KLASSE :: set_y(int y_in) {
    this->y = y_in;
}

int KLASSE :: get_x() {
    return this->x;
}

int KLASSE :: get_y() {
    return this->y;
}

double KLASSE :: calc_rad() {
    return sqrt((this->x * this->x) + ((this->y * this->y)));
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {
    
    KLASSE coord(5,3);
    printf("Die Koordinate %3.d und %3.d bilden den Radius %3.4f\n", coord.get_x(), coord.get_y(), coord.calc_rad());
    
    coord.set_x(20);
    printf("Die Koordinate %3.d und %3.d bilden den Radius %3.4f\n", coord.get_x(), coord.get_y(), coord.calc_rad());
    
    coord.~KLASSE();
    printf("Die Koordinate %3.d und %3.d bilden den Radius %3.4f\n", coord.get_x(), coord.get_y(), coord.calc_rad());

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////