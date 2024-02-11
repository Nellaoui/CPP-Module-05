#include <iostream>       // std::cerr
#include <typeinfo>       // operator typeid
#include <exception>      // std::exception

class Polymorphic { virtual void member(){} };

int main () {
  try
  {
    Polymorphic* pb = 0;
    const std::type_info& typeInfo = typeid(*pb);  // store the result in a reference
    // or
    static_cast<void>(typeid(*pb));  // explicitly discard the result
  }
  catch (std::exception& e)
  {
    std::cerr << "exception caught: " << e.what() << '\n';
  }
  return 0;
}
