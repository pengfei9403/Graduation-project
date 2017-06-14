#include "triangle.h"
#include <math.h>

using namespace std;

//  三角形格子随机行走函数实现 

void Triangle::randWalk(){
	getRandom();
	for ( int i = 0 ; i < steps ; i++ ){
		if ( arr_steps[ i ] <= 1/6.0 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_x--;
		}else if ( arr_steps[ i ] <= 2/6.0 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_x -= 0.5;
			position_y += pow(3,0.5)/2;
		}else if ( arr_steps[ i ] <= 3/6.0 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_x += 0.5;
			position_y += pow(3,0.5)/2;
		}else if ( arr_steps[ i ] <= 4/6.0 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_x++;
		}else if ( arr_steps[ i ] <= 5/6.0 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_x += 0.5;
			position_y -= pow(3,0.5)/2;
		}else if ( arr_steps[ i ] <= 6/6.0 ){
			location_x[i] = position_x;
			location_y[i] = position_y;
			position_x -= 0.5;
			position_y -= pow(3,0.5)/2;
		}
	}
	location_x[steps] = position_x;
	location_y[steps] = position_y;
}



bool Triangle::check(int xx , int yy){
	bool temp1 , temp2 ;
	if(passby(xx-1 , yy) && passby(xx-1 , yy+1) && passby(xx , yy+1)){
		temp1 = true ;
	}else{
		temp1 = false ;
	}
	if(passby(xx+1 , yy) && passby(xx+1 , yy-1) && passby(xx , yy-1)){
		temp2 = true ;
	}else{
		temp2 = false ;
	}
	if(temp1 && temp2){
		return true ;
	}else{
		return false ;
	}
}

int Triangle::driect(double value , int xx , int yy){
	if ( value <= 1/6.0 ){
		if(passby(xx-1 , yy)){
			signal = false ;
			return 0 ;
		}else{
			return 1 ;
		}
	}else if ( value <= 2/6.0 ){
		if(passby(xx-1 , yy+1)){
			signal = false ;
			return 0 ;
		}else{
			return 2 ;
		}
	}else if ( value <= 3/6.0 ){
		if(passby(xx , yy+1)){
			signal = false ;
			return 0 ;
		}else{
			return 3 ;
		}
	}else if ( value <= 4/6.0 ){
		if(passby(xx+1 , yy)){
			signal = false ;
			return 0 ;
		}else{
			return 4 ;
		}
	}else if ( value <= 5/6.0 ){
		if(passby(xx+1 , yy-1)){
			signal = false ;
			return 0 ;
		}else{
			return 5 ;
		}
	}else if ( value <= 6/6.0 ){
		if(passby(xx , yy-1)){
			signal = false ;
			return 0 ;
		}else{
			return 6 ;
		}
	}
}

void Triangle::SAW(){
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
					xmark--;
					pass[xmark + ymark*2000] = 1 ;
					location_x[i] = position_x;
					location_y[i] = position_y;
					position_x--;
					break;
				case 2 :
					xmark--;
					ymark++;
					pass[xmark + ymark*2000] = 1 ;
					location_x[i] = position_x;
					location_y[i] = position_y;
					position_x -= 0.5;
					position_y += pow(3,0.5)/2;
					break;
				case 3 :
					ymark++;
					pass[xmark + ymark*2000] = 1 ;
					location_x[i] = position_x;
					location_y[i] = position_y;
					position_x += 0.5;
					position_y += pow(3,0.5)/2;
					break;
				case 4 :
					xmark++;
					pass[xmark + ymark*2000] = 1 ;
					location_x[i] = position_x;
					location_y[i] = position_y;
					position_x++;
					break;
				case 5 :
					xmark++;
					ymark--;
					pass[xmark + ymark*2000] = 1 ;
					location_x[i] = position_x;
					location_y[i] = position_y;
					position_x += 0.5;
					position_y -= pow(3,0.5)/2;
					break;
				case 6 :
					ymark--;
					pass[xmark + ymark*2000] = 1 ;
					location_x[i] = position_x;
					location_y[i] = position_y;
					position_x -= 0.5;
					position_y -= pow(3,0.5)/2;
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
