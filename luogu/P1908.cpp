#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[500005];
int c[500005];
ll ans;
void find(int l, int r)
{
    if (r == l)
        return;
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1, k = l;
    find(l, mid);
    find(mid + 1, r);
    while (i <= mid && j <= r)
        if (a[i] <= a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++], ans += mid - i + 1; // 统计答案
    while (i <= mid)
        c[k++] = a[i++];
    while (j <= r)
        c[k++] = a[j++];
    for (int li = l; li <= r; li++)
        a[li] = c[li];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    find(1, n);
    printf("%lld\n", ans);
    return 0;
}