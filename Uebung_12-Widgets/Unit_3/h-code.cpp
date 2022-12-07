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

#include "header.h"


LEDBlock :: LEDBlock(QWidget *parent)
    : QWidget(parent) {

    lcd = new QLCDNumber(1);
        lcd->setSegmentStyle(QLCDNumber::Filled);
        lcd->display(1);

    button = new QPushButton(tr("Push"));

    connect(button, SIGNAL(clicked()), this, SIGNAL(clicked()));
    connect(button, SIGNAL(clicked()), this, SLOT(LEDon()));
    
    QVBoxLayout *box = new QVBoxLayout;
    box->addWidget(lcd);
    box->addWidget(button);
    setLayout(box);
}


void LEDBlock :: LEDon() {
    lcd->display(1);
}

void LEDBlock :: LEDoff() {
    lcd->display(0);
}