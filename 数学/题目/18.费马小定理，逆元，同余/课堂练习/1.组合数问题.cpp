#include<bits/stdc++.h>
#define MAXN 5000005
typedef long long LL;
const int mod = 998244353;
int f[MAXN], inv[MAXN];
int main() {
    int T, N;
    scanf("%d%d", &T, &N);
    f[0] = f[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= N; i++) f[i] = (LL) f[i - 1] * i % mod, inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
    for (int i = 1; i <= N; i++) inv[i] = (LL) inv[i - 1] * inv[i] % mod;
    LL ans = 0;
    int n, m;
    while(T--) scanf("%d%d", &n, &m), ans ^= (LL) f[n] * inv[m] % mod * inv[n - m] % mod;
    printf("%lld\n", ans);
    return 0;
}