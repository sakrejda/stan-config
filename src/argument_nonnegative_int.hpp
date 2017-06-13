#include <stan/config/argument.hpp>

namespace stan {
  namespace config {

    class argument_nonnegative_int : argument<int> {
      public:
        virtual argument_nonnegative_int();
        virtual argument_nonnegative_int(int arg);
        static const std::string description;
        static const T default_value;
        virtual bool is_valid(int value);

      private:
        int value;
    };

    std::string argument_nonnegative_int::description = "non-negative integer";
    int argument_nonnegative_int::default_value = 0;
  }
}


