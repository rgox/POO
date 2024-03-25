CPP_STANDARD=c++14

SRC = main.cpp image.cpp filtre_addition.cpp filtre_moyenne.cpp suite_filtres.cpp
OBJS := $(SRC:.cpp=.o)

TARGET=image

RM=rm -f

CXX = g++
CXXFLAGS = -O3 -Wall -std=$(CPP_STANDARD)
LD = g++
LDFLAGS = -O3 -std=$(CPP_STANDARD)

all: $(TARGET)

$(OBJS): %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(TARGET)

clean:
	$(RM) $(OBJS) $(TARGET)

