#include <bits/stdc++.h>
using namespace std;
int T;
struct node
{
    int l, r;
    bool operator<(const node &others) const
    {
        return r < others.l;
    }
};
set<node> s;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        getchar();
        if (getchar() == 'A')
        {
            int l, r, cnt = 0;
            scanf("%d %d", &l, &r);
            node tmp;
            tmp.l = l, tmp.r = r;
            auto iter = s.find(tmp);
            while (iter != s.end())
                ++cnt, s.erase(iter), iter = s.find(tmp);
            s.insert(tmp);
            printf("%d\n", cnt);
        }
        else
            printf("%d\n", s.size());
    }
    return 0;
}