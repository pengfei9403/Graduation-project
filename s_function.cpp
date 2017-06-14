#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>
#include <time.h>
#include "function.h"
#include "line.h"
#include "triangle.h"
#include "square.h"
#include "hex.h"

using namespace std;


//  在正方形上进行自规避随机行走 

int SquareSAW( int steps , int n , int flag ){
	long int begin , end ;
	int count = 0 , temp = 0 ;
	int len = 1 ;
	int loop = steps / len ;
	double temp_mean_sd[loop];
	double temp_sum_sd[loop];
	double mean_sd[loop];										//  记录均方距离 
	double sum_sd[loop];										//  记录平方距离之和 
	for(int i = 0 ; i < loop ; i++){
		temp_mean_sd[i] = 0 ;
		temp_sum_sd[i] = 0 ;
		mean_sd[i] = 0 ;
		sum_sd[i] = 0 ;
	}
	fstream outputFile;
	fstream temp_outputFile;
	begin = time(0) ;
	for (int ipoint = 0 ; ipoint < n ; ){
		Square *obj = new Square(steps , flag);
		obj->SAW();
		if( obj->getSignal() ){
			for( int i = 0 ; i < loop ; i++){
				int temp_steps = (i+1) * len ;
				sum_sd[i] += obj->getSquaredistance(temp_steps);
			}
			ipoint++ ;
		}
		if( obj->getSteps() == steps ){
			for( int i = 0 ; i < loop ; i++){
				int temp_steps = (i+1) * len ;
				temp_sum_sd[i] += obj->getSquaredistance(temp_steps);
			}
			temp++ ;		
		}
		count++ ;
		delete obj;
	}
	for(int i = 0 ; i < loop ; i++){
		mean_sd[i] = sum_sd[i] / n ;
		temp_mean_sd[i] = temp_sum_sd[i] / temp ;
	}
	outputFile.open("./data/Square_SAW_data.txt",ios::out);
	temp_outputFile.open("./data/Square_SAW_data_temp.txt",ios::out);
	if( !outputFile ){
		cout << "Failed to open file \"Square_SAW_data.txt\" "<< endl;
		return 0; 
	}
	for (int i = 0 ; i < loop ; i++){
		outputFile << std::fixed << mean_sd[i] <<endl;
		temp_outputFile << std::fixed << temp_mean_sd[i] <<endl;
	}
	outputFile.close();
	temp_outputFile.close();
	end = time(0) ;
	cout << n << " Square samples have been generated , the total number is ：" << count << endl;
	cout << "The number of " << steps << " steps samples is : " << temp << endl;
	cout << "The efficiency of samples is : " << (double)  100*n / count << "%" << '\t' << (double) 100*n / temp << "%" << endl;
	cout << "Time cost ：" << end - begin << " seconds" << endl ;
	return 1;
}


int TriangleSAW( int steps , int n , int flag ){
	long int begin , end ;
	int count = 0 , temp = 0 ;
	int len = 1 ;
	int loop = steps / len ;
	double temp_mean_sd[loop];
	double temp_sum_sd[loop];
	double mean_sd[loop];										//  记录均方距离 
	double sum_sd[loop];										//  记录平方距离之和 
	for(int i = 0 ; i < loop ; i++){
		temp_mean_sd[i] = 0 ;
		temp_sum_sd[i] = 0 ;
		mean_sd[i] = 0 ;
		sum_sd[i] = 0 ;
	}
	fstream outputFile;
	fstream temp_outputFile;
	begin = time(0) ;
	for (int ipoint = 0 ; ipoint < n ; ){
		Triangle *obj = new Triangle(steps , flag);
		obj->SAW();
		if( obj->getSignal() ){
			for( int i = 0 ; i < loop ; i++){
				int temp_steps = (i+1) * len ;
				sum_sd[i] += obj->getSquaredistance(temp_steps);
			}
			ipoint++ ;
		}
		if( obj->getSteps() == steps ){
			for( int i = 0 ; i < loop ; i++){
				int temp_steps = (i+1) * len ;
				temp_sum_sd[i] += obj->getSquaredistance(temp_steps);
			}
			temp++ ;		
		}
		count++ ;
		delete obj;
	}
	for(int i = 0 ; i < loop ; i++){
		mean_sd[i] = sum_sd[i] / n ;
		temp_mean_sd[i] = temp_sum_sd[i] / temp ;
	}
	outputFile.open("./data/Triangle_SAW_data.txt",ios::out);
	temp_outputFile.open("./data/Triangle_SAW_data_temp.txt",ios::out);
	if( !outputFile ){
		cout << "Failed to open file \"Triangle_SAW_data.txt\" "<< endl;
		return 0; 
	}
	for (int i = 0 ; i < loop ; i++){
		outputFile << std::fixed << mean_sd[i] <<endl;
		temp_outputFile << std::fixed << temp_mean_sd[i] <<endl;
	}
	outputFile.close();
	temp_outputFile.close();
	end = time(0) ;
	cout << n << " triangle samples have been generated , the total number is ：" << count << endl;
	cout << "The number of " << steps << " steps samples is : " << temp << endl;
	cout << "The efficiency of samples is : " << (double)  100*n / count << "%" << '\t' << (double) 100*n / temp << "%" << endl;
	cout << "Time cost ：" << end - begin << " seconds" << endl ;
	return 1;
}


