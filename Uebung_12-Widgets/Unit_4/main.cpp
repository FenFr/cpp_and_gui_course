//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		4
// Name:          		main.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <QApplication>
#include <QPaintDevice>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPalette>
#include <QWidget>
#include <vector>

#include "header.h"


class MyWidget : public QWidget {
    public:
        MyWidget(QWidget *parent = 0);
};


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) {

    QPushButton *quit = new QPushButton("Quit");
    
    cSlider *rSlider = new cSlider("R");
    cSlider *gSlider = new cSlider("G");
    cSlider *bSlider = new cSlider("B");

    colorDemo *palette = new colorDemo();

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    connect(rSlider, SIGNAL(colorValue(int)), palette, SLOT(setRvalue(int)));
    connect(gSlider, SIGNAL(colorValue(int)), palette, SLOT(setGvalue(int)));
    connect(bSlider, SIGNAL(colorValue(int)), palette, SLOT(setBvalue(int)));

    QVBoxLayout *box = new QVBoxLayout;
    box->addWidget(quit);
    box->addWidget(rSlider);
    box->addWidget(gSlider);
    box->addWidget(bSlider);
    box->addWidget(palette);
    setLayout(box);
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    QApplication app(argc, argv);

    MyWidget widget;
    widget.show();

    return app.exec();
}

// MAIN END //////////////////////////////////////////////////////////////////