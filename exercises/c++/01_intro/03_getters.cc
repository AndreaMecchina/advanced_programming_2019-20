#include <iostream>
#include <string>

void get_int();
void get_double();

int main() {
  
  get_int();
  //get_double(); calls the other function
 
  return 0;
}

void get_int(){
  
  int i; 
  while(!(std::cin >> i)){ // reads from stdin until a valid int is fed
      
    std::cin.clear(); // clears error flag after wrong input 
    std::cin.ignore(); // ignores what just read
    
  }
  
  std::cout << "integer "<< i << " was fed\n";
  
}

void get_double(){
  
  double i;
  while(!(std::cin >> i)){ // read from stdin until a valid double is fed
 
    std::cin.clear();
    std::cin.ignore();  
    
  }

  std::cout << "double " << i << " was fed\n";
  
}
