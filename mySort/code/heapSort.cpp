#include"head.h"
struct myChar {
	char ele[20];
	myChar(char Ele[]) {
		strcpy(ele, Ele);
	}
};
bool operator>(myChar A, myChar B) {
	if (strcmp(A.ele, B.ele) > 0)
		return true;
	return false;
}
bool operator<(myChar A, myChar B) {
	if (strcmp(A.ele, B.ele) < 0)
		return true;
	return false;
}
void sortClass :: heapSort() {
	//cout << "ÅÅĞòÇ°£º";
	//disArray();
	priority_queue<myChar> Q;
	for (int i = 0; i < rowN; i++) {
		myChar tChar(Array[i]);
		Q.push(tChar);
	}
	for (int i = 0; i < rowN; i++) {
		strcpy(Array[rowN-i-1], Q.top().ele);
		Q.pop();
	}
	//cout << "ÅÅĞòºó£º";
	//disArray();
}