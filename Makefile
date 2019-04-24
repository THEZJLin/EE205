# -Wall, -Wextra, -pedantic are there to show extra warnings during compile time
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11
SFMLFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

#Commands to create executable files

main: ./src/main_menu.o ./tst/main.o ./src/game.o
	g++ ./tst/main.o ./src/main_menu.o ./src/game.o -o ./tst/a.out $(SFMLFLAGS)
	./tst/a.out

menu_test: ./src/menu_test.o 
	g++ ./src/menu_test.o -o ./tst/menu_test.out $(SFMLFLAGS)
	./tst/menu_test.out

grid_test: ./src/grid.o
	g++ ./src/grid.o -o ./tst/grid_test.out $(SFMLFLAGS)
	./tst/grid_test.out
#==========================================================================================================

#Commands to create .o files

./src/main_menu.o: ./src/main_menu.cpp ./bin/main_menu.hpp ./src/game.cpp ./bin/game.hpp ./bin/state_man.hpp
	g++ -c ./src/main_menu.cpp -I./bin/ -o ./src/main_menu.o

./src/game.o: ./bin/state_man.hpp ./bin/game.hpp ./src/game.cpp
	g++ -c ./src/game.cpp -I./bin/ -o ./src/game.o

./tst/main.o: ./tst/main.cpp ./bin/main_menu.hpp
	g++ -c ./tst/main.cpp -I./bin/ -o ./tst/main.o

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
