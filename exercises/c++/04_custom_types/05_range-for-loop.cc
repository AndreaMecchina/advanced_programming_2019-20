#include <iostream>
#include <string>

template <typename num>
class Vector {
	num* elem;
	std::size_t _size;

	public:
	Vector(const std::size_t size) : elem{new num[size]}, _size{size} {}
	~Vector() { delete[] elem; }

	std::size_t size() const { return _size; }
	num& operator[](const std::size_t i) { return elem[i]; }
	const num& operator[](const std::size_t i) const { return elem[i]; }
	
	// pointer to the first element
	num* begin() { return elem; }
	const num* begin() const { return elem; }
  	
  	// pointer to the last element
  	num* end() { return elem + _size; }
	const num* end() const { return elem + _size; }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
	// range-for-loop
	for (auto i = v.begin(); i < v.end(); ++i)
	  os << "v[" << i-v.begin() << "] = " << *i << std::endl;
	return os;
}

int main() {
	Vector<double> v{10};

	for (auto i = 0u; i < v.size(); ++i)
		v[i] = i;
	std::cout << v;
	
	return 0;
}
