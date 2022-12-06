TEMPLATE	= app
CONFIG     += qt warn_on
HEADERS	    =
SOURCES	    = main.cpp
TARGET		= U3
QTDIR_build:REQUIRES="contains(QT_CONFIG, small-config)"

# install
target.path     = Uebung_12-Widgets/Unit_3/U3
sources.files   = $$SOURCES $$HEADERS $$RESOURCES $$FORMS U3.pro
sources.path    = Uebung_12-Widgets/Unit_3/U3
INSTALLS       += target sources
QT             += widgets