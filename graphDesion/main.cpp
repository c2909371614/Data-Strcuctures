#include"head.h"
using namespace std;
int villageN;//extern variable 
Graph graph[N];
int main() {
	int furthestVill = 0;
	int allVill = 0;
	init();
	getData();
	floyd(furthestVill, allVill);
	printDistance();

	cout << "使距离医院最远的村庄到医院的路程最短的村庄：" << furthestVill << endl;
	cout << "使其它所有村庄到医院的路径总和最短的村庄：" << allVill << endl;
}