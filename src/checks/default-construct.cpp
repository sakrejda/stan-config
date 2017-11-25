#include <iostream>
#include <string>

template <typename T> class thing {
  public:
    static T member;
};

template <typename T> T thing<T>::member = T();

int main() {
  std::cout << thing<int>::member << std::endl;
  std::cout << thing<double>::member << std::endl;
  std::cout << thing<std::string>::member << std::endl;

  return 0;
}
