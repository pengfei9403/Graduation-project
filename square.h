#ifndef SQUARE_H
#define SQUARE_H

#include "rand_walk.h"

// �����ά�����θ��Ӷ��� 

class Square : public Particle {
	public:
		using Particle::Particle;				//  �̳л��๹�캯�� 
		void randWalk();						// �麯����ִ��������߹��� 
		void SAW();
		bool check(int xx , int yy); 
		int driect(double , int , int );
		 
};



#endif