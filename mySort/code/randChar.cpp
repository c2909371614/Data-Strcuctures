#include"head.h"
void randChar(int n) {
	fstream out("unsort.txt", ios::out);
	srand(time(0) );
	for (int i = 0; i < n; i++) {
		int rowSize = rand() % 10 + 1;
		for (int j = 0; j < rowSize; j++) {
			char ch = rand() % 26 + 'a';
			out << ch;
		}
		out << endl;
	}
	out.close();
}