int sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp != 0) {
            if (temp % 10 == 1)
                sum++;
            temp /= 10;
        }
    }
    return sum;
}