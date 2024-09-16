///
/// @param A 学号集合
/// @param n 总人数
/// @param key 需要移动的关键字
/// @param x 移动的步数

void SqSort(int A[], int n, int key, int x) {
    // 找到第一个符合 key 的元素位置 i
    int i = 0;
    while (i < n && A[i] != key) {
        i++;
    }
    // 如果没有找到符合 key 的元素，直接返回
    if (i == n) {
        printf("error: key not found\n");
        return;
    }
    // 计算新位置
    int new_position = i + x;
    // 检查新位置是否合法
    if (new_position < 0 || new_position >= n) {
        printf("error: new position out of bounds\n");
        return;
    }

    // 保存待移动的元素
    int t = A[i];

    // 移动元素
    if (x < 0) {
        // 移动到左侧
        for (int j = i; j > new_position; --j) {
            A[j] = A[j - 1];
        }
    } else if (x > 0) {
        // 移动到右侧
        for (int j = i; j < new_position; ++j) {
            A[j] = A[j + 1];
        }
    }

    // 将元素放到新位置
    A[new_position] = t;
}