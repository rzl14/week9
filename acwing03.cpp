/**
 * 完全背包问题
 * 状态表示：f(i, j)
        集合：所有只考虑前 i 个物品，且总体积不大于 j 的所有选法
        属性：Max。

 * 状态计算：集合的划分
        分成若干组，按照第 i 个物品选多少个来划分(k = i 选择的数量)
        k = 0,  f(i - 1, j);
        k != 0,  f(i - 1, j - k * v[i]) + k * w[i],  并求max;
 * 
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++ )
        for (int j = v[i]; j <= m; j ++ )
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}