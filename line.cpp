#include "line.h"

using namespace std;

//  һάֱ�߸���������ߺ���ʵ��

void Line::randWalk(){
	getRandom();
	for ( int i = 0 ; i < steps ; i++ ){
		if ( arr_steps[ i ] <= 0.5 ){
			location_x[i] = position_x; 
			location_y[i] = position_y;
			position_x++;
		}else{
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_x--;
		}
	}
	location_x[steps] = position_x;
	location_y[steps] = position_y;
} 

void Line::SAW(){}
