#include<bits/stdc++.h>
typedef struct node{
	int data;
	struct node *next;
}Node;
//初始化
Node *initList()
{
	Node *head = (Node*)malloc(sizeof(Node));
	head -> data = 0;
	head -> next = NULL;
	return head;
}
//头插法
int insertHead(Node* l, int e){
	Node *p = (Node*)malloc(sizeof(Node));
	p -> data = e;
	p -> next = l -> next;
	l -> next = p;
}
Node* find_last_node(Node* l,int num){
	Node* fast = l;
	Node* slow = l;
	while(num--){
		fast = fast -> next;
	}
	while(fast != NULL){
		fast = fast -> next;
		slow = slow -> next;	
	}
	return slow;
}
int main(){
	Node * list = initList();
	for(int i = 1;i <= 7;i++){
		insertHead(list,i);
	}
	int n; std::cin>>n;
	std::cout<<find_last_node(list,n) -> data;
	return 0;
}
