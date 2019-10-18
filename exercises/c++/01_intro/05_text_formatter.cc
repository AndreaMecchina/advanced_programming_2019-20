#include <iostream>
#include <string>

int main(){
  
  std::string line, print;
  unsigned int max{60}, end;

  while(std::getline(std::cin, line)){ // breaks lines longer than max
    
    while(line.length() > max){

      for(unsigned int i = 0; i < line.length(); i++){
	if(line[i]=='\t'){
	  line[i]=' '; // converts tabs '\t' in spaces ' ' 
	}
      }

      unsigned int i{0};
      while(line[max - i] != ' '){
	i++;
      }
      end = max - i + 1;

      // this formatter does not break words
      print = line.substr(0, end);
      std::cout << print << "\n";
      
      line = line.substr(end);
    }
    
    std::cout << line << "\n";

  }
  
  return 0;
}
