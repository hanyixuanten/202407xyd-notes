#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int minlen = INT_MAX;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        minlen = min(minlen, r - l + 1);
    }
    printf("%d\n", minlen);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        printf("%d ", i % minlen);
    return 0;
}