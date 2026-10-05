#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    int cnt = 0; 
    while (!q.empty()) {
        int person = q.front();
        q.pop();
        cnt++;
        if (cnt == m) {
            cout << person << " ";
            cnt = 0; 
        } else {
            // 没数到 m，放回队尾继续等待
            q.push(person);
        }
    }
    return 0;
}
