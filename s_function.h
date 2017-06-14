#ifndef S_FUNCTION_H
#define S_FUNCTION_H

int SquareSAW( int steps , int n , int flag );

int TriangleSAW( int steps , int n , int flag );

int HexSAW( int steps , int n , int flag );

//  计算并保存二维正方形格子局部分形维数 
void Square_SAW_lfd(int steps , int n , int flag );

//  计算并保存二维三角形格子局部分形维数 
void Triangle_SAW_lfd(int steps , int n , int flag );

//  计算并保存二维六边形格子局部分形维数 
void Hex_SAW_lfd(int steps , int n , int flag );

//  生成 n 个二维正方形格点随机行走样本点数据
int SquareSAW_Sample(int steps , int n , int flag);

//  生成 n 个二维三角形格点随机行走样本点数据
int TriangleSAW_Sample(int steps , int n , int flag);

//  生成 n 个二维六边形格点随机行走样本点数据
int HexSAW_Sample(int steps , int n , int flag) ;

#endif 
