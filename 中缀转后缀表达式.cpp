#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// 运算符优先级
int precedence(char op) {
    if (op == '^') return 3;//不知道这是什么符号 
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 中缀 → 后缀
string infixToPostfix(const string& infix) {//输入中缀字符串 
    stack<char> opStack;//开一个存char类型的栈 
    string postfix;//后缀 
    int n = infix.length();//中缀的长度 

    for (int i = 0; i < n; ++i) {//重要！！！！！string可以这样分割字符，用c++还直接有栈 有string 
        char ch = infix[i];
        if (isspace(ch)) continue;   // 忽略空格

        // 操作数（数字/小数点）
        if (isdigit(ch) || ch == '.') {
            while (i < n && (isdigit(infix[i]) || infix[i] == '.')) {
                postfix += infix[i];
                ++i;
            }
            postfix += ' ';
            --i;   // 回退，外层循环会 i++
        }
        // 左括号
        else if (ch == '(') {
            opStack.push(ch);//遇到左括号压栈 
        }
        // 右括号
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {//遇到右括号，弾栈直到遇到左括号 
                postfix += opStack.top();
                postfix += ' ';//后缀加上栈顶内容 
                opStack.pop();//然后把栈顶弹出  
            }
            if (!opStack.empty()) opStack.pop(); // 下一个就是左括号，把左括号也弹出 
        }
        // 运算符
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!opStack.empty() && opStack.top() != '(' &&
                   ((ch != '^' && precedence(opStack.top()) >= precedence(ch)) ||
                    (ch == '^' && precedence(opStack.top()) > precedence(ch)))) {//
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            opStack.push(ch);
        }
    }

    // 弹出剩余运算符
    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += ' ';
        opStack.pop();
    }

    if (!postfix.empty() && postfix.back() == ' ') {
        postfix.pop_back();   // 去掉末尾空格
    }
    return postfix;
}

int main() {
    cout << "请输入中缀表达式（可含空格，直接回车退出）:" << endl;
    string input;
    while (true) {
        cout << "> ";
        getline(cin, input);//！！！！！！！！！！！！！ 
        if (input.empty()) break;          // 空行退出
        string output = infixToPostfix(input);
        cout << "后缀: " << output << endl;
    }
    return 0;
}
