TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11

QMAKE_CXXFLAGS += -std=c++11 -fprofile-arcs -ftest-coverage -O0

SUBDIRS = app tests

CONFIG += ordered
