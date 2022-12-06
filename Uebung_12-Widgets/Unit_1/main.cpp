//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		1
// Name:          		main.cpp
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
#include <QSpinBox>


class MyWidget : public QWidget {
    public:
        MyWidget(QWidget *parent = 0);
};


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) {
        
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));

    QLCDNumber *lcd = new QLCDNumber(3);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 420);
    slider->setValue(0);

    QSpinBox *spinner = new QSpinBox();
    spinner->setRange(0, 420);


    connect(quit   , SIGNAL(clicked())        , qApp, SLOT(quit()));
    connect(slider , SIGNAL(valueChanged(int)), lcd , SLOT(display(int)));
    connect(spinner, SIGNAL(valueChanged(int)), lcd , SLOT(display(int)));

    connect(slider , SIGNAL(valueChanged(int)), spinner, SLOT(setValue(int)));
    connect(spinner, SIGNAL(valueChanged(int)), slider , SLOT(setValue(int)));


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addWidget(lcd);
    layout->addWidget(slider);
    layout->addWidget(spinner);
    setLayout(layout);
}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();

    return app.exec();
}

// MAIN END //////////////////////////////////////////////////////////////////