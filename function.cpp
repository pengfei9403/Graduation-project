#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>
#include "function.h"
#include "line.h"
#include "triangle.h"
#include "square.h"
#include "hex.h"

using namespace std;

//  计算随机数的均值 

double meanValue(double *arr,  int steps ){
	double temp = 0 , value;
	for (int i = 0 ; i < steps ; i++ ){
		temp += arr[ i ];
	}
	value = temp / steps;
	return value;
} 

//  计算随机数的方差 

double var(double *arr , int steps ){
	double temp_1 , temp_2 , value ;
	temp_1 = meanValue( arr , steps);
	temp_2 = 0 ;
	for ( int i = 0 ; i < steps ; i++ ){
		temp_2 += (temp_1 - arr[ i ]) * (temp_1 - arr[ i ]);
	}
	value = temp_2 / steps;
	return value;
}

//  在直线上进行随机行走 

int LineWalk( int steps , int n , int flag ){
	int loop = steps / 50 ;
	double mean_sd[loop];										//  记录均方距离 
	double sum_sd = 0;										//  记录平方距离之和 
//	mean_sd = new double [steps];
	fstream outputFile;
	for (int i = 0 ; i < loop ; i++){
		int temp_steps = (i+1) * 50 ;
		sum_sd = 0;
		for (int i = 0 ;i < n; i++ ){
			Line *obj = new Line(temp_steps , flag);		//  获取新的点对象 
			obj->randWalk();								//  进行随机行走 
			sum_sd += obj->getSquaredistance(temp_steps);				//  记录平方距离 
			delete obj; 
		}
		mean_sd[i] = sum_sd / n ;
	}
//  将计算每一步的均方距离结果写入文件 
	outputFile.open("./data/Line_data.txt",ios::out);
	if( !outputFile ){
		cout << "Failed to open file \"Line_data.txt\" "<< endl;
		return 0; 
	}
	for (int i = 0 ; i < loop ; i++){
//		cout << mean_sd[i] <<endl;
		outputFile << mean_sd[i] <<endl;
	}
	outputFile.close();
	cout << "The data of rand walk on Line has been generated !" <<endl;
//	delete mean_sd;
	return 1;
}

//  在正方形上进行随机行走 

int SquareWalk( int steps , int n , int flag ){
	int loop = steps / 50 ;
	double mean_sd[loop];										//  记录均方距离 
	double sum_sd = 0;										//  记录平方距离之和 
//	mean_sd = new double [steps];
	fstream outputFile;
	for (int i = 0 ; i < loop ; i++){
		int temp_steps = (i+1) * 50 ;
		sum_sd = 0;
		for (int i = 0 ;i < n; i++ ){
			Square *obj = new Square(temp_steps , flag);	//  获取一个新的对象 
			obj->randWalk();								//  进行随机行走 
			sum_sd += obj->getSquaredistance(temp_steps);				//  记录平方距离 
			delete obj; 
		}
		mean_sd[i] = sum_sd / n ;
	}
	outputFile.open("./data/Square_data.txt",ios::out);
	if( !outputFile ){
		cout << "Failed to open file \"Square_data.txt\" "<< endl;
		return 0; 
	}
	for (int i = 0 ; i < loop ; i++){
//		cout << mean_sd[i] <<endl;
		outputFile << mean_sd[i] <<endl;
	}
	outputFile.close();
	cout << "The data of rand walk on Square has been generated !" <<endl;
//	delete mean_sd;
	return 1;
}

//  在三角形上进行随机行走 

int TriangleWalk( int steps , int n , int flag ){
	int loop = steps / 50 ;
	double mean_sd[loop];										//  记录均方距离 
	double sum_sd = 0;												//  记录平方距离之和 
//	mean_sd = new double [steps];	
	fstream outputFile;
	for (int i = 0 ; i < loop ; i++){
		int temp_steps = (i+1) * 50 ;
		sum_sd = 0;
		for (int i = 0 ;i < n; i++ ){
			Triangle *obj = new Triangle(temp_steps , flag);		//  获取新的点对象 
			obj->randWalk();										//  进行随机行走 
			sum_sd += obj->getSquaredistance(temp_steps);						//  记录平方距离 
			delete obj; 
		}
		mean_sd[i] = sum_sd / n ;
	}
//  将计算每一步的均方距离结果写入文件 
	outputFile.open("./data/Triangle_data.txt",ios::out);
	if( !outputFile ){
		cout << "Failed to open file \"Triangle_data.txt\" "<< endl;
		return 0; 
	}
	for (int i = 0 ; i < loop ; i++){
//		cout << mean_sd[i] <<endl;
		outputFile << mean_sd[i] <<endl;
	}
	outputFile.close();
	cout << "The data of rand walk on Triangle has been generated !" <<endl;
//	delete mean_sd;
	return 1;
}

