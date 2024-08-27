#include "Window_mgr.h"
#include <string>

using std::string;

void Window_mgr::clear(ScreenIdx i) {
  Screen &s = screens[i];
  s.contents = string(s.height * s.width, ' ');
}
