game: main.o map.o event.o inventory.o roll.o
	g++ main.o map.o event.o inventory.o -o game

main.o: main.cpp
	g++ -c main.cpp

map.o: map.cpp
	g++ -c map.cpp

event.o: event.cpp
	g++ -c event.cpp

inventory.o: inventory.cpp
	g++ -c inventory.cpp

roll.o: roll.cpp
	g++ -c roll.cpp

clean:
	rm *.o