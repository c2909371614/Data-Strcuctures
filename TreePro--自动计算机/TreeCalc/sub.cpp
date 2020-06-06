#include"head.h"
Tree :: Tree()
{ //打开文件
	ans = 0;
	tLen = 0;
	io.open("Exp.txt", ios::in | ios::out);
}
Tree :: ~Tree() {//关闭文件
	io.close();
}
void Tree :: INIT() {
	for (int i = 0; i < tLen; i++)
		Node[i].clear(),
		tempExp[i].clear();
}
int Tree :: setData() {
	stringstream str;
	int count = 0;
	while (getline(io, inExp)) {
		INIT();//初始化
		str << inExp;
		inExp_to_postExp();
		BuildNode();
		//disNode();
		ans = CalcTree(0);
		str << "=" << ans << endl;
		count++;
	}
	io.close();
	io.open("Exp.txt", ios::out);
	io << str.str() << endl;
	return count;
}
void Tree :: disNode() {
	cout << "\n表达式树：" << endl;
	for (int i = 0; i < tLen; i++) {
		//cout << tLen << endl;
		cout << Node[i] << endl;
	}
}
double Tree :: CalcTree(int tree_i) {
	int lNode = tree_i * 2 + 1;
	int rNode = lNode + 1;
	if (Node[tree_i] == "+")return CalcTree(lNode) + CalcTree(rNode);
	if (Node[tree_i] == "*")return CalcTree(lNode) * CalcTree(rNode);
	if (Node[tree_i] == "/")return CalcTree(lNode) / CalcTree(rNode);
	if (Node[tree_i] == "-")return CalcTree(lNode) - CalcTree(rNode);
	//cout << "Node" << Node[tree_i] << endl;
	return strToVal(Node[tree_i]);
}
