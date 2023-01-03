//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		13
// Task:          		1
// Name:          		main.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <QApplication>
#include <QPaintDevice>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPalette>
#include <QWidget>
#include <QLayout>
#include <QTimer>

#include "traffic_light.h"


class MyWidget : public QWidget {
    public:
        MyWidget(QWidget *parent = 0);
};


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) {

    QWidget *window   = new QWidget;

    QPushButton *quit = new QPushButton("Quit");
    QPushButton *itt  = new QPushButton("Iterate");
    QTimer *timer     = new QTimer(this);

    TL    *light_calc   = new TL();
    TCirc *red_light    = new TCirc(134,  26,  34, 1);
    TCirc *yellow_light = new TCirc(249, 168,   0, 0);
    TCirc *green_light  = new TCirc( 50,  89,  40, 0);

    connect(quit,  SIGNAL(clicked()), qApp,  SLOT(quit()));
    connect(itt,   SIGNAL(clicked()), light_calc, SLOT(iterate_light()));
    connect(timer, SIGNAL(timeout()), light_calc, SLOT(iterate_light()));

    connect(light_calc, SIGNAL(redChanged(int))   , red_light   , SLOT(active(int)));
    connect(light_calc, SIGNAL(yellowChanged(int)), yellow_light, SLOT(active(int)));
    connect(light_calc, SIGNAL(greenChanged(int)) , green_light , SLOT(active(int)));

    timer->start(1000);

    QVBoxLayout *box = new QVBoxLayout;
    box->addWidget(quit);
    box->addWidget(itt);
    box->addWidget(red_light);
    box->addWidget(yellow_light);
    box->addWidget(green_light);
    
    window->setLayout(box);
    window->setMinimumSize(100, 200);
    window->show();

}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    QApplication app(argc, argv);

    MyWidget widget;
    //widget.show();

    return app.exec();
}

// MAIN END //////////////////////////////////////////////////////////////////