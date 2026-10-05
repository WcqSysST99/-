#include<bits/stdc++.h>
using namespace std;
//上楼梯问题，有n个台阶，每次可以上2/3个台阶，有几种登上楼的方式？
int upstairs(int n){	//形参
		//递归中止
	if(n <= 1) return 0;
	if(n == 2 || n == 3) return 1;
	return upstairs(n - 2) + upstairs(n - 3);
}
int main(){
	int n; cin>> n ;
	cout<<upstairs(n);
	return 0;
}
