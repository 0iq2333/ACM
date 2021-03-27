#include <bits/stdc++.h>
using namespace std;
map<int, bool> vis;
vector<int> num;
void E_sushu(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (vis.count(i) == 0)
            for (int j = i * i; j <= n; j += i)
                vis[j] = 1;
    for (int i = 2; i <= n; i++)
        if (vis.count(i) == 0)
            num.push_back(i);
}
int fx(int n, int p)
{
    int re = 0;
    while (n)
    {
        re += (n / p);
        n /= p;
    }
    return re;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, ans = 1;
    cin >> n;
    E_sushu(n);
    for (vector<int>::iterator iter = num.begin(); iter != num.end(); ++iter)
        ans *= (fx(n, *iter) + 1);
    cout << ans << endl;
    return 0;
}