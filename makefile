FLAGS = -pedantic-errors -std=c++11

beginning.o: beginning.cpp commands.h map.h roll.h scenes.h 
	g++ $(FLAGS) -c $<

commands.o: commands.cpp commands.h events.h inventory.h map.h
	g++ $(FLAGS) -c $<

ending.o: ending.cpp events.h roll.h scenes.h 
	g++ $(FLAGS) -c $<

event.o: events.cpp events.h inventory.h map.h roll.h 
	g++ $(FLAGS) -c $<

inventory.o: inventory.cpp inventory.h 
	g++ $(FLAGS) -c $<

main.o: main.cpp commands.h events.h inventory.h map.h scenes.h 
	g++ $(FLAGS) -c $<

map.o: map.cpp events.h map.h 
	g++ $(FLAGS) -c $<

roll.o: roll.cpp roll.h
	g++ $(FLAGS) -c $<

save.o: save.cpp events.h inventory.h map.h 
	g++ $(FLAGS) -c $<

game: beginning.o commands.o ending.o events.o inventory.o main.o map.o roll.o save.o
	g++ beginning.o commands.o ending.o events.o inventory.o main.o map.o roll.o save.o -o game

clean:
	rm *.o game _CERTIFICATE.txt

#list of header files:
#commands.h events.h inventory.h map.h roll.h scenes.h 