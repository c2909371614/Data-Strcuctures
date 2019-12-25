#include"head.h"
void sortClass::shellSort() {
	//disArray();

	int i, j, gap = rowN / 2;
	char tChar[20];
	while (gap > 0) {
		for (int i = gap; i < rowN; i++) {//对所有间隔gap的元素进行插入排序
			strcpy(tChar, Array[i]);
			j = i - gap;
			while (j >= 0 && strcmp(tChar, Array[j]) < 0) {
				strcpy(Array[j + gap], Array[j]);
				j -= gap;
			}
			strcpy(Array[j + gap], tChar);
		}
		gap >>= 1;//除二
	}
	//disArray();
}