#include <bits/stdc++.h>
using namespace std;
int n, L;
char s[1000005];
int dept(int l, int r)
{
    if ((r - l + 1) % 2 != 0)
        return -1;
    if (r == l + 1)
        return (s[l] == '(' && s[r] == ')') ? 1 : -1;
    if (s[l] == '(' && s[r] == ')')
    {
        int tmp = dept(l + 1, r - 1);
        if (tmp != -1)
            return tmp + 1;
    }
    int dep = 0;
    int ll = l;
    bool ans = 1;
    int maxdep = 0;
    for (int i = l; i <= r; ++i)
    {
        if (dep == 0 && i != l && i != r)
        {
            int tmp = dept(ll, i);
            ans = ans && (tmp != -1), ll = i;
        }
        if (s[i] == '(')
            ++dep, maxdep = max(maxdep, dep);
        else
            --dep;
        if (dep < 0 || !ans)
            return -1;
    }
    return (ans && dep == 0) ? maxdep : -1;
}
int ans = INT_MAX;
void dfs(int dep, int nowid) // 30pts
{
    if (nowid > n)
        return;
    if (dep > ans)
        return;
    int tmp = dept(1, n);
    if (tmp <= L && tmp != -1)
    {
        ans = min(ans, dep);
        return;
    }
    dfs(dep, nowid + 1);
    s[nowid] = (s[nowid] == '(' ? ')' : '(');
    dfs(dep + 1, nowid + 1);
    s[nowid] = (s[nowid] == '(' ? ')' : '(');
    return;
}
int main()
{
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    scanf("%d%d\n", &n, &L);
    cin >> s + 1;
    dfs(0, 1);
    printf("%d\n", ans);
    return 0;
}
