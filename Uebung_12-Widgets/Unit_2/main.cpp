//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		2
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

// Muss in eine Header-File
class ClickChange : public QWidget {
    Q_OBJECT

    public:
        ClickChange(int ini_val, QWidget *parent = 0);

        int value;

    public slots:

        void setValue( int val_in );
        void incValue( void );
        void decValue( void );

    signals:
        int newValue( void );
};


ClickChange::ClickChange(int ini_val, QWidget *parent)
    : QWidget(parent) {
    this->value = ini_val;
}

void ClickChange::setValue(int val_in) {
    this->value = val_in;
}

void ClickChange::incValue( void ) {
    this->value++;
}

void ClickChange::decValue( void ) {
    this->value--;
}

int ClickChange::newValue( void ) {
    return this->value;
}



class MyWidget : public QWidget {
    public:
        MyWidget(QWidget *parent = 0);
};


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) {

    setFixedSize(400,200);

    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));

    QLCDNumber *lcd = new QLCDNumber(3);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->display(10);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 420);
    slider->setValue(10);

    QPushButton *b_left  = new QPushButton("-");

    QPushButton *b_right = new QPushButton("+");

    ClickChange *val = new ClickChange(10);

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    connect(slider, SIGNAL(valueChanged(int)), val , SLOT(setValue(int)));
    connect(val   , SIGNAL(newValue())       , lcd , SLOT(setValue(int)));
/*
    connect(slider , SIGNAL(valueChanged(int)), lcd , SLOT(display(int)));
    connect(b_left , SIGNAL(clicked())        , lcd , SLOT(setValue(int)));
    connect(b_right, SIGNAL(clicked())        , lcd , SLOT(setValue(int)));
*/
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addWidget(lcd);
    layout->addWidget(slider);
    layout->addWidget(b_left);
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