#ifndef HEX_H
#define HEX_H

#include "rand_walk.h"

// 子类二维六边形格子定义 

class Hex : public Particle {
	public:
		using Particle::Particle;				//  继承基类构造函数 
		void randWalk();						// 虚函数，执行随机行走过程 
		void SAW(); 
		bool check(int flag , int xx , int yy); 
		int driect(int flag , double , int , int);
};


#endif
