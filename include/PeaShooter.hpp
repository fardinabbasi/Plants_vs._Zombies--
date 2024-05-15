#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

#include "Plant.hpp"
#include "Defs.hpp"

class PeaShooter : public Plant 
{
	public:
	    PeaShooter(map<string, float> config,string shots_tex_file,const Vector2f& position);
	    void update();
	    void set_target(BaseZombie* z);
	    void render(RenderWindow &window);

	protected:
	Texture shot_tex;
	list<Sprite> shots;
};

#endif 

