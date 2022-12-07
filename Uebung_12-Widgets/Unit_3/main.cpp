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
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QMenu>
#include <QFont>

#include "header.h"


class MyWidget : public QWidget {
    public:
        MyWidget(QWidget *parent = 0);
};


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) {
    
    LEDBlock *l_block = new LEDBlock();
    LEDBlock *m_block = new LEDBlock();
    LEDBlock *r_block = new LEDBlock();

    QPushButton *quit = new QPushButton(tr("Quit"));
    
    QMenu *menu = new QMenu(); 
        menu->addAction("Mode 1");
        menu->addAction("Mode 2");
        menu->addAction("Mode 3");

    QPushButton *mode = new QPushButton(tr("Mode 1"));
        mode->setMenu(menu);

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    
    connect(l_block, SIGNAL(clicked()), m_block, SLOT(LEDoff()));
    connect(l_block, SIGNAL(clicked()), r_block, SLOT(LEDoff()));

    connect(m_block, SIGNAL(clicked()), l_block, SLOT(LEDoff()));
    connect(m_block, SIGNAL(clicked()), r_block, SLOT(LEDoff()));

    connect(r_block, SIGNAL(clicked()), l_block, SLOT(LEDoff()));
    connect(r_block, SIGNAL(clicked()), m_block, SLOT(LEDoff()));

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(mode,    0, 0);
    grid->addWidget(quit,    0, 2);
    grid->addWidget(l_block, 1, 0);
    grid->addWidget(m_block, 1, 1);
    grid->addWidget(r_block, 1, 2);
    setLayout(grid);
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char**argv) {

    QApplication app(argc, argv);

    MyWidget widget;
    widget.show();

    return app.exec();
}

// MAIN END //////////////////////////////////////////////////////////////////