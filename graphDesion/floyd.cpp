#include"head.h"
extern Graph graph[N];//extern variable 
extern int villageN;//extern variable 

void floyd(int &furthestVill, int &allVill) {
	//-----floyd algorithm-----
	for (int k = 0; k < villageN; k++) {
		for (int i = 0; i < villageN; i++) {
			for (int j = 0; j < villageN; j++) {
				graph[i].dis[j] = min(graph[i].dis[j], graph[i].dis[k] + graph[k].dis[j]);
			}
		}
	}
	//---get furthest distance and sum distance --- 
	for (int i = 0; i < villageN; i++) {
		graph[i].dis[i] = 0x3f3f3f3f;
		for (int j = 0; j < villageN; j++) {
			if (i == j || graph[i].dis[j] > 0x3f3f3f)continue;
			graph[i].Q.push(graph[i].dis[j]);//get the furthest distance
			graph[i].sum += graph[i].dis[j];//maintain the sum of distance
		}
		graph[i].furthest = graph[i].Q.top();
		if (graph[furthestVill].furthest > graph[i].furthest)
			furthestVill = i;
		if (graph[allVill].sum > graph[i].sum)
			allVill = i;
	}
}