#include"head.h"
int Tree::degree(char a) {//Ȩֵ
	if (a == '+' || a == '-')
		return 1;
	if (a == '*' || a == '/')
		return 2;
	return -1;
}
string Tree::inExp_to_postExp() {
//	cout << "xy"<<endl;
	string ans;
	stack<char> sta_ch;
	int Len = inExp.size();
	for (int i = 0; i < Len; ) {
		//cout << i << " " << ans << endl;
		if (inExp[i] == ' ')continue;
		if (inExp[i] >= '0' && inExp[i] <= '9' || inExp[i] == '.') {
			while (inExp[i] >= '0' && inExp[i] <= '9' || inExp[i] == '.') {
				ans += inExp[i++];
			}
			ans += ' ';
		}
		else {
			if (inExp[i] == '(') {
				sta_ch.push(inExp[i]);
			}
			else if (inExp[i] == ')') {
				while (!sta_ch.empty()) {
					char temp = sta_ch.top();
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
						sta_ch.pop();
					}
					else break;
				}
				sta_ch.push(inExp[i]);
				//cout << sta_ch.top() << endl;
			}
			i++;//递增
		}
	}
	while (!sta_ch.empty()) {
		char temp = sta_ch.top();
		sta_ch.pop();
		ans += temp;
		ans += ' ';
	}
	cout << ans << endl;
	ans.insert(0, 1, ' ');//在后缀表达式前面加空格
	postExp = ans;
	return ans;
//	return "214";
}
