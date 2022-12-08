//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		12
// Task:          		4
// Name:          		header.h
// Description:   		
//////////////////////////////////////////////////////////////////////////////


#ifndef HEADER_H
#define HEADER_H

#include <QWidget> 


class QPushButton;
class QLCDNumber;
class QSlider;
class QLabel;


class cSlider : public QWidget {
    Q_OBJECT

    public:
        cSlider(char *name, QWidget *parent = 0);

    private:
        QPushButton *button;
        QLCDNumber *lcd;
        QSlider *slider;

    signals:
        void colorValue(int cValue);

    public slots:
        int value();

    private slots:
        void pushButton();
};


class adjustPalette : public QWidget {
    Q_OBJECT

    public:
        adjustPalette(QWidget *parent = 0);

    private:
        int rValue, gValue, bValue;
        QLabel *colorBox;

    signals:

    public slots:
        void setRvalue(int rV);
        void setGvalue(int gV);
        void setBvalue(int bV);

    private slots:
        void makePalette();
};

#endif