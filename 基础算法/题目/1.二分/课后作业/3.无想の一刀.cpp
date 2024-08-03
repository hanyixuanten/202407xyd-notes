#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2005;
int n, m, mx = -1, h[maxn][maxn], ans, col[maxn][maxn], lst[maxn];
int mn = 1e18;
bool ok[maxn][maxn];
void clear()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            col[i][j] ^= col[i][j];
}
void init()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ok[i][j] ^= ok[i][j];
}
bool check(int x)
{
    clear();
    bool flag = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (h[i][j] >= mx - x)
                if (h[i][j] <= mn + x)
                    col[i][j] = 3;
                else
                    col[i][j] = 1;
            else if (h[i][j] <= mn + x)
                col[i][j] = 2;
            else
                return false;
    // check1
    init();
    int l = 1, r = m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= r; ++j)
            if (col[i][j] == 1 || col[i][j] == 3)
                ok[i][j] = true;
            else
            {
                r = j - 1;
                break;
            }
        if (col[i + 1][1] == 2)
            break;
    }
    for (int i = n; i > 0; --i)
    {
        for (int j = m; j >= l; --j)
        {
            if (!ok[i][j] && col[i][j] != 1)
                ok[i][j] = 1;
            else
            {
                l = j + 1;
                break;
            }
        }
        if (col[i - 1][m] == 1)
            break;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!ok[i][j])
                flag = false;
    if (flag)
        return true;
    // check2
    init();
    flag = true, l = 1, r = m;
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= r; ++j)
            if (col[i][j] == 1 || col[i][j] == 3)
                ok[i][j] = true;
            else
            {
                r = j - 1;
                break;
            }
        if (col[i - 1][1] == 2)
            break;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= l; --j)
        {
            if (!ok[i][j] && col[i][j] != 1)
                ok[i][j] = 1;
            else
            {
                l = j + 1;
                break;
            }
        }
        if (col[i + 1][m] == 1)
            break;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!ok[i][j])
                flag = false;
    if (flag)
        return true;
    // check3
    init();
    flag = true, l = m, r = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= r; --j)
            if (col[i][j] == 1 || col[i][j] == 3)
                ok[i][j] = true;
            else
            {
                r = j + 1;
                break;
            }
        if (col[i + 1][1] == 2)
            break;
    }
    for (int i = n; i > 0; --i)
    {
        for (int j = 1; j <= l; ++j)
        {
            if (!ok[i][j] && col[i][j] != 1)
                ok[i][j] = 1;
            else
            {
                l = j - 1;
                break;
            }
        }
        if (col[i - 1][1] == 1)
            break;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!ok[i][j])
                flag = false;
    if (flag)
        return true;
    // check4
    init();
    flag = true, l = m, r = 1;
    for (int i = n; i >= 1; --i)
    {
        for (int j = m; j >= r; --j)
            if (col[i][j] == 1 || col[i][j] == 3)
                ok[i][j] = true;
            else
            {
                r = j + 1;
                break;
            }
        if (col[i - 1][m] == 2)
            break;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= l; ++j)
        {
            if (!ok[i][j] && col[i][j] != 1)
                ok[i][j] = 1;
            else
            {
                l = j - 1;
                break;
            }
        }
        if (col[i + 1][1] == 1)
            break;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!ok[i][j])
                flag = false;
    if (flag)
        return true;
    return false;
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            scanf("%lld", &h[i][j]);
            mx = max(mx, h[i][j]), mn = min(mn, h[i][j]);
        }
    int l = 0, r = mx - mn, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld", ans);
    return 0;
}