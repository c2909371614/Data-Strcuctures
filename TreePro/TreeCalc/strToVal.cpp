#include"head.h"
double Tree :: strToVal(const string& s) {
	double ans = 0;
	double n = 10;
	double m = 1;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) ans = ans * n + (s[i] - '0') * m;
		if (m < 1) m = m * 0.1;
		if (s[i] == '.') {
			n = 1;
			m = 0.1;
		}
	}
	return ans;
}
