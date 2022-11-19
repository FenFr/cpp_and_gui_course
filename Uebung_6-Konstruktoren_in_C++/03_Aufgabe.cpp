//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenja Freitag
// Exercise:      		6
// Task:          		1
// Name:          		03_Aufgabe.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class CBUF {
    private:
        int  len;
        int  size;
        char *buf;        
    
    public:
         CBUF();                                // constructor
         CBUF(CBUF &from);                      // copy constructor
        ~CBUF();                                // deconstructor
        
        void     cbuf_reset ();                 // clear the content
        char    *cbuf_addc  (char c);           // add one char
        char    *cbuf_addstr(const char *s);    // add a string
        char    *cbuf_buf   ();                 // get the content
};


#define INCR 128

using namespace std;


static void test_memory(void *p, const char *fname) {
    if(!p) {
        printf("%s: out of memory\n", fname);
        exit(1);
    }    
}

CBUF :: CBUF() 
    : size(INCR), buf(new char[INCR]) {
    test_memory(buf, "CBUF");
    this->cbuf_reset();
}

CBUF :: CBUF(CBUF &from)
    : size(from.size), buf(new char[from.size]) {
    for (int i = 0; i < this->size; i++)
        this->buf[i] = from.buf[i];
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


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    /*
    CBUF *p = new CBUF;
    p->cbuf_addc( 'h' );
    p->cbuf_addc( 'i' );
    p->cbuf_addstr( " you" );
    p->cbuf_addc( '!' );
    printf( "buf = '%s'\n", p->cbuf_buf() );
    p->cbuf_reset();
    printf( "buf = '%s'\n\n", p->cbuf_addstr( "servus" ) );
    */

    CBUF buf_1, buf_3;
    buf_1.cbuf_addstr("ABC");
    printf("buf_1 = %s\n\n", buf_1.cbuf_buf());

    CBUF buf_2(buf_1);
    buf_3 = buf_1;
//    buf_2.cbuf_addc('D');
    buf_3.cbuf_addc('E');
    printf("buf_1 = %s\n", buf_1.cbuf_buf());
    printf("buf_2 = %s\n", buf_2.cbuf_buf());
    printf("buf_3 = %s\n", buf_3.cbuf_buf());

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////