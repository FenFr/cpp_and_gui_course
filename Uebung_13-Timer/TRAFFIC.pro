TEMPLATE	= app
CONFIG     += qt warn_on
HEADERS	    = traffic_light.h
SOURCES	    = main.cpp traffic_light.cpp
TARGET		= TRAFFIC
QTDIR_build:REQUIRES="contains(QT_CONFIG, small-config)"

# install
target.path     = Uebung_13-Timer/TRAFFIC
sources.files   = $$SOURCES $$HEADERS $$RESOURCES $$FORMS TRAFFIC.pro
sources.path    = Uebung_13-Timer/TRAFFIC
INSTALLS       += target sources
QT             += widgets