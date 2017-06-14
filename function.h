#ifndef FUNCTION_H
#define FUNCTION_H

#include "rand_walk.h"

double meanValue( double *arr , int steps);

double var( double *arr , int steps);

int LineWalk( int steps , int n , int flag );

int SquareWalk( int steps , int n , int flag);

int TriangleWalk( int steps , int n , int flag);

int HexWalk( int steps , int n , int flag);

//  计算并返回 N 步支链均方根 
double r(double x[] , double y[] , int n , int steps);

//  计算并返回 N 步平方根 数组 
void rr(double x[] , double y[] , int steps , double value[]);

//  计算并保存二维正方形格子局部分形维数 
void Square_lfd(int steps , int n , int flag );

//  计算并保存二维三角形格子局部分形维数 
void Triangle_lfd(int steps , int n , int flag );

//  计算并保存二维六边形格子局部分形维数 
void Hex_lfd(int steps , int n , int flag );

//  计算并保存局部分形维数数组
int LFD (int steps , double rr[] , string type);

//  生成 n 个直线随机行走样本点数据
int LineSample(int stesp , int n , int flag);

//  生成 n 个二维正方形格点随机行走样本点数据
int SquareSample(int steps , int n , int flag);

//  生成 n 个二维三角形格点随机行走样本点数据
int TriangleSample(int steps , int n , int flag);

//  生成 n 个二维六边形格点随机行走样本点数据
int HexSample(int steps , int n , int flag) ;

//  从文件读取数据并计算均方根 
int read_MD(int steps , int n , string type); 

int sample(int step , int n , string type);

int SAWsample(int step , int n , string type);

 
#endif 
