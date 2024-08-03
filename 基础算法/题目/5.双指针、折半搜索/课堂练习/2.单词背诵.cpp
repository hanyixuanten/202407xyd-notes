#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, h, t, n1, nown1, j_i = INT_MAX; // n1表示最多单词 j_i表示最小段落
map<string, int> mapp;
string s;
int a[maxn], b[maxn], q[maxn];
bool recited[maxn];
int main()
{
    h = 1;
    t = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        mapp[s] = i;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        cin >> s;
        a[i] = mapp[s];
        if (a[i] == 0)
            continue;
        if (!recited[a[i]])
        {
            ++n1;
            recited[a[i]] = true;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (b[a[i]] == 0 && a[i] != 0)
            ++nown1;
        b[a[i]] = i;
        q[++t] = i;
        while (q[h] < b[a[q[h]]] && h <= t)
            ++h;
        if (nown1 == n1)
            j_i = min(j_i, i - q[h] + 1);
    }
    if (nown1 == 0)
        printf("0\n0\n");
    else
        printf("%d\n%d\n", n1, j_i);
}