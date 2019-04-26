#include "square.hpp"

//Constructor, sets coordinates with given input arguments
Square::Square(int x_pos, int y_pos, int n_) {

     //Set graphical appearance of square
     rect = RectangleShape(Vector2f(SIZE, SIZE));

//==Place holder color until texture is implemented==
     rect.setFillColor(Color::Green);
     rect.setOutlineThickness(1);
     rect.setOutlineColor(Color::Red);
//===================================================

     //Set coordinates of square
     rect.setPosition(Vector2f(x_pos, y_pos));

     //Assign values to square parameters
     n = n_;
     birth = .9;
     death = .9;
}


