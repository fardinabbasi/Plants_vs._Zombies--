#ifndef Decks_HPP
#define Decks_HPP

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Defs.hpp"

class Deck 
{
	public:
	Deck(map<string, int> config,FloatRect bg_bound,string type,int y_ofset, IntRect subrect);
	void render(RenderWindow &window);
	bool can_plant_any();
	
	
	private:
	void update();
	map<string, int> config;
	string type;
	Sprite deck_sp;
    	Texture deck_tex;
    	Font font;
    	Text deck_txt;
    	Clock cool_down;
    	Vector2f position;
    	bool can_plant;
}


#endif
