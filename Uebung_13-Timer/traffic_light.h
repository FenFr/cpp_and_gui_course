//////////////////////////////////////////////////////////////////////////////
// Course:	  			C++ / GUI
// Lecturer:      		Prof. Dr.-Ing. habil. Ralf Salomon
// Exercise instructor: M.Sc. Theo Gabloffsky
// Author:              Fenya Freitag
// Exercise:      		13
// Task:          		1
// Name:          		traffic_light.h
// Description:   		header for traffic light
//////////////////////////////////////////////////////////////////////////////


#ifndef HEADER_H
#define HEADER_H

#include <QWidget> 

class QColor;


class TL : public QWidget {
    Q_OBJECT

    public:
        TL(QWidget *parent = 0);

    private:
        const char *light;
        short int phase;
        short int color_state[3];   // [0] == red ; [1] == yellow ; [2] == green

        void change_light();
        void check_changed_light(int r, int y, int g);

    public slots:
        void iterate_light();

    private slots:

    signals:
        void redChanged   (int rState);
        void yellowChanged(int ySate);
        void greenChanged (int gSate);
};



class TCirc : public QWidget {
    Q_OBJECT

    public:
        TCirc(short int r, short int g, short int b, short int s, QWidget *Parent = 0);

    private:
        short int rVal, gVal, bVal, status;

    protected:
        void paintEvent(QPaintEvent *event);

    public slots:
        void active(int status);

    signals:
};

#endif