void activity(int n, int s[], int f[], bool A[]) {
    A[1] = true;
    int j = 1;
    for (int i = 2; i <= n; ++i) {
        if (s[i] >= f[j]) {
            A[i] = true;
            j = i;
        } else {
            A[i] = false;
        }

    }
}