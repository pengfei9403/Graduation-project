#ifndef LINE_H
#define LINE_H

#include "rand_walk.h"

//  子类一维直线定义 

class Line : public Particle {
	public:
		using Particle::Particle;
		void randWalk();
		void SAW();
		int driect(double value);
}; 


#endif
