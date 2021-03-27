#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxx = 1e4 + 5;
const ll B = 131;
ll Hash[maxn], Base[maxx], ha, lena, lenb, cnt;
string a, b;
void Hash_a(string s, int len)
{
    Base[0] = 1;
    ha = 0;
    for (int i = 1; i <= len; i++)
    {
        Base[i] = Base[i - 1] * B % mod;
        ha = (ha * B + s[i - 1]) % mod;
    }
}
void Hash_b(string s, int len)
{
    Hash[0] = 0;
    for (int i = 1; i <= len; i++)
        Hash[i] = (Hash[i - 1] * B + s[i - 1]) % mod;
}
ll gethash(int l, int r) // s[l]~s[r]
{
    l++;
    r++;
    return ((Hash[r] - Hash[l - 1] * Base[r - l + 1] % mod) + mod) % mod;
}
void solve()
{
    Hash_a(a, lena);
    Hash_b(b, lenb); //l=i,r=i+lena-1;
    for (int i = 0; i + lena <= lenb; i++)
    {
        ll tmp = gethash(i, i + lena - 1);
        if (tmp == ha)
            ++cnt;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cnt = 0;
        cin >> a >> b; //用a是字串
        lena = a.size();
        lenb = b.size();
        if (lena >= lenb)
        {
            if (a == b)
                ++cnt;
        }
        else
            solve();
        cout << cnt << endl;
    }
    return 0;
}