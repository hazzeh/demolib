# -*- mode:make; tab-width:2; -*-

include $(HEADER)

NAME    := demolib
VERSION := 1.0.0
RELEASE := 1

TARGETS := libdemo.so

_CXXFLAGS += -std=c++11

libdemo.so_SRCS := src/demolib.cpp

include $(FOOTER)
