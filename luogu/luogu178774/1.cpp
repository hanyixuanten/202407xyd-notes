#include <iostream>
#include <vector>

using namespace std;

long long solve(long long n, vector<int> &ops)
{
    long long ans = n;
    for (int op : ops)
    {
        if (op == 1)
        {
            ans = (ans + 1) / 2;
        }
        else
        {
            ans = ans / 2;
        }
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n, k;
        cin >> n >> k;
        vector<int> ops(k);
        for (int i = 0; i < k; i++)
        {
            cin >> ops[i];
        }
        cout << solve(n, ops) << endl;
    }
    return 0;
}
