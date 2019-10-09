#include<bits/stdc++.h>
using namespace std;
struct sss
{
	string s1,s2,s3;
};
int main(){
	fstream in("data.txt",ios::in);
	sss ss;
	in >> ss.s1 >> ss.s2 >> ss.s3;
	cout << ss.s1 << ss.s2 << ss.s3;
}