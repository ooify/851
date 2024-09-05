int MaxSum(int a[], int n) {
    int sum = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (b > 0)
            b += a[i];
        else
            b = a[i];
        if (b > sum)
            sum = b;
//        c=i  记录位置
    }
    return sum;
}