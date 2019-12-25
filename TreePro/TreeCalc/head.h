#ifndef HEAD
#define HEAD
//#include<bits/stdc++.h>
#include<fstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<sstream>
const int N = 1e3+5;
using namespace std;
class Tree {
	private:
		string postExp;// postfix expression 
		string Node[N];//expression tree
		int tLen;//记录string数组的长度 
		string tempExp[N];//Operands and operators string 
		void BuildTree(int,int,string tExp[]);//构建
	public:
		fstream io;//filestream
		double ans;//the result of expression
		string inExp;//infix expression
		Tree();
		~Tree();
		void INIT();//Initialization function
		int setData();//import data from file stream
		int degree(char);//define the operator degree
		string inExp_to_postExp();  //中缀转后缀
		void BuildNode();//create the expression tree with tempExp array
		void disNode();//display the expression tree
		double strToVal(const string&);//return the value of string operands
		double CalcTree(int tree_i);//calculate the expression tree and return the result
};
bool isOpChar(const string&);//check string is operator or not
bool isOpDigit(const string&);//check string is operand or not
#endif
