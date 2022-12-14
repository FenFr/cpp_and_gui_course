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
#include <QPainter>
#include <QLCDNumber>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPaintDevice>

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



colorDemo :: colorDemo(QWidget *parent)
    : QWidget(parent) {
    rValue = 0;
    gValue = 0;
    bValue = 0;
}


void colorDemo::paintEvent(QPaintEvent *) {  
    QPainter painter(this);
    QColor color(rValue, gValue, bValue);
    QRectF rectangle(0, 0, 500, 20);

    painter.setPen(Qt::NoPen);
    painter.fillRect(rectangle, color);
}


void colorDemo :: setRvalue(int rV) {
    if(rValue != rV) {
        rValue = rV;
        update();
    }
}


void colorDemo :: setGvalue(int gV) {
    if(gValue != gV) {
        gValue = gV;
        update();
    }
}


void colorDemo :: setBvalue(int bV) {
    if(bValue != bV) {
        bValue = bV;
        update();
    }
}