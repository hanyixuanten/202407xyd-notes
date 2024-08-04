#include <bits/stdc++.h>
using namespace std;
string s;
string t;
bool s1[500005], t1[500005], backup[500005];
int minans;
int ans;
int n;
void dfs()
{
    if (ans > minans || ans > n)
        return;
    bool flag = 0;
    for (int i = 0; i < n; ++i)
        if (s1[i] != t1[i])
        {
            flag = 1;
            break;
        }
    if (!flag)
    {
        minans = min(ans, minans);
        return;
    }
    for (int l = 0; l < n; ++l)
    {
        for (int r = n - 1; r >= l; --r)
        {
            memcpy(backup, s1, n + 1);
            for (int i = l; i <= r; ++i)
                s1[i] = !s1[i];
            ++ans;
            dfs();
            --ans;
            for (int i = l; i <= r; ++i)
                s1[i] = 0;
            ++ans;
            dfs();
            --ans;
            for (int i = l; i <= r; ++i)
                s1[i] = 1;
            ++ans;
            dfs();
            --ans;
            memcpy(s1, backup, n + 1);
        }
    }
    return;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        cin >> s >> t;
        n = s.length();
        minans = 0x7f7f7f7f;
        ans = 0;
        for (int i = 0; i < n; ++i)
        {
            s1[i] = (s[i] == '0') ? 0 : 1;
            t1[i] = (t[i] == '0') ? 0 : 1;
        }
        dfs();
        printf("%d\n", minans);
    }
    return 0;
}