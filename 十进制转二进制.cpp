#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 将十进制非负整数转换为二进制字符串
string zhuanhuan(int n) {
    if (n == 0) return "0";  // 特殊处理 0

    stack<int> s;
    // 除 2 取余，余数入栈
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }

    // 依次出栈拼接结果
    string binary ; 
    while (!s.empty()) {
        binary += to_string(s.top());//!!int转字符串 
        s.pop();
    }
    return binary;
}

int main() {
    int num;
    cin >> num;
    cout << zhuanhuan(num) << endl;
    return 0;
}
