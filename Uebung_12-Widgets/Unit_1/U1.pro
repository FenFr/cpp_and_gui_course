TEMPLATE	= app
CONFIG     += qt warn_on
HEADERS	    = 
SOURCES	    = main.cpp
TARGET		= U1
QTDIR_build:REQUIRES="contains(QT_CONFIG, small-config)"

# install
target.path     = Uebung_12-Widgets/Unit_1/U1
sources.files   = $$SOURCES $$HEADERS $$RESOURCES $$FORMS U1.pro
sources.path    = Uebung_12-Widgets/Unit_1/U1
INSTALLS       += target sources
QT             += widgets