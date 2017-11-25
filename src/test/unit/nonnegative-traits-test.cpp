#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <stan/config/argument_traits.hpp>
#include <stan/config/validate.hpp>


TEST(traits, nonnegative) {
  using stan::config::nonnegative;

  int i=0;
  double j=0.0;

  EXPECT_TRUE(nonnegative::valid(i));
  EXPECT_TRUE(nonnegative::valid(j));

  i=1;
  j=1.2;

  EXPECT_TRUE(nonnegative::valid(i));
  EXPECT_TRUE(nonnegative::valid(j));

  i=-1;
  j=-1.2;

  EXPECT_FALSE(nonnegative::valid(i));
  EXPECT_FALSE(nonnegative::valid(j));

  std::string s="bob";
  EXPECT_FALSE(nonnegative::valid(s));
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int returnValue;
  returnValue = RUN_ALL_TESTS();
  return returnValue;
}

