/// 装载量问题  转换为将尽可能多的集装箱装到第一艘船上
/// @param i 当前集装箱
/// @param n 总集装箱个数
/// @param c 第一艘船的承载量
/// @param r 剩余总重量  初始为集装箱总和
/// @param cw 当前载货量
/// @param w w[i] 第i个集装箱的重量
/// @param x x[i] 第i个集装箱装与不装（0/1）
int bestw;

void backtrack(int i, int n, int c, int &r, int cw, int w[], int x[]) {
    if (i > n) {
//        处理bestw、bestx
        handle();
        return;
    }
    r -= w[i];
    if (cw + w[i] <= c) {
        x[i] = 1;
        cw += w[i];
        backtrack(i + 1, n, c, r, cw, w, x);
        cw -= w[i];
    }
    if (cw + r > bestw) {
        x[i] = 0;
        backtrack(i + 1, n, c, r, cw, w, x);
    }
    r += w[i];
}