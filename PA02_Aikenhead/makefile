TARGET = proj2
HEADERS = my_string.h menu.h
SRCS = proj2.cpp menu.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))
CXX = g++
CXX_FLAGS = -Wall -std=c++11

.PHONY: default all clean

all: $(TARGET)

#compile a single object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

#makes object files then links them together
$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
