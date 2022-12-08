//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		3
// Name:          		header.h
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#ifndef HEADER_H
#define HEADER_H

#include <QWidget>

class QPushButton;
class QLCDNumber;


class LEDBlock : public QWidget {
    Q_OBJECT

    public:
        LEDBlock(QWidget *parent = 0);

    private:
        int LEDstate = 0;
        QLCDNumber  *lcd;
        QPushButton *button;

    public slots:
        void LEDon();
        void LEDoff();
        void setValue(int value);
        void initLogic();
        void binLogic();

    private slots:
        
    signals:
        void clicked();
        void tick();
        void valueChanged(int newValue);
        void valueClicked(int value);
};

#endif