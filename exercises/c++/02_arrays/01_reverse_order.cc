#include <iostream>

// using templates
template <typename T>
T * read(std::size_t dim);

template <typename T>
void print(T *array, std::size_t dim);

int main () {

  std::cout << "Please insert int array lenght: ";
  std::size_t size_pippo;
  std::cin >> size_pippo; // reads from stdin the length of the array

  int * pippo = read<int>(size_pippo);
  print(pippo, size_pippo);
 
  delete[] pippo; // frees heap memory

  std::cout << "Please insert double array lenght: ";
  std::size_t size_pluto;
  std::cin >> size_pluto;

  double * pluto = read<double>(size_pluto);
  print(pluto, size_pluto);
 
  delete[] pluto;
  
  return 0;
}

template <typename T>
T * read(std::size_t dim){
  std::cout << "Please insert array elements: ";
  T * array{new T[dim]}; // allocates on the heap one array of size dim
  for(std::size_t i = 0; i < dim; i++){
    std::cin >> array[i]; // initializes array elements
  }
  return array; // returns the pointer to the first element of the array
}

template <typename T>
void print(T *array, std::size_t dim){
  std::cout << "Array in reverse order is: ";
  for(std::size_t i = dim; i >= 1; i--){
    std::cout << array[i-1] << " "; // prints the array elements in the reverse order
  }
  std::cout << std::endl;
}
