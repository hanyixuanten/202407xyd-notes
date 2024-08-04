#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double temp = 0;
        int i = 1;
        int n, k;
        scanf("%d%d", &n, &k);
        while (k + temp / i > temp && n > 0)
        {
            temp = k + temp / i, ++i, --n;
        }
        printf("%.1lf\n", temp);
    }
    return 0;
}