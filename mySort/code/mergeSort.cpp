#include"head.h"
void Merge(char Array[N][20], int low, int mid, int high) {
	//������R[low..mid]��R[mid+1..high]��·�鲢
	char tChar[N][N];
	int i = low, j = mid + 1, k = 0; // k��R���±꣬ i�� j�ֱ�Ϊ��1��2�ε��±�
	while (i <= mid && j <= high) {
		if (strcmp(Array[i], Array[j]) <= 0) {
			strcpy(tChar[k], Array[i]);
			k++, i++;
		}
		else {
			strcpy(tChar[k], Array[j]);
			k++, j++;
		}
	}
	//-------��ʣ��Ĳ���ȫ������tChar������----
	while (i <= mid) {
		strcpy(tChar[k], Array[i]);
		k++, i++;
	}
	while (j <= high) {
		strcpy(tChar[k], Array[j]);
		k++, j++;
	}
	//---����������tChar�е�data���ƻ�����---
	for (k = 0, i = low; i <= high; k++, i++)
		strcpy(Array[i], tChar[k]);
}
void MergePass(char Array[N][20], int length, int n) {
	//----���һ�ι鲢-----
	int i;
	for (i = 0; i + 2 * length <= n; i = i + 2 * length)//0 2 4 6 
		//---������ֳɵȳ����ӱ����һ�˹鲢�������Ԫ�ز�������--
		Merge(Array, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n)//�����һ�鲻�ȳ���Ԫ�ؽ��й鲢
		Merge(Array, i, i + length - 1, n - 1);
}
void sortClass :: mergeSort() {
	//disArray();
	for (int length = 1; length < rowN; length *= 2)
		MergePass(Array, length, rowN);
	//disArray();
}