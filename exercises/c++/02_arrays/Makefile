CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++11

SRC = 01_reverse_order.cc \
      02_prime_numbers.cc \
      03_sieve_of_Eratosthenes.cc \
      04_prime_numbers_alt.cc \
      05_sieve_of_Eratosthenes_alt.cc

EXE = $(SRC:.cc=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cc .x

all: $(EXE)

.PHONY: all

%.x: %.cc 
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean
