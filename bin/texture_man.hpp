#ifndef TEXTURE_MAN_HPP
#define TEXTURE_MAN_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

//Class contains textures used in game
class TexManager {
     public:
          //load texture from file and store it in map
          void loadTex(const std::string& texName, const std::string& texFile);
          
          //load texture from map
          sf::Texture& getTex(const std::string& texName);


     private:
          //map of textures
          std::map<std::string, sf::Texture> textures;

};

#endif
