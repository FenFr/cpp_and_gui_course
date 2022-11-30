//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		10
// Task:          		1
// Name:          		main.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    QApplication app(argc, argv);

    QWidget window;
    window.resize(200, 120);

    QPushButton quit("Quit", &window);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    quit.setGeometry(10, 40, 180, 40);
    quit.setVisible(false);

    QPushButton hello("Hello world!", &window);
    hello.setFont(QFont("Times", 18, QFont::Bold));
    hello.setGeometry(10, 40, 180, 40);

    QObject::connect(&hello, SIGNAL(clicked()), &quit,  SLOT(show()));
    QObject::connect(&hello, SIGNAL(clicked()), &hello, SLOT(hide()));
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    window.show();
    return app.exec();


}

// MAIN END //////////////////////////////////////////////////////////////////