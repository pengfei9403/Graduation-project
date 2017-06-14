#ifndef FUNCTION_H
#define FUNCTION_H

#include "rand_walk.h"

double meanValue( double *arr , int steps);

double var( double *arr , int steps);

int LineWalk( int steps , int n , int flag );

int SquareWalk( int steps , int n , int flag);

int TriangleWalk( int steps , int n , int flag);

int HexWalk( int steps , int n , int flag);

//  ���㲢���� N ��֧�������� 
double r(double x[] , double y[] , int n , int steps);

//  ���㲢���� N ��ƽ���� ���� 
void rr(double x[] , double y[] , int steps , double value[]);

//  ���㲢�����ά�����θ��Ӿֲ�����ά�� 
void Square_lfd(int steps , int n , int flag );

//  ���㲢�����ά�����θ��Ӿֲ�����ά�� 
void Triangle_lfd(int steps , int n , int flag );

//  ���㲢�����ά�����θ��Ӿֲ�����ά�� 
void Hex_lfd(int steps , int n , int flag );

//  ���㲢����ֲ�����ά������
int LFD (int steps , double rr[] , string type);

//  ���� n ��ֱ�������������������
int LineSample(int stesp , int n , int flag);

//  ���� n ����ά�����θ�������������������
int SquareSample(int steps , int n , int flag);

//  ���� n ����ά�����θ�������������������
int TriangleSample(int steps , int n , int flag);

//  ���� n ����ά�����θ�������������������
int HexSample(int steps , int n , int flag) ;

//  ���ļ���ȡ���ݲ���������� 
int read_MD(int steps , int n , string type); 

int sample(int step , int n , string type);

int SAWsample(int step , int n , string type);

 
#endif 
