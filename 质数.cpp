//埃拉托斯特尼筛法：欧拉筛/aishishai
//筛选1-n的质数
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1E8;
int prime[maxn];
void lineshai(int n){
	for(int i = 2;i <= n; i++){
		bool flag = 0;
		for(int j = 2;j <= sqrt(n); j++){
			if(i % j == 0) flag = 1;
		}
		if (flag = 0) prime[cnt++] = i;
	}
}
int main(){
	int n;cin>>n;
	lineshai(n);
}
