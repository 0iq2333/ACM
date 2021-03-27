#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int maxn = 1e6 + 5;
bool vis[maxn];
int cnt = 0;
ll prime[maxn];
void init()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        if (vis[i] == 0)
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    init();
    return 0;
}