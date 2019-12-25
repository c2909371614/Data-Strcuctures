#include"head.h"
void sortClass::insertSort() {
	int i, j;
	char tChar[20];
	for (i = 1; i < rowN; i++) {
		strcpy(tChar, Array[i]);
		j = i - 1;
		while (j >= 0 && strcmp(tChar, Array[j]) < 0) {
			strcpy(Array[j + 1], Array[j]);
			j--;
		}
		strcpy(Array[j + 1], tChar);
	}
	//outdata("insertSort.txt");
}