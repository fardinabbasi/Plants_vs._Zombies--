#ifndef SUNFLOWER_HPP
#define SUNFLOWER_HPP

#include "Plant.hpp"
#include "Defs.hpp"

class SunFlower : public Plant 
{
	public:
	    SunFlower(map<string, float> config,string shots_tex_file,const Vector2f& position);
	    bool mouse_pressed(int x,int y);
	    void render(RenderWindow &window);
	    void update();
	protected:
	Texture sun_tex;
	list<Sprite> suns;
};

#endif 
