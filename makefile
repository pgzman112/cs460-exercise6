run : run.o
	./run

run.o : 	zimmermanE6.o real.o
	g++ -o run zimmermanE6.o real.o -g

zimmermanE6.o : zimmermanE6.cpp Real.h
	g++ -c zimmermanE6.cpp -g -w

real.o : Real.cpp Real.h
	g++ -c Real.cpp -g

clean :
	rm -f *.o run
