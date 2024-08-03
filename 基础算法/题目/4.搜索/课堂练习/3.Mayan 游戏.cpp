#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int backup[10][10][10]; // 第n步的备份
bool need_pop[10][10];
int ans[10][4];
void drop() // 掉下去
{
    for (int i = 1; i <= 5; ++i)
    {
        int x = 0;
        for (int j = 1; j <= 7; ++j)
            if (!a[i][j])
                ++x;
            else
            {
                if (!x)
                    continue;
                a[i][j - x] = a[i][j], a[i][j] = 0;
            }
    }
    return;
}

bool pops() // 遇到3个
{
    bool flag = 0;
    memset(need_pop, 0, sizeof(need_pop));
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 7; ++j)
        {
            if (i - 1 >= 1 && i + 1 <= 5 && a[i - 1][j] == a[i][j] && a[i + 1][j] == a[i][j] && a[i][j])
                need_pop[i][j] = 1, need_pop[i + 1][j] = 1, need_pop[i - 1][j] = 1, flag = 1;
            if (j - 1 >= 1 && j + 1 <= 7 && a[i][j + 1] == a[i][j] && a[i][j - 1] == a[i][j] && a[i][j])
                need_pop[i][j] = 1, need_pop[i][j + 1] = 1, need_pop[i][j - 1] = 1, flag = 1;
        }
    if (!flag)
        return 0;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 7; j++)
            if (need_pop[i][j])
                a[i][j] = 0;
    return 1;
}
void back(int x) // 回溯
{
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 7; ++j)
            backup[x][i][j] = a[i][j];
}
void move(int i, int j, int x)
{
    swap(a[i][j], a[i + x][j]);
    drop();
    while (pops())
        drop();
}
bool all0()
{
    for (int i = 1; i <= 5; ++i)
    {
        if (a[i][1] != 0)
            return 0;
    }
    return 1;
}
void dfs(int x)
{
    if (all0())
    {
        for (int i = 1; i <= n; i++)
        {
            if (i != 1)
                printf("\n");
            for (int j = 1; j <= 3; j++)
                printf("%d ", ans[i][j]);
        }
        exit(0);
    }
    if (x == n + 1)
        return;
    back(x);
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 7; ++j)
        {
            if (a[i][j])
            {
                if (i + 1 <= 5 && a[i][j] != a[i + 1][j])
                {
                    move(i, j, 1);
                    ans[x][1] = i - 1;
                    ans[x][2] = j - 1;
                    ans[x][3] = 1;
                    dfs(x + 1);
                    for (int i = 1; i <= 5; i++)
                        for (int j = 1; j <= 7; j++)
                            a[i][j] = backup[x][i][j];
                    ans[x][1] = -1;
                    ans[x][2] = -1;
                    ans[x][3] = -1;
                }
                if (i - 1 >= 1 && a[i - 1][j] == 0)
                {
                    move(i, j, -1);
                    ans[x][1] = i - 1;
                    ans[x][2] = j - 1;
                    ans[x][3] = -1;
                    dfs(x + 1);
                    for (int i = 1; i <= 5; i++)
                        for (int j = 1; j <= 7; j++)
                            a[i][j] = backup[x][i][j];
                    ans[x][1] = -1;
                    ans[x][2] = -1;
                    ans[x][3] = -1;
                }
            }
        }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 5; ++i)
    {
        int tmp, j = 1;
        scanf("%d", &tmp);
        while (tmp != 0)
        {
            a[i][j] = tmp;
            scanf("%d", &tmp);
            ++j;
        }
    }
    memset(ans, -1, sizeof(ans));
    dfs(1);
    printf("-1");
    return 0;
}