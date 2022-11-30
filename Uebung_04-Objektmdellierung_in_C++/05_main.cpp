//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		4
// Task:          		1
// Name:          		05_main.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdlib.h>

#include "03_header.h"

using namespace std;

// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    CBUF *p = new CBUF;
    p->cbuf_addc( 'h' );
    p->cbuf_addc( 'i' );
    p->cbuf_addstr( " you" );
    p->cbuf_addc( '!' );
    printf( "buf= '%s'\n", p->cbuf_buf() );
    p->cbuf_reset();
    printf( "buf= '%s'\n", p->cbuf_addstr( "servus" ) );    

    return 0;
}

// MAIN END //////////////////////////////////////////////////////////////////