#include "math.h"

//最长上升子序列
int LIS(int A[], int n) {
    int ans = 1;
    int dp[n + 1];
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (A[i] > A[j]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
        ans = fmax(ans, dp[i]);
    }
    return ans;

}