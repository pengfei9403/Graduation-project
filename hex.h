#ifndef HEX_H
#define HEX_H

#include "rand_walk.h"

// �����ά�����θ��Ӷ��� 

class Hex : public Particle {
	public:
		using Particle::Particle;				//  �̳л��๹�캯�� 
		void randWalk();						// �麯����ִ��������߹��� 
		void SAW(); 
		bool check(int flag , int xx , int yy); 
		int driect(int flag , double , int , int);
};


#endif
