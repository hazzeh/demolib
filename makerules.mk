# -*- mode:make; tab-width:2; -*-

# Temporary home variable for Bob to find Java
JAVA_HOME ?= /usr/lib/jvm/java-7-openjdk-amd64

include $(HEADER)

# --------------------------------------------------
NAME     := demolib
VERSION  := 1.0.0
RELEASE  := 1
REQUIRES := java
$(call setup)
# --------------------------------------------------

_CXXFLAGS := -std=c++11 -pedantic
_CFLAGS   := -std=c11 -pedantic

SUBMODULES := gtest

TARGETS := libdemo.so

libdemo.so_SRCS := src/demolib.cpp src/DemoLib.c
libdemo.so_USES := java

ifdef __bobBUILDSTAGE
jni: $(OBJDIR)
	javac -d $(OBJDIR) java/DemoLib.java
	javah -d src -classpath $(OBJDIR) DemoLib

jni-test: jni libdemo.so
	java -cp $(OBJDIR) -Djava.library.path=$(TGTDIR) DemoLib
endif

include $(FOOTER)
