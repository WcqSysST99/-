//单链表data,next
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
//尾插法
Node * get_tail(Node *l){
	Node *p = l;
	while(p -> next != NULL){
		p = p->next;
	}
	return p;
}
void insertTail(Node *tail,int e){
	Node *p = (Node*)malloc(sizeof(Node));
	p -> data = e;
	tail -> next = p;
	p -> next = NULL;   //一个节点内存，包含指针内容而无赋值->悬垂指针，导致内存泄露
	return ;
}
//指定位置插入数据
int insertnode(Node *l,int pos,int e){
	Node *p = l;
	int i = 0;
	while(i < pos-1){
		p = p->next;
		i++;
		if(p == NULL){
			return 0;
		}
	}
	Node * q = (Node*)malloc(sizeof(Node));
	q -> data = e;
	q -> next = p -> next;
	p -> next = q;
	return 1;
}
//删除节点
int deleteNode(Node *l,int pos){
	Node *p = l;
	int i = 0;
	while(i < pos-1){
		p = p->next;
		i++;
		if(p == NULL){
			return 0;
		}
	}
	if(p -> next == NULL){
		return 0;
	}
	Node *q = p -> next;
	p -> next = q -> next;
	free(q);
	return 1;
}
//找目标数据节点位置 
int findnode(Node* l,int tgt){
	int cnt = 0;
	while(l -> data != tgt){
		l = l -> next;
		cnt++;
	}
	return cnt;
}
//删目标数据节点 
void delete_tgtnode(Node *l,int tgt){
	deleteNode(l,findnode(l,tgt));
	return;
}
//获取链表长度
int Listlength(Node *l){
	Node *p = l;
	int len = 0;
	while(p != NULL){
		p = p->next;
		len++;
	}
	return len;
}
//释放链表
void freelist(Node* l){
	Node *p = l->next;
	Node *q;
	while(p != NULL){
		q = p -> next;
		free(p);
		p = q;
	}
	l -> next = NULL;
}


int main(){
	Node *list = initList();
	/*实现一个简单功能：以图书馆书籍编号为例，写一个读入、读出，来操作该链表。
	需要达到以下功能：
	1.根据书籍编号，查找书籍的pos;->遍历
	2.插入新书籍及其编号
	3.删除书籍
	4.查询图书馆书总数。*/
	int a; std::cin>>a;
	insertHead(list,a);
	delete_tgtnode(list,a);
	std::cout<<Listlength(list);
	return 0;
}
