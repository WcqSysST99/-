#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj(n);
void addEdge(int u,int v){
	adj[u].push_back(v);
	return;
}

void dfs(int u,vector<vector<int>> &adj,vector<bool> &visited)
{
	visited[u] = true;
	cout<<u<<" ";
	for(int v : adj[u]){
	//for(int v=0;v<adj[u].size();v++)Ò²ÐÐ
		if(!visited[v]){
			dfs(v,adj,visited);
		}
	}
}
int main(){
	vector<bool> visited(n,false);
	for(int i = 0;i <= n;i++){
		dfs(i,adj,visited);
	}
}
	
