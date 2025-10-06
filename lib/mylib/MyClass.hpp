#ifndef MYCLASS_HPP_
#define MYCLASS_HPP_

#include <iostream>

class MyClass {
public:
  explicit MyClass(std::ostream& out);

  void Print(const std::string& str);

private:
  std::ostream& out_;
};

#endif // MYCLASS_HPP_
