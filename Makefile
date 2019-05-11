# -Wall, -Wextra, -pedantic are there to show extra warnings during compile time
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11
SFMLFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

#Commands to create executable files

main: ./src/main_menu.o ./tst/main.o ./src/game.o ./src/square.o ./src/map.o ./src/action.o ./src/map_select.o ./src/movement.o ./src/console.o ./src/turn.o ./src/player.o ./src/utilities.o ./src/texture_man.o ./src/skills.o ./src/use_skill.o
	g++ ./tst/main.o ./src/main_menu.o ./src/game.o ./src/square.o ./src/map.o ./src/map_select.o ./src/action.o ./src/movement.o ./src/console.o ./src/turn.o ./src/player.o ./src/utilities.o ./src/texture_man.o ./src/skills.o ./src/use_skill.o -o ./tst/a.out $(SFMLFLAGS)
	./tst/a.out

menu_test: ./src/menu_test.o
	g++ ./src/menu_test.o -o ./tst/menu_test.out $(SFMLFLAGS)
	./tst/menu_test.out

grid_test: ./src/grid.o
	g++ ./src/grid.o -o ./tst/grid_test.out $(SFMLFLAGS)
	./tst/grid_test.out

#==========================================================================================================

#Commands to create .o files

./src/main_menu.o: ./src/main_menu.cpp ./bin/main_menu.hpp ./src/game.cpp ./bin/game.hpp ./bin/state_man.hpp ./src/map.cpp ./bin/map.hpp
	g++ -c ./src/main_menu.cpp -I./bin/ -o ./src/main_menu.o

./src/utilities.o: ./src/utilities.cpp ./bin/utilities.hpp
	g++ -c ./src/utilities.cpp -I./bin/ -o ./src/utilities.o

./src/action.o: ./src/action.cpp ./bin/action.hpp ./src/map.cpp ./bin/map.hpp ./bin/game.hpp ./bin/state_man.hpp ./bin/player.hpp ./src/player.cpp
	g++ -c ./src/action.cpp -I./bin/ -o ./src/action.o

./src/map.o: ./src/map.cpp ./bin/map.hpp ./src/game.cpp ./bin/game.hpp ./src/square.cpp ./bin/square.hpp ./src/game.cpp ./bin/game.hpp
	g++ -c ./src/map.cpp -I./bin/ -o ./src/map.o

./src/square.o: ./src/square.cpp ./bin/square.hpp
	g++ -c ./src/square.cpp -I./bin/ -o ./src/square.o

./src/game.o: ./bin/state_man.hpp ./bin/game.hpp ./src/game.cpp ./bin/texture_man.hpp ./src/texture_man.cpp
	g++ -c ./src/game.cpp -I./bin/ -o ./src/game.o

./src/console.o: ./bin/console.hpp ./src/console.cpp ./bin/map.hpp ./bin/game.hpp ./src/game.cpp ./bin/paths.hpp
	g++ -c ./src/console.cpp -I./bin/ -o ./src/console.o

./src/turn.o: ./bin/turn.hpp ./src/turn.cpp ./bin/map.hpp ./src/map.cpp ./bin/game.hpp ./src/game.cpp ./bin/state_man.hpp ./bin/paths.hpp ./bin/player.hpp ./src/player.cpp ./bin/use_skill.hpp ./src/use_skill.cpp
	g++ -c ./src/turn.cpp -I./bin/ -o ./src/turn.o

./tst/main.o: ./tst/main.cpp ./bin/map.hpp ./bin/main_menu.hpp ./bin/action.hpp
	g++ -c ./tst/main.cpp -I./bin/ -o ./tst/main.o

./src/movement.o: ./bin/movement.hpp ./src/movement.cpp ./bin/map.hpp ./src/map.cpp ./bin/game.hpp ./bin/action.hpp ./src/action.cpp
	g++ -c ./src/movement.cpp -I./bin/ -o ./src/movement.o

./src/player.o: ./bin/player.hpp ./src/player.cpp
	g++ -c ./src/player.cpp -I./bin/ -o ./src/player.o

./src/texture_man.o: ./bin/texture_man.hpp ./src/texture_man.cpp
	g++ -c ./src/texture_man.cpp -I./bin/ -o ./src/texture_man.o

./src/skills.o: ./bin/skills.hpp ./src/skills.cpp ./bin/map.hpp ./src/map.cpp
	g++ -c ./src/skills.cpp -I./bin/ -o ./src/skills.o

./src/use_skill.o: ./bin/use_skill.hpp ./src/use_skill.cpp
	g++ -c ./src/use_skill.cpp -I./bin/ -o ./src/use_skill.o

./src/map_select.o: ./bin/map_select.hpp ./src/map_select.cpp
	g++ -c ./src/map_select.cpp -I./bin/ -o ./src/map_select.o
	
./src/skillCast.o: ./bin/skillCast.hpp ./src/skillCast.cpp ./bin/use_skill.hpp ./src/use_skill.cpp
	g++ -c ./src/skillCast.cpp -I./bin/ -o ./src/skillCast.o

#Individual function proof of concepts

./src/menu_test.o: ./src/menu_test.cpp
	g++ -c ./src/menu_test.cpp -o ./src/menu_test.o

./src/grid.o: ./src/grid.cpp
	g++ -c ./src/grid.cpp -o ./src/grid.o


#===========================================================================================================

#Commands for testing


#===========================================================================================================

#Clean command
clean:
	rm ./src/*.o ./tst/*.out
