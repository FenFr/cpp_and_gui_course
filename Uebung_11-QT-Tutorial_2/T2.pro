TEMPLATE	= app
CONFIG     += qt warn_on
HEADERS	    =
SOURCES	    = main.cpp
TARGET		= T2
QTDIR_build:REQUIRES="contains(QT_CONFIG, small-config)"

# install
target.path     = Uebung_11-QT-Tutorial_2/T2
sources.files   = $$SOURCES $$HEADERS $$RESOURCES $$FORMS T2.pro
sources.path    = Uebung_11-QT-Tutorial_2/T2
INSTALLS       += target sources
QT             += widgets