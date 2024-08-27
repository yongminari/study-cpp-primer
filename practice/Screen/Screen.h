#ifndef SCREEN_H
#define SCREEN_H

#include <ostream>
#include <string>
#include <strstream>
class Screen {
  friend class Window_mgr;

public:
  using pos = std::string::size_type;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);

  Screen &display(std::ostrstream &os) {
    do_display(os);
    return *this;
  }

  const Screen &display(std::ostream &os) {
    do_display(os);
    return *this;
  }

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  void do_display(std::ostream &os) const { os << contents; }
};

#endif // !SCREEN_H
