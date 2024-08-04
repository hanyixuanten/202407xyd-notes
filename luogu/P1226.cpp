#include <bits/stdc++.h>
#define int long long
using namespace std;
int power(int a, int b, int p)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % p;
    if (b % 2 == 0)
        return power(a * a % p, b / 2, p) % p;
    else
        return (power(a * a % p, b / 2, p) * a) % p;
}
int a, b, p;
signed main()
{
    scanf("%d%d%d", &a, &b, &p);
    printf("%lld^%lld mod %lld=%lld", a, b, p, power(a, b, p) % p);
    return 0;
}