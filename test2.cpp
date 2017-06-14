#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h> 

using namespace std;

int read_MD(int steps , int n , string type){
	fstream input;
	fstream output;
	double value1[steps];
	double* value = new double[n*steps]; 
	double x[steps+1];
	double y[steps+1];
	double mean_dis[steps];
	double sum;
	int loop = steps ;
	string name ;
	string name2;
	string temp = "./data/" + type + "Sample/Sample_";
	char buf[30];
	sum = 0 ;
	for(int ipoint = 0 ; ipoint < n ; ipoint++){
		sprintf(buf , "%d" , ipoint);
		name = buf ;
		name = temp + name + ".txt";
		cout << name <<endl; 
		input.open(name.c_str() , ios::in); 
		if( !input ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		for(int i = 0 ; i <= steps ; i++){
			input >> x[i] >> y[i] ;
		}
		input.close();
//		for(int i = 0 ; i < steps ; i++){
//			cout<<x[i]<<endl;
//		}
		for(int i = 1 ; i < steps ; i++){
			value[ipoint*loop+i] = pow(x[i-1] , 2) + pow(y[i-1] , 2);
			cout<<"n*loop + i" << n*loop +i <<endl;				
		}
//		if (type == "Line"){
//			for(int i = 1 ; i < loop ; i++){
//				value[n*loop + i - 1] = pow(y[i-1] , 2);
//			}
//		}else{
//			for(int i = 1 ; i < loop ; i++){
//				value[n*loop + i - 1] = pow(x[i-1] , 2) + pow(y[i-1] , 2);				
//			}
//		}
	}
//	for(int istep = 0 ; istep < loop ; istep++){
//		sum = 0 ;
//		for(int ipoint = 0 ; ipoint < n ; ipoint++){
//			sum += value[n*loop + istep] ;
//		}
//		mean_dis[istep] = sum / n ;
//	}
//	name2 = "./data/" + type + "Sample/" + type +"_data.txt" ;
//	output.open(name2.c_str() , ios::out);
//	if( !output ){
//		cout << "Failed to open file !"<< endl;
//		return 0; 
//	}
//	for(int i = 0 ; i < loop ; i++){
//		cout<<i;
//		output << mean_dis[i] << endl;
//	}
	delete[] value;
//	output.close();
	cout << type << " read_MD has been generated !" <<endl;
}


//  产生一个随机数
double Random(){
	double a = 32719 , m  ;
	double temp , value ;
	double static seed = time(0);
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
    seed = ((double)((int) time(0) % 10) / 10  + value) * pow(2,30) * 0.5;
//    srand( (int) seed );
//    value = ( double ) random( 1000 ) / 1000 ;
    return value ;
}

void fun(int x){
	cout<<x<<endl;
} 

int main(){
	clock_t start , stop ;
	cout << CLK_TCK;
	start = clock();
	cout << start << endl ;
	for(int i = 1 ; i < 1000 ; i++){
		
	}
	stop = clock();
	cout << stop <<endl ;
	cout << stop - start << endl ;
	
	return 0;
}
