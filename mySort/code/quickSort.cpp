#include"head.h"
void sortClass :: quickSort(int L, int R) {
	int i = L, j = R;
	char tChar[20];
	if (L < R) {
		strcpy(tChar, Array[i]);//������ĵ�һ��Ԫ����Ϊ��׼
		while (i != j) {
			while (j > i&& strcmp(Array[j], tChar) >= 0)
				j--;//�ҵ��ұߵ�һ��С�ڻ�׼�Ĵ�
			strcpy(Array[i], Array[j]);
			while (i < j && strcmp(Array[i], tChar) <= 0)
				i++;//�ҵ���ߵ�һ�����ڻ�׼�Ĵ�
			strcpy(Array[j], Array[i]);
		}
		strcpy(Array[i], tChar);
		quickSort(L, i - 1);//��������
		quickSort(i + 1, R);//��������
	}
}