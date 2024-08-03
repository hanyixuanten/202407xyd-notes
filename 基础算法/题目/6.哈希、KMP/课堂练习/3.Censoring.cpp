#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int hashs = 13331, N = 1000005;
int p[N], hb, h[N];
int len, la, lb;
char s1[N], s2[N], ans[N];
signed main()
{
    cin >> s1 + 1 >> s2 + 1;
    la = strlen(s1 + 1);
    lb = strlen(s2 + 1);
    p[0] = 1;
    for (int i = 1; i <= lb; i++) // hash init
    {
        p[i] = p[i - 1] * hashs;
        hb = hb * hashs + s2[i];
    }
    for (int i = 1; i <= la; i++)
    {
        ans[++len] = s1[i];
        h[len] = h[len - 1] * hashs + s1[i]; // hash
        if (hb == h[len] - h[len - lb] * p[lb])
            len -= lb;
    }
    for (int i = 1; i <= len; i++)
        printf("%c", ans[i]);
    return 0;
}
