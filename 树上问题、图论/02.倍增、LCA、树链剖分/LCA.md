# LCA

- [LCA](#lca)
  - [定义](#定义)
  - [基本性质](#基本性质)
  - [算法流程](#算法流程)
    - [朴素LCA](#朴素lca)
    - [倍增LCA](#倍增lca)
      - [参考代码](#参考代码)

## 定义

在一个**有根树**中，多个点（并非一定两个）离根最远的公共的祖先。

## 基本性质

1. $u$ 是 $v$ 的祖先，当且仅当 $LCA(u, v) = u$
2. 如果 $u, v$ 互相不为祖先，那么 $u, v$ 分别处于 $LCA(u, v)$ 的两棵不同子树中
3. 前序遍历中， $LCA(S)$ 出现在所有 $S$ 中的元素之前，后序遍历则相反。
4. 两点集并的LCA为两点集分别的LCA的LCA,即 $LCA(A \cup B ) = LCA(LCA(A), LCA(B))$
5. 两点的LCA一定在两点的树上最短路径上。

## 算法流程

### 朴素LCA

每次找到深度较大的点，往上跳，显然最后这两个点会汇聚在同一个点，这个点就是LCA

朴素算法需要DFS整棵树，预处理和单次查询的最坏时间复杂度为 $O(n)$

参考代码就不写了--

### 倍增LCA

记 $fa_{x, i}$ 表示点 $x$ 的第 $2 ^ i$ 个祖先，显然 $fa_{x, i} = fa_{fa_{x, i - 1}, i - 1}$，可以以 $O(n log n)$ 的复杂度预处理。

查询LCA时，我们求出两点深度之差 $\Delta dep$，通过对其的二进制拆分，将两个点跳到同一高度。深度相同后，若 $u, v$ 仍不相等，则两点同时向上跳 $2 ^ i$ 步，一直尝试到两节点不相等，重复这个步骤直到两节点相等且儿子不相等，时间复杂度为 $O(log n)$

#### 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int fa[20][maxn], dep[maxn];
void get_fa(int n)
{
    for (int k = 1; k < 20; ++k)
    {
        for (int u = 1; u <= n; ++u)
        {
            fa[k][u] = fa[k - 1][fa[k - 1][u]];
        }
    }
}
int LCA(int u, int v)
{
    if (dep[u] > dep[v])
        swap(u, v);
    for (int k = 19; k >= 0; --k)
        if (dep[fa[k][v]] >= dep[u])
            v = fa[k][v];
    if (u == v)
        return u;
    for (int k = 19; k >= 0; --k)
    {
        if (fa[k][u] != fa[k][v])
            u = fa[k][u], v = fa[k][v];
    }
    return fa[0][u];
}
```

---
