/* an array struct of self-adjusting lists like a regular list
all insertions are performed at the front
element is moved to the front of the list when it is accessed by find

author:CPX
time:2019.10.7

*/

#include<iostream>
using namespace std;
struct Array{
	int val;//value
	static int size;//size of array
	strcut Array *nxt;//behind point
	Array(){
		val = -1;///init value of -1
		nxt = NULL;//init the point with NULL
	}
	Array(int Val){
		val = Val;
	}
	int push(int a){
		struct Array *A = new Array(a);
		A->nxt = nxt->nxt;
		nxt = A;
		size++;//adujec
		return 1;
	}
	bool find(int a){
		//---check the existendce of a the Array
		//---and change its pos into the first of Array
		struct Array *ptr;
		for(ptr = nxt; ptr != NULL; ptr = ptr->nxt){
			if(ptr->nxt->val == a){
				//insert into the first place
				ptr->nxt = nxt->nxt;
				nxt->nxt = ptr;
				//unlink the strcut 
				ptr->nxt = ptr->nxt->nxt;
				return true; 
			}
		}
		return false;
	}
};
Array :: size = 0;//init the size of array with zero
int main(){

}