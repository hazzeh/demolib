# -*- mode:make; tab-width:2; -*-

include $(HEADER)

TARGETS := test.mod.demolib

_LIBS := -Wl,-rpath="\$$$$ORIGIN" -Wl,-z,origin

test.mod.demolib_SRCS := test.mod.demolib.cpp
test.mod.demolib_LINK := demo gtest_local pthread

include $(FOOTER)
