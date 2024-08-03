#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int INF = 0x3f3f3f3f;
int dp[20][305][305];
LL ans;
int n;
void work(int num, int l, int r)
{
    if (l == r)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)

                if (i != l && j != l && i != j)
                {
                    if (dp[num][i][j] >= INF)
                        ans -= 1;
                    else
                        ans += dp[num][i][j];
                }
        return;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[num + 1][i][j] = dp[num][i][j];
    int mid = (l + r) / 2;
    for (int k = l; k <= mid; k++)
        for (int i = 1; i <= n; i++)
        {
            if (dp[num + 1][i][k] == -1)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if (dp[num + 1][k][j] == -1)
                    continue;
                dp[num + 1][i][j] = min(dp[num + 1][i][j], dp[num + 1][i][k] + dp[num + 1][k][j]);
            }
        }
    work(num + 1, mid + 1, r);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[num + 1][i][j] = dp[num][i][j];
    for (int k = mid + 1; k <= r; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dp[num + 1][i][k] == -1)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if (dp[num + 1][k][j] == -1)
                    continue;
                dp[num + 1][i][j] = min(dp[num + 1][i][j], dp[num + 1][i][k] + dp[num + 1][k][j]);
            }
        }
    }
    work(num + 1, l, mid);
}
int main()
{
    scanf("%d",&n);
    ans = 0;
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &dp[0][i][j]);
            if (dp[0][i][j] == -1)
                dp[0][i][j] = INF;
        }
    }
    work(0, 1, n);
    printf("%lld\n",ans);
    return 0;
}