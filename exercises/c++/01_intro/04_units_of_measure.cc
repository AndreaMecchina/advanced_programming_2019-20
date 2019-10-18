#include <iostream>
#include <string>

// defines symbolic constants in order to avoid magic numbers
#define inch_per_meter 0.0254
#define feet_per_meter 0.3048
#define yard_per_meter 0.9144
#define mile_per_meter 1609.34

void get_double();

int main() {

  std::cout << "Please enter a lenght value with its unit (inch, feet, yard, mile): \n";
  get_double();
 
  return 0;
}

void get_double(){
  
  double i;
  
  while(!(std::cin >> i)){ // reads from stdin until a valid double is fed
 
    std::cin.clear();
    std::cin.ignore();  
    
  }
  
  std::string line1;
  std::getline(std::cin,line1);

  if (line1==" inch") {
    
  i *= inch_per_meter; // prints back the number according to the SI units
  std::cout << i  << " m\n";
  
  } else if (line1==" feet") {
    
  i *= feet_per_meter;
  std::cout << i  << " m\n";
  
  } else if (line1==" yard") {
    
  i *= yard_per_meter;
  std::cout << i  << " m\n";
  
  } else if (line1==" mile") {
    
  i *= mile_per_meter;
  std::cout << i  << " m\n";
  
  } else {

  std::cout << "unknown unit\n";
  
  }

}
