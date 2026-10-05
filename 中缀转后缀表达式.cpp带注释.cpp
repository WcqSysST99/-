#include <iostream>        // 包含标准输入输出流头文件
#include <stack>           // 包含栈容器头文件
#include <string>          // 包含字符串类头文件
#include <cctype>          // 包含字符处理函数（如 isdigit）
using namespace std;       // 使用标准命名空间，避免写 std::
// 函数：返回运算符的优先级，数值越大优先级越高
int precedence(char op) {                 // 定义优先级函数，参数为运算符字符
    if (op == '^') return 3;              // 幂运算优先级最高，返回 3
    if (op == '*' || op == '/') return 2; // 乘除优先级次之，返回 2
    if (op == '+' || op == '-') return 1; // 加减优先级最低，返回 1
    return 0;                             // 非运算符返回 0
}                                         // 函数结束
// 函数：将中缀表达式转换为后缀表达式
string infixToPostfix(const string& infix) {  // 函数定义，参数为常引用中缀字符串
    stack<char> opStack;                      // 创建字符栈，存放运算符和括号
    string postfix;                           // 创建空字符串，用于构建后缀表达式
    int n = infix.length();                   // 获取中缀表达式的长度
    for (int i = 0; i < n; ++i) {             // 遍历中缀表达式的每个字符
        char ch = infix[i];                   // 取出当前字符
        if (isspace(ch)) continue;            // 如果是空白字符，跳过本次循环
        // 处理操作数（数字或小数点）
        if (isdigit(ch) || ch == '.') {       // 如果当前字符是数字或小数点
            while (i < n && (isdigit(infix[i]) || infix[i] == '.')) { // 循环读取连续的数字和小数点
                postfix += infix[i];         // 将数字或小数点追加到后缀表达式
                ++i;                         // 移动索引到下一字符
            }                                // 循环结束，已读完一个完整操作数
            postfix += ' ';                  // 操作数后添加空格分隔
            --i;                             // 回退一位，因为外层循环会自增 i
        }                                    // 处理操作数结束
        // 处理左括号
        else if (ch == '(') {                // 如果当前字符是左括号
            opStack.push(ch);                // 直接将左括号压入运算符栈
        }                                    // 处理左括号结束
        // 处理右括号
        else if (ch == ')') {                // 如果当前字符是右括号
            while (!opStack.empty() && opStack.top() != '(') { // 当栈非空且栈顶不是左括号时循环
                postfix += opStack.top();    // 将栈顶运算符追加到后缀表达式
                postfix += ' ';              // 运算符后添加空格分隔
                opStack.pop();               // 弹出栈顶运算符
            }                                // 循环结束
            if (!opStack.empty()) opStack.pop(); // 弹出对应的左括号（不输出）
        }                                    // 处理右括号结束
        // 处理运算符（+ - * / ^）
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {  // 如果是运算符
            // 处理运算符优先级和结合性
            while (!opStack.empty() && opStack.top() != '(' &&                     // 栈非空且栈顶不是左括号
                   ((ch != '^' && precedence(opStack.top()) >= precedence(ch)) ||  // 左结合：栈顶优先级 >= 当前
                    (ch == '^' && precedence(opStack.top()) > precedence(ch)))) {  // 右结合(^)：栈顶优先级 > 当前
                postfix += opStack.top();    // 弹出栈顶运算符并追加到后缀
                postfix += ' ';              // 添加空格分隔
                opStack.pop();               // 弹出栈顶元素
            }                                // 循环结束
            opStack.push(ch);                // 当前运算符入栈
        }                                    // 处理运算符结束
    }                                        // 遍历中缀表达式结束
    // 将栈中剩余的运算符全部弹出
    while (!opStack.empty()) {               // 当运算符栈非空时循环
        postfix += opStack.top();            // 将栈顶运算符追加到后缀表达式
        postfix += ' ';                      // 添加空格分隔
        opStack.pop();                       // 弹出栈顶运算符
    }                                        // 循环结束
    // 去掉末尾多余的空格（美化输出）
    if (!postfix.empty() && postfix.back() == ' ') { // 如果后缀非空且最后一个字符是空格
        postfix.pop_back();                  // 删除最后一个字符（空格）
    }                                        // 处理结束
    return postfix;                          // 返回转换完成的后缀表达式
}                                            // 函数结束
// 主函数：程序入口，提供交互式输入转换
int main() {                                 // 主函数开始
    cout << "请输入中缀表达式（可含空格，直接回车退出）:" << endl; // 输出提示信息
    string input;                              // 声明字符串变量，存储用户输入
    while (true) {                             // 无限循环，直到用户退出
        cout << "> ";                          // 输出提示符
        getline(cin, input);                   // 读取用户输入的一整行
        if (input.empty()) break;              // 如果输入为空行，跳出循环退出程序
        string output = infixToPostfix(input); // 调用转换函数得到后缀表达式
        cout << "后缀: " << output << endl;    // 输出转换结果
    }                                          // 循环结束
    return 0;                                  // 程序正常结束
}                                              // 主函数结束
