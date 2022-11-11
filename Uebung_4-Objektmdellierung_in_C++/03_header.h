//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenja Freitag
// Exercise:      		4
// Task:          		1
// Name:          		03_header.h
// Description:   		
//////////////////////////////////////////////////////////////////////////////


class CBUF {
    private:
        int  len;
        int  size;
        char *buf;        
    
    public:
         CBUF(int len, int size, char *buf);        // constructor
        ~CBUF();                                    // deconstructor
        
        CBUF     cbuf_malloc();             // new CBUF
        void     cbuf_free();               // free
        
        CBUF    *cbuf_reset ();             // clear the content
        char    *cbuf_addc  (char c);       // add one char
        char    *cbuf_addstr(char *s);      // add a string
        char    *cbuf_read  ();             // get the content
};