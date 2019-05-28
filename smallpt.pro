#QT modules used
QT -= core opengl gui
QT +=opengl
#name of the executable
TARGET=smallpt

# as I want to support 4.8 and 5 this will set a flag for some of the mac stuff
# mainly in the types.h file for the setMacVisual which is native in Qt5
isEqual(QT_MAJOR_VERSION, 5) {
cache()
DEFINES +=QT5BUILD
}
#moc dir (.moc for hidden moc directory)
#MOC_DIR= moc

#no app_bundle on mac
CONFIG-=app_bundle
CONFIG+=c++11

#for executable
DESTDIR=./
OBJECTS_DIR=obj

#include all source and header files
SOURCES=$$PWD/src/*.cpp
HEADERS =$$PWD/include/*.h

#console app 
CONFIG += console

INCLUDEPATH +=$$PWD/include
INCLUDEPATH +=$$PWD/lib/pcg32
INCLUDEPATH +=$$PWD/lib/Eigen
INCLUDEPATH +=$$PWD/lib/lodepng
DEPENDPATH += $${INCLUDEPATH}


#compiler flags for different platforms
QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
macx:INCLUDEPATH+=/usr/local/boost/
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native
#openmp
QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS +=  -fopenmp


LIBS+=-L/usr/local/lib -lglfw3

macx:INCLUDEPATH+=/usr/local/include
LIBS += -L/usr/local/lib
macx:LIBS+= -framework OpenGL -framework IOKit -framework Cocoa -framework CoreVideo
linux:LIBS+= -lGL -lX11 -lXxf86vm -lXrandr -lXi -ldl -lXinerama -lXcursor -lglfw3 -lGLEW -lpthread
macx:QMAKE_MAC_SDK = macosx10.12

#NGL path : no longer used as Eigen is being used instead
INCLUDEPATH += $$(HOME)/NGL/include/









