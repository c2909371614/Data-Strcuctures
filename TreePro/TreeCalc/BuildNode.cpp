#include"head.h"
bool isOpChar(const string& str){//�ж��Ƿ�Ϊ����� 
	if(str != "+" && str != "-" && str != "/" && str != "*")
		return false;
	return true;
}
bool isOpDigit(const string& str) {//�ж��Ƿ�Ϊ������
	if (str >= "0" && str <= "9" || str == ".")
		return true;
	return false;
}
void Tree::BuildTree(int tree_i, int array_i, string tExp[]) {
	//��tExp����ӵ�array_i���������ڵ�Ϊtree_i�Ķ�����
	int i = array_i;
	if (isOpChar(tExp[i])) {//�����һ��Ϊ�����
		tree_i = tree_i * 2 + 1;//����
		Node[tree_i] = tExp[i+1];//����ǰstring�����ֵ��ֵ����ǰ�Ľڵ�

		//-------�Һ���---------
		if (isOpDigit(tExp[i+1])) {
			//�������Ϊ������
			Node[tree_i + 1] = tExp[i+2];
			if (isOpChar(tExp[i + 2]))
				BuildTree(tree_i + 1, i + 2, tExp);
		}
		else if (isOpChar(tExp[i+1]) ){
			BuildTree(tree_i, i+1, tExp);//����߽���
			//�������Ϊ�����
			int t_i = i+2;
			while (!isOpChar(tExp[t_i]))
				t_i++;//�ҵ���һ�������
			Node[tree_i + 1] = tExp[t_i];
			BuildTree(tree_i+1, t_i, tExp);
		}
	}
}
void Tree::BuildNode() {
	int Len = postExp.size();
	//---------����׺���ʽ�����string����---- 
	for(int i = Len-1, j = 0/*jΪ�ڵ���*/; i > 0; i--) {
		if(postExp[i] == ' ')continue;//�����ո�
		if(postExp[i]=='+' || postExp[i]=='*' || postExp[i]=='/' || postExp[i]=='-') {
			tempExp[j] = postExp[i];
			//cout << "+" << endl;
		} else {
			while(isdigit(postExp[i]) || postExp[i]=='.') 
				tempExp[j] += postExp[i--];
			i++;//�пո���ʵ���ã�������Ϊ�˱��� 
		}
		j++;
		tLen = j;
	}
	for(int i = 0; i <= tLen; i++)
		reverse(tempExp[i].begin(), tempExp[i].end() );
	//-------��string���鹹���ɶ�����-------
	Node[0] = tempExp[0];//��������
	BuildTree(0,0, tempExp);//���Ľڵ��Ŵ�1��ʼ
}
