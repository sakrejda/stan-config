#include <stan/config/argument.hpp>
#include <stan/config/argument_traits.hpp>

namespace stan {
  namespace config {

    class thin : stan::config::argument<thin, integer, positive> {
      public:
        typedef int from;
        const static std::string description;
        const static int default_value;
    };

    const std::string thin::description = "integer (n) describing the number of "
      "values skipped for each values saved.  After each value saved, n-1 "
      "values are skipped.";
    const int thin::default_value = 1;

  }
}

