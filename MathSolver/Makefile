CPP = g++
CXXFLAGS = -ansi -pedantic -Wall -Werror -Wconversion -std=c++0x -g
CPPFLAGS = -I.

PROGRAM = MathSolver

SOURCES = Main.cpp ./MathSolver.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(PROGRAM): $(OBJECTS)
	$(CPP) $(CXXFLAGS) $(CPPFLAGS) $(OBJECTS) -o $(PROGRAM)

include depends

depends:
	$(CPP) $(CXXFLAGS) $(CPPFLAGS) -MM $(SOURCES) > depends

run:
	@./$(PROGRAM)

gdb:
	@gdb ./$(PROGRAM) -q

clean:
	rm *.o depends $(PROGRAM)