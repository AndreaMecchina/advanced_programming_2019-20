#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

template <typename T, typename s>
void print(const T &array,const s r,const s c);

template <typename T, typename s>
T transpose(const T &array,const s r,const s c);

int main(int argc, char* argv[]) {

  std::size_t r, c;
  std::istringstream rows{argv[1]}, columns{argv[2]};
  rows >> r, columns >> c;

  std::vector<double> m;
  
  for(auto i = 0lu; i < r*c; i++){
    m.push_back(i);
  }

  std::cout << "Original matrix:" << std::endl;
  print(m, r, c);
  
  m = transpose(m,r,c);
  
  std::cout << "Transpose matrix:" << std::endl;
  print(m, c, r);

  return 0;
}

template <typename T, typename s>
void print(const T &array,const s r,const s c){
  for (auto i = 0lu; i < r; ++i){
    for (auto j = 0lu; j < c; ++j){
      std::cout << std::setw(2) << array[i * c + j] << " ";
    }
    std::cout << std::endl;
  }
}

template <typename T, typename s>
T transpose(const T &array,const s r,const s c){
  T t=array;
  for (auto i = 0lu; i < c; ++i) {
    for (auto j = 0lu; j < r; ++j){
	  t.at(i*r+j)=array[i+j*c];
    }
  } 
  return t;
}