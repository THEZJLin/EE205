#include "console.hpp"
//map used to get current map dimension
#include "map.hpp"
#include "paths.hpp"

//Constructor
Console::Console(Game* game_) : game(game_) {
     //Get resolution of screen
     float resY = game->desktop.height;
     float resX = game->desktop.width;

     //Load font, throw exception if font not found
     if(!font.loadFromFile(MENU_FONT)) { throw "font not loaded"; }

     //Set font of log
     title.setFont(font);
     aText.setFont(font);

     //Change look of the log title
     title.setString("Log");
     title.setCharacterSize(TSIZE);

     //Change look of log message text
     aText.setString("");
     aText.setCharacterSize(resY*0.02);

     //Set text to appear to the right of map, title appears at top
     title.setPosition(Vector2f(resY*PERCENT+((resX-(resY*PERCENT))*.4),0));
     aText.setPosition(Vector2f(resY*PERCENT,TSIZE));

     //Set max visible entries of log
     max = 10;
}

//Draws console to game window
void Console::draw() {
     game->window.draw(title);
     game->window.draw(aText);
}



//Pushes input screen into log messages
void Console::pushEntry(std::string entry) {
     //Insert input string at end of deque
     aEntries.push_back(entry);

     //Pop oldest entry if above max
     if(aEntries.size() > max) { aEntries.pop_front(); }

     //Update aText text object
     std::stringstream ss;
     for(auto it : aEntries) {
          //Push all strings in queue to sstream
          ss << it << "\n";
     }
     
     //Set aText object to string in sstream
     aText.setString(ss.str());
}


//Getter to return font
sf::Font& Console::getFont() {
     
     return font;

}



//Clears deque and thus, clears all messages from log
void Console::clear() {
     //clear deque
     aEntries.clear();
     //Remove all messages from aText object
     aText.setString("");
}