//  在六边形上进行随机行走 

int HexWalk( int steps , int n , int flag ){
	int loop = steps / 50 ;
	double mean_sd[loop];										//  记录均方距离 
	double sum_sd = 0;										//  记录平方距离之和 
//	mean_sd = new double [steps];
	fstream outputFile;
	for (int i = 0 ; i < loop ; i++){
		int temp_steps = (i+1) * 50 ;
		sum_sd = 0;
		for (int i = 0 ;i < n; i++ ){
			Hex *obj = new Hex(temp_steps , flag);			//  获取新的点对象 
			obj->randWalk();								//  进行随机行走 
			sum_sd += obj->getSquaredistance(temp_steps);				//  记录平方距离 
			delete obj; 
		}
		mean_sd[i] = sum_sd / n ;
	}
//  将计算每一步的均方距离结果写入文件 
	outputFile.open("./data/Hex_data.txt",ios::out);
	if( !outputFile ){
		cout << "Failed to open file \"Hex_data.txt\" "<< endl;
		return 0; 
	}
	for (int i = 0 ; i < loop ; i++){
//		cout << mean_sd[i] <<endl;
		outputFile << mean_sd[i] <<endl;
	}
	outputFile.close();
	cout << "The data of rand walk on Hex has been generated !" <<endl;
//	delete mean_sd;
	return 1;
}

double r(double x[] , double y[] , int n , int steps){				 //  计算并返回 N 步支链均方根 
	double temp = 0;
	int i = 0 ;
	for( i = 0 ; i < steps - n + 1 ; i++){
		temp += pow(x[i+n]-x[i] , 2) + pow(y[i+n]-y[i] , 2);
	}
	temp /= (steps - n + 1);
	return temp ;
}

void rr(double x[] , double y[] , int steps , double value[]){		//  计算并返回 N 步均方根 
//	double value[steps - 2] ;
	for(int i = 2 ; i <= steps ; i++){
		value[i-2] = r(x , y , i , steps);
	}
//	return value;
}

void Square_lfd(int steps , int n , int flag ){					//  计算并返回 N 步均方根数组 
	double* temp = new double [n * (steps-1)];
	double temp1[steps-1]; 
	double value[steps - 1];
//	double value [steps-1];
	for(int ipoint = 0 ; ipoint < n ; ipoint++){
		Square* obj = new Square(steps , flag);
		obj->randWalk();
		rr(obj->getLocation_x() , obj->getLocation_y() , steps , temp1);
		delete obj;
		for(int istep = 0 ; istep < steps - 1 ; istep++){
			temp[ipoint * (steps-1) + istep] = temp1[istep];
		} 
	}
	for(int istep = 0 ; istep < steps - 1 ; istep++){
		double sum ;
		sum = 0 ;
		int ipoint = 0;
		for(ipoint = 0 ; ipoint < n ; ipoint++){
			sum += temp[ipoint * (steps -1) + istep];			
		}
		value[istep] = sum / n ;
	}
	delete[] temp;
	LFD(steps , value , "Square");
//	return value;
}

void Triangle_lfd(int steps , int n , int flag ){					//  计算并返回 N 步均方根数组 
	double* temp = new double [n * (steps-1)];
	double temp1[steps-1]; 
	double value[steps - 1];
//	double value [steps-1];
	for(int ipoint = 0 ; ipoint < n ; ipoint++){
		Triangle* obj = new Triangle(steps , flag);
		obj->randWalk();
		rr(obj->getLocation_x() , obj->getLocation_y() , steps , temp1);
		delete obj;
		for(int istep = 0 ; istep < steps - 1 ; istep++){
			temp[ipoint * (steps-1) + istep] = temp1[istep];
		} 
	}
	for(int istep = 0 ; istep < steps - 1 ; istep++){
		double sum ;
		sum = 0 ;
		int ipoint = 0;
		for(ipoint = 0 ; ipoint < n ; ipoint++){
			sum += temp[ipoint * (steps -1) + istep];			
		}
		value[istep] = sum / n ;
	}
	delete[] temp;
	LFD(steps , value , "Triangle");
//	return value;
}

