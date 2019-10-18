#include <iostream>
#include <string>

int main() {

  std::string line1;
  std::string line2;
  int counter = 1;
    
  std::getline(std::cin,line1);

  if(line1==""){ // checks if the input file is empty
    std::cout << "Input file is empty" << std::endl;
  } else {
    while(std::getline(std::cin,line2)) { // scans the stdin
      if(line1==line2){ // compares the two strings
	counter ++;
      } else {
	std::cout << counter << " " << line1 << "\n";
	counter = 1;
      }
      line1 = line2;
    }
    std::cout << counter << " " << line1 << "\n";
  }

  return 0;
}
