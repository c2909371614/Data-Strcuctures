
#include"head.h"
extern Graph graph[N];//extern variable 
extern int villageN;//extern variable 
Graph::Graph() {
	tot = -1;
	sum = 0;
	memset(dis, 0x3f, sizeof(dis));//Initialize dis with a
	while (!Q.empty()) {
		Q.pop();//clear the priority
	}
}
Graph :: ~Graph() {}
Graph Graph :: copy(const Graph& A) {//copy the data
	if (this != &A) {
		for (int i = 0; i < N; i++)
			dis[i] = A.dis[i];
		Q = A.Q;
		sum = A.sum;
		tot = A.tot;
		furthest = A.furthest;
	}
	return *this;
}
void getData() {
	fstream in("graph.txt", ios::in);
	int x, y, z;
	in >> villageN;// the number of village
	while (in >> x >> y >> z) {
		graph[x].dis[y] = z;//z is the distance of x --> y
		graph[y].dis[x] = z;
	}
	in.close();
}
void printDistance() {
	for (int i = 0; i < villageN; i++) {
		printf("%d-th village sum of distance = %d furthest = %d\n", i, graph[i].sum, graph[i].Q.top() );
		for (int j = 0; j < villageN; j++) {
			if (i >= j )continue;
			printf("distance of %d to % d = %d\n", i, j, graph[i].dis[j]);//cout  the data
		}
	}
}
bool cmpSingle(Graph A, Graph B) {
	return A.furthest < B.furthest;
}
bool cmpAll(Graph A, Graph B) {
	return A.sum < B.sum;
}
void init() {
	for (int i = 0; i < villageN; i++)
		graph[i].tot = i;
}
