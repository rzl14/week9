#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1000010;

int primes[N], cnt;
int phi[N];
bool st[N];

LL get_eulers(int n)
{
    LL res = 1;
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) {
            primes[cnt ++] = i;
            phi[i] = i - 1;
            res += phi[i];
        }
        for (int j = 0; primes[j] <= n / i; j ++) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                phi[t] = primes[j] * phi[i];
                res += phi[t];
                break;
            }
            phi[t] = (primes[j] - 1) * phi[i];
            res += phi[t];
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << get_eulers(n) << endl;
}