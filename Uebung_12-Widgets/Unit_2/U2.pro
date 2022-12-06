TEMPLATE	= app
CONFIG     += qt warn_on
HEADERS	    =
SOURCES	    = main.cpp
TARGET		= U2
QTDIR_build:REQUIRES="contains(QT_CONFIG, small-config)"

# install
target.path     = Uebung_12-Widgets/Unit_2/U2
sources.files   = $$SOURCES $$HEADERS $$RESOURCES $$FORMS U2.pro
sources.path    = Uebung_12-Widgets/Unit_2/U2
INSTALLS       += target sources
QT             += widgets