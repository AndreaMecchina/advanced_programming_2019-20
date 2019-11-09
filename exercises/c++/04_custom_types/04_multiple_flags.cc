#include <iostream>

enum class flags : unsigned int {

  flag1 = 1,  // 00001
  flag2 = 2,  // 00010
  flag3 = 4,  // 00100
  flag4 = 8,  // 01000
  flag5 = 16, // 10000
  
  comb1 = flag1 | flag2, // 00011
  comb2 = flag1 | flag3, // 00101
  comb3 = comb1 | flag3, // 00111
};

// bitwise OR overloading returning a flag
flags operator|(const flags f1, const flags f2) {
  return static_cast<flags>(static_cast<unsigned int>(f1) |
                            static_cast<unsigned int>(f2));
}

// bitwise AND overloading returning an unsigned int
unsigned int operator&(const flags f1, const flags f2) {
  return static_cast<unsigned int>(static_cast<unsigned int>(f1) &
                                   static_cast<unsigned int>(f2));
}

// assignment by bitwise OR overloading returning a flag
flags& operator|=(flags& f1, const flags f2) { 
  f1 = f1 | f2;
  return f1;
}

void compute_multiple_flags(flags& f) {
  // performs random operations
  if (f & flags::flag4) 
  	f |= (flags::flag1 | flags::flag2);
  if (f & flags::flag5) 
  	f |= flags::flag3;
}

void do_complicated_stuff(flags flags) {
  compute_multiple_flags(flags);

  // zero is false, non-zero is true
  if (flags & flags::flag1) 
  	std::cout << "flag 1 selected\n";
  if (flags & flags::flag2) 
  	std::cout << "flag 2 selected\n";
  if (flags & flags::flag3) 
  	std::cout << "flag 3 selected\n";
  if (flags & flags::flag4) 
  	std::cout << "flag 4 selected\n";
  if (flags & flags::flag5) 
  	std::cout << "flag 5 selected\n";
}

int main() {

  std::cout << "testing flag1 and flag3\n" 
  			<< "expected  flag1 and flag3 \n\n";
  do_complicated_stuff(flags::flag1 | flags::flag3 | flags::flag1 | flags::flag1);
  // input 00101

  std::cout << "--------------\n\n" 
  			<< "testing comb3\n" 
  			<< "expected  flag1, flag2 and flag3 \n\n";
  do_complicated_stuff(flags::comb3);
  // input 00111

  std::cout << "--------------\n\n" 
  			<< "testing flag4\n" 
  			<< "expected  flag1, flag2 and flag4 \n\n";
  do_complicated_stuff(flags::flag4);
  // input 01000

  std::cout << "--------------\n\n" 
			<< "testing flag5\n" 
			<< "expected flag3 and flag5 \n\n";
  do_complicated_stuff(flags::flag5);
  // input 10000

  return 0;
}