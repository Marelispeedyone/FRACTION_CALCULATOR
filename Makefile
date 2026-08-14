@ -0,0 +1,15 @@
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include
TARGET = programme.exe
SOURCES = main.cpp src/core/Fraction.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run