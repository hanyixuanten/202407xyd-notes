#include <bits/stdc++.h>
using namespace std;
long long ans;
const int maxn = 1000005;
const int mod = 1e9 + 7;
char str[maxn + 1];
int n, nxt[maxn], num[maxn];
void get_Next()
{
    num[1] = 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && str[i] != str[j + 1])
            j = nxt[j];
        if (str[i] == str[j + 1])
            j++;
        nxt[i] = j;
        num[i] = num[j] + 1;
    }
}
void Next_to_Num()
{
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && str[i] != str[j + 1])
            j = nxt[j];
        if (str[i] == str[j + 1])
            j++;
        while ((j << 1) > i)
            j = nxt[j];
        ans *= (num[j] + 1) % mod;
        ans %= mod;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ans = 1;
        scanf("%s", str + 1);
        n = strlen(str + 1);
        get_Next();
        Next_to_Num();
        printf("%d\n", ans);
    }
    return 0;
}