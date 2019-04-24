#ifndef GRID_HPP
#define GRID_HPP
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>


class squares
			{
				private:
					 			int x;
								int y;
				public:
								sf::RectangleShape tile;
								//default consturctor
								squares();
								//returns the x position
								int get_XPosition();
								//returns the y position of the tile
								int get_YPosition();
								//sets the X and Y position
								void set_XYPosition(int Xpos int Ypos);

			};
class map : public squares
			{
				private:


				public:
								std::vector<squares*> columns;
								//constructs and object for map
								grid();
			};

#endif
