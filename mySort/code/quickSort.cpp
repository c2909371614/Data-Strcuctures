#include"head.h"
void sortClass :: quickSort(int L, int R) {
	int i = L, j = R;
	char tChar[20];
	if (L < R) {
		strcpy(tChar, Array[i]);//以区间的第一个元素作为基准
		while (i != j) {
			while (j > i&& strcmp(Array[j], tChar) >= 0)
				j--;//找到右边第一个小于基准的串
			strcpy(Array[i], Array[j]);
			while (i < j && strcmp(Array[i], tChar) <= 0)
				i++;//找到左边第一个大于基准的串
			strcpy(Array[j], Array[i]);
		}
		strcpy(Array[i], tChar);
		quickSort(L, i - 1);//向左排序
		quickSort(i + 1, R);//向右排序
	}
}