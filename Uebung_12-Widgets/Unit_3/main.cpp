//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		3
// Name:          		main.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>


class MyWidget : public QWidget {
    public:
        MyWidget(QWidget *parent = 0);
};


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) {
    
    
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    QApplication app(argc, argv);



    return app.exec();
}

// MAIN END //////////////////////////////////////////////////////////////////