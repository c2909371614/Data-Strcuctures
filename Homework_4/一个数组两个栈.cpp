#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+5;
struct Stack{
	char ch[N];
	//栈的指针
	int L_top ;//左指针
	int R_top ;//右指针
	Stack(){
		L_top = 0;
		R_top = N-1;
	}
};
bool Full(Stack *A){
	if(A->L_top == A->R_top)
		return true;
	return false;
}
bool L_Pop(Stack *A){//出栈
	if(A->L_top == 0)
		return false;
	char c = A->ch[A->L_top--];
	return true;
}
char L_Top(Stack *A){//取顶
	return A->ch[A->L_top];
}
bool L_Push(Stack *A, char C){//压栈
	if(Full(A))return false;
	A->ch[L_top++] = C;
	return true;
}
bool L_Empty(Stack *A){//是否为空
	if(A->L_top == 0)
		return true;
	return false;
}
bool R_Pop(Stack *A){//出栈
	if(A->R_top == N-1)
		return false;
	char c = A->ch[A->top++];
	return true;
}
char R_Top(Stack *A){//取顶
	return A->ch[A->R_top];
}
bool R_Push(Stack *A, char C){//压栈
	if(Full(A))return false;
	A->ch[R_top--] = C;
	return true;
}
bool R_Empty(Stack *A){//是否为空
	if(A->top == N-1)
		return true;
	return false;
}