#ifndef RAND_WALK_H
#define RAND_WALK_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
// ����Ķ��� 

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
		static double seed ; 					//  ��̬��Աseed 
	public:
		Particle();								//  �޲ι��캯�������ڳ�ʼ�� 
		Particle( int steps , int flag ); 		//  ���캯�� 
		~Particle(){							//  ��������
			delete[] arr_steps;
			delete[] location_x;
			delete[] location_y;
		}
		void getArr1( int n );					//  ʹ��ϵͳ������������� 
		void getArr2( int n );					//  ʹ�ó�ͬ�෨��������� 
		void getArr3( int n );					//  ʹ�ó˼�ͬ�෨��������� 
		void getArr4( int n );					//  ʹ������ӳ�䷨��������� 
		void getRandom();						//  ��ȡ��������� 
		double Random();						//  ����һ������� 
		double* getArr();						//  ��ȡ�������ָ�� 
		double* getLocation_x();				//  ��ȡ����·������ָ�� ��x�� 
		double* getLocation_y();				//  ��ȡ����·������ָ�루y��	
		double getPosition_x();					//  ��ȡλ�� 
		double getPosition_y();					//  ��ȡλ��
		int getSteps();							//  ��ȡ����������ߵĲ�������Ҫ�����Թ��������� 
		bool getSignal();
		void setSteps(int n);					//  ��������������ߵĲ�������Ҫ�����Թ��������� 
		void showSteps();						//  ��ʾ����������� 
		virtual void randWalk() = 0;			//  ���麯�� ��ִ��������߹��� 
		virtual void SAW() = 0;					//  ���麯�� ��ִ���Թ��������߹��� 
		void SAW_INI();							//  �Թ��������߳�ʼ�� 
		bool passby(int xx , int yy );			//  �жϸõ��Ƿ��߹� 
		double getSquaredistance( int n );		//  ����ƽ������ 
		static void setSeed(double value); 		//  �޸���������� 
};


//  �����ά Kagome ���Ӷ��� 

//class Kagome : public Particle {
//	public:
//		Kagome(){
//			getArr(500);
//		} 
//		Kagome( int n ){
//			getArr( n );
//		}
//	virtual void randWalk();					// �麯����ִ��������߹��� 
//}; 


#endif
