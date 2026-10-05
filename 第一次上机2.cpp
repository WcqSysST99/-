#include<bits/stdc++.h>
using namespace std;
string zhuanhuan(int n,int r) {
    stack<int> s;
    while (n>0) {
        s.push(n%r);
        n /= r;
    }
    string binary ; 
    while (!s.empty()) {
        if(s.top()<10) binary += to_string(s.top());
        else{
        	if(s.top()==10) binary +="A";
        	if(s.top()==11) binary +="B";
        	if(s.top()==12) binary +="C";
        	if(s.top()==13) binary +="D";
        	if(s.top()==14) binary +="E";
        	if(s.top()==15) binary +="F";
        	if(s.top()==16) binary +="G";
        	if(s.top()==17) binary +="H";
        	if(s.top()==18) binary +="I";
        	if(s.top()==19) binary +="J";
        	if(s.top()==20) binary +="K";
        	if(s.top()==21) binary +="L";
        	if(s.top()==22) binary +="M";
        	if(s.top()==23) binary +="N";
        	if(s.top()==24) binary +="O";
        	if(s.top()==25) binary +="P";
        	if(s.top()==26) binary +="Q";
        	if(s.top()==27) binary +="R";
        	if(s.top()==28) binary +="S";
        	if(s.top()==29) binary +="T";
        	if(s.top()==30) binary +="U";
        	if(s.top()==31) binary +="V";
        	if(s.top()==32) binary +="W";
        	if(s.top()==33) binary +="X";
        	if(s.top()==34) binary +="Y";
        	if(s.top()==35) binary +="Z";
		}
        s.pop();
    }
    return binary;
}
int main(){
	int n;int r;
	scanf("%d",&n);
	scanf("%d",&r);
	cout<<zhuanhuan(n,r);
	return 0;
}
