#include"head.h"
void sortClass::disArray() {//����ַ�������
	for (int i = 0; i < rowN; i++)
		cout << Array[i] << " ";
	cout << endl;
}
void sortClass::selectSort() {//��������
//	cout << "����ǰ: ";
//	disArray();
	//----- ��ʼ����----
	for (int i = 0; i < rowN; i++) {
		int min = i;
		strcpy(Array[min], Array[i]);
		for (int j = i; j < rowN; j++) {
			if (strcmp(Array[min], Array[j]) > 0)//�ҵ���С���ַ���
				min = j;
		}
		char tChar[20];
		//---- ����С���ַ���������������---
		strcpy(tChar, Array[i]);
		strcpy(Array[i], Array[min]);
		strcpy(Array[min], tChar);
	}

//	//---------
//	cout << "�����: ";
//	disArray();
}
