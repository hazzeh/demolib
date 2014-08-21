# -*- mode:make; tab-width:2; -*-

include $(HEADER)

NAME    := demolib
VERSION := 1.0.0
RELEASE := 1

TARGETS := libdemo.so

libdemo.so_SRCS := src/demolib.cpp

SUBMODULES := gtest

include $(FOOTER)
