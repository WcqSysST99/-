#include<bits/stdc++.h>
using namespace std;
bool solve(string s){
	stack<char> kuohaozhan;
	char pair[1500] = {0};
	pair['('] = ')';
	pair['['] = ']';
	pair['{'] = '}';
		int n = s.length();
		for(int i = 0;i < n;i++){
			if(s[i] == '{' or s[i] == '[' or s[i] == '('){
				kuohaozhan.push(s[i]);
			}
			else if(s[i] == '}' or s[i] == ']' or s[i] == ')'){
				if(kuohaozhan.empty()) return false;
				char temp = kuohaozhan.top();
				if(pair[temp] != s[i]) return false;
			}
	}
	return true;
}
int main(){
	string s; 
	cin>>s;
	cout<<solve(s);
	}
