#include <stan/config/argument_int.hpp>

namespace stan {
  namespace config {

    class argument_nonnegative_int : argument_int {
      public:
        virtual argument() = 0;
        virtual validate() = 0;
        static const std::string description;
        virtual default_value() = 0;
        virtual bool is_valid(int value) = 0;
    };

    argument<int>::description = "integer number";
  }
}


