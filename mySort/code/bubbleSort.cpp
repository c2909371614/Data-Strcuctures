#include"head.h"
void sortClass :: bubbleSort() {
	//cout << "����ǰ: ";
	//disArray();
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < rowN-i; j++) {
			if (strcmp(Array[j], Array[j + 1])  > 0) {
				char tChar[20];
				//----����������ð�ݴﵽ��С���������Ŀ��---
				strcpy(tChar, Array[j]);
				strcpy(Array[j], Array[j + 1]);
				strcpy(Array[j + 1], tChar);
			}
		}
	}
//	cout << "�����";
//	disArray();
}