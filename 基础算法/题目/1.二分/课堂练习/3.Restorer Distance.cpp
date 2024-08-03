#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, A, R, M;
const int maxN = 1e5 + 5;
int h[maxN], cxy[maxN];
int calc(int H)
{
    int p = upper_bound(h + 1, h + N + 1, H) - h - 1, X = p * H - cxy[p], Y = (cxy[N] - cxy[p]) - (N - p) * H, c = min(X, Y);
    return A * (X - c) + R * (Y - c) + M * c;
}
bool check(int lmid, int rmid) { return calc(lmid) < calc(rmid); }
signed main()
{
    scanf("%lld%lld%lld%lld", &N, &A, &R, &M);
    M = min(M, A + R);
    for (int i = 1; i <= N; ++i)
        scanf("%lld", &h[i]);
    sort(h + 1, h + N + 1);
    for (int i = 1; i <= N; ++i)
        cxy[i] = cxy[i - 1] + h[i];
    int l = h[1], r = h[N];
    while (l < r)
    {
        int lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
        if (check(lmid, rmid))
            r = rmid - 1;
        else
            l = lmid + 1;
    }
    printf("%lld\n", calc(l));
    return 0;
}