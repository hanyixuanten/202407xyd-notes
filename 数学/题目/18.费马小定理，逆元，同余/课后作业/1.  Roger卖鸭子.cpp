#include <bits/stdc++.h>
using namespace std;
int n;
int a[15];
int dp[1000005];
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= 1000000; j++)
        {
            dp[j] += dp[j - a[i]];
        }
    }
    for (int i = 1000000; i >= 1; i--)
    {
        if (!dp[i])
        {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("0");
    return 0;
}
