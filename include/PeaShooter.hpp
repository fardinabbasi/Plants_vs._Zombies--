#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

#include "Plant.hpp"
#include "Defs.hpp"

class PeaShooter : public Plant 
{
	public:
	    PeaShooter(map<string, float> config,string shots_tex_file,const Vector2f& position,FloatRect bg_bound);
	    void update();
	    void set_target(BaseZombie* z);
	    void render(RenderWindow &window);

	private:
	Texture shot_tex;
	list<Sprite> shots;
	FloatRect bg_bound;
};

#endif 

