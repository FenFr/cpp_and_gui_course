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
         CBUF();                                // constructor
        ~CBUF();                                // deconstructor
        
        void     cbuf_reset ();                 // clear the content
        char    *cbuf_addc  (char c);           // add one char
        char    *cbuf_addstr(const char *s);    // add a string
        char    *cbuf_buf   ();                 // get the content
};