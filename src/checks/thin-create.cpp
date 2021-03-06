
#include <stan/config/arg_thin.hpp>
#include <iostream>
#include <string>
#include <vector>

int main () {

  int i, j, k;

  i = 3; 
  j = 0; 
  k = -5;

  std::cout << "default constructed: " << std::endl;
  stan::config::thin A;
  std::vector<stan::config::thin> v(1);
  v.push_back(A);
  std::cout << "should work: " << std::endl;
  stan::config::thin B(i);
  std::cout << "worked " << std::endl;
  try {
    stan::config::thin C(j);
  } catch (...) {
    std::cout << "should not work, zero: " << std::endl;
  }
  try {
    stan::config::thin D(k);
  } catch (...) {
    std::cout << "should not work, negative: " << std::endl;
  }

  std::cout << "Finished." << std::endl;
  return 0;
}




