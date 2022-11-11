//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenja Freitag
// Exercise:      		4
// Task:          		1
// Name:          		04_h-code.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string.h>
#include "03_header.h"

#define INCR 128

using namespace std;


CBUF :: CBUF(int len, int size, char *buf) {
    this->len = len;
    this->size = size;
    buf = new char[size];
}

CBUF :: ~CBUF() {
    delete [] buf;
}

CBUF CBUF :: *cbuf_reset () {
    this->buf[this->len = 0] = '\0';
    return(this);
}

static void *new_memory(int size, char *name) {
    void *p;
    if (!(p = malloc(size))) {
        cout << "Error: Memory allocation failed!";
        exit(1);
    }
    
    return p;
}