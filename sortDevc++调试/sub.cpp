//ʵ��sortClass���һЩ��������
#include"head.h"
sortClass :: sortClass() {
    rowN = 0;
    getdata();
}
int sortClass :: getRow() {
    return rowN;
}
void sortClass :: getdata() {
    //---ˢ��class��������---
    //fstream in("unsort.txt", ios::in);
    fstream in("unsort.txt", ios::in);
    string str;
    int i = 0;
    while (getline(in, str)) {
        myCopy(Array[i++], str);//����
    }
    rowN = i;//Ԫ�ظ���
    in.close();
}
void sortClass :: outdata(const string & outFile) {
    //---������õ��ַ��������txt---
    fstream out(outFile.c_str(), ios::out);
    for (int i = 0; i < rowN; i++) {
        out << Array[i] << endl;
    }
    out.close();
}
void myCopy(char *A, const string& str) {
    for (int i = 0; i <= str.size(); i++) {//���ںŽ�������Ҳ��ֵ��ȥ'\0'
        A[i] = str[i];
    }
 }
void swapChar(char* A, char* B) {//���ַ�����A��B����
    char tChar[20];
    strcpy(tChar, A);
    strcpy(A, B);
    strcpy(B, tChar);
}
