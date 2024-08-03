#include <bits/stdc++.h>
using namespace std;
int n;
void work(char s[])
{
    printf("%s",s);
    for (int i = 1; i <= n - 3; ++i)
        printf("0");
    printf("\n");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("2.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        if (n == 1)
        {
            puts("1");
            continue;
        }
        work("169");
        work("196");
        work("961");
        for (int i = 1; i < n / 2; ++i) //
        {
            printf("1");
            for (int j = 1; j <= i; ++j)
                printf("0");
            printf("6");
            for (int j = 1; j <= i; ++j)
                printf("0");
            printf("9");
            for (int j = 3 + 2 * i; j < n; ++j)
                printf("0");
            printf("\n");

            printf("9");
            for (int j = 1; j <= i; ++j)
                printf("0");
            printf("6");
            for (int j = 1; j <= i; ++j)
                printf("0");
            printf("1");
            for (int j = 3 + 2 * i; j < n; ++j)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}
/*
13: 169
14: 196 n=3
31: 961

103: 10609 130: 16900
140: 19600 n=5
301: 90601 310: 96100

1003: 1006009 1030: 1060900 1300: 1690000
1400: 196000 n=7
3001: 9006001 3010: 9060100 3100: 9610000
*/