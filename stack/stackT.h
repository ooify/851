#include "linkstack.h"
#include "sqstack.h"

//1.只有小括号，检查是否匹配
bool Match(int exp[], int n)
{
    SqStack S;
    InitSqStack(S);
    for (int i = 0; i < n; ++i)
    {
        if (exp[i] == '(')
            Push(S, exp[i]);
        else
        {
            if (SqStackEmpty(S))
                return false;
            int x;
            Pop(S, x);
        }
    }
    return SqStackEmpty(S);
}

//2.一个后缀表达式存放在char exp[]中计算并返回最终计算结果
int Calc(int a, char op, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (!b)return -999;
        return a / b;
    default:
        return -999;
    }
}

int CalcExp(char exp[])
{
    int a, b, x;
    SqStack S;
    InitSqStack(S);
    char* p = exp;
    while (*p)
    {
        //        printf("%d\n", *p);
        if (*p >= '0' && *p <= '9')
        {
            Push(S, *p - '0');
        }
        else
        {
            Pop(S, b);
            Pop(S, a);
            x = Calc(a, *p, b);
            if (x == -999)
                return -999;
            Push(S, x);
        }
        p++;
    }
    Pop(S, x);
    return x;
}

//4.使用两个栈模拟队列
bool EnStackQueue(SqStack& in, int e)
{
    return Push(in, e);
}

bool DeStackQueue(SqStack& in, SqStack& out, int& e)
{
    if (SqStackEmpty(out))
        while (!SqStackEmpty(in))
        {
            int x;
            Pop(in, x);
            if (!Push(out, x))
                return false;
        }
    return Pop(out, e);
}

//5.I代表入栈，O代表出栈，开始栈为空，最后栈为空，判断操作序列是否合法
bool JudgeSq(char str[])
{
    char* p = str;
    int i = 0;
    int o = 0;
    while (*p)
    {
        if (*p == 'i')
            i++;
        else
            o++;
        if (o > i)return false;
        p++;
    }
    if (i != o)
        return false;
    return true;
}

// bool JudgeSq(char str[]) {
//     SqStack S;
//     InitSqStack(S);
//     char *p = str;
//      while (*p) {
//         if (*p == 'i') {
//             Push(S, *p);
//         } else {
//             int t;
//             if (!Pop(S, t))return false;
//         }
//         p++;
//     }
//     return SqStackEmpty(S);
// }

//6.带头节点的循环单链表表示队列 只有一个指向尾节点的指针
bool EnLinkListQueue(LNode*& rear, int e)
{
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (!s)return false;
    s->Elem = e;
    s->next = rear->next;
    rear->next = s;
    rear = s;
    return true;
}

bool DeLinkListQueue(LNode*& rear, int& e)
{
    if (rear->next == rear)return false;
    LNode* p = rear->next->next;
    e = p->Elem;
    rear->next->next = p->next;
    if (p == rear)
        rear = rear->next;
    free(p);
    return true;
}


//7.只有小括号和中括号，检查是否匹配
bool CheakBrac(char str[])
{
    SqStack S;
    InitSqStack(S);
    int s;
    char* p = str;
    while (*p)
    {
        if (*p == '(' || *p == '[')
            Push(S, *p);
        else if (*p == ')')
        {
            Pop(S, s);
            if (s != '(')return false;
        }
        else if (*p == ']')
        {
            Pop(S, s);
            if (s != '[')return false;
        }
        p++;
    }
    return SqStackEmpty(S);
}

//T8.火车软硬卧调换
void SwitchType(char str[])
{
    SqStack S;
    InitSqStack(S);
    char* p = str;
    while (*p)
    {
        if (*p == 'H') Push(S, *p);
        else
            printf("%c", *p);
        p++;
    }
    while (!SqStackEmpty(S))
    {
        int c;
        Pop(S, c);
        printf("%c", c);
    }
}

//T9.以@结束的字符串判断是否形如：序列1&序列2，a+b&b+a
bool Chack(char str[])
{
    char *p, *q;
    p = q = str;
    while (*q != '@')q++;
    q--;
    while (p <= q)
    {
        if (*p++ != *q--)
            return false;
    }
    return true;
}

//T13.回文判断
bool ChackStr(char str[])
{
    char *p, *q;
    p = q = str;
    while (*q)q++;
    q--;
    while (p < q)
    {
        if (*p == *q)
        {
            p++;
            q--;
        }
        else
            return false;
    }
    return true;
}
