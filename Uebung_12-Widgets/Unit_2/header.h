//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		2
// Name:          		header.h
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#ifndef HEADER_H
#define HEADER_H

#include <QWidget>

class QSlider;


class FancySlider : public QWidget {
    Q_OBJECT                                // always necessary

    public:
        FancySlider(QWidget *parent = 0);   // constructor

    private:
        // defining *slider here so that slider->value() can be changed in incValue() and decValue()
        QSlider *slider;

    private slots:
        // Functions to in- or decrease slider->value() 
        void incValue();
        void decValue();

    signals:
        // necessary to establish a connection between FancySlider and QLCDNumber
        void valueChanged(int value);
};


#endif