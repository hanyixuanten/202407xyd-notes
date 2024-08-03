#include <bits/stdc++.h>
#define int long long
const int maxn = 50005;
using namespace std;
int n, k;
int a[maxn], lm[maxn], rm[maxn]; // lm含 rm不含
signed main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    lm[1] = 1;
    int j = 1;
    for (int i = 2; i <= n; i++)
    {
        while (a[i] - a[j] > k)
            j++;
        lm[i] = max(lm[i - 1], i - j + 1);
    }
    rm[n] = 1;
    j = n;
    for (int i = n - 1; i >= 1; i--)
    {
        while (a[j] - a[i] > k)
            j--;
        rm[i] = max(rm[i + 1], j - i + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; i++)
        ans = max(ans, lm[i] + rm[i + 1]);
    printf("%d", ans);
    return 0;
}