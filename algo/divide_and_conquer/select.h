int j;

/// 查找a中的第k小
/// @param a 数集
/// @param p 头
/// @param r 尾
/// @param k 第k小
/// @return
int Select(int a[], int p, int r, int k) {
//    第一个等于最后一个
    if (p == r)return a[p];
    int i = partition(a, p, r);
    j = i - p + 1;
    if (k <= j)
        return Select(a, p, i, k);
    else
        return Select(a, p, i + 1, k - j);
}