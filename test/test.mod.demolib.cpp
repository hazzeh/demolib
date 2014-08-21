// -*- mode:c++; indent-tabs-mode:nil; -*-

#include <gtest/gtest.h>

#include "demolib.h"

namespace Test {

class TestClass : public testing::Test {
 protected:

  TestClass()
  {
    // Setup things, which will NOT throw.
  }

  virtual ~TestClass()
  {
    // Nothing to remove.
  }

  virtual void SetUp()
  {
    // Setup things, which might throw.
  }

  virtual void TearDown()
  {
    // Remove things setup by SetUp.
  }

};

// Describe test.
TEST_F(TestClass, BasicInterfaceTests) {

  int32_t seed1 = -1;
  int32_t seed2 = 11;
  int32_t seed3 = 99;

  EXPECT_EQ(10,getToken(seed1))
      << "Less than 10 seed should given token == 10";

  EXPECT_EQ(20,getToken(seed2))
      << "Less than 20 seed should given token == 20";

  EXPECT_EQ(99,getToken(seed3))
      << "Larger than 20 shall return token == seed";
}

} //  namespace end


int
main(int ac, char** av)
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
