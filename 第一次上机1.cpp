#include<bits/stdc++.h>
using namespace std;
bool zhishu(int m){
	for(int i=2;i<=sqrt(m);i++){
		if(m%i==0) return false;
	}
	return true;
}
int zhishuyinzi(int m){
	if(zhishu(m)) return m;
	else{
	
	for(int i=m;i>=2;i--){
		if(zhishu(i)&&(m%i==0)) return i;
	}
	
	}
	
}
int main(){
	int m;int n;
	scanf("%d %d",&m,&n);
	for(int i=m;i<=n;i++){
		cout<<zhishuyinzi(i);
		if(i!=n) cout<<",";
	}
	return 0;
}
