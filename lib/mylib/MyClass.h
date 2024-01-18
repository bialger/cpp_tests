#ifndef MYCLASS_H_
#define MYCLASS_H_

#include <iostream>

class MyClass {
 public:
  explicit MyClass(std::ostream& out);

  void Print(const std::string& str);

 private:
  std::ostream& out_;
};

#endif //MYCLASS_H_