void Hex_lfd(int steps , int n , int flag ){					//  计算并返回 N 步均方根数组 
	double* temp = new double [n * (steps-1)];
	double temp1[steps-1]; 
	double value[steps - 1];
//	double value [steps-1];
	for(int ipoint = 0 ; ipoint < n ; ipoint++){
		Hex* obj = new Hex(steps , flag);
		obj->randWalk();
		rr(obj->getLocation_x() , obj->getLocation_y() , steps , temp1);
		delete obj;
		for(int istep = 0 ; istep < steps - 1 ; istep++){
			temp[ipoint * (steps-1) + istep] = temp1[istep];
		} 
	}
	for(int istep = 0 ; istep < steps - 1 ; istep++){
		double sum ;
		sum = 0 ;
		int ipoint = 0;
		for(ipoint = 0 ; ipoint < n ; ipoint++){
			sum += temp[ipoint * (steps -1) + istep];			
		}
		value[istep] = sum / n ;
	}
	delete[] temp;
	LFD(steps , value , "Hex");
//	return value;
}


//  计算并保存局部分形维数数组
int LFD (int steps , double rr[] , string type){
	fstream outputFile;
	double value[steps - 2];
	double temp1 , temp2 , temp3 , temp4;
	string name = "./data/" + type + "_LFD_arr_data.txt" ;
	string name2 = type + "_LFD_arr_data.txt" ;
	for(int i = 2 ; i < steps ; i++){
		temp1 = pow( rr[i-1] / rr[i-2] , 0.5);
//		cout << "temp1: "<<temp1<<endl; 
		temp2 = (i+1) / (double)i ;
		value[i-2] = log(temp2) / log(temp1) ;
//		cout<<value[i-2]<<endl;
	} 
//  将计算每一步的均方距离结果写入文件 
	outputFile.open( name.c_str() , ios::out);
	if( !outputFile ){
		cout << "Failed to open file " << name2 << endl;
		return 0; 
	}
	for (int i = 0 ; i < steps - 2; i++){
//		cout << mean_sd[i] <<endl;
		outputFile << value[i] <<endl;
	}
	outputFile.close();
	cout << name2 << " has been generated !" <<endl;
//	delete mean_sd;
	return 1;
} 


