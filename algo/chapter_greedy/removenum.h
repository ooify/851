/// 删除字符串num中n个数字保证剩下的数字最小
/// @param num
/// @param n
/// @return
char *RemoveNum(char *num, int n) {
    while (n--) {
        bool flag = false;
        char *s = num;
        while (*s) {
            if (*s > *(s + 1)) {
                flag = true;
                break;
            }
            s++;
        }
        if (flag) {
            while (*(s + 1)) {
                *s = *(s + 1);
                s++;
            }
        }
        *s = '\0';
    }
    return num;
}