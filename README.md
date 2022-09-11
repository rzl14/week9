# week9
## 数学知识
### 欧拉函数
1∼N 中与 N 互质的数的个数被称为欧拉函数
```
int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);

    return res;
}
```

### 筛法求欧拉函数
当x为质数，欧拉函数为x - 1;
当i % j == 0，且j为质数，i * j 的欧拉函数为i的欧拉函数乘以j;
当i % j != 0，且j为质数，i * j 的欧拉函数为i的欧拉函数乘以j - 1;
```
int primes[N], cnt;     // primes[]存储所有素数
int euler[N];           // 存储每个数的欧拉函数
bool st[N];         // st[x]存储x是否被筛掉


void get_eulers(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)
            {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}
```
### 快速幂
求 m^k mod p，时间复杂度 O(logk)。
```
int qmi(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
```

### 扩展欧几里得算法
求x, y，使得ax + by = gcd(a, b)
```
void exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= (a/b) * x;
}
```

## 动态规划
状态就是一个未知数
###    状态表示 ：
如 f(i,j)，只从前i个物品中选，总体积不超过j
考虑清楚需要几维的状态来表示以及每一种状态的意义
 ####       两个角度
  #####          集合怎样表示所有选法
  如01背包问题
  只考虑前 i 个物品
  只考虑体积<= j
  f(i,j)表示只从前i个物品中选，总体积不超过j


   #####         集合的属性，如最大值，最小值，个数


 ###   状态计算
 就是指如何一步一步的算出来每一个状态
 方法是集合划分

 ###   优化
 对代码或计算方程进行等价变形


### 背包问题
 ####   01背包问题
  特点：每件物品只能用一次
  #####      状态表示：f(i, j)
  集合：只从前 i 个物品中选，选出来的总体积不超过 j
  属性：Max

   #####     状态计算：集合的划分
   分成两组，选第 i 个和不选第 i 个
   f(i, j) = max(f(i - 1, j), f(i - 1, j - v[i]) + w[i])


 ####   完全背包问题
 特点：每件物品有无限个
  #####      状态表示：f(i, j)
  集合：所有只考虑前 i 个物品，且总体积不大于 j 的所有选法
  属性：Max。

  #####      状态计算：集合的划分
  分成若干组，按照第 i 个物品选多少个来划分(k = i 选择的数量)
  k = 0,  f(i - 1, j); k != 0,  f(i - 1, j - k * v[i]) + k * w[i],  并求max;
  求max


  ####  多重背包问题
  每个物品的个数不一样

  ####  分组背包问题
  每一组最多只能选一种物品


