#include <bits/stdc++.h>
using namespace std;
const int N = 16;
int ones[1 << N], cnt_log[1 << N]; // ones[x]表示x在二进制下有多少个1；log[x]表示log(x)的值
int state[N][N];                   // 状态存储，表示x行y列这个格子可以填哪些数（0-15），15位二进制表示
char str[N][N + 1];
int bstate[N * N + 1][N][N], bstate2[N * N + 1][N][N]; // bstate和bstate2都存储状态的备份(搜索最多有N*N层，每层有一个备份)
char bstr[N * N + 1][N][N + 1];                        // 输入的N宫格也要备份
inline int lowbit(int x)
{
    return x & -x;
}
void draw(int x, int y, int c) // 在(x,y)这个格子上写上字母c(0到15表示A到P)
{
    str[x][y] = 'A' + c; // 先写进去，转换为原来的字母

    for (int i = 0; i < N; ++i) // 更新state
    {
        state[x][i] &= ~(1 << c); // x这一行其他位置都不能再填c (把表示c的二进制位改成0，yxc大佬的位运算)
        state[i][y] &= ~(1 << c); // y这一列其他位置都不能再填c
    }

    int sx = x / 4 * 4, sy = y / 4 * 4; // 把(x,y)所在的十六宫格也做一次同样的操作
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            state[sx + i][sy + j] &= ~(1 << c); // 同上

    state[x][y] = 1 << c;
}
bool dfs(int cnt) // 传入的参数cnt表示当前空格个数
{
    if (!cnt)
        return true; // cnt为零就找到了方案，返回true
    int kcnt = cnt;  // 先进行备份
    memcpy(bstate[kcnt], state, sizeof state);
    memcpy(bstr[kcnt], str, sizeof str);
    // 1对于每个空格，如果不能填任何一个字母，则返回false；如果只能填一个字母，那么直接填上
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (str[i][j] == '-')
            {
                if (!state[i][j]) 
                {
                    memcpy(state, bstate[kcnt], sizeof state);
                    memcpy(str, bstr[kcnt], sizeof str);
                    return false;
                }
                if (ones[state[i][j]] == 1)
                {
                    draw(i, j, cnt_log[state[i][j]]);
                    --cnt;
                }
            }
    // 2对于每一行，如果某个字母不能出现在任何一个位置，则返回false；如果某个字母只有一个位置可以填，则直接填上
    for (int i = 0; i < N; ++i)
    {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        for (int j = 0; j < N; ++j)
        {
            int s = state[i][j];
            sand &= ~(sor & s);
            sor |= s;
            if (str[i][j] != '-')
                drawn |= state[i][j];
        }
        if (sor != (1 << N) - 1)
        {
            memcpy(state, bstate[kcnt], sizeof state); 
            memcpy(str, bstr[kcnt], sizeof str);
            return false;
        }
        for (int j = sand; j; j -= lowbit(j))
        {
            int t = lowbit(j);
            if (!(drawn & t))
            {
                for (int k = 0; k < N; ++k)
                    if (state[i][k] & t)
                    {
                        draw(i, k, cnt_log[t]);
                        --cnt;
                        break;
                    }
            }
        }
    }
    // 3对于每一列，同剪枝2
    for (int i = 0; i < N; ++i)
    {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        for (int j = 0; j < N; ++j)
        {
            int s = state[j][i];
            sand &= ~(sor & s);
            sor |= s;
            if (str[j][i] != '-')
                drawn |= state[j][i];
        }
        if (sor != (1 << N) - 1)
        {
            memcpy(state, bstate[kcnt], sizeof state);
            memcpy(str, bstr[kcnt], sizeof str);
            return false;
        }
        for (int j = sand; j; j -= lowbit(j))
        {
            int t = lowbit(j);
            if (!(drawn & t))
            {
                for (int k = 0; k < N; ++k)
                    if (state[k][i] & t)
                    {
                        draw(k, i, cnt_log[t]);
                        --cnt;
                        break;
                    }
            }
        }
    }
    // 4对于每个N宫格，同剪枝2
    for (int i = 0; i < N; ++i)
    {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        for (int j = 0; j < N; ++j)
        {
            int sx = i / 4 * 4, sy = i % 4 * 4;
            int dx = j / 4, dy = j % 4;
            int s = state[sx + dx][sy + dy];
            sand &= ~(sor & s);
            sor |= s;

            if (str[sx + dx][sy + dy] != '-')
                drawn |= state[sx + dx][sy + dy];
        }
        if (sor != (1 << N) - 1)
        {
            memcpy(state, bstate[kcnt], sizeof state);
            memcpy(str, bstr[kcnt], sizeof str);
            return false;
        }
        for (int j = sand; j; j -= lowbit(j))
        {
            int t = lowbit(j);
            if (!(drawn & t))
            {
                for (int k = 0; k < N; ++k)
                {
                    int sx = i / 4 * 4, sy = i % 4 * 4;
                    int dx = k / 4, dy = k % 4;
                    if (state[sx + dx][sy + dy] & t)
                    {
                        draw(sx + dx, sy + dy, cnt_log[t]);
                        --cnt;
                        break;
                    }
                }
            }
        }
    }
    // 5每次选择空格时，选择能填的字母数量最少的格子来填
    if (!cnt)
        return true;

    int x, y, s = 100;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (str[i][j] == '-' && ones[state[i][j]] < s)
            {
                s = ones[state[i][j]];
                x = i, y = j;
            }
    memcpy(bstate2[kcnt], state, sizeof state); 
    for (int i = state[x][y]; i; i -= lowbit(i))
    {
        memcpy(state, bstate2[kcnt], sizeof state);
        draw(x, y, cnt_log[lowbit(i)]);
        if (dfs(cnt - 1))
            return true;
    }
    memcpy(state, bstate[kcnt], sizeof state);
    memcpy(str, bstr[kcnt], sizeof str);
    return false;
}

int main()
{
    for (int i = 0; i < N; ++i) // 预处理log
        cnt_log[1 << i] = i;
    for (int i = 0; i < (1 << N); ++i) // 预处理ones数组
        for (int j = i; j; j -= lowbit(j))
            ++ones[i];
    while (cin >> str[0])
    {
        for (int i = 1; i < N; ++i)
            cin >> str[i];
        for (int i = 0; i < N; ++i) // 预处理state
            for (int j = 0; j < N; ++j)
                state[i][j] = (1 << N) - 1;
        int cnt = 0;                // 待填个数
        for (int i = 0; i < N; ++i) // 接着在遍历一遍，看那些格子已经填好了
            for (int j = 0; j < N; ++j)
                if (str[i][j] != '-')
                    draw(i, j, str[i][j] - 'A'); // 如果已经填好了就更新state,A到P分别用0到15表示
                else
                    ++cnt;

        dfs(cnt);
        for (int i = 0; i < N; ++i)
            cout << str[i] << endl;
        puts("");
    }
    return 0;
}