#include <limits>

namespace stan {
  namespace config {

    struct integer {
      template <typename T> static bool valid(T x);
    };

    template <typename T> 
    bool integer::valid(T x) {
      return false;
    }

    template <> 
    bool integer::valid<int>(int x) {
      return true;
    }

    struct nonnegative {
      template <typename T> static bool valid(T x);
    };

    template <typename T>
    bool nonnegative::valid(T x) {
      return x >= 0;
    }

    struct positive {
      template <typename T> static bool valid(T x);
    };

    template <typename T>
    bool positive::valid(T x) {
      return x > 0;
    }

    struct unit_interval_open {
      template <typename T> static bool valid(T x);
    };

    template <typename T>
    bool unit_interval_open::valid(T x) {
      return x > 0 && x < 1;
    }

    struct unit_interval_close {
      template <typename T> static bool valid(T x);
    };

    template <typename T>
    bool unit_interval_close::valid(T x) {
      return x >= 0 && x <= 1;
    }

  }
}


template <typename T> bool validate (T x) {
  return true;
}

template <typename C, typename... CC, typename T> bool validate(T x) {
  return C::valid(x) && validate<CC...>(x);
}


