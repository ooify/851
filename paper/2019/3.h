int strcmp(char *s1, char *s2) {
    down(s1);
    down(s2);
    while (*s1 == *s2) {
        s1++;
        s2++;
        if (!(*s1) && !(*s2))
            return 0;
    }
    if (*s1 < *s2)
        return -1;
    else
        return 1;
}

void split(char *str, char *m[], int &n) {
    n = 0;
    char *s = str;
    while (*s) {
        if (*s == ' ') {
            *s = '\0';
            m[n++] = str;
            str = ++s;
        }
        s++;
    }
    m[n++] = str;
}

void sort(char *A[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(A[i], A[j]) == 1) {
                char *temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}