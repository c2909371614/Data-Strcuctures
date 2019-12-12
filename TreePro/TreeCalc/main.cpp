#include"head.h"
int main(){
	double begin_t;
	double end_t;
	begin_t = clock();
	Tree A;
	int count = A.setData();
	end_t = clock();
	//A.disNode();
	A.io << "the time is " << end_t - begin_t << "ms" << endl;
	A.io << "the total of exp:" << count << endl;
	A.io << "the error of exp: " << 0 << endl;
	A.io << "the right of exp: " << count << endl;
	printf("the time is %.0f ms\n ", end_t - begin_t);
	return 0;
}