int HexSAW( int steps , int n , int flag ){
	long int begin , end ;
	int count = 0 , temp = 0 ;
	int len = 1 ;
	int loop = steps / len ;
	double temp_mean_sd[loop];
	double temp_sum_sd[loop];
	double mean_sd[loop];										//  记录均方距离 
	double sum_sd[loop];										//  记录平方距离之和 
	for(int i = 0 ; i < loop ; i++){
		temp_mean_sd[i] = 0 ;
		temp_sum_sd[i] = 0 ;
		mean_sd[i] = 0 ;
		sum_sd[i] = 0 ;
	}
	fstream outputFile;
	fstream temp_outputFile;
	begin = time(0) ;
	for (int ipoint = 0 ; ipoint < n ; ){
		Hex *obj = new Hex(steps , flag);
		obj->SAW();
		if( obj->getSignal() ){
			for( int i = 0 ; i < loop ; i++){
				int temp_steps = (i+1) * len ;
				sum_sd[i] += obj->getSquaredistance(temp_steps);
			}
			ipoint++ ;
		}
		if( obj->getSteps() == steps ){
			for( int i = 0 ; i < loop ; i++){
				int temp_steps = (i+1) * len ;
				temp_sum_sd[i] += obj->getSquaredistance(temp_steps);
			}
			temp++ ;		
		}
		count++ ;
		delete obj;
	}
	for(int i = 0 ; i < loop ; i++){
		mean_sd[i] = sum_sd[i] / n ;
		temp_mean_sd[i] = temp_sum_sd[i] / temp ;
	}
	outputFile.open("./data/Hex_SAW_data.txt",ios::out);
	temp_outputFile.open("./data/Hex_SAW_data_temp.txt",ios::out);
	if( !outputFile ){
		cout << "Failed to open file \"Hex_SAW_data.txt\" "<< endl;
		return 0; 
	}
	for (int i = 0 ; i < loop ; i++){
		outputFile << std::fixed << mean_sd[i] <<endl;
		temp_outputFile << std::fixed << temp_mean_sd[i] <<endl;
	}
	outputFile.close();
	temp_outputFile.close();
	end = time(0) ;
	cout << n << " Hex samples have been generated , the total number is ：" << count << endl;
	cout << "The number of " << steps << " steps samples is : " << temp << endl;
	cout << "The efficiency of samples is : " << (double)  100*n / count << "%" << '\t' << (double) 100*n / temp << "%" << endl;
	cout << "Time cost ：" << end - begin << " seconds" << endl ;
	return 1;
}


