#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> nd[20];
void dfs(int m)
{
    if (m == n - 1)
    {
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < nd[i].size(); ++j)
        {
            if (nd[i].size() > 1 && nd[nd[i][j]].size() > 1)
            {
                
                // del dfs add
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        nd[x].push_back(y);
        nd[y].push_back(x);
    }
    dfs(m);
    return 0;
}