#include <stan/config/argument.hpp>

namespace stan {
  namespace config {

    class argument_postivive_int : argument<int> {
      public:
        virtual argument_postivive_int();
        virtual argument_postivive_int(int arg);
        static const std::string description;
        static const T default_value;
        virtual bool is_valid(int value);

      private:
        virtual validate();
    };

    std::string argument_postivive_int::description = "positive integer";
    int argument_postivive_int::default_value = 0;
  }
}

