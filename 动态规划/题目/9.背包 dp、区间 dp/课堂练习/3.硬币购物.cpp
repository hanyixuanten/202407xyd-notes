#include <bits/stdc++.h>
using namespace std;
unsigned long long c[5];
int n;
unsigned long long d[5];
unsigned int t;
int main()
{
    scanf("%llu%llu%llu%llu%d", &c[0], &c[1], &c[2], &c[3], &n);
    while (n--)
    {
        scanf("%llu%llu%llu%llu%u", &d[0], &d[1], &d[2], &d[3], &t);
        vector<unsigned long long> f(t + 1);
        f[0] = 1;
        for (size_t o = 0; o < 4; ++o)
        {
            unsigned int w = c[o], m = d[o];
            vector<unsigned long long> g(f);
            vector<unsigned long long> s(w);
            for (unsigned long long i = 0; i * w <= t; ++i)
                for (unsigned long long j = 0; j < w && i * w + j <= t; ++j)
                {
                    g[i * w + j] += s[j];
                    s[j] += f[i * w + j];
                    if (i >= m)
                        s[j] -= f[(i - m) * w + j];
                }
            f = g;
        }
        printf("%llu\n", f.back());
    }
    return 0;
}