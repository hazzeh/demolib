# -*- mode:make; tab-width:2; -*-

include $(HEADER)

TARGETS := libgtest_local.so

libgtest_local.so_SRCS := src/gtest-all.cc

include $(FOOTER)
