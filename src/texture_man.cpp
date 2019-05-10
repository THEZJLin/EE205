#include "texture_man.hpp"

//load texture from file and store it in map
void TexManager::loadTex(const std::string& texName, const std::string& texFile) {

     //Load texture
     sf::Texture tex;
     
     if(!tex.loadFromFile(texFile)) {
          throw "Texture not loaded";
     }

     textures.insert( {texName,tex} );

}

sf::Texture& TexManager::getTex(const std::string& texName) {
     //the at function checks bounds and throws an exception if texName isn't valid
     return textures.at(texName);
}


