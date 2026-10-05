#include<iostream>
#include<malloc.h>
#include<cstring>
typedef struct node{
	char text;
	node *next;
}node;
node* initlist(){
	node *head = (node*)malloc(sizeof(node));
	head -> next = NULL;
	head ->text = 0;
	return head;	
}
void insert_node(node* l,char val){
	node* Node = (node*)malloc(sizeof(node));
	Node -> text = val;
	Node -> next = l-> next;
	l -> next = Node;
	return;
}
node* write_char(){
	char a[100];
	scanf("%s",a);
	node* list = initlist();
	for(int i = 0;i < strlen(a);i++){
		insert_node(list,a[i]);
	}	
	return list;
}
node* find_middle(node* list){
	node* fast = list;
	node* slow = list;
	while(fast != NULL and fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
node* reverse_list(node* l){
	node* pre = NULL;
	node* cur = l;
	while(cur != NULL){
		node* nexttemp = cur->next; 
		cur -> next = pre;
		pre = cur;
		cur = nexttemp;
	}
	return pre;
}
int main(){
	node* list = write_char();
	node* mid = find_middle(list);
	node* tail = reverse_list(mid);
	node* first = list->next;
	node* second = tail;
	while(first != NULL && second !=NULL){
		if(first -> text != second -> text) {
			printf("不是回文");
			return 0;
		}
		first = first -> next;
		second = second -> next;
		
	}
	printf("是回文");
	return 0;
	
	
}
