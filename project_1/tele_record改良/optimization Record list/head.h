#ifndef HEAD_H
#define HEAD_H
#include<iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
#include<vector>
#include<cstring>
#include<fstream>
#define Filename "data.txt"
using namespace std;
struct Record{
	string tele;//telephone
	string name;//name
	string id;	//numbers
	struct Record *Next;//behind point

	Record() {
		tele = "None";
		name = "None";
		id = "None";
		Next = NULL;
	}
};
int read_data();//1.read data from file
int insert_record(Record*);//2.insert a record to list records
void print_record();//3.print all list records
Record *search_name();//4.search a record from list records
void save_to_file();//5.save list records to file
int del_all();//6.delete all records and delete file
void print_main_menu();//7.display main menu data
struct Record * new_re();//create a struct record

extern Record* head_re;
const int N = 1e3;

#endif
