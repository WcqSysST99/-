#include<bits/stdc++.h>
using namespace std;
int precedence(char fuhao){
	if(fuhao=='*'||fuhao=='/') return 2;
	if(fuhao=='+'||fuhao=='-') return 1;
	return 0;
}
string zhuanhuan(string zhongzhui){
	stack<char> fuhaozhan;
	string houzhui;
	int n=zhongzhui.length();
	for(int i=0;i<n;i++){
		char ch=zhongzhui[i];
		if(isspace(ch)) continue;
		if(isdigit(ch)){
			while(i<n&&isdigit(zhongzhui[i])){
				houzhui+=zhongzhui[i];
				houzhui+=' ';
				i++;//!!!!
			}
			i--;//外层循环自增i减掉 
		}
	    if(ch=='(') fuhaozhan.push(ch);
	    else if(ch==')'){
	    	while(!fuhaozhan.empty()&&fuhaozhan.top()!='('){
	    		houzhui+=fuhaozhan.top();
	    		houzhui+=' ';
	    		fuhaozhan.pop();
			}
			if(!fuhaozhan.empty()) fuhaozhan.pop();//弹出左括号 
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
			while(!fuhaozhan.empty()&&precedence(ch)<=precedence(fuhaozhan.top())){
				houzhui+=fuhaozhan.top();
				houzhui+=' ';
				fuhaozhan.pop();
			}
			fuhaozhan.push(ch);//不是上述情况就将ch压栈 
		}
	}
	while(!fuhaozhan.empty()){
			houzhui+=fuhaozhan.top();
			houzhui+=' ';
			fuhaozhan.pop();
		}//剩余的弹栈 ,在循环外面 
	return houzhui;
}
int houzhuijisuan(string s){
	
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
return nums.top();
} 
int main(){
	string zhongzhui;
	getline(cin,zhongzhui);
	string houzhui=zhuanhuan(zhongzhui);
	int a=houzhuijisuan(houzhui);
	cout<<a;
	return 0;
	
}
