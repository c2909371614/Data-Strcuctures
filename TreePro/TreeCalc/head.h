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
		string postExp;
		string Node[N];
		int tLen;//记录string数组的长度 
		string tempExp[N];
		void BuildTree(int,int,string tExp[]);//构建运算                                                           符
		//void BuildDigit();//构建运算数
	public:
		fstream io;
		double ans;
		string inExp;
		Tree()
		{ //打开文件
			io.open("Exp.txt",ios::in|ios::out);
		}
		~Tree() { //关闭文件
			//cout << "length:" << tLen << endl;;
			io.close();
		}
		void INIT() {
			//postExp = "";
			for (int i = 0; i < tLen; i++)
				Node[i].clear(),
				tempExp[i].clear();
			/*ans = 0;
			inExp.clear();
			tLen = 0;*/
		}
		int setData() {
			stringstream str;
			int count = 0;
			while (getline(io, inExp)) {
				INIT();//初始化
				//cout << inExp << endl;
				str << inExp;
				inExp_to_postExp();
				BuildNode();
				//disNode();
				ans = CalcTree(0);
				//cout << postExp << endl;
				//cout << "ans = " << ans << endl;
				str << "=" << ans << endl;
				count++;
			}
			io.close();
			io.open("Exp.txt", ios::out);
			io << str.str() << endl;
			return count;
		}
		int degree(char);
		string inExp_to_postExp();  //中缀转后缀
		void BuildNode();
		void disNode() {
			cout << "\n表达式树：" << endl; 
			for(int i = 0; i < tLen; i++) {
				//cout << tLen << endl;
				cout << Node[i] << endl;
			}
		};
		double strToVal(const string&);
		double CalcTree(int tree_i) {
			int lNode = tree_i * 2 + 1;
			int rNode = lNode + 1;
			if (Node[tree_i] == "+")return CalcTree(lNode) + CalcTree(rNode);
			if (Node[tree_i] == "*")return CalcTree(lNode) * CalcTree(rNode);
			if (Node[tree_i] == "/")return CalcTree(lNode) / CalcTree(rNode);
			if (Node[tree_i] == "-")return CalcTree(lNode) - CalcTree(rNode);
			//cout << "Node" << Node[tree_i] << endl;
			return strToVal(Node[tree_i]);
		}
};
bool isOpChar(const string&);
bool isOpDigit(const string&);
#endif
