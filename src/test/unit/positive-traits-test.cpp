#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <stan/config/argument_traits.hpp>
#include <stan/config/validate.hpp>


TEST(traits, positive) {
  using stan::config::positive;

  int i=0;
  double j=0.0;

  EXPECT_FALSE(positive::valid(i));
  EXPECT_FALSE(positive::valid(j));

  i=1;
  j=1.2;

  EXPECT_TRUE(positive::valid(i));
  EXPECT_TRUE(positive::valid(j));

  i=-1;
  j=-1.2;

  EXPECT_FALSE(positive::valid(i));
  EXPECT_FALSE(positive::valid(j));
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int returnValue;
  returnValue = RUN_ALL_TESTS();
  return returnValue;
}

/*
int main () {
  using stan::config::validate;
  using stan::config::integer;
  using stan::config::nonnegative;
  using stan::config::positive;
  using stan::config::unit_interval_open;


  // Pass:
  i=0;
  j=0.0;
  std::cout << nonnegative::valid(i) << std::endl;
  std::cout << nonnegative::valid(j) << std::endl;

  // Fail:
  std::cout << positive::valid(i) << std::endl;
  std::cout << positive::valid(j) << std::endl;

  // More better:
  // Pass: 
  std::cout << validate<integer>(-3) << std::endl;
  std::cout << validate<positive, integer>(3) << std::endl;
  std::cout << validate<unit_interval_open>(.3) << std::endl;

  // Fail:
  std::cout << validate<positive, integer>(3.3) << std::endl;
  std::cout << validate<integer, positive>(-3) << std::endl;
  std::cout << validate<unit_interval_open>(3) << std::endl;


  

  std::cout << "Finished." << std::endl;
  return 0;
}



*/
