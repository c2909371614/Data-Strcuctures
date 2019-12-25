#ifndef HEAD
#define HEAD
#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<fstream> 
#include<algorithm>
#include <iostream>
#include<queue>
#include<ctime>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e4;
class sortClass {
private:
    int rowN;//元素个数
    char Array[N][20];
public:
    sortClass();
    int getRow();
    void getdata();
    void outdata(const string&);
    void disArray();
    void selectSort();//1
    void bubbleSort();//2
    void heapSort();//3
    void quickSort(int, int);//4
    void shellSort();//5
    void mergeSort();//6
    void insertSort();//7
      
};
void myCopy(char*, const string&);
void swapChar(char*, char*);
void randChar(int n);//生成n行不同的字符
#endif
