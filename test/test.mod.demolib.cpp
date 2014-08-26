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


TEST_F(Test, Equal) {
  EXPECT_STREQ("Do. Or do not. There is no try!"   , getMessage(10));
  EXPECT_STREQ("Judge me by my size, do you?"      , getMessage(20));
  EXPECT_STREQ("Fear is the path to the dark side" , getMessage(30));
  EXPECT_STREQ("Wars not make one great"           , getMessage(40));
}


TEST_F(Test, NotEmpty) {
  EXPECT_STRNE("" , getMessage(10));
  EXPECT_STRNE("" , getMessage(20));
  EXPECT_STRNE("" , getMessage(30));
  EXPECT_STRNE("" , getMessage(40));
}


TEST_F(Test, DefaultReturn) {
  EXPECT_STREQ("That is why you fail", getMessage(21));
  EXPECT_STREQ("That is why you fail", getMessage(35));
  EXPECT_STREQ("That is why you fail", getMessage(50));
  EXPECT_STREQ("That is why you fail", getMessage(99));
}


TEST_F(Test, Quoted) {
  EXPECT_STREQ("judge_me_by_my_size_do_you" , getMessageQuoted(20));
  EXPECT_STREQ("that_is_why_you_fail"       , getMessageQuoted(51));
}


TEST_F(Test, Repetition) {
  auto msg1 = getMessage(10);
  auto msg2 = getMessage(10);
  auto msg3 = getMessage(99);
  auto msg4 = getMessage(99);

  EXPECT_EQ(msg1, msg2)
      << "Consecutive for the same message should return equal messages";

  EXPECT_EQ(msg3, msg4)
      << "Consecutive for the same message should return equal messages";
}


} //  namespace end


int
main(int ac, char** av) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
