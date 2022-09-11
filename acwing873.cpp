#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n --) {
        int x;
        cin >> x;
        int res = x;
        for (int i = 2; i <= x / i; i ++)
            if (x % i == 0) {
                while (x % i == 0) x /= i;
                res = res / i * (i - 1);
            }
        if (x > 1) res = res / x * (x - 1);
        cout << res << endl;
    }
}