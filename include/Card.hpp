#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Defs.hpp"

class Card 
{
	public:
	Deck(map<string, int> config,FloatRect bg_bound,string type,int y_ofset, IntRect subrect);
	void render(RenderWindow &window);
	bool contains(int x, int y);
	string get_name();
	reset();
	bool ready();
	
	
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
