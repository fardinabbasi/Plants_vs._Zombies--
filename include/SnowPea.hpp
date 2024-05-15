#ifndef SNOWPEA_HPP
#define SNOWPEA_HPP

#include "Plant.hpp"
#include "Defs.hpp"

class SnowPea : public Plant 
{
	public:
		SnowPea(map<string, float> config,string shots_tex_file,const Vector2f& 		position,const FloatRect bg_bound);
	    void update();
	    void set_target(BaseZombie* z);
	    void render(RenderWindow &window);

	protected:
	Texture shot_tex;
	list<Sprite> shots;
};

#endif 
