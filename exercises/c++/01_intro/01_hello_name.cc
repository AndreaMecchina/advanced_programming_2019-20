#include <iostream>
#include <string>

// program to test compiler error messages
int main() {
  std::cout << "Insert your name and age:\n";
  std::string name;
  unsigned int age;
  
  std::cin >> name >> age;
  std::cout << "Hello, " << name << " [" << age << "]\n";
  return 0;
}
