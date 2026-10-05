#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int balance = 0;
    int flips = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } 
		else {
            balance--;
        }
        if (balance < 0) {
            flips++;
            balance = 1; // 翻转后相当于一个 '('，平衡从 -1 变为 +1
        }
    }
    // 多余的 '(' 需要翻转一半
    flips += balance / 2;
    cout << flips;
    return 0;
}
