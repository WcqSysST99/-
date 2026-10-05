#include<bits/stdc++.h> 
using namespace std;

// 七进制字符串 → 十进制整数
long long sevenToten(string s) {
    long long ten = 0;
    int n=s.length();
    for(int i=0;i<n;i++){
    	char ch=s[i];
    	ten=ten*7+(ch-'0');//让ch转为int 
	}
    return ten;
}
// 十进制 → 二进制字符串（用栈逆序）
//只有十进制转其他进制时才用到栈 （int栈），和前面十进制转二进制同理 
//只有十进制是int 其他都是字符串 

string tenTotwo(long long ten) {
	stack<int>Stack;
    if (ten == 0) return "0";
    while (ten > 0) {
        Stack.push(ten % 2);  // 余数入栈
        ten /= 2;
    }
    string two;
    while (!Stack.empty()) {
        two += to_string(Stack.top());
		Stack.pop();  // 出栈拼接到结果
    }
    return two;
}

int main() {
    string seven;
    cin >> seven;
    long long ten = sevenToten(seven);
    string two = tenTotwo(ten);
    cout << two << endl;
    return 0;
}
