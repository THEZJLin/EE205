#include "grid.hpp"

int main()
{
	int mapsize = 1800;
	sf::RenderWindow window(sf::VideoMode(mapsize, mapsize), "wtf");
	grid world;
	while(window.isOpen())
	{

		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for(int i=0; i<16*16;i++)
		{
			window.draw(world.columns[i]->tile);
		}

		window.display();

	}

	return 0;
}
