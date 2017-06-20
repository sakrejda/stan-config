#include <stan/config/argument.hpp>
#include <stan/config/argument_traits.hpp>

namespace stan {
  namespace config {

    class num_samples : stan::config::argument<int, num_samples, integer, positive> {
      public:
        num_samples();
        num_samples(int arg);
        typedef int from;
        const static std::string description;
        const static int default_value;
    };

    num_samples::num_samples() : num_samples::num_samples(num_samples::default_value) {}
    num_samples::num_samples(int arg) : stan::config::argument<int, num_samples, integer, positive>(arg) {}

    const std::string num_samples::description = "Integer (n) describing the number of "
      "samples to generate from the posterior density.  Includes warmup iterations. ";
    const int num_samples::default_value = 1000;

  }
}

