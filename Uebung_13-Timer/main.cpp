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

#include "traffic_light.h"


class MyWidget : public QWidget {
    public:
        MyWidget(QWidget *parent = 0);
};


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) {

    QPushButton *quit = new QPushButton("Quit");

}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    QApplication app(argc, argv);

    MyWidget widget;
    widget.show();

    return app.exec();
}

// MAIN END //////////////////////////////////////////////////////////////////