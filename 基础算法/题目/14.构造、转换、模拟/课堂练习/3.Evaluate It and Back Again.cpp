#include <bits/stdc++.h>
using namespace std;
string ans;
string to_9(long long n)
{
    bool flag = n >= 0;
    if (!flag)
        n = -n;
    ans = "";
    long long cnt = 0;
    long long yu[20] = {};
    while (n >= 10ll)
        yu[cnt++] = n % 9ll, n /= 9ll;
    yu[cnt] = n;
    if (!flag)
        ans += "0-";
    for (long long i = 0; i <= cnt; ++i)
    {
        if (yu[cnt - i] != 0)
        {
            for (long long j = 0; j < cnt - i; ++j)
                ans += "9*";
            ans += yu[cnt - i] + '0';
            if (flag)
                ans += "+0+";
            else
                ans += "-0-";
        }
    }
    while (ans[ans.size() - 1] == '+' || ans[ans.size() - 1] == '-')
        ans.pop_back();
    return ans;
}
string to_9_0(long long n)
{
    bool flag = n >= 0;
    if (!flag)
        n = -n;
    ans = "";
    long long cnt = 0;
    long long yu[20] = {};
    while (n >= 10)
    {
        yu[cnt++] = n % 9ll;
        n /= 9ll;
    }
    yu[cnt] = n;
    if (!flag)
        ans += "0-";
    for (long long i = 0; i <= cnt; ++i)
    {
        if (yu[cnt - i] != 0)
        {
            for (long long j = 0; j < cnt - i; ++j)
                ans += "9*";
            ans += yu[cnt - i] + '0';
            if (flag)
                ans += "-0+";
            else
                ans += "+0-";
        }
    }
    while (ans[ans.size() - 1] == '+' || ans[ans.size() - 1] == '-')
        ans.pop_back();
    return ans;
}
int main()
{
    long long p = 0, q = 0;
    scanf("%lld%lld", &p, &q);
    if (abs(p) % 2 == abs(q) % 2) // 同号
    {
        long long _pq = p + q >> 1, p_q = p - _pq;
        if (p == 0 && q == 0)
        {
            puts("0");
            return 0;
        }
        cout << to_9(_pq) << ((_pq != 0 && p_q != 0) ? "+" : "") << to_9_0(p_q) << endl;
    }
    else // 异号
    {
        long long _pq = (p - 21 + q - 12) >> 1, p_q = p - 21 - _pq;
        cout << to_9(_pq) << ((_pq != 0 && p_q != 0) ? "+" : "") << to_9_0(p_q) << ((p_q != 0 || _pq != 0) ? "+" : "") << "21" << endl;
    }
    return 0;
}

/*
_pq表示为翻过来相同的数
p_q表示为翻过来相反的数
p=_pq+p_q p=_pq+p_q+21
q=_pq-p_q q=_pq+p_q+12
*/