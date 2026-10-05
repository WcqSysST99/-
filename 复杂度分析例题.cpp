1.
int x = 2;
while(x < n/2){
	x = 2*x;
}
O(logn)  O(n)  O(nlogn)  O(n^2)

2.
cnt = 0;
for(k = 1;k <= n;k*=2){
	for(j = 1;j <= n;j++){
		cnt++;
	}
}
std::cout<<cnt;

3.
int func(int n){
	int i = 0,sum = 0;
	while(sum < n){
		sum += ++i;
	}
	return i;
}
