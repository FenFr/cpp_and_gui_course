//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		3
// Name:          		header.h
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#ifndef HEADER_H
#define HEADER_H

#include <QWidget>

class QPushButton;
class QLCDNumber;


class MyClass : public QWidget {
    Q_OBJECT

    public:
        MyClass(QWidget *parent = 0);

    private:
        QLCDNumber  *lcd;
        QPushButton *button;

    public slots:

    
    private slots:


    signals:

};

#endif