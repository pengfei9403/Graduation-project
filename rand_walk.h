#ifndef RAND_WALK_H
#define RAND_WALK_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
// 基类的定义 

class Particle{
	protected:
		double position_x , position_y ;
		int *pass ;
//		int xmark , ymark , zmark ;
		double* location_x ;
		double* location_y ;
		double* arr_steps ;
		int steps , flag;
		bool signal = true ; 
		static double seed ; 					//  静态成员seed 
	public:
		Particle();								//  无参构造函数，用于初始化 
		Particle( int steps , int flag ); 		//  构造函数 
		~Particle(){							//  析构函数
			delete[] arr_steps;
			delete[] location_x;
			delete[] location_y;
		}
		void getArr1( int n );					//  使用系统函数产生随机数 
		void getArr2( int n );					//  使用乘同余法产生随机数 
		void getArr3( int n );					//  使用乘加同余法产生随机数 
		void getArr4( int n );					//  使用人字映射法产生随机数 
		void getRandom();						//  获取随机数数组 
		double Random();						//  产生一个随机数 
		double* getArr();						//  获取随机数组指针 
		double* getLocation_x();				//  获取行走路径数组指针 （x） 
		double* getLocation_y();				//  获取行走路径数组指针（y）	
		double getPosition_x();					//  获取位置 
		double getPosition_y();					//  获取位置
		int getSteps();							//  获取样本随机行走的步数，主要用于自规避随机行走 
		bool getSignal();
		void setSteps(int n);					//  设置样本随机行走的步数，主要用于自规避随机行走 
		void showSteps();						//  显示生产的随机数 
		virtual void randWalk() = 0;			//  纯虚函数 ，执行随机行走过程 
		virtual void SAW() = 0;					//  纯虚函数 ，执行自规避随机行走过程 
		void SAW_INI();							//  自规避随机行走初始化 
		bool passby(int xx , int yy );			//  判断该点是否走过 
		double getSquaredistance( int n );		//  计算平方距离 
		static void setSeed(double value); 		//  修改随机数种子 
};


//  子类二维 Kagome 格子定义 

//class Kagome : public Particle {
//	public:
//		Kagome(){
//			getArr(500);
//		} 
//		Kagome( int n ){
//			getArr( n );
//		}
//	virtual void randWalk();					// 虚函数，执行随机行走过程 
//}; 


#endif
