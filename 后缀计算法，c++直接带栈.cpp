#include<bits/stdc++.h>
using namespace std;       

int main(){
	
	char s[1000]; scanf("%s",s);
	int n; n = strlen(s);	
	stack<int> numbers; 
	for(int i = 0;i < n;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			numbers.push(s[i] - '0'); //s[i] - '0'  equals to the original number
		}
		else{
			if(s[i] == '+'){
				int first = numbers.top(); numbers.pop();
                int second = numbers.top(); numbers.pop();
				numbers.push(second + first);
			}
			if(s[i] == '-'){
				int first = numbers.top(); numbers.pop();
                int second = numbers.top(); numbers.pop();
				numbers.push(second - first);
			}
			if(s[i] == '*'){
				int first = numbers.top(); numbers.pop();
                int second = numbers.top(); numbers.pop();
				numbers.push(second * first);
			}
			if(s[i] == '/'){
				int first = numbers.top(); numbers.pop();
                int second = numbers.top(); numbers.pop();
				numbers.push(second / first);
			}
		}
	}
	printf("%d",numbers.top());
	return 0;
}
