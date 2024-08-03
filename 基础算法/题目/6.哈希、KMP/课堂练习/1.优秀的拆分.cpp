#include <bits/stdc++.h>
using namespace std;
int ans;
string s1, s2, s;
int a1, a2;
const int N = 1e5 + 5;
const int P = 13331;
unsigned long long p[N], h[N];
int n;

void init()
{
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i - 1];
    }
}
unsigned long long get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{

    int t;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        cin >> s;
        n = s.size();
        init();
        for (int i = 0; i < n; ++i)
        {
            a1 = 0, a2 = 0;
            for (int r = i + 2; r <= n; ++r, ++r)
            {
                if (get(i + 1, (r + i) / 2) == get((r + i) / 2 + 1, r))
                {
                    ++a1;
                    // cout << get(i + 1, (r + i) / 2) << " " << get((r + i) / 2 + 1, r) << " " << i << " r" << endl;
                }
            }

            for (int l = i - 2; l >= 0; --l, --l)
            {
                if (get(l + 1, (l + i) / 2) == get((l + i) / 2 + 1, i))
                {
                    ++a2;
                    // cout << get(l + 1, (l + i) / 2) << " " << get((l + i) / 2 + 1, l) << " " << i << " l" << endl;
                }
            }

            ans += a1 * a2;
        }
        printf("%d\n", ans);
    }
    return 0;
}