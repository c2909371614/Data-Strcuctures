#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+5;
struct Stack{
	char ch[N];
	int top = 0;//栈的指针
};
bool Pop(Stack *A){//出栈
	if(A->top == 0)
		return false;
	char c = A->ch[A->top--];
	return true;
}
char Top(Stack *A){//取顶
	return A->ch[A->top];
}
bool Push(Stack *A, char C){//压栈
	if(A->top >= N)return false;
	A->ch[top++] = C;
	return true;
}
bool Empty(Stack *A){//是否为空
	if(A->top == 0)
		return true;
	return false;
}
bool judge_bracket(char s[]){//括号判断
	int len = strlen(s);
	char temp = '$';//作为中间处理初始化为'$'
	Stack A, B;
	for(int i = 0; i < len; i++)//推入栈
		Push(A, s[i]);
	while(!Empty(A)){//栈内是否为空
		temp = Top(A);
		Pop(A);//出栈
		//------将左括号全波-------
		if(temp=='{' || temp=='[' || temp=='(' || temp=='/'){
			Push(B, temp);
			if(temp == '/'){//处理/* 和 */
				temp = Top(A);
				Pop(A);
				Push(B, temp);
			}
		}
		if(temp=='}' || temp==']' || temp==')' || temp == '*'){
			if(!Empty(B) && temp != Top(B))
				return false;
			else {
				Pop(B);
			}
		}
	}
	return true;
}