int LineSample(int steps , int n , int flag){
	fstream output;
	string name , name2 , temp ;
	string name3 = "./data/LineSample/Sample_30_" ;
	string name1 = "./data/LineSample/Sample_" ;
	char buf[30];
	for(int i = 0 ; i < n ; i++){
		sprintf(buf, "%d", i);
		temp = buf ;
		name = name1 + temp + ".txt" ;
		name2 = name3 + temp + ".txt" ;
		output.open(name.c_str() , ios::out) ;
		if( !output ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		Line *obj = new Line(steps , flag);
		obj->randWalk();
		for(int i = 0 ; i <= steps ; i++){
			output << std::fixed << i << '\t' << std::fixed << abs(obj->getLocation_x()[i]) <<endl;
		}
		output.close();
		output.open(name2.c_str() , ios::out) ;
		if( !output ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		for(int i = 0 ; i <= steps ; i++){
			output << std::fixed << abs(obj->getLocation_x()[i]) <<endl;
		}
		output.close();
		delete obj;
	}
	cout << n << " LineSamples have been generated !" <<endl;
	read_MD(steps , n , "Line");
	sample(steps , n , "Line");
}

int SquareSample(int steps , int n , int flag){
	fstream output;
	string name , name2 , temp ;
	string name3 = "./data/SquareSample/Sample_30_" ;
	string name1 = "./data/SquareSample/Sample_" ;
	char buf[30];
	for(int i = 0 ; i < n ; i++){
		sprintf(buf, "%d", i);
		temp = buf ;
		name = name1 + temp + ".txt" ;
		name2 = name3 + temp + ".txt" ;
		output.open(name.c_str() , ios::out) ;
		if( !output ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		Square *obj = new Square(steps , flag);
		obj->randWalk();
		for(int i = 0 ; i <= steps ; i++){
			output << std::fixed << obj->getLocation_x()[i] << '\t' << std::fixed << obj->getLocation_y()[i] <<endl;
		}
		output.close();
		output.open(name2.c_str() , ios::out) ;
		if( !output ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		for(int i = 0 ; i <= 10 ; i++){
			output << std::fixed << obj->getLocation_x()[i] << '\t' << std::fixed << obj->getLocation_y()[i] <<endl;
		}
		output.close();
		delete obj;
	}
	cout << n << " SquareSamples have been generated !" <<endl;
	read_MD(steps , n , "Square");
	sample(steps , n , "Square");
}

int TriangleSample(int steps , int n , int flag){
	fstream output;
	string name , name2 , temp ;
	string name3 = "./data/TriangleSample/Sample_30_" ;
	string name1 = "./data/TriangleSample/Sample_" ;
	char buf[30];
	for(int i = 0 ; i < n ; i++){
		sprintf(buf, "%d", i);
		temp = buf ;
		name = name1 + temp + ".txt" ;
		name2 = name3 + temp + ".txt" ;
		output.open(name.c_str() , ios::out) ;
		if( !output ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		Triangle *obj = new Triangle(steps , flag);
		obj->randWalk();
		for(int i = 0 ; i <= steps ; i++){
			output << std::fixed << obj->getLocation_x()[i] << '\t' << std::fixed << obj->getLocation_y()[i] <<endl;
		}
		output.close();
		output.open(name2.c_str() , ios::out) ;
		if( !output ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		for(int i = 0 ; i <= 10 ; i++){
			output << std::fixed << obj->getLocation_x()[i] << '\t' << std::fixed << obj->getLocation_y()[i] <<endl;
		}
		output.close();
		delete obj;
	}
	cout << n << " TriangleSamples have been generated !" <<endl;
	read_MD(steps , n , "Triangle");
	sample(steps , n , "Triangle");
}

int HexSample(int steps , int n , int flag){
	fstream output;
	string name , name2 , temp ;
	string name3 = "./data/HexSample/Sample_30_" ;
	string name1 = "./data/HexSample/Sample_" ;
	char buf[30];
	for(int i = 0 ; i < n ; i++){
		sprintf(buf, "%d", i);
		temp = buf ;
		name = name1 + temp + ".txt" ;
		name2 = name3 + temp + ".txt" ;
		output.open(name.c_str() , ios::out) ;
		if( !output ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		Hex *obj = new Hex(steps , flag);
		obj->randWalk();
		for(int i = 0 ; i <= steps ; i++){
			output << std::fixed << obj->getLocation_x()[i] << '\t' << std::fixed << obj->getLocation_y()[i] <<endl;
		}
		output.close();
		output.open(name2.c_str() , ios::out) ;
		if( !output ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		for(int i = 0 ; i <= 10 ; i++){
			output << std::fixed << obj->getLocation_x()[i] << '\t' << std::fixed << obj->getLocation_y()[i] <<endl;
		}
		output.close();
		delete obj;
	}
	cout << n << " HexSamples have been generated !" <<endl;
	read_MD(steps , n , "Hex");
	sample(steps , n , "Hex");
}

//  从文件读取数据并计算均方根 
int read_MD(int steps , int n , string type){
	fstream input;
	fstream output;
	int len = 1 ;
	int loop = steps / len ;
	double* value = new double[n*loop]; 
	double x[steps+1];
	double y[steps+1];
	double mean_dis[loop];
	double sum;
	string name ;
	string temp = "./data/" + type + "Sample/Sample_";
	char buf[30];
	for(int ipoint = 0 ; ipoint < n ; ipoint++){
		sprintf(buf , "%d" , ipoint);
		name = buf ;
		name = temp + name + ".txt";
		input.open(name.c_str() , ios::in); 
		if( !input ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		for(int i = 0 ; i <= steps ; i++){
			input >> x[i] >> y[i] ;
		}
		input.close();
		if (type == "Line"){
			for(int i = 1 ; i <= loop ; i++){
				value[ipoint*loop + i - 1] = pow(y[i*len] , 2);
			}
		}else{
			for(int i = 1 ; i <= loop ; i++){
				value[ipoint*loop + i - 1] = pow(x[i*len] , 2) + pow(y[i*len] , 2);				
			}
		}
	}
	for(int istep = 0 ; istep < loop ; istep++){
		sum = 0 ;
		for(int ipoint = 0 ; ipoint < n ; ipoint++){
			sum += value[ipoint*loop + istep] ;
		}
		mean_dis[istep] = sum / n ;
	}
	name = "./data/" + type + "Sample/" + type +"_data.txt" ;
	output.open(name.c_str() , ios::out);
	if( !output ){
		cout << "Failed to open file !"<< endl;
		return 0; 
	}
	for(int i = 0 ; i < loop ; i++){
		output << mean_dis[i] << endl;
	}
	delete[] value;
	output.close();
	cout << type << " read_MD has been generated !" <<endl;
}



int sample(int step ,  int n , string type){
	fstream input;
	fstream output1;
	fstream output2;
	fstream output3;
	fstream output4;
	string name1 = "./data/" + type + "Sample/" + type +"_5_data.txt" ;
	string name2 = "./data/" + type + "Sample/" + type +"_10_data.txt" ;
	string name3 = "./data/" + type + "Sample/" + type +"_15_data.txt" ;
	string name4 = "./data/" + type + "Sample/" + type +"_20_data.txt" ;
	output1.open(name1.c_str() , ios::out);
	output2.open(name2.c_str() , ios::out);
	output3.open(name3.c_str() , ios::out);
	output4.open(name4.c_str() , ios::out);
	double tempx , tempy ;
	string name ;
	string temp = "./data/" + type + "Sample/Sample_";
	char buf[30];
	for(int ipoint = 0 ; ipoint < n ; ipoint++){
		sprintf(buf , "%d" , ipoint);
		name = buf ;
		name = temp + name + ".txt";
		input.open(name.c_str() , ios::in); 
		if( !input ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		for(int i = 0 ; i <= step ; i++){
			input >> tempx >> tempy ;
			if( i == 5 ){
				output1 << std::fixed << tempx << '\t' << std::fixed << tempy << endl;
			}
			if( i == 10 ){
				output2 << std::fixed << tempx << '\t' << std::fixed << tempy << endl;
			}
			if( i == 15 ){
				output3 << std::fixed << tempx << '\t' << std::fixed << tempy << endl;
			}
			if( i == 20 ){
				output4 << std::fixed << tempx << '\t' << std::fixed << tempy << endl;
			}
		}
		input.close();
	}
	output1.close();
	output2.close();
	output3.close();
	output4.close();
	cout << type << " samples have been handled !" << endl;
}

int SAWsample(int step , int n , string type){
	fstream input;
	fstream output1;
	fstream output2;
	fstream output3;
	fstream output4;
	string name1 = "./data/" + type + "SAWSample/" + type +"_5_data.txt" ;
	string name2 = "./data/" + type + "SAWSample/" + type +"_10_data.txt" ;
	string name3 = "./data/" + type + "SAWSample/" + type +"_15_data.txt" ;
	string name4 = "./data/" + type + "SAWSample/" + type +"_20_data.txt" ;
	output1.open(name1.c_str() , ios::out);
	output2.open(name2.c_str() , ios::out);
	output3.open(name3.c_str() , ios::out);
	output4.open(name4.c_str() , ios::out);
	double tempx , tempy ;
	string name ;
	string temp = "./data/" + type + "SAWSample/Sample_";
	char buf[30];
	for(int ipoint = 0 ; ipoint < n ; ipoint++){
		sprintf(buf , "%d" , ipoint);
		name = buf ;
		name = temp + name + ".txt";
		input.open(name.c_str() , ios::in); 
		if( !input ){
			cout << "Failed to open file " << endl;
			return 0; 
		}
		for(int i = 0 ; i <= step ; i++){
			input >> tempx >> tempy ;
			if( i == 5 ){
				output1 << std::fixed << tempx << '\t' << std::fixed << tempy << endl;
			}
			if( i == 10 ){
				output2 << std::fixed << tempx << '\t' << std::fixed << tempy << endl;
			}
			if( i == 15 ){
				output3 << std::fixed << tempx << '\t' << std::fixed << tempy << endl;
			}
			if( i == 20 ){
				output4 << std::fixed << tempx << '\t' << std::fixed << tempy << endl;
			}
		}
		input.close();
	}
	output1.close();
	output2.close();
	output3.close();
	output4.close();
	cout << type << " SAWsamples have been handled !" << endl;
}
