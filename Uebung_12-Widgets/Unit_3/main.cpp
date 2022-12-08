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

#define MODUS 3


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

    QPushButton *mode = new QPushButton(tr("Mode"));
        mode->setMenu(menu);

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));


switch(MODUS) {
    case 1  :   connect(l_block, SIGNAL(clicked()), l_block, SLOT(LEDon()));
                connect(l_block, SIGNAL(clicked()), m_block, SLOT(LEDoff()));
                connect(l_block, SIGNAL(clicked()), r_block, SLOT(LEDoff()));

                connect(m_block, SIGNAL(clicked()), l_block, SLOT(LEDoff()));
                connect(m_block, SIGNAL(clicked()), m_block, SLOT(LEDon()));
                connect(m_block, SIGNAL(clicked()), r_block, SLOT(LEDoff()));

                connect(r_block, SIGNAL(clicked()), l_block, SLOT(LEDoff()));
                connect(r_block, SIGNAL(clicked()), m_block, SLOT(LEDoff()));
                connect(r_block, SIGNAL(clicked()), r_block, SLOT(LEDon()));
                break;


    case 2  :   l_block->LEDon();
                connect(l_block, SIGNAL(clicked()), l_block, SLOT(initLogic()));
                connect(m_block, SIGNAL(clicked()), l_block, SLOT(initLogic()));
                connect(r_block, SIGNAL(clicked()), l_block, SLOT(initLogic()));

                connect(l_block, SIGNAL(tick()), m_block, SLOT(initLogic()));
                connect(m_block, SIGNAL(tick()), r_block, SLOT(initLogic()));

                connect(l_block, SIGNAL(valueClicked(int)), m_block, SLOT(setValue(int)));
                connect(m_block, SIGNAL(valueClicked(int)), r_block, SLOT(setValue(int)));
                connect(r_block, SIGNAL(valueClicked(int)), l_block, SLOT(setValue(int)));
                break; 


    case 3  :   connect(l_block, SIGNAL(clicked()), r_block, SLOT(binLogic()));
                connect(m_block, SIGNAL(clicked()), r_block, SLOT(binLogic()));
                connect(r_block, SIGNAL(clicked()), r_block, SLOT(binLogic()));

                connect(r_block, SIGNAL(tick()), m_block, SLOT(binLogic()));
                connect(m_block, SIGNAL(tick()), l_block, SLOT(binLogic()));
                break;


    default :   printf("Error: must be case 1, 2 or 3");
                exit(1);
}


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