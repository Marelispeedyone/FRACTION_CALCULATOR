CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include
TARGET = programme.exe
SOURCES = main.cpp src/core/Fraction.cpp src/core/Parsing.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation et exécution du test (avec les dépendances nécessaires)
test: tests/unit/Fraction_test.cpp src/core/Fraction.cpp src/core/Parsing.cpp
	$(CXX) $(CXXFLAGS) -o tests/unit/Fraction_test.exe $^
	./tests/unit/Fraction_test.exe

clean:
	rm -f $(TARGET) tests/unit/Fraction_test.exe

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run test