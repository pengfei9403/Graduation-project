#include <iostream>
#include <math.h>
#include <time.h>
#include "rand_walk.h"
#define random(x) (rand()%x)

using namespace std;

double Particle::getPosition_x(){
	return position_x;
}

double Particle::getPosition_y(){
	return position_y;
}

double Particle::seed = (int) time(0);

// 基类构造函数

Particle::Particle(){
	
} 

void Particle::setSteps(int n ){
	steps = n ;
}

int Particle::getSteps(){
	return steps;
}

Particle::Particle( int steps , int flag ){
	this->steps = steps ;
	this->flag = flag ; 
	arr_steps = new double[ steps ];
	location_x = new double[steps+1];
	location_y = new double[steps+1];
	position_x = 0 ;							//  初始化起始位置 
	position_y = 0 ;
} 

//  获取随机数数组
void Particle::getRandom(){
		switch ( flag ){							//  判断使用哪种随机数生成方法 
		case 1 :
			getArr1( steps );
			break;
		case 2 :
			getArr2( steps );
			break;
		case 3 :
			getArr3( steps );
			break;
		case 4 :
			getArr4( steps );
			break;
		default :
			getArr4( steps );
			break;
	}
}

//  修改随机数种子

void Particle::setSeed( double value ){
//	srand( (int) time(0));
	seed = ((double)((int) time(0) % 10) / 10  + value) * pow(2,30) * 0.5;
//	cout<<"seed:"<<seed<<endl;
} 

//  产生一个随机数
double Particle::Random(){
	double a = 32719 , m  ;
	double temp , value ;
	m = pow ( 2 , 31 );
//	seed = time( 0 );
	temp = seed;    
//	cout<<"seed in get arr function :"<< seed <<endl;
    value = fmod( (a * temp) , (m-1) );
    if( value <= m/2 ){     								//与人字映射结合生成随机数
        value = (2 * value ) / (m-1);
    }else{
		value = (2*(m-value) + 1) / (m-1);
    }
    setSeed( value );
//    srand( (int) seed );
//    value = ( double ) random( 1000 ) / 1000 ;
    return value ;
} 


// 随机数生产——系统函数 

void Particle::getArr1( int n ){
//	steps = n;
	srand( (int) seed );					//  设置随机数种子 
	for ( int i = 0 ; i < n ; i++ ){
		arr_steps[ i ] = ( double ) random( 1000 ) / 1000 ;
	} 
	setSeed( arr_steps[n-1] );
}

//  随机数产生——乘同余法

void Particle::getArr2( int n ){
//	steps = n;
	double *temp = new double[ steps+1];
	double a = 32719 , m ;
	m = pow ( 2 , 31 );
//	seed = time( 0 );
	temp [ 0 ] = seed;    
	for( int i = 1 ; i <= steps; i++ ){
	    temp[ i ] = fmod( (a * temp[i-1]) , (m-1) );
	    arr_steps[ i-1 ] = temp[ i ] / (m-1);
	}
	setSeed( arr_steps[n-1] );	
	delete[] temp;
} 


//  随机数产生——乘加同余法

void Particle::getArr3( int n ){
//	steps = n;
	double *temp = new double[ steps+1];
	double a = 32719 , c , m ;
	m = pow ( 2 , 31 );
	c = 29;
//	seed = time( 0 );
	temp [ 0 ] = seed;    
	for( int i = 1 ; i <= steps; i++ ){
	    temp[ i ] = fmod( (a * temp[i-1]) + c, (m-1) );
	    arr_steps[ i-1 ] = temp[ i ] / (m-1);
	}
	setSeed( arr_steps[n-1] );
	delete[] temp;	
} 

//  随机数产生——人字映射法

void Particle::getArr4( int n ){
//	steps = n;
	double *temp = new double[ steps+1];
	double a = 32719 , m  ;
	m = pow ( 2 , 31 );
//	seed = time( 0 );
	temp [ 0 ] = seed;    
//	cout<<"seed in get arr function :"<< seed <<endl;
	for( int i = 1 ; i <= steps; i++ ){
	    temp[ i ] = fmod( (a * temp[i-1]) , (m-1) );
        if( temp[ i ] <= m/2 ){     								//与人字映射结合生成随机数
            arr_steps[ i-1 ] = (2*temp[ i ] ) / (m-1);
        }else{
			arr_steps[ i-1 ] = (2*(m-temp[ i ]) + 1) / (m-1);
        }
    }
    setSeed( arr_steps[n-1] );
    delete[] temp;
} 

//  获取随机数组指针

double* Particle::getArr(){
	return arr_steps;
} 

//  获取行走路径数组指针 (x)

double* Particle::getLocation_x(){
	return location_x;
}

//  获取行走路径数组指针 (y)

double* Particle::getLocation_y(){
	return location_y;
}

//  显示生产的随机数列 

void Particle::showSteps(){
	for ( int i = 0 ; i < steps ; i++){
		cout.precision(6);
		cout << arr_steps[ i ] << " " << endl;
	}
}

//  计算平方距离 
double Particle::getSquaredistance( int n ){
	return pow(location_x[n],2) + pow(location_y[n],2);
}


bool Particle::passby(int xx , int yy){
//	cout << zz <<endl;
	int value = pass[xx + yy*2000] ;
	if(value != 1){
		return false;
	}else{
		return true;
	}
} 

void Particle::SAW_INI(){
	pass = new int[2000*2000];
	pass[1000+1000*2000] = 1 ;
} 

bool Particle::getSignal(){
	return signal ;
}

