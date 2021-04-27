TARGET = proj4
HEADERS = my_string.h Sensor.h Car.h Agency.h menu.h
SRCS = proj4.cpp my_string.cpp Sensor.cpp Car.cpp Agency.cpp menu.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))
CXX = g++
CXX_FLAGS = -Wall -std=c++03

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
