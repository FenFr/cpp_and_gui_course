//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		4
// Name:          		h-code.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <vector>
#include <QLabel>
#include <QWidget>
#include <QSlider>
#include <QPalette>
#include <QLCDNumber>
#include <QPushButton>
#include <QVBoxLayout>

#include "header.h"


cSlider :: cSlider(char *name, QWidget *parent)
    : QWidget(parent) {

    button = new QPushButton(name);
    lcd    = new QLCDNumber(3);
    slider = new QSlider(Qt::Horizontal);
        slider->setRange(0, 255);

    connect(slider, SIGNAL(valueChanged(int)), this, SIGNAL(colorValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), lcd , SLOT(display(int)));
    connect(button, SIGNAL(clicked())        , this, SLOT(pushButton()));

    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(button);
    box->addWidget(slider);
    box->addWidget(lcd);
    setLayout(box);
}


int cSlider :: value() {
    return slider->value();
}


void cSlider :: pushButton() {
    switch(slider->value()) {
        case 255 :  slider->setValue(0);
                    break;

        default  :  slider->setValue(255);
    }
}



adjustPalette :: adjustPalette(QWidget *parent)
    : QWidget(parent) {

    rValue = 0;
    gValue = 0;
    bValue = 0;

    colorBox = new QLabel();
        colorBox->setFrameStyle(1);

    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(colorBox);
    setLayout(box);
}


void adjustPalette :: setRvalue(int rV) {
    if(rValue != rV) {
        rValue = rV;
        this->makePalette();
    }
}


void adjustPalette :: setGvalue(int gV) {
    if(gValue != gV) {
        gValue = gV;
        this->makePalette();
    }
}


void adjustPalette :: setBvalue(int bV) {
    if(bValue != bV) {
        bValue = bV;
        this->makePalette();
    }
}

// Error is here!
void adjustPalette :: makePalette() {
    colorBox->setPalette(QPalette(QColor(rValue, gValue, bValue)));
}