SRC = 01_class_date.cc \
      02_helper_functions.cc \
      03_c++14.cc \
      04_multiple_flags.cc \
      05_range-for-loop.cc

CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++14

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
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean

01_enum.x : CXXFLAGS += -Wno-unused-variable
02_scoped_enum.x : CXXFLAGS += -Wno-unused-variable
05_struct_class.x : CXXFLAGS += -Wno-unused-but-set-variable -Wno-unknown-warning-option
