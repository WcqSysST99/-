#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void Build_map(int u,int v,int w){
	//adj[u][v] = w;
	dist[u][v] = w;
} 
void floyd(/*int &adj[n+1][n+1],*/int &dist[n+1][n+1]){
	for(int k = 0;k <= n;k++){	//k 代表中间点 
		for(int i = 0 ;i <= n;i++){	//i 代表起点 
			for(int j = 0;j <= n;j++){	//j 代表终点 
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	return;
}
int main(){
	int n;cin >> n;
	int adj[n+1][n+1];
	int dist[n+1][n+1];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <= n;j++){
			adj[i][j] = INF;
		}
	}
	floyd(dist);
	int start,target;cin>>start>>target;
	cout<<dist[start][target];
}
