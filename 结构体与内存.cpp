//指针 结构体 动态内存分配
#include<iostream>
int a=1E6;//全局内存
typedef struct
{
	int a;
	int b;
	int add(int a,int b){
		return a+b;
	}
}tiankexin;
int addsum(int n){
	if(n == 0) return n;
	return addsum(n-1) + n;
}
int main(){
	tiankexin tian;
	std::cout<<tian.add(1,2);
	return 0;
}
/*
1.静态内存/全局内存：
static 关键字后的变量用静态内存
在程序开始运行时分配，程序终止后消失。
2.自动内存/栈内存：
int a;递推过程极度消耗栈空间->递归深度不可以超过1e6 10^6
生命周期跟随函数开始和返回
3.动态内存/堆内存：
用代码编写来分配内存。
malloc free->C语言规范  ->数据结构：成点分布，可确定大小的
new delete->C++语言规范 ->类内：可成批申请的
生命周期：我定
if I malloc but i didn't free it,?
内存泄漏
*/
 
