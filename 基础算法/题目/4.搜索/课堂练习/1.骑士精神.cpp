#include <bits/stdc++.h>
using namespace std;
string a[10];
int D = 1;
int moves[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
string alast[5] = {"11111", "01111", "00*11", "00001", "00000"};
int maxflag = 0;
int e()
{
    int cnt = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (a[i][j] != alast[i][j])
                ++cnt;
        }
    }
    return cnt;
}
int dfs(int nowd, int wx, int wy, int prex, int prey)
{
    int flag = e();
    if (flag == 0)
        return nowd;
    if (flag >= 1 && nowd == 15)
        return 16;
    if (flag + nowd > D)
        return 16;
    int mina = 16;
    for (int i = 0; i < 8; ++i)
    {
        int x = wx + moves[i][0], y = wy + moves[i][1];
        if (x >= 0 && y >= 0 && x <= 4 && y <= 4 && (x != prex || y != prey))
        {
            a[wx][wy] = a[x][y], a[x][y] = '*';
            int ans = dfs(nowd + 1, x, y, wx, wy);
            a[x][y] = a[wx][wy], a[wx][wy] = '*';
            mina = min(mina, ans);
        }
    }
    return mina;
}
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        int wx = 0, wy = 0;
        for (int i = 0; i < 5; ++i)
            getline(cin, a[i]);
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
            {
                if (a[i][j] == '*')
                {
                    wx = i, wy = j;
                    break;
                }
            }
        int ans = dfs(0, wx, wy, -1, -1);
        while (ans == 16 && D <= 15)
        {
            ++D;
            ans = dfs(0, wx, wy, -1, -1);
        }
        printf("%d\n", (ans == 16) ? -1 : ans);
    }
    return 0;
}