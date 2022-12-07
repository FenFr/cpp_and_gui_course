<div align = "center">
      <h1> QT </h1>
      <h3> Meine Zusammenfassung für QT </h3>
</div>


- [Eigene Klassen in QT](#eigene-klassen-in-qt)
  - [Header.h](#headerh)
  - [Header-Code.cpp](#header-codecpp)
- [Sonnstiges](#sonnstiges)
  - [Meta Object Compiler (MOC)](#meta-object-compiler-moc)
  - [Grafische Oberfläche](#grafische-oberfläche)


## Eigene Klassen in QT
### Header.h
Für eigene Klassen in QT muss **IMMER** eine Header-Datei genutzt werden, da *signals* und *slots* nie in einer .cpp Datei deklariert werden können.

```cpp
#ifndef HEADER_H
#define HEADER_H

#include <QWidget>                      // muss immer hier stehen

class QSlider;                          // muss hier stehen, da QSlider genutzt wird
class QPushButton;                      // muss hier stehen, da QPushButton genutzt wird


class MyClass : public QWidget {
    Q_OBJECT                            // muss hier immer stehen

    public:
        MyClass(QWidget *parent = 0);   // typischer Konstruktor

    private:
        QSlider *slider;                // Widgets, die noch benutzt werden
        QPushButton *button;

    public slots:
        int a_slot();                   // ein Slot, um die Klasse mit anderen Widgets, etc. zu connecten
    
    private slots:
        void a_function();              // ein Slot, um innerhalb der Klasse Funktionen durchzuführen

    signals:
        void a_signal();                // ein Signal, um die Klasse mit anderen Widgets, etc. zu connecten
        void valueChanged(int value);   // nicht alle Signale und Slots müssen später beschrieben werden
};

#endif
```
So eine Klasse kann man sich wie einen eigenen Funktionsblock vorstellen. Alle Eingänge (slots) und Ausgänge (signals) dieses Blockes müssen in der Header-Datei deklariert werden. Für die Header-Datei wird noch eine CPP-Datei benötigt, in welcher der Konstruktor und die einzelnen Funktionen beschrieben werden. Wird die Klasse in einer anderen CPP-Datei verwendet, so kann nur mittels der in der .h-Datei deklarierten Funktionen auf die Klasse zugegriffen werden. Da wir Objektorientiert arbeiten, sind alle Widgets in der Klasse privat.

### Header-Code.cpp
Hier sind der Konstruktor und alle Funktionen der oberen header-Datei beschrieben. Dies dient natürlich nur als Beispiel.

```cpp
#include <QWidget>
#include <QSlider>
#include <QLCDNumber>
#include <QPushButton>
#include <QVBoxLayout>

#include "header.h"


MyClass::MyClass(QWidget *parent)
    : QWidget(parent) {
    
    // da slider und button schon im Header definiert wurden, müssen sie hier lediglich so geschrieben werden
    slider = new QSlider(Qt::Horizontal);
    button = new QPushButton(ty("Button"));

    // lcd wurde nich im Header definiert und wird hier erst definiert
    QLCDNumber *lcd = new QLCDNumber(3);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    // "this" bezieht sich auf MyClass
    // der Button-Klick führt die "Funktion" a_function() aus; Achtung, beide Signaturen müssen übereinstimmen!
    connect(button, SIGNAL(clicked()), this, SLOT(a_function()));
    
    // slider reicht sein Signal an das Signal von MyClass weiter
    connect(slider, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(button);
    setLayout(layout);
}


 int MyClass :: a_slot() {
    return slider->value;
}

void MyClass :: a_function() {
    slider->setValue(slider->value() + 1);
}

void MyClass :: a_signal() {
    // something, I'm too lazy rn
}
```



## Sonnstiges

### Meta Object Compiler (MOC)
- Produziert für Klassenobjekt ein Metaobjekt


### Grafische Oberfläche
- Ein Widget besteht aus 14 verschiedenen Farben
- Ein Widget hat 3 Farbpaletten:
  - Im Fokus
  - nicht im Fokus
  - Deaktiviert