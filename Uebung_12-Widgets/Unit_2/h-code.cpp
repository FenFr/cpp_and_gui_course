//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		2
// Name:          		h-code.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <QWidget>
#include <QSlider>
#include <QLCDNumber>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>

#include "header.h"


FancySlider::FancySlider(QWidget *parent)
    : QWidget(parent) {
    
    slider               = new QSlider(Qt::Horizontal);
    QPushButton *b_left  = new QPushButton("-");
    QPushButton *b_right = new QPushButton("+");

    connect(b_left,  SIGNAL(clicked()), this, SLOT(decValue()));
    connect(b_right, SIGNAL(clicked()), this, SLOT(incValue()));

    // "this" refers to FancySlider and will be the variable of the type FancySlider in main.cpp
    connect(slider, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(slider,  0, 1);
    layout->addWidget(b_left,  0, 0);
    layout->addWidget(b_right, 0, 2);
    setLayout(layout);
}

// slider must be defined within the header so it can be used here
 void FancySlider :: incValue() {
    slider->setValue(slider->value() + 1);
}

void FancySlider :: decValue() {
    slider->setValue(slider->value() - 1);
}