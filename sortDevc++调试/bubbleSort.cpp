#include"head.h"
void sortClass :: bubbleSort() {
//	cout << "排序前: ";
//	disArray();
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < rowN-i; j++) {
			if (strcmp(Array[j], Array[j + 1])  > 0) {
				char tChar[20];
				//----将大的数向后冒泡达到从小到大的排序目的---
				strcpy(tChar, Array[j]);
				strcpy(Array[j], Array[j + 1]);
				strcpy(Array[j + 1], tChar);
			}
		}
	}
//	cout << "排序后：";
//	disArray();
}
