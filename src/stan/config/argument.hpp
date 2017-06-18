#include <string>
#include <exception>
#include <stan/config/validate.hpp>


namespace stan {
  namespace config {

    template <typename S, typename T, typename... C>
    class argument {
      public:

        argument();
        argument(S arg);
        static bool is_valid(S value);

      protected:
        void validate();
        S value;
    };

    template <typename S, typename T, typename... C> 
    argument<S, T, C...>::argument() : argument<S, T, C...>::argument(T::default_value) {}

    template <typename S, typename T, typename... C>
    argument<S, T, C...>::argument(S arg) {
      value = arg;
      validate();
    }

    template <typename S, typename T, typename... C>
    bool argument<S, T, C...>::is_valid(S value) {
      return stan::config::validate<C...>(value);
    }

    template <typename S, typename T, typename... C>
    void argument<S, T, C...>::validate() {
      bool valid = is_valid(value);
      if (!valid) {
        throw;
        //throw stan::config::invalid_value(value, T::description);
      }
    }
  }
}



