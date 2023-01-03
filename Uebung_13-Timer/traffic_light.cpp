//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		13
// Task:          		1
// Name:          		traffic_light.cpp
// Description:   		Creates a traffic light and prints its cycles
//////////////////////////////////////////////////////////////////////////////

/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
*/

#include <QBrush>
#include <QPainter>

#include "traffic_light.h"


// TL /////

TL :: TL(QWidget *parent)
    : QWidget(parent) {

    this->phase = 1;
    change_light();
}


void TL :: change_light() {
    
    switch(this->phase) {
        default :   this->phase = 1;

        case  1 :   check_changed_light(1, 0, 0);
                    break;

        case  2 :   check_changed_light(1, 1, 0);
                    break;

        case  3 :   check_changed_light(0, 0, 1);
                    break;

        case  4 :  check_changed_light(0, 1, 0);
                    break;
    }
}


void TL :: check_changed_light(int r, int y, int g) {
    if(color_state[0] != r) {
        emit redChanged    (this->color_state[0] = r);
    }

    if(color_state[1] != y) {
        emit yellowChanged (this->color_state[1] = y);
    }

    if(color_state[2] != g) {
        emit greenChanged  (this->color_state[2] = g);
    }        
}


void TL :: iterate_light() {
    this->phase++;
    change_light();
}

// TCirc /////

TCirc :: TCirc(short int r, short int g, short int b, short int s, QWidget *Parent) {
//    : QWidget(parent) {

    this->rVal   = r;
    this->gVal   = g;
    this->bVal   = b;
    this->status = s;

};


void TCirc :: paintEvent(QPaintEvent *) {  
    QPainter circle(this);
    QColor c_color (this->rVal, this->gVal, this->bVal);
    QBrush c_brush ((status) ? c_color : Qt::white, Qt::SolidPattern);

    circle.setPen(Qt::black);
    circle.setBrush(c_brush);
    circle.drawEllipse(0, 0, 30, 30);
}


void TCirc :: active(int status) {
    if(this->status != status) {
        this->status = status;
        update();
    }
}