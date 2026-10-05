#include <iostream>
using namespace std;

/**
 * 递归求解汉诺塔
 * @param n    盘子数量
 * @param src  源柱子（起点）
 * @param aux  辅助柱子（中转）
 * @param dst  目标柱子（终点）
 */
void hanoi(int n, char src, char aux, char dst) {
    if (n == 1) {
        // 只剩一个盘子时直接移动
        cout << "将盘子 1 从 " << src << " 移动到 " << dst << endl;
        return;
    }
    // 1. 将上方 n-1 个盘子从 src 借助 dst 移到 aux
    hanoi(n - 1, src, dst, aux);
    // 2. 将最底下的大盘子从 src 移到 dst
    cout << "将盘子 " << n << " 从 " << src << " 移动到 " << dst << endl;
    // 3. 将 n-1 个盘子从 aux 借助 src 移到 dst
    hanoi(n - 1, aux, src, dst);
}

int main() {
    int n;
    cout << "请输入汉诺塔的盘子数量：";
    cin >> n;

    if (n <= 0) {
        cout << "盘子数量必须大于0" << endl;
        return 1;
    }

    cout << "移动步骤（共 " << ((1 << n) - 1) << " 步）：" << endl;//???几步？ 
    hanoi(n, 'A', 'B', 'C');  // A 为源，B 为辅助，C 为目标
    return 0;
}
