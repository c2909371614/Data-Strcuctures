#include <iostream>
#include<cstring>
#include<string>
#include<stack>
#include<algorithm>
#include<ctime>
#include<fstream>
using namespace std;
struct node {
	string S;
	struct node* lchild;
	struct node* rchild;
	node() {//初始化
		S = "";
		lchild = NULL;
		rchild = NULL;
	}
};
void DisTree(struct node* Tree) {
	if (Tree != NULL) {
		DisTree(Tree->lchild);
		cout << Tree->S;
		DisTree(Tree->rchild);
	}
}
int degree(char a) {
	if (a == '+' || a == '-')
		return 1;
	if (a == '*' || a == '/')
		return 2;
}
string inExp_to_postExp(const string& inExp) {
	string ans;
	stack<char> sta_ch;
	int Len = inExp.size();
	for (int i = 0; i < Len; i++) {
		//cout << i << " " << ans << endl;
		if (inExp[i] == ' ')continue;
		if (inExp[i] >= '0' && inExp[i] <= '9' || inExp[i] == '.') {//将数字字符加入答案
			while (inExp[i] >= '0' && inExp[i] <= '9' || inExp[i] == '.') {
				ans += inExp[i];
				i++;
			}
			ans += ' ';//添加空格区分数字
			i--;
		}
		else {
			if (inExp[i] == '(') {
				sta_ch.push(inExp[i]);
			}
			else if (inExp[i] == ')') {//遇到右括号将栈中左括号前的符号全部推出
				while (!sta_ch.empty()) {
					char temp = sta_ch.top();//取出栈顶符号
					sta_ch.pop();
					if (temp == '(')break;
					ans += temp;
					ans += ' ';
				}
			}
			else {
				while (!sta_ch.empty() ) {
					char temp = sta_ch.top();
					if (temp == '(' ) {
						break;
					}
					if (degree(inExp[i]) <= degree(temp)) {
						ans += temp;
						ans += ' ';
						sta_ch.pop();//加入以后弹出
					}
					else break;
				}
				sta_ch.push(inExp[i]);//加入栈
				//cout << sta_ch.top() << endl;
			}
		}
	} 
	while (!sta_ch.empty()) {
		char temp = sta_ch.top();
		sta_ch.pop();
		ans += temp;
		ans += ' ';
	}
	//cout << ans << endl;
	return ans;
}
struct node* BuildTree(const string& postExp) {
	int Len = postExp.size();
	stack <node*> sta_tree;
	for (int i = 0; i <= Len; i++) {
		node* p = new node;
		p->S = "";
		p->lchild = NULL;
		p->rchild = NULL;
		if (postExp[i] == ' ')continue;//清除空格
		if (postExp[i] >= '0' && postExp[i] <= '9') {
			string str;
			while (postExp[i] >= '0' && postExp[i] <= '9' || postExp[i] == '.') {
				str += postExp[i];
				i++;
			}
			p->S = str;
		}
		else {
			p->S = postExp[i];
			p->rchild = sta_tree.top();//先右后左
			sta_tree.pop();
			p->lchild = sta_tree.top();
			sta_tree.pop();
			DisTree(p);
			cout << endl;
		}
		//cout << i << " " << p->S << endl;
		sta_tree.push(p);
	}
	//node* ExpTree = sta_tree.top();//最后一个运算符为树的根
	//sta_tree.pop();
	//DisTree(ExpTree);
	//return ExpTree;
	return NULL;
}
int main()
{
	fstream fileExp("Exp.txt", ios::in | ios::out);
	string inExp;
	while (getline(fileExp, inExp)) {
		cout << "inExp:" << inExp << endl;
		string str = inExp_to_postExp(inExp);
		cout <<"posExp:" << str << endl;
		BuildTree(str);
	}
	fileExp.close();//关闭文件
}


