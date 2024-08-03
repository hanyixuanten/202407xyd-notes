#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, mx;
int a[5000005];
const ll p = 1e9 + 7, ct = 998244353;
ll ans;
ll fact[5000005], pre[5000005], suf[5000005], invp[5000005], invs[5000005];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();

    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
            ch = getchar();
        }
    }

    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * f;
}
ll qpow(int b, int k) {
    ll r = 1, base = b;

    while (k) {
        if (k & 1)
            r = r * base % p;

        base = base * base % p;
        k >>= 1;
    }

    return r % p;
}
void init() {
    fact[n] = 1;

    for (int i = n - 1; i >= 1; i --) {
        fact[i] = fact[i + 1] * ct % p;
    }

    pre[0] = suf[n + 1] = 1;

    for (int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] * (ll)a[i] % p;
    }

    for (int i = n; i >= 1; i --) {
        suf[i] = suf[i + 1] * (ll)a[i] % p;
    }

    invp[n] = invs[1] = qpow(pre[n], p - 2);
    invp[0] = invs[n + 1] = 1;

    for (int i = n; i >= 2; i --) {
        invp[i - 1] = invp[i] * a[i] % p;
    }

    for (int i = 1; i < n; i ++) {
        invs[i + 1] = invs[i] * a[i] % p;
    }
}
int main() {
    n = read();

    for (int i = 1; i <= n; i ++) {
        a[i] = read();
    }

    init();
    for (int i = 1; i <= n; i ++) {
        ans = (ans % p + pre[n] % p * invp[i] % p * invs[i] % p * fact[i] % p) % p;
    }

    printf("%lld", ans);

    return 0;
}
