#include <iostream>
#include <string>

template <typename num>
class Vector {
	num* elem;
	std::size_t _size;

	public:
	Vector(const std::size_t size) : elem{new num[size]}, _size{size} {}
  	~Vector() { delete[] elem; }

  	auto size() const { return _size; }
  	auto& operator[](const std::size_t i) { return elem[i]; }
  	const auto& operator[](const std::size_t i) const { return elem[i]; }
  	// function return type deduction
};

template <typename T>
auto& operator<<(std::ostream& os, const Vector<T>& v) {
	for (auto i = 0u; i < v.size(); ++i)
		os << "v[" << i << "] = " << v[i] << std::endl;
  	return os;
}

int main() {
	Vector<double> v{10};

	for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;
	std::cout << v << std::endl;

  	Vector<double>* pv{&v};
 	(*pv)[0] = -99.999;
  	pv->operator[](1) = 77777.3333;
  	std::cout << *pv << std::endl;

  	Vector<double>& rv{v};
  	rv[5] = 555;
  	std::cout << v << std::endl;

  	return 0;
}