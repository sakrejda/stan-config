#include "../src/argument_traits.hpp"
#include <iostream>
#include <string>


int main () {
  using stan::config::integer;
  using stan::config::nonnegative;
  using stan::config::positive;

  int i=3;
  double j=3.3;
  double k=3.0;

  // Pass:
  std::cout << integer::valid(i) << std::endl;
  std::cout << integer::valid(static_cast<int>(j)) << std::endl;
  std::cout << integer::valid(static_cast<int>(k)) << std::endl;

  // Fail:
  std::cout << integer::valid(j) << std::endl;
  std::cout << integer::valid(k) << std::endl;

  // Pass:
  i=0;
  j=0.0;
  std::cout << nonnegative::valid(i) << std::endl;
  std::cout << nonnegative::valid(j) << std::endl;

  // Fail:
  std::cout << positive::valid(i) << std::endl;
  std::cout << positive::valid(j) << std::endl;

  // Pass: 
  std::cout << validate<int, positive>(3) << std::endl;
  std::cout << validate<int, positive, integer>(3) << std::endl;
  std::cout << validate<positive, integer>(3.3) << std::endl;
  std::cout << validate<integer, positive>(-3) << std::endl;

  std::cout << "Finished." << std::endl;
  return 0;
}




