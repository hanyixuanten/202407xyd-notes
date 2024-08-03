#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10005;
const int P = 13331;
unsigned long long p[N], h[N];
char s[N];
int n;
int f[N]; // 前i个字符最小压缩长度

void init()
{
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i];
    }
}
unsigned long long get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
inline int calca(int x)
{
    int res = 0;
    while (x)
        x /= 10, ++res;
    return res;
}
signed main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    init();
    for (int i = 1; i <= n; ++i)
        f[i] = i + 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            int H = get(i - j + 1, i);
            for (int k = i - j + 1, t = 1; k > 0; k -= j, ++t)
            {
                if (get(k, k + j - 1) != H)
                    break;
                f[i] = min(f[i], f[k - 1] + j + calca(t));
            }
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}