#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <stan/config/argument_traits.hpp>
#include <stan/config/validate.hpp>

TEST(traits, integer) {
  using stan::config::integer;

  int i=3;
  double j=3.3;
  double k=3.0;
  std::string s = "bob";

  EXPECT_TRUE(integer::valid(i));
  EXPECT_TRUE(integer::valid(static_cast<int>(j)));
  EXPECT_TRUE(integer::valid(static_cast<int>(k)));

  EXPECT_FALSE(integer::valid(j));
  EXPECT_FALSE(integer::valid(k));
  EXPECT_FALSE(integer::valid(s));

}



int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int returnValue;
  returnValue = RUN_ALL_TESTS();
  return returnValue;
}

