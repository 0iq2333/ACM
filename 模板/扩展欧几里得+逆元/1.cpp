#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
const double PI = acos(-1.0);
void exgcd(int a, int b, int &x, int &y) //求ax+my=b;
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}
int mod_inverse(int a, int m)
{
    int x, y;
    exgcd(a, m, x, y);
    return (m + x % m) % m;//消去复数
    //return x;
}
int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a , m , b;
    cin >> a >> m >> b;
    int x = mod_inverse(a,m)*b;
    int y = (b - a*x)/m;
    cout << "x==" << x << "  y==" << y << endl; 
    return 0;
}