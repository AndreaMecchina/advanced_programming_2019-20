#include <iostream>

int main () {

  std::cout << "Please insert an integer value: ";
  std::size_t n;
  std::cin >> n; // reads from stdin the numbers of primes to compute
  std::cout << "The first prime numbers up to " << n << " are: \n";

  bool * list{new bool[n-1]}; // all elements are 0 by default

  unsigned int p{2};
  while(!(p*p > n)){ // refinement condition without #include <cmath> and std::sqrt
    
    unsigned int m{2};
    while(m * p <= n){
      for(unsigned int i = 0; i < n-1; i++){
	
	if(i+2 == m * p){
	  list[i] = 1; // marks non-primes list elements
	}
      }
      m += 1;
    }
    p += 1;
  }
  
  for(unsigned int i = 0; i < n-1; i++){
    if(list[i]!=1){ // prints only unmarked elements of the array
      std::cout << i+2 << " "; 
    }
  }
  std::cout << std::endl;
  delete[] list;
  
  return 0;
}
