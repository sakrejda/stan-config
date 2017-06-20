#include <stan/config/argument.hpp>
#include <stan/config/argument_traits.hpp>

namespace stan {
  namespace config {

    class num_warmup : stan::config::argument<int, num_warmup, integer, positive> {
      public:
        num_warmup();
        num_warmup(int arg);
        typedef int from;
        const static std::string description;
        const static int default_value;
    };

    num_warmup::num_warmup() : num_warmup::num_warmup(num_warmup::default_value) {}
    num_warmup::num_warmup(int arg) : stan::config::argument<int, num_warmup, integer, positive>(arg) {}

    const std::string num_warmup::description = "Integer (n) describing the number of "
      "warmup iterations to generate from the posterior density. ";
    const int num_warmup::default_value = 1000;

  }
}

