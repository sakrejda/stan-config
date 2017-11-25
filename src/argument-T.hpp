#include <string>
#include <argument_traits.hpp>

namespace stan {
  namespace config {

    template <typename T, typename... VV, typename N>
    class argument {
      public:
        argument();
        argument(T arg);
        argument(const char* arg);
        bool is_valid(T value);
        static const std::string name;
        static const std::string description;
        static const T default_value;

      private:
        cast(const char*) = 0;
        T value;
    };

    template <typename T, typename... VV, typename N> argument(T arg) : 
      value(arg) {
        if(!validate<VV...>(value)) throw;
      }

    template <typename T, typename... VV, typename N> argument(const char* arg) :
      value(boost::lexical_cast<T>(arg)) {
        if(!validate<VV...>(value)) throw;
      }

    template <typename T, typename... VV, typename N> name = N::name;
    template <typename T, typename... VV, typename N> std::string argument<T>::description = N::description;
    template <typename T, typename... VV, typename N> T argument<T>::default_value = N::default_value;
  }
}

// Implementing an argument means creating a struct for N, 


