//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		5
// Task:          		1
// Name:          		03_Aufgabe.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdio.h>

#define BUF_SIZE 128

using namespace std;


class BUF {
    private:
        char buf[BUF_SIZE];
        int  len;

    public:
        char *get_buf ();
        int   add_new (const char  c);
        int   add_new (const char *s);
        int   reset   ();
};


int BUF :: reset() {
    len = 0;
    return BUF_SIZE;
}

char *BUF :: get_buf() {
    return buf;
}

int BUF :: add_new(const char c) {
    if(len < BUF_SIZE)
        buf[len++] = c;
    return BUF_SIZE - len;
}

int BUF :: add_new(const char *s) {
    while(*s)
        add_new(*s++);
    return BUF_SIZE - len;
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {
    BUF buf;
    buf.reset();
    buf.add_new("Hi");
    buf.add_new(' ');
    buf.add_new("you!");
    buf.add_new('\0');

    printf("buf = '%s'\n", buf.get_buf());

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////