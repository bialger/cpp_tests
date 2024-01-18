#include "MyClass.h"

MyClass::MyClass(std::ostream& out) : out_(out) {}

void MyClass::Print(const std::string& str) {
    out_ << str;
}
