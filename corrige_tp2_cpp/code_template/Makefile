EXEC=test
SRC=main.cpp
EXTRADEPS=matrix.hpp vector.hpp
OBJS=$(SRC:.cpp=.o) 
CXX=g++
CXXFLAGS= -g
RM=rm -f

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o : %.cpp $(EXTRADEPS)
	$(CXX) -c $(CXXFLAGS) $< -o $@ 

clean:
	$(RM) $(EXEC) $(OBJS)
