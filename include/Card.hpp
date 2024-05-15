#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "Defs.hpp"

class Card 
{
	public:
	Card(map<string, float> config, Vector2f pos, const string tex_path);
	void render(RenderWindow &window);
	bool contains(int x, int y);

	private:
	map<string, float> config;
	Sprite card_sp;
	Texture card_tex;
	Font font;
	Text price_txt;
	Clock cool_down;
	string type;
}


#endif
