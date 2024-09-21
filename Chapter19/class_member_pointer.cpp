#include <string>

class Screen {
  friend void prvAccess();

public:
  using pos = std::string::size_type;
  char get_cursor() const { return contents[cursor]; }
  char get() const;
  char get(pos ht, pos wd) const;

private:
  std::string contents;
  pos cursor;
  pos height, width;
};

void prvAccess() {
  Screen scr;
  std::string Screen::*pdata = &Screen::contents;

  auto pdata2 = &Screen::contents;
  decltype(&Screen::contents) pdata3 = &Screen::contents;

  void(scr.*pdata);
}

void classMemberPointer() {
  char (Screen::*func)() const = &Screen::get;
  char (Screen::*func2)(Screen::pos, Screen::pos) const = &Screen::get;

  Screen scr;
  (scr.*func)();
  (scr.*func2)(0, 0);
}

int main() { return 0; }
