//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		3
// Name:          		h-code.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <QWidget>
#include <QLCDNumber>
#include <QPushButton>
#include <QVBoxLayout>
#include <unistd.h>

#include "header.h"


LEDBlock :: LEDBlock(QWidget *parent)
    : QWidget(parent) {

    lcd = new QLCDNumber(1);
        lcd->setSegmentStyle(QLCDNumber::Filled);

    button = new QPushButton(tr("Push"));

    setValue(0);

    connect(this  , SIGNAL(valueChanged(int)), lcd , SLOT(display(int)));
    connect(button, SIGNAL(clicked())        , this, SIGNAL(clicked()));    
    
    QVBoxLayout *box = new QVBoxLayout;
    box->addWidget(lcd);
    box->addWidget(button);
    setLayout(box);
}


void LEDBlock :: LEDon() {
    setValue(1);
}


void LEDBlock :: LEDoff() {
    setValue(0);
}


void LEDBlock :: setValue(int value) {
    if((value > 1) || (value < 0)) {
        printf("\nsetValue must be between 0 and 1!\n\n");
        exit(1);
    }
    if(LEDstate != value) {
        LEDstate = value;
        emit valueChanged(value);
    }
}


void LEDBlock :: initLogic() {
    if(LEDstate == 1) {
        emit valueClicked(LEDstate);
        setValue(0);
    }
    else
        emit tick();
}


void LEDBlock :: binLogic() {
    switch(LEDstate) {
        case 0 :    setValue(1);
                    break;

        case 1 :    setValue(0);
                    emit tick();
    }
}