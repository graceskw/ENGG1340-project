game: main.o map.o events.o inventory.o roll.o
	g++ main.o map.o events.o inventory.o roll.o -o game

main.o: main.cpp
	g++ -c main.cpp

map.o: map.cpp
	g++ -c map.cpp

event.o: events.cpp
	g++ -c events.cpp

inventory.o: inventory.cpp
	g++ -c inventory.cpp

roll.o: roll.cpp
	g++ -c roll.cpp

clean:
	rm *.o