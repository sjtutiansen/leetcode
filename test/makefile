objects = main.o leetcode.o

build : $(objects)
	g++ -o build $(objects)

main.o : leetcode.h
	g++ -g -c main.cpp
leetcode.o : leetcode.h 
	g++ -g -c leetcode.cpp

.PHONY : clean
clean:
	-rm build $(objects)
    

