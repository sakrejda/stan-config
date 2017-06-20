#include <stan/config/argument.hpp>
#include <stan/config/argument_traits.hpp>

namespace stan {
  namespace config {
    class adapt {}

    class save_warmup : stan::config::argument<bool, save_warmup, boolean> {
      public:
        save_warmup();
        save_warmup(int arg);
        typedef bool from;
        const static std::string description;
        const static int default_value;
    };

    save_warmup::save_warmup() : save_warmup::save_warmup(save_warmup::default_value) {}
    save_warmup::save_warmup(int arg) : stan::config::argument<int, save_warmup, boolean>(arg) {}

    const std::string save_warmup::description = "Boolean value indicating whether warmup iterations "
      "should be recorded in output.";
    const int save_warmup::default_value = false;

  }
}

