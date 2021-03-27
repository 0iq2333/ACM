#include <bits/stdc++.h>
using namespace std;
int fx(int x)
{
    int re = 1;
    for (int i = 2; i * i <= x; i++)
    {
        int a = 1;
        while (x % i == 0)
        {
            x /= i;
            a *= i;
        }
        re = re * (a * i - 1) / (i - 1);
    }
    return x > 1 ? re * (x + 1) : re;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fx(n) << endl;
    return 0;
}