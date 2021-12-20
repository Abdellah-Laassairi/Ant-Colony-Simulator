CXX=clang++
CXXFLAGS= -I. -std=c++11 -fPIC

INC= $(wildcard *.h)
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: run

%.o: %.cpp $(INC)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ) 
	$(CXX) -o $@ $^ $(CXXFLAGS) -lX11

.PHONY: run clean

clean:
	rm -f *.o ./tp3

run: main
	export DISPLAY=:0.0
	./main
 


