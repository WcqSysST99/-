#include<bits/stdc++.h>
using namespace std;
const int N=19;
int n,col[N],cnt;
bool ua[N],ub[2*N],uc[2*N];
void dfs(int r){
	if(r>n){
		cnt++;
			for(int i=1;i<=n;i++)cout<<col[i]<<" ";
			cout<<endl;
			return;
		}
	for(int i=1;i<=n;i++){
		if(!ua[i]&&!ub[r-i+n]&&!uc[r+i]){
			col[r]=i;
			ua[i]=ub[r-i+n]=uc[r+i]=1;
			dfs(r+1);
			ua[i]=ub[r-i+n]=uc[r+i]=0;
		}
	}
}
int main(){
	cin>>n,dfs(1),cout<<cnt;
	return 0;
}
