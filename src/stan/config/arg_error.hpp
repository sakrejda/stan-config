#include <exception>

namespace stan {
  namespace config {

    template <typename T> class invalid_argument : public std::exception {
      public: 
        invalid_argument(typename T::from value);
        typename T::from value_;
        const std::string description_ = T::description;
    };

    template <typename T> 
    invalid_argument<T>::invalid_argument(typename T::from value) {
      value_ = value;
    }

  }
}


