TEMPLATE	= app
CONFIG     += qt warn_on
HEADERS	    = header.h
SOURCES	    = main.cpp h-code.cpp
TARGET		= U4
QTDIR_build:REQUIRES="contains(QT_CONFIG, small-config)"

# install
target.path     = Uebung_12-Widgets/Unit_4/U4
sources.files   = $$SOURCES $$HEADERS $$RESOURCES $$FORMS U4.pro
sources.path    = Uebung_12-Widgets/Unit_4/U4
INSTALLS       += target sources
QT             += widgets