#include <iostream>
#include <vector>

int main () {

  std::cout << "Please insert an integer value: ";
  unsigned int n; 
  std::cin >> n;
  
  std::vector<bool> list(n+1, false); // initializes a boolean vector
                                       // whose elements are all false
  
                                       // vector size is n+1 to include
                                       // the case in which n is prime
  unsigned int p{2};
  while(!(p * p > n)){
    
    unsigned int m{2};
    while(m * p <= n){ // includes the case in which n is prime
      
      for(unsigned int i = 2; i < n+1; ++i){ // the first prime must be 2
	if(i == m * p){
	  list.at(i) = 1; // marks as true non-primes vector element
	}
      }
      m += 1;
    }
    p += 1;
  }

  std::cout << "The first prime numbers up to " << n << " (included) are: \n";
  for(unsigned int i = 2; i < n+1; ++i){
    if(list.at(i) != 1){
      std::cout << i << "\n"; // prints unmarked vector elements
    }
  }
  return 0;
}
