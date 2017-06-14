#include "hex.h"
#include <math.h>

using namespace std;

//  六边形格子随机行走函数实现 

/*  
	因为六边形格子存在两种格点，
	现定义左侧有两个六边形，右侧有一个六边形的格点为 1 号格点 
	右侧有两个六边形，左侧有一个六边形的格点为 2 号格点
	当 flag 为 1 时表示当前位于 1 号格点位置，否则为 2 号格点位置
	行走方式： 以平行 X 轴的边为起始，顺时针旋转，每条边各占随机数区间 1/3 
*/  

void Hex::randWalk(){
	getRandom();
	int flag = 1;
	for ( int i = 0 ; i < steps ; i++ ){
		if ( flag == 1 ){
			if ( arr_steps[ i ] <= 1/3.0 ){
				location_x[i] = position_x;
				location_y[i] = position_y;
				position_x--;
			}else if ( arr_steps[ i ] <= 2/3.0 ){
				location_x[i] = position_x;
				location_y[i] = position_y;
				position_x += 0.5;
				position_y += pow(3,0.5)/2;
			}else if ( arr_steps[ i ] <= 3/3.0 ){
				location_x[i] = position_x;
				location_y[i] = position_y;
				position_x += 0.5;
				position_y -= pow(3,0.5)/2;
			}
		}else{
			if ( arr_steps[ i ] <= 1/3.0 ){
				location_x[i] = position_x;
				location_y[i] = position_y;
				position_x++;
			}else if ( arr_steps[ i ] <= 2/3.0 ){
				location_x[i] = position_x;
				location_y[i] = position_y;
				position_x -= 0.5;
				position_y -= pow(3,0.5)/2;
			}else if ( arr_steps[ i ] <= 3/3.0 ){
				location_x[i] = position_x;
				location_y[i] = position_y;
				position_x -= 0.5;
				position_y += pow(3,0.5)/2;
			}
		}
		flag *= -1;
	}
	location_x[steps] = position_x;
	location_y[steps] = position_y;
}

bool Hex::check(int flag , int xx , int yy){
	if(flag == 1){
		if(passby(xx-1 , yy) && passby(xx+1 , yy+1) && passby(xx , yy-1)){
			return true ;
		}else{
			return false ;
		}
	}else{
		if(passby(xx+1 , yy) && passby(xx-1 , yy-1) && passby(xx , yy+1)){
			return true ; 
		}else{
			return false ;
		}
	}
} 

int Hex::driect(int flag , double value , int xx , int yy){
	if(flag == 1){
		if ( value <= 1/3.0 ){
			if(passby(xx-1 , yy)){
				signal = false ;
				return 0 ;
			}else{
				return 1 ;
			}
		}else if ( value <= 2/3.0 ){
			if(passby(xx+1 , yy+1)){
				signal = false ;
				return 0 ;
			}else{
				return 2 ;
			}
		}else if ( value <= 3/3.0 ){
			if(passby(xx , yy-1)){
				signal = false ;
				return 0 ;
			}else{
				return 3 ;
			}
		}
	}else{
		if ( value <= 1/3.0 ){
			if(passby(xx+1 , yy)){
				signal = false ;
				return 0 ;
			}else{
				return 1 ;
			}
		}else if ( value <= 2/3.0 ){
			if(passby(xx-1 , yy-1)){
				signal = false ;
				return 0 ;
			}else{
				return 2 ;
			}
		}else if ( value <= 3/3.0 ){
			if(passby(xx , yy+1)){
				signal = false ;
				return 0 ;
			}else{
				return 3 ;
			}
		}
	}
}

void Hex::SAW(){
	int xmark = 1000 ;
	int ymark = 1000 ; 
	int flag = 1;
	double value ;
	int dri ;
	SAW_INI();
	value = Random();
	value = Random();
	for(int i = 0 ; i < steps ; i++){
		if(check(flag , xmark , ymark)){
			if( i != steps ){
				signal = false ;
			}
			setSteps(i) ;
			break;
		}else{
			do{
				value = Random();
				dri = driect(flag , value , xmark , ymark); 
			}while( !dri ) ;
			if(flag == 1){
				switch( dri ){
					case 1 :
						xmark--;
						pass[xmark + ymark*2000] = 1 ;
						location_x[i] = position_x;
						location_y[i] = position_y;
						position_x--;
						break;
					case 2 :
						xmark++;
						ymark++;
						pass[xmark + ymark*2000] = 1 ;
						location_x[i] = position_x;
						location_y[i] = position_y;
						position_x += 0.5;
						position_y += pow(3,0.5)/2;
						break;
					case 3 :
						ymark--;
						pass[xmark + ymark*2000] = 1 ;
						location_x[i] = position_x;
						location_y[i] = position_y;
						position_x += 0.5;
						position_y -= pow(3,0.5)/2;
						break;
					default :
						break;
				}
			}else{
				switch( dri ){
					case 1 :
						xmark++;
						pass[xmark + ymark*2000] = 1 ;
						location_x[i] = position_x;
						location_y[i] = position_y;
						position_x++;
						break;
					case 2 :
						xmark--;
						ymark--;
						pass[xmark + ymark*2000] = 1 ;
						location_x[i] = position_x;
						location_y[i] = position_y;
						position_x -= 0.5;
						position_y -= pow(3,0.5)/2;
						break;
					case 3 :
						ymark++;
						pass[xmark + ymark*2000] = 1 ;
						location_x[i] = position_x;
						location_y[i] = position_y;
						position_x -= 0.5;
						position_y += pow(3,0.5)/2;
						break;
					default :
						break;
				}
			}
			flag *= -1;
		}
	}
	location_x[steps] = position_x;
	location_y[steps] = position_y;
	delete pass ;
}
