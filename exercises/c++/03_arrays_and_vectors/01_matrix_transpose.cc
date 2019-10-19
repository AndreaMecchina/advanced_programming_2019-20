#include <iostream>
#include <array>
#include <iomanip>

template <std::size_t dim>
void print(const std::array<double, dim> &array,const int r,const int c);

template <typename T>
T transpose(const T &array,const int r,const int c);

int main() {
  const int r{2}, c{5}; 
  std::array<double,r*c> m; // matrix is defined as an array of r*c elements
  																		 
  for (auto i = 0; i < r*c; ++i) {		
  	m[i]=i; // populates the array
  }									 
 
  std::cout << "Original matrix:" << std::endl;
  print(m, r, c); // prints the array as an (r,c) matrix
  
  m = transpose(m,r,c); // transposition in place
  
  std::cout << "Transpose matrix:" << std::endl;
  print(m, c, r); // prints the array transposed as a (c,r) matrix

  return 0;
}

template <std::size_t dim> // no need to explicitly enter r*c this way
void print(const std::array<double, dim> &array,const int r,const int c) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j){
      std::cout << std::setw(2) << array[i * c + j] << " ";
    }
    std::cout << std::endl;
  }
}
  
template <typename T>
T transpose(const T &array,const int r,const int c){
  T t;
  for (int i = 0; i < c; ++i){
   	for (int j = 0; j < r; ++j){
	  t[i*r+j]=array[i+j*c];
    }
  }  
  return t;
}