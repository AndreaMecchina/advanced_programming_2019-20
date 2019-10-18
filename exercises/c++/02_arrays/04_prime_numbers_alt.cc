#include <iostream>
#include <vector>

int main () {

  std::vector<unsigned int> primes; // no need to explicitly free heap memory 
  std::size_t n{100};
    
  for(unsigned int x = 2; x < n; x++){
    unsigned int div{2};
    while(x%div!=0){
      div += 1;
    }
    if(x==div){
      primes.push_back(x); // adds primes to the vector
    }
  }
  // using vectors a single loop is enough

  std::cout << "The first prime numbers smaller than " << n << " are:\n";

  for (auto i = primes.cbegin(); i < primes.cend(); ++i){ // no need to know vector size
    std::cout << *i << "\n"; // prints vector elements using pointers
  }
  
  return 0;
}
