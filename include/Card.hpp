#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "Defs.hpp"
#include "Plant.hpp"

class Card 
{
	public:
	Card(map<string, float> config, Vector2f pos, const string tex_path);
	void render(RenderWindow &window);
	bool contains(int x, int y);
	plant* make_plant(Vector2f& position);
	float get_price();
	bool ready();

	

	private:
	map<string, float> config;
	Sprite card_sp;
	Texture card_tex;
	Font font;
	Text price_txt;
	Text time_txt;
	Clock cool_down;
	string type;
}


#endif
