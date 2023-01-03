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

class QPushButton;
class QLCDNumber;
class QSlider;


class TL : public QWidget {
    Q_OBJECT

    private:
        const char *light;
        short int phase;
        short int color_state[3];   // [0] == red ; [1] == green ; [2] == blue

        void change_light();
        void check_for_changed_color(int r, int g, int b);

    public:
        TL();
        TL(int phase_in);

        void print_light();

    public slots:
        void iterate_light();

    private slots:

    signals:
        void redChanged  (int rState);
        void greenChanged(int gSate);
        void blueChanged (int bSate);
};


#endif