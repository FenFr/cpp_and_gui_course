//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		11
// Task:          		1
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
    
    QPushButton *quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(62, 40, 75, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    QApplication app(argc, argv);

    MyWidget widget;
    widget.show();

    return app.exec();
}

// MAIN END //////////////////////////////////////////////////////////////////