#include"head.h"
bool isOpChar(const string& str){//判断是否为运算符 
	if(str != "+" && str != "-" && str != "/" && str != "*")
		return false;
	return true;
}
bool isOpDigit(const string& str) {//判断是否为运算数
	if (str >= "0" && str <= "9" || str == ".")
		return true;
	return false;
}
void Tree::BuildTree(int tree_i, int array_i, string tExp[]) {
	//将tExp数组从第array_i个数构建节点为tree_i的二叉树
	int i = array_i;
	if (isOpChar(tExp[i])) {//如果上一个为运算符
		tree_i = tree_i * 2 + 1;//左孩子
		Node[tree_i] = tExp[i+1];//将当前string数组的值赋值给当前的节点

		//-------右孩子---------
		if (isOpDigit(tExp[i+1])) {
			//如果孩子为运算数
			Node[tree_i + 1] = tExp[i+2];
			if (isOpChar(tExp[i + 2]))
				BuildTree(tree_i + 1, i + 2, tExp);
		}
		else if (isOpChar(tExp[i+1]) ){
			BuildTree(tree_i, i+1, tExp);//向左边建树
			//如果孩子为运算符
			int t_i = i+2;
			while (!isOpChar(tExp[t_i]))
				t_i++;//找到下一个运算符
			Node[tree_i + 1] = tExp[t_i];
			BuildTree(tree_i+1, t_i, tExp);
		}
	}
}
void Tree::BuildNode() {
	int Len = postExp.size();
	//---------将后缀表达式处理成string数组---- 
	for(int i = Len-1, j = 0/*j为节点编号*/; i > 0; i--) {
		if(postExp[i] == ' ')continue;//跳过空格
		if(postExp[i]=='+' || postExp[i]=='*' || postExp[i]=='/' || postExp[i]=='-') {
			tempExp[j] = postExp[i];
			//cout << "+" << endl;
		} else {
			while(isdigit(postExp[i]) || postExp[i]=='.') 
				tempExp[j] += postExp[i--];
			i++;//有空格其实不用，加了是为了保险 
		}
		j++;
		tLen = j;
	}
	for(int i = 0; i <= tLen; i++)
		reverse(tempExp[i].begin(), tempExp[i].end() );
	//-------将string数组构建成二叉树-------
	Node[0] = tempExp[0];//构建树根
	BuildTree(0,0, tempExp);//树的节点编号从1开始
}
