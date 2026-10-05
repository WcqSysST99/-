/*栈：后进先出->数组实现*/
#include<iostream>
#include<assert.h>
const int Maxn = 1e4+10;

class Stack{
	public:
		//判断栈是否为空
		bool empty(){
			return top == -1;
		}
		//判断栈是否为满
		bool full(){
			return top == Maxn - 1;
		}
		//入栈
		void push(int val){
			//assert(!full());//为伪中止运行，防止内存溢出。
			A[++top] = val;
		}
		//弹栈
		int pop(){
			//assert(!empty());
			return A[top--];
		}
		//找顶
		int peek(){
			//assert(!empty());
			return A[top];
		}
	private:
		int A[Maxn];
		int top = -1;
};

int main(){
	Stack stack;
	int a;
	scanf("%d",&a);
	stack.push(a);
	printf("%d",stack.pop());
	return 0;
	
}
//简单写法 
//struct Stack {
    //int data[64];  // 足够存下 64 位二进制
    //int top;
    //Stack() : top(-1) {}
    //void push(int x) { data[++top] = x; }
    //int pop() { return data[top--]; }
    //bool empty() { return top == -1; }
//}; 
