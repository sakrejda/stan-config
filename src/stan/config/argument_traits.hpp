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

    struct boolean {
      template <typename T> static bool valid(T x);
    };

    template <typename T> 
    bool boolean::valid(T x) {
      return false;
    }

    template <> 
    bool boolean::valid<bool>(bool x) {
      return true;
    }

    struct nonnegative {
      template <typename T> static bool valid(T x);
    };

    template <typename T>
    bool nonnegative::valid(T x) {
      return x >= 0;
    }

    template <>
    bool nonnegative::valid<std::string>(std::string x) {
      return false;
    }

    struct positive {
      template <typename T> static bool valid(T x);
    };

    template <typename T>
    bool positive::valid(T x) {
      return x > 0;
    }

    template <>
    bool positive::valid<std::string>(std::string x) {
      return false;
    }

    struct unit_interval_open {
      template <typename T> static bool valid(T x);
    };

    template <typename T>
    bool unit_interval_open::valid(T x) {
      return x >= 0 && x <= 1;
    }

    template <>
    bool unit_interval_open::valid<std::string>(std::string x) {
      return false;
    }

  }
}


