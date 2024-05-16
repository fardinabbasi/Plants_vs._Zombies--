#ifndef SUNFLOWER_HPP
#define SUNFLOWER_HPP

#include "Plant.hpp"
#include "Defs.hpp"

class Sunflower : public Plant 
{
	public:
	Sunflower(map<string, float> config,string shots_tex_file,const Vector2f& position);
	bool sun_pressed(int x,int y);
	void render(RenderWindow &window);
	void update();
	private:
	Texture sun_tex;
	list<Sprite> suns;
};

#endif 
