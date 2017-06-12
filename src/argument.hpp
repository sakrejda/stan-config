#include <string>

namespace stan {
  namespace config {

    template <typename T>
    class argument {
      public:
        virtual argument() = 0;
        virtual argument(T arg) = 0;
        static const std::string description;
        static const T;
        virtual default_value() = 0;
        static bool is_valid(T value) = 0;

      private:
        virtual validate() = 0;
    };

    template <typename T> std::string argument<T>::description = "";
    template <typename T> T argument<T>::default_value = T();
  }
}



