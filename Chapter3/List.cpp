#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *next;
};
struct node *head;
void create(int data[], int n){
	head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	node *p1, *p2;
	for(int i = 0; i < n; i++){
		p1 = (struct node *)malloc(sizeof(struct node));//now node 
		p1->val = data[i];// init p1 with val
		if(head->next != NULL){//no node 
//			printf("Laster = %d", p2->val);
			p1->next = p2;
//			printf("-p1-next = %d\n", p1->next->val);
		}
		else p1->next = NULL; 
		head->next = p1;
		p2 = p1;
	}
}
void display(){
	node *ptr = head->next;
	int count = 0;
	while(ptr != NULL){
		printf("%d ",ptr->val);
		ptr = ptr->next;
		count++;
	}
//	printf("count = %d\n", count);
}
int main(){
	int a[10] = {1,2,3,4,5};
	create(a,5);
//	printf("head = %d ",head->next->next->val);
	display();
}
