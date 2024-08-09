#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, modn = 1e9 + 7;
int n, k, q, suma;
int a[maxn];
int f[maxn][20], fa[maxn][20];
int main()
{

    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= n; ++i)
    {

        scanf("%d", &a[i]);
        f[i][0] = a[i];
        fa[i][0] = (i + k) % n + 1;
        suma += a[i];
    }
    while (q--)
    {
        int x;
        long long m, ans = 0;
        scanf("%d%lld", &x, &m);
        memset(f, 0, sizeof(f));
        memset(fa, 0, sizeof(fa));
        for (int k = 1; k <= 18; ++k)
        {
            for (int u = 1; u <= n; ++u)
            {
                fa[u][k] = fa[fa[u][k - 1]][k - 1] % modn;
                f[u][k] = f[u][k - 1] + f[fa[u][k - 1]][k - 1];
            }
        }
        
    }
    return 0;
}