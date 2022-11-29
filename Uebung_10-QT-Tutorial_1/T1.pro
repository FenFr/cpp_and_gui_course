TEMPLATE	= app
CONFIG     += qt warn_on
HEADERS	    =
SOURCES	    = main.cpp
TARGET		= T1
QTDIR_build:REQUIRES="contains(QT_CONFIG, small-config)"

# install
target.path     = Uebung_10-QT-Tutorial_1/T1
sources.files   = $$SOURCES $$HEADERS $$RESOURCES $$FORMS t1.pro
sources.path    = Uebung_10-QT-Tutorial_1/T1
INSTALLS       += target sources
QT             += widgets