//coding=UTF-8
#include"head.h"

int insert_record(Record *R1){
	//----头插法----
	R1->Next = head_re->Next;
	head_re->Next = R1;
	return 0;
}
Record *new_re(){
	//-----输入一条电话信息，并新建一个strcut-- 
	Record *new_R = new Record;
	cout << "please enter id, name and telephone:" << endl;
	cin >> new_R->id >> new_R->name >> new_R->tele;
	return new_R;
}
void print_record(Record *Re){
	//----打印全部的通讯录----- 
	Record * Ptr1 = Re;
	for(;Ptr1 != NULL; Ptr1 = Ptr1->Next){
		cout << Ptr1->id << " " << Ptr1->name << " " << Ptr1->tele << endl;
	}
}
