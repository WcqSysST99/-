#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
vector<vector<pair<int,int>>> adj;
vector<int> pre;

void build_map(int u, int v, int val) {
    adj[u].push_back({v, val});
}

vector<int> dijkstra(int start) {
    vector<int> dist(n+1, INF);//vector初始化写法，dist和visited还是数组 
    vector<bool> visited(n+1, false);
    dist[start] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1;
        int minDist = INF;
        for(int v = 1; v <= n; v++) {
            if(!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if(!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pre[v] = u;
            }
        }
    }
    return dist;
}

void Find_path(int start, int target) {
    stack<int> ans;
    int cur = target;
    while(cur != -1) {
        ans.push(cur);
        if(cur == start) break;
        cur = pre[cur];
    }
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    pre.resize(n + 1, -1);

    for(int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        build_map(u, v, w);
    }

    int start, target;
    cin >> start >> target;
    vector<int> dist = dijkstra(start);
    Find_path(start, target);
    return 0;
}
