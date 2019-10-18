#include <iostream>

int main () {

  unsigned int n{100};
  unsigned int count{0};
  unsigned int primes[n/2];
  // allocates one big array whose dimension for sure needs not
  // to be bigger than n/2 since half of the integers are even
                             
  for(unsigned int x = 2; x < n; x++){   
    unsigned int div{2};
    
    while(x%div!=0){
      div += 1;
    }
    
    if(x==div){
      primes[count]=x; // populates first positions of the array with primes
      count += 1; // counts all primes smaller that n     
    } 
  }

  for(unsigned int i = 0; i < count; i++){
    std::cout << i+1 << ") " << primes[i] << std::endl;
  } // prints only the elements inserted in the array
  
  return 0;
}
