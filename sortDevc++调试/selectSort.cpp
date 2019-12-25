#include"head.h"
void sortClass::disArray() {//输出字符串数组
	for (int i = 0; i < rowN; i++)
		cout << Array[i] << " ";
	cout << endl;
}
void sortClass::selectSort() {//插入排序
//	cout << "排序前: ";
//	disArray();
	//----- 开始排序----
	for (int i = 0; i < rowN; i++) {
		int min = i;
		strcpy(Array[min], Array[i]);
		for (int j = i; j < rowN; j++) {
			if (strcmp(Array[min], Array[j]) > 0)//找到最小的字符串
				min = j;
		}
		char tChar[20];
		//---- 将最小的字符串插入有序数组---
		strcpy(tChar, Array[i]);
		strcpy(Array[i], Array[min]);
		strcpy(Array[min], tChar);
	}

//	//---------
//	cout << "排序后: ";
//	disArray();
}
