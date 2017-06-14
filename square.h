#ifndef SQUARE_H
#define SQUARE_H

#include "rand_walk.h"

// 子类二维正方形格子定义 

class Square : public Particle {
	public:
		using Particle::Particle;				//  继承基类构造函数 
		void randWalk();						// 虚函数，执行随机行走过程 
		void SAW();
		bool check(int xx , int yy); 
		int driect(double , int , int );
		 
};



#endif
