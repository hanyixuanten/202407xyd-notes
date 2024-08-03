#include <bits/stdc++.h>
#define N 400001
#define len 200000
using namespace std;
int n, m, la, mi, b, ans, lm;
int a[N];
int tree[N << 2]; // 表示该子树的人数
char s;
void push_up(int u) // 更改上移
{
    tree[u] = tree[u * 2] + tree[u * 2 + 1];
}
int query(int u, int l, int r, int x, int y) // 求人数
{
    if (x <= l && r <= y)
        return tree[u];
    int mid = (l + r) >> 1, res = 0;
    if (x <= mid)
        res += query(u * 2, l, mid, x, y);
    if (y > mid)
        res += query(u * 2 + 1, mid + 1, r, x, y);
    return res;
}

void change(int u, int l, int r, int x) // 加人
{
    if (l == r)
    {
        tree[u] += 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        change(u * 2, l, mid, x);
    else
        change(u * 2 + 1, mid + 1, r, x);
    push_up(u);
}

int kth(int u, int l, int r, int k) // 求第k大
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1, l1 = -1, r1 = -1;
    if (mi < l)
        l1 = tree[u * 2];
    else if (l <= mi && mi <= mid)
        l1 = query(u * 2, l, mid, mi, mid);
    else if (mid < mi && mi <= r)
        r1 = query(u * 2 + 1, mid + 1, r, mi, r);
    else
        r1 = tree[u * 2 + 1];
    // 左边数量与右边数量
    if (r1 == -1)
        r1 = tree[u] - l1;
    l1 = tree[u] - r1;
    if (r1 >= k)
        return kth(u * 2 + 1, mid + 1, r, k);
    else
        return kth(u * 2, l, mid, k - r1);
}

void ql(int u, int l, int r, int x, int y) // 员工离职后清零操作
{
    if (l == r)
    {
        tree[u] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid && tree[u * 2])
        ql(u * 2, l, mid, x, y);
    if (y > mid && tree[u * 2 + 1])
        ql(u * 2 + 1, mid + 1, r, x, y);
    push_up(u);
}

int main()
{
    scanf("%d%d\n", &n, &m);
    lm = m, m += len;
    for (int i = 1; i <= n; i++)
    {
        int x;
        s = getchar();
        scanf("%d\n", &x);
        if (s == 'I')
        {
            if (x < lm)
                continue;
            change(1, 0, N - 1, x - b + len); // 加入员工
        }
        else if (s == 'A')
            m -= x, b += x; // 增加工资
        else if (s == 'S')
        {
            m += x, b -= x;
            if (m >= 1 && query(1, 0, N - 1, 0, m - 1) > 0)
                ans += query(1, 0, N - 1, 0, m - 1), ql(1, 0, N - 1, 0, m - 1); // 员工离职
        }
        else
        {
            if (x > query(1, 1, N - 1, m, N - 1))
                puts("-1"); // 工资大于k的数量
            else
                printf("%d\n", kth(1, 0, N - 1, x) + b - len);
        }
    }
    printf("%d\n", ans);
    return 0;
}
