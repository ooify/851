/// 符号三角形
/// @param p 三角形矩阵 0代表‘-’ 1代表‘+’
/// @param n 最终解第一行的个数
/// @param t 当前第一行的个数
/// @param sum 解的个数
/// @param count ‘-’的个数
void backtrack(int p[][MAX_SIZE], int n, int t, int &sum, int &count) {
    int half = n * (n + 1) / 4;
//    ‘-’的个数大于总符号个数的一半或‘+’的个数大于总符号个数的一半  --无解返回
    if (count > half || (t * (t - 1) / 2 - count > half))
        return;
//    到达叶子节点  --有解记录
    if (t > n)
        sum++;
    for (int i = 0; i < 2; ++i) {
        count += i;
//        第一行第t个的取值
        p[1][t] = i;
//        其余行的取值
        for (int j = 2; j <= t; ++j) {
            p[j][t - j + 1] = p[j - 1][t - j + 1] ^ p[j - 1][t - j + 2];
            count += p[j][t - j + 1];
        }
        backtrack(p, n, t + 1, sum, count);
        for (int j = 2; j <= t; ++j) {
            count -= p[j][t - j + 1];
        }
        count -= i;
    }
}