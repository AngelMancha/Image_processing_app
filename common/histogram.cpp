#include "histogram.hpp"
#include <fstream>

namespace images::common {

  void histogram::add_color(pixel p) noexcept {
    #pragma omp atomic
    channels[red_channel][p.red()]++;
    #pragma omp atomic
    channels[green_channel][p.green()]++;
    #pragma omp atomic
    channels[blue_channel][p.blue()]++;
  }

  void histogram::write(std::ostream & os) const noexcept {
    for (const auto x: channels[red_channel]) {
      os << x << '\n';
    }
    for (const auto x: channels[green_channel]) {
      os << x << '\n';
    }
    for (const auto x: channels[blue_channel]) {
      os << x << '\n';
    }
  }

}
