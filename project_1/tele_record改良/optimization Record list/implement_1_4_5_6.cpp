#include"head.h"
int read_data() {
	fstream in_record(Filename, ios::in);
	if (!in_record.is_open()) {
		cout << "no that file" << endl;
	}
	bool flag = true;
	//------read data from file----
	string id, name, tele;
	Record *sin_record = new Record[N];//N = 1e3 type(N) = int
	int i = 0;
	in_record.seekg(0);//将文件流指针导到最前
	while (!in_record.eof()) {//judge file is_end
		//struct Record sin_record = (struct Record*)malloc(sizeof(Record));//state a new Record object to read a record from file
		in_record >> sin_record[i].id >> sin_record[i].name >> sin_record[i].tele;
		insert_record(&sin_record[i]);
		if (flag) flag = false;
		i++;//i rise to using differet record
	}
	//------file empty prompt-------
	if (flag) cout << "file is empty" << endl;
	else  cout << "read data finished" << endl;
	//---don't forget close the file--
	in_record.close();
	return 0;
}
Record *search_name() {
	//-----search record by input name---
	string str;
	cout << "please enter the name:";
	cin >> str;
	Record* ptr = NULL;
	bool flag = true;
	//-------遍历通讯录进行查找------
	for (ptr = head_re->Next; ptr != NULL; ptr = ptr->Next) {
		if (str == ptr->name) {
			cout << ptr->id << "\t" << ptr->name << "\t" << ptr->tele << endl;
			flag = false;
		}
	}
	if (flag) cout << "no matching" << endl;
	return ptr;
}
void save_to_file() {
	//-----save all record to file----
	Record* ptr = NULL;
	bool flag = true;
	fstream out_record(Filename, ios::out);
	//-------遍历通讯录------
	for (ptr = head_re->Next; ptr != NULL; ptr = ptr->Next) {
		out_record << ptr->id << "\t" << ptr->name << "\t" << ptr->tele << endl;
		flag = false;
	}
	if (flag) cout << "the record list is empty" << endl;
	//---don't forget close the file--
	out_record.close();
}
int del_all() {
	//---delete all records and delete the file----
	Record* ptr = NULL;
	for (ptr = head_re->Next; ptr != NULL; ptr = head_re->Next) {//alway del head next point
		//----let head point point ptr's Next--- 
		head_re->Next = ptr->Next;
		//----then free the memory-----
		free(ptr);
	}
	//-----delete the file---- 
	remove(Filename);
	return 0;
}