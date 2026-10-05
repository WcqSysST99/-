#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int a[m];
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	int r[n];
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		printf("%d\n",a[r[i]]);
	}
	return 0;
}

