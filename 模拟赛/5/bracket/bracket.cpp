#include <bits/stdc++.h>
using namespace std;
int n, L;
char s[1000005];
int fans = 0;
bool dept(int l, int r)
{
    if (r == l + 1)
    {
        fans = max(fans, 1);
        return (s[l] == '(' && s[r] == ')') ? 1 : 0;
    }
    int dep = 0;
    int ll = l;
    bool ans = 1;
    for (int i = l; i <= r; ++i)
    {
        if (dep == 0 && i != l && i != r)
            ans = ans && dept(ll, i), ll = i;
        if (s[i] == '(')
            ++dep, fans = max(fans, dep);
        else
            --dep;
        if (dep < 0 || !ans)
            return 0;
    }
    return dep == 0 && ans;
}
int main()
{
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    scanf("%d%d\n", &n, &L);
    cin >> s + 1;
    printf("%d %d\n", dept(1, n), fans);
    return 0;
}