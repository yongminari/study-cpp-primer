#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
using std::boolalpha;
using std::cout;
using std::endl;

int main() {
  cout << true << " " << false << endl;
  cout << boolalpha << true << " " << false << endl;

  cout << std::showbase;
  cout << "default: " << 20 << " " << 1024 << endl;
  cout << "octal: " << std::oct << 20 << " " << 1024 << endl;
  cout << "hex: " << std::hex << 20 << " " << 1024 << endl;
  cout << "decimal: " << std::dec << 20 << " " << 1024 << endl;
  cout << std::noshowbase;

  cout << "default format: " << 100 * std::sqrt(2.0) << '\n'
       << "scientific: " << std::scientific << 100 * std::sqrt(2.0) << '\n'
       << "fixed decimal " << std::fixed << 100 * std::sqrt(2.0) << '\n'
       << "hexadecimal: " << std::hexfloat << 100 * std::sqrt(2.0) << '\n'
       << "use defaults: " << std::defaultfloat << 100 * std::sqrt(2.0)
       << "\n\n";

  int i = -16;
  double d = 3.14159;
  cout << "i: " << std::setw(12) << i << "next col" << '\n'
       << "d: " << std::setw(12) << d << "next col" << '\n';
  cout << std::left << "i: " << std::setw(12) << i << "next col" << '\n'
       << "d: " << std::setw(12) << d << "next col" << '\n';
  cout << std::right << "i: " << std::setw(12) << i << "next col" << '\n'
       << "d: " << std::setw(12) << d << "next col" << '\n';
  cout << std::internal << "i: " << std::setw(12) << i << "next col" << '\n'
       << "d: " << std::setw(12) << d << "next col" << '\n';
  cout << std::setfill('#') << "i: " << std::setw(12) << i << "next col" << '\n'
       << "d: " << std::setw(12) << d << "next col" << '\n';

  return 0;
}
