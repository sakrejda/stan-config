
namespace stan {
  namespace config {

    template <typename T> bool validate (T x) {
      return true;
    }
    
    template <typename C, typename... CC, typename T> bool validate(T x) {
      return C::valid(x) && validate<CC...>(x);
    }

  }
}


