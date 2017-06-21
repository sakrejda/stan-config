#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <stan/config/argument_traits.hpp>
#include <stan/config/validate.hpp>

TEST(validate, positive-integer) {
  using stan::config::validate;
  using stan::config::positive
  using stan::config::integer;

  EXPECT_TRUE(validate<positive, integer>(3));
  EXPECT_FALSE(validate<positive, integer>(0));
  EXPECT_FALSE(validate<positive, integer>(3.3));
  EXPECT_FALSE(validate<positive, integer>(-3.3));

}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int returnValue;
  returnValue = RUN_ALL_TESTS();
  return returnValue;
}

