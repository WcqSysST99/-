//线性表：由n个元素特性相同的元素构成的有限序列
//元素的个数n：线性表的长度 n=0 为空表
#include<bits/stdc++.h>
using namespace std;
struct book{
	int number;
	char name[10];
	int price;
};

book library[10000];
int cnt = 0;
void add(int num,char names[10],int price){
	for(int i = 0 ;i < strlen(names);i++){
		library[cnt].name[i] = names[i];
	}
	library[cnt].number = num;
	library[cnt].price = price;
	cnt++;
	return;
}
void del(){
	
}

int main(){
	
	return 0;
}
