#include"head.h"
void Merge(char Array[N][20], int low, int mid, int high) {
	//将数组R[low..mid]与R[mid+1..high]二路归并
	char tChar[N][N];
	int i = low, j = mid + 1, k = 0; // k是R的下标， i， j分别为第1、2段的下标
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
	//-------将剩余的部分全部加入tChar数组中----
	while (i <= mid) {
		strcpy(tChar[k], Array[i]);
		k++, i++;
	}
	while (j <= high) {
		strcpy(tChar[k], Array[j]);
		k++, j++;
	}
	//---将代存数组tChar中的data复制回数组---
	for (k = 0, i = low; i <= high; k++, i++)
		strcpy(Array[i], tChar[k]);
}
void MergePass(char Array[N][20], int length, int n) {
	//----完成一次归并-----
	int i;
	for (i = 0; i + 2 * length <= n; i = i + 2 * length)//0 2 4 6 
		//---将数组分成等长的子表进行一趟归并，多余的元素不做处理--
		Merge(Array, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n)//将最后一组不等长的元素进行归并
		Merge(Array, i, i + length - 1, n - 1);
}
void sortClass :: mergeSort() {
	//disArray();
	for (int length = 1; length < rowN; length *= 2)
		MergePass(Array, length, rowN);
	//disArray();
}