#include <string>
#include <stan/config/validate.hpp>

namespace stan {
  namespace config {

    template <typename T, typename... C>
    class argument {
      public:

        argument();
        argument(typename T::from arg);
        static bool is_valid(typename T::from value);

      private:
        void validate();
        typename T::from value;
    };

    template <typename T, typename... C> 
    argument<T, C...>::argument() : argument<T, C...>::argument(T::default_value) {}

    template <typename T, typename... C>
    argument<T, C...>::argument(typename T::from arg) {
      value = arg;
      validate();
    }

    template <typename T, typename... C>
    bool argument<T, C...>::is_valid(typename T::from value) {
      return stan::config::validate<C...>(value);
    }

    template <typename T, typename... C>
    void argument<T, C...>::validate() {
      bool valid = is_valid(value);
      if (!valid)
        false;
        // throw stan::config::invalid_value(value, T::description);
    }
  }
}



