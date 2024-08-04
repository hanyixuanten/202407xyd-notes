#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, mod;
int a[505];
int fa[5000005];
int cnt = 0;
struct node
{
    int u, v, w;
    const bool operator<(const node &x) const
    {
        return w > x.w;
    }
};
int fat(int x)
{
    return fa[x] == x ? x : fa[x] = fat(fa[x]);
}
void merge(int x, int y)
{
    fa[fat(x)] = fat(y);
}
int power(int a, int b)
{
    int sum = 1;
    while (b)
    {
        if (b & 1)
            sum = sum * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return sum % mod;
}
int pows(int i, int j)
{
    return (power(a[i], a[j]) + power(a[j], a[i])) % mod;
}
vector<node> edge;
signed main()
{
    scanf("%lld%lld", &n, &mod);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            edge.push_back((node){
                i,
                j,
                pows(i, j)});
            fa[cnt] = cnt;
            ++cnt;
        }
    }
    int T = 0;
    sort(edge.begin(), edge.end());
    for (node i : edge)
    {
        if (fat(i.u) != fat(i.v))
        {
            T += i.w;
            merge(i.u, i.v);
        }
    }
    printf("%lld\n", T);
    return 0;
}