# Society
- A Turn-based, Open Source, Civ-like, Role-playing, Free, Multiplayer Game
### Github: https://github.com/TheZJLin/f

### Team members:
* Keenan Lee
* ZJ Lin
* Dino Mariano
* Jake Castillo

Makefile should build perfectly. `make main`

Compiles and runs on ubuntu. Window dimensions modified to match any device it's being used on.

## Download: 
`git clone https://github.com/THEZJLin/f.git`

## How to play: 

Building your civilization, two gods fight to control the board. Starting at oposite corners, after each turn, each civilization grows by itself. When your population dies, you gain souls which can be used to make actions that can influence the growth in your population on the board or the decrease of the other player's population. Fighting for board control, the win condition is to conquer the whole board.

### Tile Interations
When a population in a tile grows too large, citizens of the tile will automatically expand out to adjacent tiles. If an adjacent tile is owned by a different player, the two tiles will go into a probability-based combat. Starting from a 50% win chance, having a relatively higher population will increase win chances.

### Skills
Players can spend souls to use different skills. Currently, there are three skills in the game
* *growth* - A population seed is planted on an empty tile. Using this skill on a non-empty tile will consume souls but won't have any effect
* *earthquake* (High-cost)- Tremors will spread out in a row along the map. The populations of tiles in the path of the earthquake will be converted to the player's religion
* fist - god's hand descends from the sky, this skill completely destroys a tile

### Basic and controls:
* Arrow keys control movement across board.
* Enter key takes selection, prompted by action menu.

## Classes
* *state_man* - Utilizes a stack to navigate to different game states.
* *GameState* - Base class for the states managed by the state manager
    - **Inherited Classes**
    - *Main_menu* - the main menu, the starting state of the game
    - *mapSelect* - A state allowing players to chose a map for the game, reads in maps from resources/maps/tile_textures
    - *action* - state controlling the actual game, manages turns as well as win conditions
    - *turn* - Provides a menu for players to select their actions during their turn.
    - *useSkill* - A state allowing players to select available spells to use
    - *Movement* - State that allows players to navigate through the map and view information on specific tiles
        - skillCast - State inheriting from movement, allows players to select a tile to cast skills on
    - *ff* - A state allowing players to "fast-forward" their current game
* *Console* - Utilizes a deque to display messages to the screen
* *Square* - A core part of gameplay, stores most of the game data
* *Map* - A vector of squares, also contains functions to handle the expansion of population between squares and manipulate square values.
* *Player* - Class containing relevant player information, an instance of this object is created for each player on the map
* *texManager* - Utilizes a map to store textures used in the game
* *Skills* - A virtual base class for the skills available to players

## What will be implemented in the near future (if we end up pursuing this game further)
* Tutorial: Would be nice to implement a tutorial to make playing a little easier.
* Balancing and patching: Player in top left expands faster than the player in the bottom right just because of the base iterators used in the population growth.
* More than two player game: Would be cool to implement up to a 4 or 8 player system.
* Buildings: this was intended to be part of our finished game but we ran out of time