void Square_SAW_lfd(int steps , int n , int flag ){					//  计算并返回 N 步均方根数组 
	long int begin , end ; 
	int count = 0 ;
	double* temp = new double [n * (steps-1)];
	double temp1[steps-1]; 
	double value[steps - 1];
	begin = time(0) ;
//	double value [steps-1];
	for(int ipoint = 0 ; ipoint < n ; ){
		Square* obj = new Square(steps , flag);
		obj->SAW();
		if( obj->getSignal() ){
			rr(obj->getLocation_x() , obj->getLocation_y() , steps , temp1);
			for(int istep = 0 ; istep < steps - 1 ; istep++){
				temp[ipoint * (steps-1) + istep] = temp1[istep];
			} 
			ipoint++ ;
		}
		count++ ;
		delete obj ;
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
	LFD(steps , value , "Square_SAW");
	end = time(0) ;
	cout << "Square_SAW_lfd is caculated with " << n << "samples !" << endl;
	cout << "The total number is : " << count << endl;
	cout << "The efficiency of samples is : " << (double)  100*n / count << "%" <<endl;
	cout << "Time cost ：" << end - begin << " seconds" << endl ;
//	return value;
}

void Triangle_SAW_lfd(int steps , int n , int flag ){					//  计算并返回 N 步均方根数组 
	long int begin , end ;
	int count = 0 ;
	double* temp = new double [n * (steps-1)];
	double temp1[steps-1]; 
	double value[steps - 1];
//	double value [steps-1];
	begin = time(0) ;
	for(int ipoint = 0 ; ipoint < n ; ){
		Triangle* obj = new Triangle(steps , flag);
		obj->SAW();
		if( obj->getSignal() ){
			rr(obj->getLocation_x() , obj->getLocation_y() , steps , temp1);
			for(int istep = 0 ; istep < steps - 1 ; istep++){
				temp[ipoint * (steps-1) + istep] = temp1[istep];
			} 
			ipoint++ ;
		}
		count++ ;
		delete obj;
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
	LFD(steps , value , "Triangle_SAW");
	end = time(0) ;
	cout << "Triangle_SAW_lfd is caculated with " << n << "samples !" << endl;
	cout << "The total number is : " << count << endl;
	cout << "The efficiency of samples is : " << (double)  100*n / count << "%" <<endl;
	cout << "Time cost ：" << end - begin << " seconds" << endl ;
//	return value;
}

void Hex_SAW_lfd(int steps , int n , int flag ){					//  计算并返回 N 步均方根数组 
	long int begin , end ;
	int count = 0 ;
	double* temp = new double [n * (steps-1)];
	double temp1[steps-1]; 
	double value[steps - 1];
//	double value [steps-1];
	begin = time(0) ;
	for(int ipoint = 0 ; ipoint < n ; ){
		Hex* obj = new Hex(steps , flag);
		obj->SAW();
		if( obj->getSignal() ){
			rr(obj->getLocation_x() , obj->getLocation_y() , steps , temp1);
			for(int istep = 0 ; istep < steps - 1 ; istep++){
				temp[ipoint * (steps-1) + istep] = temp1[istep];
			}
			ipoint++ ;
		}
		count++ ;
		delete obj;
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
	LFD(steps , value , "Hex_SAW");
	end = time(0) ;
	cout << "Hex_SAW_lfd is caculated with " << n << "samples !" << endl;
	cout << "The total number is : " << count << endl;
	cout << "The efficiency of samples is : " << (double)  100*n / count << "%" <<endl;
	cout << "Time cost ：" << end - begin << " seconds" << endl ;
//	return value;
}

int SquareSAW_Sample(int steps , int n , int flag){
	long int begin , end ;
	int count = 0 ;
	fstream output;
	string name , name2 , temp ;
	string name3 = "./data/SquareSAWSample/Sample_30_" ;
	string name1 = "./data/SquareSAWSample/Sample_" ;
	char buf[30];
	begin = time(0) ;
	for(int ipoint = 0 ; ipoint < n ; ){
		Square *obj = new Square(steps , flag);
		obj->SAW();
		if( obj->getSignal() ){
			sprintf(buf, "%d", ipoint);
			temp = buf ;
			name = name1 + temp + ".txt" ;
			name2 = name3 + temp +".txt" ;
			output.open(name.c_str() , ios::out) ;
			if( !output ){
				cout << "Failed to open file " << endl;
				return 0; 
			}
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
			ipoint++ ;
		}
		count++ ;
		delete obj;
	}
	cout << n << " SquareSAW_Samples have been generated !" <<endl;
	read_MD(steps , n , "SquareSAW");
	SAWsample(steps , n , "Square");
	end = time(0) ;
	cout << "The total number is : " << count << endl;
	cout << "The efficiency of samples is : " << (double)  100*n / count << "%" <<endl;
	cout << "Time cost is : " << end - begin << " seconds" << endl;
}

int TriangleSAW_Sample(int steps , int n , int flag){
	long int begin , end ;
	int count = 0 ;
	fstream output;
	string name , name2 , temp ;
	string name3 = "./data/TriangleSAWSample/Sample_30_" ;
	string name1 = "./data/TriangleSAWSample/Sample_" ;
	char buf[30];
	begin = time(0) ;
	for(int ipoint = 0 ; ipoint < n ; ){
		Triangle *obj = new Triangle(steps , flag);
		obj->SAW();
		if( obj->getSignal() ){
			sprintf(buf, "%d", ipoint);
			temp = buf ;
			name = name1 + temp + ".txt" ;
			name2 = name3 + temp + ".txt" ;
			output.open(name.c_str() , ios::out) ;
			if( !output ){
				cout << "Failed to open file " << endl;
				return 0; 
			}
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
			ipoint++ ;
		}
		count++ ;
		delete obj;
	}
	cout << n << " TriangleSAW_Samples have been generated !" <<endl;
	read_MD(steps , n , "TriangleSAW");
	SAWsample(steps , n , "Triangle");
	end = time(0) ;
	cout << "The total number is : " << count << endl;
	cout << "The efficiency of samples is : " << (double)  100*n / count << "%" <<endl;
	cout << "Time cost is : " << end - begin << " seconds" << endl;
}

int HexSAW_Sample(int steps , int n , int flag){
	long int begin , end ;
	int count = 0 ;
	fstream output;
	string name , name2 , temp ;
	string name3 = "./data/HexSAWSample/Sample_30_" ;
	string name1 = "./data/HexSAWSample/Sample_" ;
	char buf[30];
	begin = time(0) ;
	for(int ipoint = 0 ; ipoint < n ; ){
		Hex *obj = new Hex(steps , flag);
		obj->SAW();
		if( obj->getSignal() ){
			sprintf(buf, "%d", ipoint);
			temp = buf ;
			name = name1 + temp + ".txt" ;
			name2 = name3 + temp + ".txt" ;
			output.open(name.c_str() , ios::out) ;
			if( !output ){
				cout << "Failed to open file " << endl;
				return 0; 
			}
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
			ipoint++ ;
		}
		count++ ;
		delete obj;
	}
	cout << n << " HexSAW_Samples have been generated !" <<endl;
	read_MD(steps , n , "HexSAW");
	SAWsample(steps , n , "Hex");
	end = time(0) ;
	cout << "The total number is : " << count << endl;
	cout << "The efficiency of samples is : " << (double)  100*n / count << "%" <<endl;
	cout << "Time cost is : " << end - begin << " seconds" << endl;
}
