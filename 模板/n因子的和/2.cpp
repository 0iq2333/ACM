#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int maxn = 1e6;

int prime[maxn + 5];
bool vis[maxn + 5];
int cnt;
void init() //线性筛
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        if (vis[i] == 0)
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && prime[j] * i <= maxn; j++)
        {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int fx(int x) //唯一分解定理
{
    int ans = 1;
    for (int i = 1; prime[i] * prime[i] <= x; i++)
    {
        int a = 1;
        while (x % prime[i] == 0)
        {
            x /= prime[i];
            a *= prime[i];
        }
        ans = ans * (a * prime[i] - 1) / (prime[i] - 1); //等比数列求和公式，首项为一
    }
    if (x > 1)
        ans = ans * (x + 1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    init();
    while (cin >> n)
    {
        cout << fx(n) << endl;
    }
    return 0;
}