CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

OBJS = main.o parser.o node.o printTree.o scanner.o

parser: $(OBJS)
	$(CXX) $(CXXFLAGS) -o parser $(OBJS)

main.o: main.cpp parser.h printTree.h scanner.h token.h
parser.o: parser.cpp parser.h node.h scanner.h token.h
node.o: node.cpp node.h token.h
printTree.o: printTree.cpp printTree.h node.h
scanner.o: scanner.cpp scanner.h token.h
	$(CXX) $(CXXFLAGS) -c scanner.cpp -o scanner.o


clean:
	rm -f *.o parser
