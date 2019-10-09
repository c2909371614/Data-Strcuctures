#include<cstdio>
#include<iostream>
int _1(int N){
	int sum = 0;
	for(int i = 0; i < N; i++)
		sum++;
}
int _2(int N){
	int sum = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			sum++;
}
int _3(int N){
	int sum = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N * N; j++)
			sum++;
}
int _4(int N){
	int sum = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < i; j++)
			sum++;
}
int _5(int N){
	int sum = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < i * i; j++)
			for(int k = 0; k < j; k++)
				sum++;
}
int _6(int N){
	int sum = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < i * i; j++)
			if(j % i == 0)
				for(int k = 0; k < j; k++)
					sum++;
}