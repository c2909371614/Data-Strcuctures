#include"head.h"
int main() {
	//cout << M << " " << N<< endl;
	//randChar(M);
	sortClass a;
	int begin_time = clock();
	/*a.insertSort();//1
	int insert_time = clock();
	cout << " time of insert: " << insert_time - begin_time  << "ms" << endl;
	
	a.getdata();
	begin_time = clock();
	a.bubbleSort();//2
	int bubble_time = clock();
	cout << " time of bubble: " << bubble_time - begin_time << "ms" << endl;
	
	a.getdata();
	begin_time = clock();
	a.heapSort();//3
	int heap_time = clock();
	cout << " time of heap: " << heap_time - begin_time << "ms" << endl;*/
	
	a.getdata();
	begin_time = clock();
	a.quickSort(0, a.getRow() );//4
	int quick_time = clock();
	cout << " time of quick: " << quick_time - begin_time << "ms" << endl;
	a.outdata("new.txt");
	/*a.getdata();
	begin_time = clock();
	a.shellSort();//5
	int shell_time = clock();
	cout << " time of shell: " << shell_time - begin_time << "ms" << endl;*/
	
	//a.getdata();
	//begin_time = clock();
	//a.mergeSort();//6
	//int merge_time = clock();
	//cout << " time of merge: " << merge_time - begin_time << "ms" << endl;
	return 0;
}