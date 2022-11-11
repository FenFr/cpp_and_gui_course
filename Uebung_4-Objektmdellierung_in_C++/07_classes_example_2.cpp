//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenja Freitag
// Exercise:      		4
// Task:          		-
// Name:          		07_classes_example_2.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <math.h>

using namespace std;


class KLASSE {
    private:
        int *data;
        int  size;

    public:
        KLASSE(int size_in);
       ~KLASSE();
        
        void change_value(int index, int data_in);
        int give_value(int index);
};



KLASSE :: KLASSE(int size_in) {
    this->size = size_in;
    data = new int[size_in];
}

KLASSE :: ~KLASSE() {
    delete [] data;
}

void KLASSE :: change_value(int index, int data_in) {
    this->data[index] = data_in;
}

int KLASSE :: give_value(int index) {
    return this->data[index];
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    KLASSE var(5);

    var.change_value(0, 1);

    printf("%ld", var.give_value(0));

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////