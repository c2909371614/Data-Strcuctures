//coding=UTF-8
#include"head.h"
int insert_record(Record *R1){
	//-----检测原来的 list 里面是否已经存在该号码----
	Record* ptr = NULL;
	for (ptr = head_re; ptr != NULL; ptr = ptr->Next) {
		if (ptr->tele == R1->tele) {
			cout << "the telephone has exit " << endl;
			return -1;
		}
	}
	//----头插法----
	if(R1->Next != head_re->Next)
		R1->Next = head_re->Next;//let the point of now point the head next record
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
void print_record(){
	//----打印全部的通讯录----- 
	Record * Ptr1 = head_re->Next;
	try {
		if (Ptr1 == NULL)
			throw 1;
		cout << "------------Record list-----------\n"\
			"     id \t   name \t  telephone" << endl;
		for(;Ptr1 != NULL; Ptr1 = Ptr1->Next){
			cout << Ptr1->id << " \t " << Ptr1->name 
				<< " \t " << Ptr1->tele << endl;
		}
	}
	catch(int &ex){
		cout << "Record is empty" << endl;
	}
}
void print_main_menu() {
	cout << "---------------Main menu--------------\n"\
				  "1.read data from file\n"\
				  "2.insert a record to record list\n"\
				  "3.print the record list\n"\
				  "4.search record with name\n"\
				  "5.save record list to file\n"\
				  "6.delete all record and delete file\n"\
				  "7.display main menu data\n"\
				  "-----------------------------------------\n" << endl;
}
