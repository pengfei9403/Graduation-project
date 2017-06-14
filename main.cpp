#include <iostream>
#include <fstream>
#include <iomanip>
#include "line.h"
#include "triangle.h"
#include "square.h"
#include "hex.h"
#include "function.h"
#include "s_function.h"

using namespace std;

int main(){
	int steps , flag , n;
	long int begin , end , t ; 
	string walk_mark , LFD_mark , file_mark ;
//	cout << "Please select the method of random number generation：" << endl ;
//	cout << "1、系统函数 rand() " << endl;
//	cout << "2、乘同余法 " << endl;
//	cout << "3、乘加同余法 " << endl; 
//	cout << "4、人字映射法 " << endl;
//	cin >> flag ;
	flag = 4;
	begin = time(0) ;
	
//	cout << "Would you want to calculate the the mean square distance by no files generated. <Y/N>" << endl;
//	cin >> walk_mark ;
//	if(walk_mark == "Y" || walk_mark == "y"){
//		cout << "Plesse input the number of steps: " << endl;
//		cin >> steps ;
//		cout << "Please input the number of points: "<< endl;
//		cin >> n ;
//		steps = 1000 ; n = 10000 ; 
//		cout << endl; 
//		LineWalk(steps , n , flag);
//		cout << endl;
//		SquareWalk(steps , n , flag);
//		cout << endl;
//		TriangleWalk(steps , n , flag);
//		cout << endl;
//		HexWalk(steps , n , flag);
//		steps = 20 ; n = 100 ;
//		cout << endl;
//		SquareSAW(steps , n , flag);
//		cout << endl;
//		TriangleSAW(steps , n , flag);
//		cout << endl;
//		HexSAW(steps , n , flag); 
//	}
	
//	cout << "Would you want to calculate the the mean square distance by files generated. <Y/N>" << endl; 
//	cin>> file_mark ;
//	if(file_mark == "Y" || file_mark == "y"){
//		cout << "Plesse input the number of steps: " << endl;
//		cin >> steps ;
//		cout << "Please input the number of points: "<< endl;
//		cin >> n ;
//		cout << endl;
//		steps = 20 ; n = 30 ;
//		LineSample(steps , n , flag);
//		cout << endl;
//		SquareSample(steps , n , flag);
//		cout << endl;
//		TriangleSample(steps , n , flag);
//		cout << endl;
//		HexSample(steps , n , flag); 
//		steps = 20 ; n = 30 ;
//		cout << endl;
//		SquareSAW_Sample(steps , n , flag);
//		cout << endl;
//		TriangleSAW_Sample(steps , n , flag);
//		cout << endl;
//		HexSAW_Sample(steps , n , flag); 
//	}
//	
//	cout << "Would you want to calculate the the local fractal dimensionality by no files generated. <Y/N>" << endl; 
//	cin >> LFD_mark ;
//	if(LFD_mark == "Y" || LFD_mark == "y"){
//		cout << "Plesse input the number of steps: " << endl;
//		cin >> steps ;
//		cout << "Please input the number of points: "<< endl;
//		cin >> n ;
//		steps = 50 ; n = 10000 ;
//		cout << endl;
//		Square_lfd(steps , n , flag );
//		cout << endl;
//		Triangle_lfd(steps , n , flag );
//		cout << endl;
//		Hex_lfd(steps , n , flag );
		steps = 20 ; n = 100 ;
		cout << endl;
		Square_SAW_lfd(steps , n , flag );
		cout << endl;
		Triangle_SAW_lfd(steps , n , flag );
		cout << endl;
		Hex_SAW_lfd(steps , n , flag );
		cout << endl;
//	}
	
//	Hex obj(100,4);
//	obj.randWalk();
//	obj.showSteps();
//	obj.SAW();
//	cout << "number of walk :"<<obj.getSteps()<<endl;
//	fstream output;
//	output.open("./data/saw.txt" , ios::out);
//	for(int i = 0 ; i <= obj.getSteps() ; i++){
//		output << std::fixed << obj.getLocation_x()[i] << "\t" << std::fixed << obj.getLocation_y()[i] << endl;
//	}

//	cout << "Please input the number of points: "<< endl;
//	cin >> n ;
//	int count , begin , end ;
//	begin = time(0);
//	for(int i = 0 ; i < n ; ){
//		Square *obj = new Square(20 , 4);
//		obj->SAW();
//		if(obj->getSignal()){
//			i++;
//		}
//		count++;
//		delete obj;
////		cout << count << '\t' << i << endl;
//	}
//	end = time(0);
//	cout << "time = " << end - begin << endl;
//	SquareSAW(20 , n , 4);
//	TriangleSAW(50 , n , 4);
//	HexSAW(50 , n , 4);
	
	end = time(0) ;
	t = end - begin ;
	cout << "The entire time cost is : " << t / 3600 << " h " << (t/60) % 60 << " mins " << t % 60 << " seconds" << endl;
	return 0;
}
