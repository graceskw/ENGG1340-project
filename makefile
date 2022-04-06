game: main.o map.o 
	g++ main.o map.o -o game

main.o: main.cpp
	g++ -c main.cpp

map.o: map.cpp
	g++ -c map.cpp

clean:
	rm *.o