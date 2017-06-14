#include "square.h"

using namespace std;

//  二维正方形格子随机行走函数实现 

void Square::randWalk(){
	getRandom();
	for ( int i = 0 ; i < steps ; i++ ){
		if ( arr_steps[ i ] <= 0.25 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_x++;
		}else if ( arr_steps[ i ] <= 0.50 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_x--;
		}else if ( arr_steps[ i ] <= 0.75 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_y++;
		}else if ( arr_steps[ i ] <= 1.00 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_y--;
		}
	}
	location_x[steps] = position_x;
	location_y[steps] = position_y;
}

bool Square::check(int xx , int yy){
	if(passby(xx+1 , yy) && passby(xx , yy+1) && passby(xx-1 , yy) && passby(xx , yy-1)){
		return true ;
	}else{
		return false ;
	}
}

int Square::driect(double value , int xmark , int ymark){
	if ( value <= 0.25 ){
		if(passby(xmark+1 , ymark)){
			signal = false ;
			return 0 ;
		}else{
			return 1 ;
		}
	}else if ( value <= 0.50 ){
		if(passby(xmark-1 , ymark)){
			signal = false ;
			return 0 ;
		}else{
			return 2 ;
		}
	}else if ( value <= 0.75 ){
		if(passby(xmark , ymark+1)){
			signal = false ;
			return 0 ;
		}else{
			return 3 ;
		}
	}else if ( value <= 1.00 ){
		if(passby(xmark , ymark-1)){
			signal = false ;
			return 0 ;
		}else{
			return 4 ;
		}
	}
}

void Square::SAW(){
//	getRandom();
	int xmark = 1000 ;
	int ymark = 1000 ; 
	double value ;
	int dri ;
	SAW_INI();
	value = Random();
	value = Random();
	for(int i = 0 ; i < steps ; i++){
		if(check(xmark , ymark)){
			if( i != steps ){
				signal = false ;
			}
			setSteps(i) ;
			break;
		}else{
			do{
				value = Random();
				dri = driect(value , xmark , ymark); 
			}while( !dri ) ;
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
					pass[xmark + ymark*2000] = 1 ;
					location_x[i] = position_x;
					location_y[i] = position_y;
					position_x--;
					break;
				case 3 :
					ymark++;
					pass[xmark + ymark*2000] = 1 ;
					location_x[i] = position_x;
					location_y[i] = position_y;
					position_y++;
					break;
				case 4 :
					ymark--;
					pass[xmark + ymark*2000] = 1 ;
					location_x[i] = position_x;
					location_y[i] = position_y;
					position_y--;
					break;
				default :
					break;
			}
		}
	}
	location_x[steps] = position_x;
	location_y[steps] = position_y;
	delete pass ;
} 

