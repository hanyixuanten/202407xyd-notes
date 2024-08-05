#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> unused;
vector<int> a;
unordered_map<int, int> ma;
int main()
{
    freopen("seq.in", "r", stdin);
    freopen("seq.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp), ++ma[tmp];
    }
    for (int i = n; i >= 1; --i)
    {
        if (ma[i] == 0)
            unused.push_back(i);
    }
    for (auto i : unused)
    {
        auto j = a.begin();
        while (*j < i && j != a.end())
            ++j;
        a.emplace(j, i);
    }
    for (auto i : a)
    {
        printf("%d\n", i);
    }
}
/*
记录未用过的数，从小到大排序，放在第一个大于他的数的前面
预计：100pts-eps
*/