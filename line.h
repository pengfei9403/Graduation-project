#ifndef LINE_H
#define LINE_H

#include "rand_walk.h"

//  ����һάֱ�߶��� 

class Line : public Particle {
	public:
		using Particle::Particle;
		void randWalk();
		void SAW();
		int driect(double value);
}; 


#endif
