EXEC=test
SRC=main.cpp vector.cpp matrix.cpp
OBJS=$(SRC:.cpp=.o) 
CXX=g++
CXXFLAGS= -g
RM=rm -f

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@ 

clean:
	$(RM) $(EXEC) $(OBJS)
