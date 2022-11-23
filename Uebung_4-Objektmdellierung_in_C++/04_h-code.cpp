//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		4
// Task:          		1
// Name:          		04_h-code.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "03_header.h"

#define INCR 128


static void test_memory(void *p, const char *fname) {
    if(!p) {
        printf("%s: out of memory\n", fname);
        exit(1);
    }    
}

CBUF :: CBUF() {
    test_memory(buf = new char[size = INCR], "CBUF");
    this->cbuf_reset();
}

CBUF :: ~CBUF() {
    delete this->buf;
}

void CBUF :: cbuf_reset() {
    this->buf[this->len = 0] = '\0';
}

char *CBUF :: cbuf_buf() {
    return this->buf;
}

char *CBUF :: cbuf_addc(char c) {
    if( this->len + 1 >= this->size ) {
        char *new_buf = new char[this->size + INCR];
        test_memory(new_buf, "CBUF :: cb_addc()");
        memcpy(new_buf, buf, len+1);
        delete buf;
        size += INCR;
        buf = new_buf;
    }
    buf[len++] = c;
    buf[len]   = '\0';
    
    return this->buf;
}

char *CBUF :: cbuf_addstr(const char *s) {
    while(*s)
        this->cbuf_addc(*s++);
    
    return this->buf;
}