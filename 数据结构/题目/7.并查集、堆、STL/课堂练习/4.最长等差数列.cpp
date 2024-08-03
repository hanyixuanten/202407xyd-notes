#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, a[N];
short f[N][N]; // fij表示i为第一项,j为第二项的最长等差序列
short ans = 2;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("4.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            f[i][j] = 2;
    for (int j = n - 1; j >= 2; j--)
    {
        int i = j - 1, k = j + 1;
        while (i >= 1 && k <= n)
        {
            if (a[j] * 2 == a[i] + a[k])
                f[i][j] = f[j][k] + 1, ans = max(ans, f[i][j]), ++k, --i;
            if (a[j] * 2 > a[i] + a[k])
                ++k;
            if (a[j] * 2 < a[i] + a[k])
                --i;
        }
    }
    printf("%d\n", ans);
    return 0;
}