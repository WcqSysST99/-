//表达式求值
//表达式：操作数(变量)；运算符(+=*/)，界限符：()[]{} 
//表达式的表示方法:前缀、后缀、中缀表达
//中缀表达式：运算符在运算对象之间：(a+b*c)/d-e 
//把中缀表达转变为其他的表达方式->后缀表达式：逆波兰表达式。
//后缀表达式：运算符紧紧跟在运算对象之后的表达式
//没有括号，不存在优先级，计算过程只与先后顺序有关。
/*a+b			a b + 
1+2*3		1 2 3 * +
(a+b)*c		 a b + c *
a*b*c+a*b	 a b * c * a b * +
(a+b)*[(c-d)*e-f] a b + c d - e * f - *
a + (b - c / d) * e   a b c d / - e * +*/
//后缀表达式怎么求值？
//怎么实现这一步呢？
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;getline(cin,s);
	int n=s.length();	
	stack<int> nums; 
	int cnt = 0;
	for(int i = 0;i < n;i++){
		if (isspace(s[i])) continue;
		cnt++;
		if(s[i] >= '0' && s[i] <= '9'){
			nums.push(s[i] - '0'); 
		}
		else{
			int b = nums.top(); nums.pop();
            int a = nums.top(); nums.pop();
            switch (s[i]) {
                case '+': nums.push(a + b); break;
                case '-': nums.push(a - b); break;
                case '*': nums.push(a * b); break;
                case '/': nums.push(a / b); break;
		}
	
	}
}
	printf("%d",nums.top());
	return 0;
}
