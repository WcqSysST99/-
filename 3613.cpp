#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int a[n],b[n],c[n],d[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){
			scanf("%d %d %d",&b[i],&c[i],&d[i]);
		}
		else if(a[i]==2){
			scanf("%d %d",&b[i],&c[i]);
		}
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]==2&&b[i]==b[j]&&c[i]==c[j]){
				printf("%d\n",d[j]);
			}
		}
	}
	return 0;
}
