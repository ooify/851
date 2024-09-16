void up(char *s) {
    while (*s != ' ' && *s) {
        if ('a' <= *s && *s <= 'z') {
            *s -= 32;
        }
        s++;
    }
}

void down(char *s) {
    while (*s != ' ' && *s) {
        if ('A' <= *s && *s <= 'Z') {
            *s += 32;
        }
        s++;
    }
}

void Reverse(char *str) {
    while (*str) {
        int low = 0, high = 0;
        char *s = str;
        while (*s != ' ' && *s) {
            if ('a' <= *s && *s <= 'z')
                low++;
            if ('A' <= *s && *s <= 'Z')
                high++;
            s++;
        }
        if (low < high)
            up(str);
        else
            down(str);
        str = ++s;
    }
}