#include "hex.h"
#include <math.h>

using namespace std;

//  �����θ���������ߺ���ʵ�� 

/*  
	��Ϊ�����θ��Ӵ������ָ�㣬
	�ֶ�����������������Σ��Ҳ���һ�������εĸ��Ϊ 1 �Ÿ�� 
	�Ҳ������������Σ������һ�������εĸ��Ϊ 2 �Ÿ��
	�� flag Ϊ 1 ʱ��ʾ��ǰλ�� 1 �Ÿ��λ�ã�����Ϊ 2 �Ÿ��λ��
	���߷�ʽ�� ��ƽ�� X ��ı�Ϊ��ʼ��˳ʱ����ת��ÿ���߸�ռ��������� 1/3 
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
