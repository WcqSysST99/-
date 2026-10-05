#include <iostream>
#include <queue>   // 使用队列必须包含此头文件
using namespace std;
int main() {
    // 创建一个存放整数的队列
    queue<int> q;

    // 1. 入队：push
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "当前队列大小: " << q.size() << endl;         // 输出 3
    cout << "队首元素: " << q.front() << endl;            // 10
    cout << "队尾元素: " << q.back()  << endl;            // 30

    // 2. 出队：pop（只删除，不返回值，通常配合 front 使用）
    cout << "出队元素: " << q.front() << endl;            // 10
    q.pop();   // 移除队首元素

    cout << "出队后队首元素: " << q.front() << endl;      // 20
    cout << "当前队列大小: " << q.size() << endl;         // 2

    // 3. 继续出队直至队列为空
    while (!q.empty()) {
        cout << "出队: " << q.front() << endl;
        q.pop();
    }

    cout << "队列是否为空: " << (q.empty() ? "是" : "否") << endl; // 是

    return 0;
}
