// -*- mode:c++; indent-tabs-mode:nil; -*-

#include <gtest/gtest.h>

#include "demolib.h"

namespace Test {

class Test : public testing::Test {
 protected:
  Test() {}
  virtual ~Test() {}
  virtual void SetUp() {}
  virtual void TearDown() {}
};


TEST_F(Test, TokenValues) {
  EXPECT_EQ(10,getToken(-1))
      << "Less than 10 seed should give token == 10";
  EXPECT_EQ(20,getToken(11))
      << "Less than 20 seed should give token == 20";
  EXPECT_EQ(50,getToken(99))
      << "Greater than 50 should give token == 50";
  EXPECT_EQ(30,getToken(30))
      << "[20,50] should give token == seed";
}


TEST_F(Test, NotEmpty) {
  EXPECT_STRNE("", getMessage(10));
  EXPECT_STRNE("", getMessage(20));
  EXPECT_STRNE("", getMessage(30));
  EXPECT_STRNE("", getMessage(40));
  EXPECT_STRNE("", getMessage(50));
}


TEST_F(Test, DefaultReturn) {
  EXPECT_STREQ("That is why you fail", getMessage(12));
  EXPECT_STREQ("That is why you fail", getMessage(21));
  EXPECT_STREQ("That is why you fail", getMessage(35));
  EXPECT_STREQ("That is why you fail", getMessage(50));
  EXPECT_STREQ("That is why you fail", getMessage(99));
}


TEST_F(Test, Quoted) {
  std::string msg1 = getMessageQuoted(1);
  EXPECT_EQ(std::string::npos, msg1.find(" "));
  EXPECT_EQ(std::string::npos, msg1.find("."));
  EXPECT_EQ(std::string::npos, msg1.find(","));
  EXPECT_EQ(std::string::npos, msg1.find("!"));
  EXPECT_EQ(std::string::npos, msg1.find("?"));
}


} //  namespace end


int
main(int ac, char** av) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
