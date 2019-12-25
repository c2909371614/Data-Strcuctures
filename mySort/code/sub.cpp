//实现sortClass类的一些辅助函数
#include"head.h"
sortClass :: sortClass() {
    rowN = 0;
    getdata();
}
int sortClass :: getRow() {
    return rowN;
}
void sortClass :: getdata() {
    //---刷新class的数据域---
    //fstream in("unsort.txt", ios::in);
    fstream in("unsort.txt", ios::in);
    string str;
    int i = 0;
    while (getline(in, str)) {
        myCopy(Array[i++], str);//复制
    }
    rowN = i;//元素个数
    in.close();
}
void sortClass :: outdata(const string & outFile) {
    //---将排序好的字符串输出到txt---
    fstream out(outFile.c_str(), ios::out);
    for (int i = 0; i < rowN; i++) {
        out << Array[i] << endl;
    }
    out.close();
}
void myCopy(char *A, const string& str) {
    for (unsigned int i = 0; i <= str.size(); i++) {//等于号将结束符也赋值进去'\0'
        A[i] = str[i];
    }
 }
void swapChar(char* A, char* B) {//将字符数组A和B交换
    char tChar[20];
    strcpy(tChar, A);
    strcpy(A, B);
    strcpy(B, tChar);
}