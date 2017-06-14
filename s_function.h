#ifndef S_FUNCTION_H
#define S_FUNCTION_H

int SquareSAW( int steps , int n , int flag );

int TriangleSAW( int steps , int n , int flag );

int HexSAW( int steps , int n , int flag );

//  ���㲢�����ά�����θ��Ӿֲ�����ά�� 
void Square_SAW_lfd(int steps , int n , int flag );

//  ���㲢�����ά�����θ��Ӿֲ�����ά�� 
void Triangle_SAW_lfd(int steps , int n , int flag );

//  ���㲢�����ά�����θ��Ӿֲ�����ά�� 
void Hex_SAW_lfd(int steps , int n , int flag );

//  ���� n ����ά�����θ�������������������
int SquareSAW_Sample(int steps , int n , int flag);

//  ���� n ����ά�����θ�������������������
int TriangleSAW_Sample(int steps , int n , int flag);

//  ���� n ����ά�����θ�������������������
int HexSAW_Sample(int steps , int n , int flag) ;

#endif 
