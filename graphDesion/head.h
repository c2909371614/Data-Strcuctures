#ifndef HEAD
#define HEAD
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<sstream>
#include<map>
#include<queue>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
const int N = 105;
//可变的变量不要放在头文件中，否则会出现重定义的错误
using namespace std;
class Graph {
	friend void getData();//import the graph from file
	friend void floyd(int&, int&);//get the nearest distance from i to j
	friend void printDistance();//print the distance i to j
	friend bool cmpSingle(Graph A, Graph B);
	friend bool cmpAll(Graph A, Graph B);
	friend void init();
private:
	int dis[N];
	priority_queue<int> Q;//get the furthest
	int sum;
	int furthest;
public:
	int tot;
	Graph();
	~Graph();
	Graph copy(const Graph& A);
};
//Graph graph[N];
void getData();
void floyd(int&, int&);
void printDistance();
bool cmpSingle(Graph A, Graph B);
bool cmpAll(Graph A, Graph B);
void init();
#endif